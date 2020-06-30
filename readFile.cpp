#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int* readFile(string path) {

    string line;
    int cols, rows, range;
    ifstream infile(path);
    stringstream ss;
    if (infile.is_open()) {
        getline(infile, line);
        //aca iria condicion de line= "P5 O P6"
        ss << infile.rdbuf();
        ss >> cols >> rows;
        int img[cols][rows];
        ss >> range;
        //------------------- CANTIDAD DE COLUMNAS, FILAS Y RANGO
        cout << cols << endl;
        cout << rows << endl;
        cout << range << endl;
        //--------------------CANTIDAD DE COLUMNAS, FILAS Y RANGO
        unsigned char c;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                ss >> c;
                cout << c << " "; // caracter del pixel
                cout << int(c) << " "; //valor del caracter en la tabla ASCII
                img[i][j] = int(c);
            }
            cout << endl;
        }
        return *img;
        /*  for(int i = 0; i < rows; i++) {
              for(int j=0;j<rows;j++){
                  cout << img[i][j] << "  ";
              }
              cout << endl;
          }*/
    }
}
int main() {
    string path = "C:/Users/curisantiago3/Desktop/facultad/ATIPI/Imagenes-LOCO-PGM/baloons.pgm";
    int* image = readFile(path);
    return 0;
}

