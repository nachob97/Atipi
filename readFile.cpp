#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int* readFile(string path) {

    string line;
    int cols, rows, range;
    ifstream infile(path);
    streambuf* ss = infile.rdbuf();
    if (infile.is_open()) {
        getline(infile, line);
        //aca iria condicion de line= "P5 O P6"
        getline(infile, line);// esto es el comentario
        getline(infile, line, ' ');
        cols = stoi(line);
        getline(infile, line);
        rows = stoi(line);
        int** img = new int* [cols];
        for (int i = 0; i < cols; i++) {
            img[i] = new int[rows];
        }
        getline(infile, line);
        range = stoi(line);
        //------------------- CANTIDAD DE COLUMNAS, FILAS Y RANGO
        cout << cols << endl;
        cout << rows << endl;
        cout << range << endl;
        //--------------------CANTIDAD DE COLUMNAS, FILAS Y RANGO
        unsigned char c;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                c = char(ss->sbumpc());
                cout << c << " "; // caracter del pixel
                cout << int(c) << " "; //valor del caracter en la tabla ASCII
                img[i][j] = int(c);
            }
            cout << endl;
        }
        return *img;
    }
    return 0;
}
int main() {
    string path = "C:/Users/curisantiago3/Desktop/facultad/ATIPI/ImgDUDE-M-arioSimetrico/Img99M0.05.pgm";
    int* image = readFile(path);
    return 0;
}
