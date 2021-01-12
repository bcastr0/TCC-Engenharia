dir='C:\Users\marce\Desktop\MATLAB\Interface\Imagens\';
Alfabeto = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'I', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'];

for i = 1:size(Alfabeto,2)
    file = sprintf('%s%s.jpg',dir,Alfabeto(i));
    image = imread(file);
    imshow(image);
end
size(Alfabeto,2)

