#include "context.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

Context::Context(int** img, int pixel_x, int pixel_y, int k, int cols, int rows) {
	//this->extracto = new char[4 + k];
	this->contexto = new int* [3];

	for (int i = 0; i < 3; i++) {
		this->contexto[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//los contextos son espaciales.
			//por lo tanto 0 < x < columns
			//			   0 < y < rows

			//hay que arreglar esto... o no
			//cout << rows << "  " << cols << endl;
			if ((pixel_x + i - 1) < 0 || (pixel_x - 1 + i) > cols-1 
				|| (pixel_y - 1 + j) < 0 || (pixel_y - 1 + j) > rows-1) {
				this->contexto[i][j] = this->out;
			}
			else
				this->contexto[i][j] = img[pixel_x - 1 + i][pixel_y - 1 + j];
			//cout << this->contexto[i][j] << " "; //para verifcar si se carga bien
			
		}
		//cout << endl;
	}
	this->setExtracto(k);
}

int binaryToDecimal(string n) 
{
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 


int** Context::getContexto() {
	return this->contexto;
}
bitset<12> Context::getExtracto() {
	return this->extracto;
}

int Context::promedio() {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i!=1) || (j!=1)) {
				res = res + this->contexto[i][j];
			}
		}
	}
	res = floor((res / 8) + 0.5);
	return res;
}

void Context::setExtracto(int k) {
	bitset<8> norte(this->contexto[1][0]);//pixel NORTE en binario
	bitset<8> este(this->contexto[2][1]);//pixel ESTE en binario
	bitset<8> sur(this->contexto[1][2]);//pixel SUR en binario
	bitset<8> oeste(this->contexto[0][1]);//pixel OESTE en binario
	/*cout << "Norte: "<< norte << endl; 
	cout << "Este: "<< este << endl;
	cout << "Sur: "<< sur << endl;
	cout << "Oeste: "<< oeste << endl;*/


	this->extracto[3+k] = norte[7];
	this->extracto[2+k] = este[7];
	this->extracto[1+k] = sur[7];
	this->extracto[k] = oeste[7];

	int promedio = this->promedio();
	bitset<8> promedio_bin(promedio);
	if (k > 0) this->extracto[k-1] = norte[6];
	if (k > 1) this->extracto[k-2] = promedio_bin[7];
	if (k > 2) this->extracto[k-3] = oeste[6];
	if (k > 3) this->extracto[k-4] = promedio_bin[6];
	if (k > 4) this->extracto[k-5] = sur[6];
	if (k > 5) this->extracto[k-6] = promedio_bin[5];
	if (k > 6) this->extracto[k-7] = este[6];
	if (k > 7) this->extracto[k-8] = promedio_bin[4];
	/*cout << "Extracto:  " << this->extracto << endl;*/
}

Context::~Context() {}