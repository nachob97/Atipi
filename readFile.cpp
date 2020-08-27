#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "readFile.hpp"


using namespace std;

int** readFile(string path, int cols, int rows, int range) {

    string line;
    ifstream infile(path, ios::in | ios::binary);
    streambuf* ss = infile.rdbuf();
    if (infile.is_open()) {
        getline(infile, line);
        //aca iria condicion de line= "P5 O P6"
        getline(infile, line);// esto es el comentario
        getline(infile, line);
        getline(infile, line);
        int** img = new int* [rows];
        for (int i = 0; i < rows; i++) {
            img[i] = new int[cols];
        }
        //------------------- CANTIDAD DE COLUMNAS, FILAS Y RANGO
        cout << cols << endl;
        cout << rows << endl;
        cout << range << endl;
        //--------------------CANTIDAD DE COLUMNAS, FILAS Y RANGO
        unsigned char c;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //infile.read(&c, sizeof(char));
                c= char(ss->sbumpc());
                img[i][j] = int(c);//ss->sbumpc();
            }
        }
        infile.close();
        return img;
    }
    else cout << "ERROR ABRIENDO PGM" << endl; 
    return 0;
}



void readHead(string path,int &cols, int &rows, int &range) {
    string line;
    ifstream in_file(path);
    if (in_file.is_open()) {
        getline(in_file, line);
        //aca iria condicion de line= "P5 O P6"
        getline(in_file, line);// esto es el comentario
        getline(in_file, line, ' ');
        cols = stoi(line);
        getline(in_file, line);
        rows = stoi(line);
        getline(in_file, line);
        range = stoi(line);
        in_file.close();
    }
    else
        cout << "ERROR" << endl;
}


void createImage(int** image, int cols, int rows){
    FILE* pgmimg;
    pgmimg = fopen("foto_ReadFile.pgm", "wb");
    fprintf(pgmimg, "P5\n");
    fprintf(pgmimg, "#Denoised Image (Ignacio bianchi & Santiago Curi)\n");  
    fprintf(pgmimg, "%d %d\n", cols, rows); 
    fprintf(pgmimg, "255\n"); 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(pgmimg, "%c", (image[i][j]) );
        }
        //fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
}


/*
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
*/