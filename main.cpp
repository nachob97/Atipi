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
    HandlerContext* hc = HandlerContext::getInstance();
    //ACA VAN 2 FOR PARA SACAR CONTEXTO DE TODOS LOS PIXEL
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            Context* cont = new Context(image, i, j, 4);//valores de prueba para contexto
            int extracto = (int)cont->getExtracto().to_ulong();
            //if 
            hc->add(extracto); 
            //{
                //ya se hace en add
              //  hc->addContToDist(cont->getExtracto());
            //}
            hc->sum1(extracto, image[i][j]);
        }
    }
    //crear la imagen
  /*  for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            int prediccion = (int)cont->getExtracto().to_ulong();

        }
    }*/
    return 0;
}