count=1;
for i = 1:323

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/es/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 0;
    count = count + 1;
            
        
end
for i = 1:183

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wb/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 1;
    count = count + 1;
            
        
end
for i = 1:180

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wk/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 2;
    count = count + 1;
            
        
end
for i = 1:183

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wn/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 3;
    count = count + 1;
            
        
end
for i = 1:172

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wp/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 4;
    count = count + 1;
            
        
end
for i = 1:179

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wq/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 5;
    count = count + 1;
            
        
end
for i = 1:244

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/wr/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 6;
    count = count + 1;
            
        
end
for i = 1:182

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/bb/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 7;
    count = count + 1;
            
        
end
for i = 1:179

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/bk/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 8;
    count = count + 1;
            
        
end
for i = 1:183

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/bn/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 9;
    count = count + 1;
            
        
end
for i = 1:181

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/bp/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 10;
    count = count + 1;
            
        
end
for i = 1:170

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/bq/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 11;
    count = count + 1;
            
        
end
for i = 1:248

    myfilename = sprintf('F:/Github/chess-playing-robot/Model/Dataset/train/br/800 (%d).png', i);
    img = imread(myfilename);
    [height, width, dim] = size(img);
    X(:,:,:,count) = img;                
    Y(count,1) = 12;
    count = count + 1;
            
        
end
save('chess_train_final_5.mat','X','Y');