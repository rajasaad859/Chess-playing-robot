from collections import defaultdict
from utils import *
import struct

class ControllerLayer:

    def __init__(self, arduino):

        self.__arduino = arduino

    def send_to_arduino(self, capturing, angle1, angle2):

        self.__arduino.write(struct.pack('>BBBBBBBBB', int(capturing), int(angle1[0]), int(angle1[1]), int(angle1[2]),
                                         int(angle1[3]), int(angle2[0]), int(angle2[1]), int(angle2[2]),
                                         int(angle2[3])))