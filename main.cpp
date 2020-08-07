#include <iostream>
#include "readFile.cpp"





int main() {
    string path = "./ImgDUDE-M-arioSimetrico/Img20M0.05.pgm";
    int cols, rows, range;
    readHead(path, cols, rows, range);
    int** image = readFile(path, cols, rows, range);
    createImage(image, cols, rows); //test de que carga bien la imagen
    Context* cont = new Context(image, 0, 0, 4);//valores de prueba para contexto
    //image = cont->getContexto();
    //cout << image[1][1] << endl;
    return 0;
}