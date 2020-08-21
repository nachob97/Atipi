#include <iostream>
#include "readFile.hpp"
#include "handlerContext.hpp"

using namespace std;

int main() {
    string path = "./ImgDUDE-M-arioSimetrico/Img07M0.05.pgm";
    int cols, rows, range;
    readHead(path, cols, rows, range);
    int** image = readFile(path, cols, rows, range);
    int** extractos = new int* [cols];
    for (int i = 0; i < cols; i++) {
		extractos[i] = new int[rows];
	}
    HandlerContext* hc = HandlerContext::getInstance();
    //ACA VAN 2 FOR PARA SACAR CONTEXTO DE TODOS LOS PIXEL
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            Context* cont = new Context(image, i, j, 4, cols, rows);//valores de prueba para contexto
            int extracto = (int)cont->getExtracto().to_ulong();
            extractos[i][j]= extracto;
            hc->add(extracto); 
            hc->sum1(extracto, image[i][j]);
        }
    }
    //crear la imagen
    double delta = 0.35;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            int prediccion = hc->predict(image[i][j], extractos[i][j], delta);
            image[i][j]= prediccion;
        }
    }

    createImage(image, cols, rows); //test de que carga bien la imagen
    return 0;
}