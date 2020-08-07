#include <iostream>
#include "readFile.hpp"
#include "handlerContext.hpp"

using namespace std;

int main() {
    string path = "./ImgDUDE-M-arioSimetrico/Img20M0.05.pgm";
    int cols, rows, range;
    readHead(path, cols, rows, range);
    int** image = readFile(path, cols, rows, range);
    createImage(image, cols, rows); //test de que carga bien la imagen
    //ACA VAN 2 FOR PARA SACAR CONTEXTO DE TODOS LOS PIXEL
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            Context* cont = new Context(image, i, j, 4);//valores de prueba para contexto
            HandlerContext* hc = HandlerContext::getInstance();
            hc->add(cont->getExtracto());
        }
    }
    //image = cont->getContexto();
    //cout << image[1][1] << endl;
    return 0;
}