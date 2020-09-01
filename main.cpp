#include <iostream>
#include "readFile.hpp"
#include "handlerContext.hpp"
#include <time.h>

using namespace std;


int main(int arguments, char* argv[]) {
//--------------------------------------------------float delta, string prefilterPath
    clock_t start, end;
    start = clock();
//--------------------------------------------------
    float delta = strtof(argv[1],nullptr);
    int k = atoi(argv[2]);
    string path = (argv[3]);
    cout << path << endl;
    char* output = argv[4];
    
    int cols, rows, range;
    cols = 0; rows = 0;range=0;
    //readHead(path, cols, rows, range);
    int** prefilter;
    if (arguments > 5) {
        string prefilterPath = argv[5];
        cout << prefilterPath << endl;
        prefilter = readFile(prefilterPath, cols, rows, range);
    }
    int** image = readFile(path, cols, rows, range);
    int** extractos = new int* [rows];
    for (int i = 0; i < rows; i++) {
		extractos[i] = new int[cols];
	}
    HandlerContext* hc = HandlerContext::getInstance();
    //ACA VAN 2 FOR PARA SACAR CONTEXTO DE TODOS LOS PIXEL

    if (arguments > 5) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Context* cont = new Context(prefilter, i, j, k, cols, rows);//valores de prueba para contexto
                int extracto = (int)cont->getExtracto().to_ulong();
                extractos[i][j] = extracto;
                hc->add(extracto);
                hc->sum1(extracto, image[i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Context* cont = new Context(image, i, j, k, cols, rows);//valores de prueba para contexto
                int extracto = (int)cont->getExtracto().to_ulong();
                extractos[i][j] = extracto;
                hc->add(extracto);
                hc->sum1(extracto, image[i][j]);
            }
        }
    }




    //crear la imagen
    int prediccion;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            prediccion = hc->predict(image[i][j], extractos[i][j], delta);
            image[i][j]= prediccion;
        }
    }
    createImage(image, cols, rows, output); //test de que carga bien la imagen

//--------------------------------------------------
    end = clock();
    float runtime = float(end - start) / float(CLOCKS_PER_SEC);
    cout << runtime << "seconds" << endl;
//--------------------------------------------------

    return 0;
}