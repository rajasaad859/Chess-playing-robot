import math
import operator
import sys
import pickle
from collections import defaultdict
import tensorflow as tf
from glob import glob
import random
import string
import serial
import struct
from time import sleep
import h5py
import cython
from image_slicer import slice
    
import cv2
load = cv2.imread
save = cv2.imwrite
    
import scipy.spatial as spatial
import scipy.cluster as clstr
    
import sklearn
    
import os, shutil
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
    
from tensorflow import keras 
from keras.preprocessing import image
from keras.preprocessing.image import load_img
from keras.models import load_model
from keras.applications.xception import preprocess_input
from keras.preprocessing.image import ImageDataGenerator
keras.backend.set_learning_phase(0)
    
import chess
import chess.engine
import chess.svg
# import chess.uci
    
from misc.config import *
from misc.utils import ImageObject, save_corners
from misc.slid import pSLID, SLID, slid_tendency

# from tensorflow.keras.optimizers import RMSprop
from misc.laps import LAPS                       
from misc.llr import LLR, llr_pad 

from misc import utils

from IPython.core.interactiveshell import InteractiveShell

HEIGHT = 150
WIDTH = 150
IMAGE_DIMS = (150, 150)

MODEL_LOC1 = '/misc/data/models/laps.h5'
MODEL_LOC2 = "/Model/saved_models/trained_model_final_bs32_225_dg_6.h5"

CHESS_ENGINE_PATH = "F:/Github/stockfish_14.1_win_x64_avx2/stockfish_14.1_win_x64_avx2.exe"

ARDUINO_PORT = 'COM4'

IP = 'http://192.168.29.227:8080/video'

def show_img(img):
    img = cv2.resize(img, (700, 700))
    cv2.imshow("Image", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
        
def adjust_gamma(image, gamma=1.5):
    invGamma = 1.0 / gamma
    table = np.array([((i / 255.0) ** invGamma) * 255
        for i in np.arange(0, 256)]).astype("uint8")
    
    return cv2.LUT(image, table)

def generate_board_arr1(img_number):
        
    row = ["H", "G", "F", "E", "D", "C", "B", "A"]
    col = ["8", "7", "6", "5", "4", "3", "2", "1"]
        
    a = 1
    b = 1
        
    matrix = []

    for r in range(0, 8):
        matrix.append([0 for c in range(0, 8)])

        
    arr = np.zeros((8, 8))
        
    an_array = np.full([8, 8], None)
        
    slice("chess-playing-robot/During Game/04 Picture Selected From Model 1/"+str(img_number)+".png" , 64)
        
    for j in row:
        b=1
        for k in col:
            os.rename("chess-playing-robot/During Game/04 Picture Selected From Model 1/"+str(img_number)+"_0" + str(a) + "_0"+ str(b) +".png","chess-playing-robot/During Game/05 Model 2 Output/" + j + k +".png")
            b += 1
        a += 1
        
    a = 0
    b = 0
        
    row = ["A", "B", "C", "D", "E", "F", "G", "H"]
    col = ["8", "7", "6", "5", "4", "3", "2", "1"]
        
    for j in col:
        a = 0
        for k in row:
            img = image.load_img("chess-playing-robot/During Game/05 Model 2 Output/" + k + j + ".png", target_size=(HEIGHT, WIDTH))
                
            img = np.reshape(img,(1,150,150,3))
            # print(img.shape)

            y = model1.predict_classes(img)
            print(y)

            if y==0:
                classes='E'
            elif y==1:
                classes='B'
            elif y==2:
                classes='K'
            elif y==3:
                classes='N'
            elif y==4:
                classes='P'
            elif y==5:
                classes='Q'
            elif y==6:
                classes='R'
            elif y==7:
                classes='b'
            elif y==8:
                classes='k'
            elif y==9:
                classes='n'
            elif y==10:
                classes='p'
            elif y==11:
                classes='q'
            else:
                classes='r'

            an_array[b][a] = classes
                
            a += 1
        b += 1
    return an_array

def fen_data_generation(new_board_arr):        
    fen=""
    count1=0
    count2=0
        
    for r in new_board_arr:
        s=""
        count1=count1+1
        count2=0
        for c in r:
            if c=='E':
                count2=count2+1
            else:
                if count2!=0:
                    s=s+str(count2)
                s=s+c
                count2=0
        if count2!=0:
            s=s+str(count2)
        if count1!=1:
            fen=fen+'/'+s
        else:
            fen=fen+s
    fen=fen+' b - - 0 0'
    return fen

def saveBoardImage():
    a=0
    count=1
    cam = cv2.VideoCapture(IP)
       
    while count < 6:
        # Get current frame
        ret, img = cam.read()
        cv2.namedWindow('Board Image',cv2.WINDOW_NORMAL)
        cv2.imshow("Board Image", img)
        
        key = cv2.waitKey(1)

        if key % 256 == 27: #ESC Pressed
            break

        elif key % 56 == 32: #SPACE Pressed
            for a in range(0, 5):
                file='chess-playing-robot/During Game/01 Original Image/' + str(count) + '.png'

                cv2.imwrite(file, img)
                count += 1
                sleep(1)

    # Release the object
    cam.release()

    # Close the window
    cv2.destroyAllWindows()

    
def passSavedImageToModel():
    
    count = 1
    
    perceptLayer = PerceptionLayer(model)
    
    while count <= 5:
        board_img = cv2.imread("chess-playing-robot/During Game/01 Original Image/"+ str(count) + ".png")

        try:
            perceptLayer.detect(board_img)
        except:
            count += 1
            continue
        else:
            img = cv2.imread("chess-playing-robot/3.png")
            
            img = cv2.resize(img, (700, 700))
            cv2.imshow("Board Image", img)
            
            key = cv2.waitKey(0)
            
            if key % 256 == 27: #ESC Pressed
                print ("REJECTED")
                count += 1
                continue
        
            elif key % 56 == 32: #SPACE Pressed
                print ("ACCEPTED")
                os.rename("chess-playing-robot/1.png", "chess-playing-robot/During Game/02 Model 1 Output 1/1.png")
                os.rename("chess-playing-robot/2.png", "chess-playing-robot/During Game/03 Model 1 Output 2/1.png")
                os.rename("chess-playing-robot/3.png", "chess-playing-robot/During Game/04 Picture Selected From Model 1/1.png")
                count = 5
                break

        count += 1
        
    cv2.destroyAllWindows()
    

def rotateImage():
    
    os.rename("chess-playing-robot/During Game/04 Picture Selected From Model 1/1.png", "chess-playing-robot/During Game/04 Picture Selected From Model 1/2.png")
    path = r'chess-playing-robot/During Game/04 Picture Selected From Model 1/2.png'
    src = cv2.imread(path)
    image = cv2.rotate(src, cv2.ROTATE_180)
    
    file='chess-playing-robot/During Game/04 Picture Selected From Model 1/1.png'
    cv2.imwrite(file, image)
    os.remove("chess-playing-robot/During Game/04 Picture Selected From Model 1/2.png")


def deleteFiles():
    a = 0
    b = 0
        
    row = ["A", "B", "C", "D", "E", "F", "G", "H"]
    col = ["8", "7", "6", "5", "4", "3", "2", "1"]
        
    for j in col:
        a = 0
        for k in row:
            os.remove("chess-playing-robot/During Game/05 Model 2 Output/" + k + j + ".png")
    
    os.remove("chess-playing-robot/During Game/01 Original Image/1.png")
    os.remove("chess-playing-robot/During Game/01 Original Image/2.png")
    os.remove("chess-playing-robot/During Game/01 Original Image/3.png")
    os.remove("chess-playing-robot/During Game/01 Original Image/4.png")
    os.remove("chess-playing-robot/During Game/01 Original Image/5.png")
    
    os.remove("chess-playing-robot/During Game/02 Model 1 Output 1/1.png")
    os.remove("chess-playing-robot/During Game/03 Model 1 Output 2/1.png")
    os.remove("chess-playing-robot/During Game/04 Picture Selected From Model 1/1.png")

def checkDestAvailability(squareName):    
    
    img = image.load_img("chess-playing-robot/During Game/05 Model 2 Output/" + squareName + ".png", target_size=(HEIGHT, WIDTH))
    
    img = np.reshape(img,(1,150,150,3))

    y = model1.predict_classes(img)

    if y==0:
         return '0'
    else:
        return '1'

AllAngles = [None] * 0

with open("Arm Movement\Angles.txt", "r") as file:
 
    for line in file:
     
        for word in line.split():
            
            AllAngles.append(word)


def getSouceAnglesFromFile(SquareName):
    
    count1 = 0
    
    Angle1 = 0 
    Angle2 = 0
    Angle3 = 0
    Angle4 = 0

    for word in AllAngles:
        if word == SquareName:
            count1 += 1
            continue

        if count1 == 1:
            Angle1 = word
            count1 += 1
            continue

        if count1 == 2:
            Angle2 = word
            count1 += 1
            continue

        if count1 == 3:
            Angle3 = word
            count1 += 1
            continue

        if count1 == 4:
            Angle4 = word
            count1 += 1
            continue
    ReqAngle = [Angle1, Angle2, Angle3, Angle4]
    
    return ReqAngle

class PerceptionLayer:

    def __init__(self, model):
        
        self.model = model

    def layer(self):
        global NC_LAYER, NC_IMAGE

        segments = pSLID(NC_IMAGE['main'])
        raw_lines = SLID(NC_IMAGE['main'], segments)
        lines = slid_tendency(raw_lines)
        points = LAPS(NC_IMAGE['main'], lines)
        inner_points = LLR(NC_IMAGE['main'], points, lines)
        four_points = llr_pad(inner_points, NC_IMAGE['main'])

        try:
            NC_IMAGE.crop(four_points)
            save(str(NC_LAYER) + ".png", NC_IMAGE['orig'])

        except:
            utils.warn("Next layer is not needed")
            NC_IMAGE.crop(inner_points)

        print("\n")


    def detect(self, image):
        global NC_LAYER, NC_IMAGE, NC_CONFIG

        NC_IMAGE, NC_LAYER = ImageObject(image), 0
        for _ in range(NC_CONFIG['layers']):
            NC_LAYER += 1
            self.layer()

        #show_img(NC_IMAGE['orig'])
        return NC_IMAGE['orig']

def predict(model, img):
    x = image.img_to_array(img)
    x = np.expand_dims(x, axis=0)
    x = preprocess_input(x)
    preds = model.predict(x)
    return preds[0]
    
def plot_preds(img, preds):
    gs = gridspec.GridSpec(2, 1, height_ratios=[4, 1])
    plt.figure(figsize=(8, 8))
    plt.subplot(gs[0])
    plt.imshow(np.asarray(img))
    plt.subplot(gs[1])
    plt.barh(range(0, CLASSES), preds, alpha=0.5)
    plt.yticks(range(0, CLASSES), LABELS)
    plt.xlabel('Probability')
    plt.xlim(0, 1)
    plt.tight_layout()
        
def get_pred(preds, labels):
    index_of_max = np.argmax(preds)
    return labels[index_of_max]

model = tf.keras.models.load_model(MODEL_LOC1)
model1 = tf.keras.models.load_model(MODEL_LOC2)

class ControllerLayer:

    def __init__(self, arduino):

        self.__arduino = arduino

    def send_to_arduino(self, capturing, angle1, angle2):

        self.__arduino.write(struct.pack('>BBBBBBBBB', int(capturing), int(angle1[0]), int(angle1[1]), int(angle1[2]),
                                         int(angle1[3]), int(angle2[0]), int(angle2[1]), int(angle2[2]),
                                         int(angle2[3])))
    
# Initalize Controller layer
arduino = serial.Serial(ARDUINO_PORT, 9600)
controlLayer = ControllerLayer(arduino)

# Initalize Perception Layer
perceptLayer = PerceptionLayer(model)

file_name = 1
capturing = 0
    
# Initalize Perception Layer
perceptLayer = PerceptionLayer(model)

# sleep(5)

while True:
    
    engine = chess.engine.SimpleEngine.popen_uci(CHESS_ENGINE_PATH)

    saveBoardImage()
    passSavedImageToModel()
    rotateImage()

    board_array = generate_board_arr1(file_name)

    fen_notation = fen_data_generation(board_array)

    board = chess.Board(fen_notation)

    chess.svg.board(board, size=350)

    result = engine.play(board, chess.engine.Limit(time=3))
    squares = str(result.move)

    Square = list(map(''.join, zip(*[iter(squares)]*2)))

    Angles1 = getSouceAnglesFromFile(Square[0].upper())
    Angles2 = getSouceAnglesFromFile(Square[1].upper())

    capturing = checkDestAvailability(Square[1].upper())
    
    sleep(5)
    
    deleteFiles()

    controlLayer.send_to_arduino(capturing,Angles1,Angles2)
    
    engine.quit()
        

arduino.close()