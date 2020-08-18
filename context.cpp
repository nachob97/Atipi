#include "context.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

Context::Context(int** img, int pixel_x, int pixel_y, int k) {
	//this->extracto = new char[4 + k];
	this->contexto = new int* [3];
	int rows =  sizeof img / sizeof img[0]; // 2 rows  
  	int cols = sizeof img[0] / sizeof(int); // 5 cols

	for (int i = 0; i < 3; i++) {
		this->contexto[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//los contextos son espaciales.
			//por lo tanto 0 < x < columns
			//			   0 < y < rows

			//hay que arreglar esto... o no
			if ((pixel_x + i - 1) < 0 || (pixel_x - 1 + i) >= cols 
				|| (pixel_y - 1 + j) < 0 || (pixel_y - 1 + j) >= rows) {
				this->contexto[i][j] = this->out;
			}
			else
				this->contexto[i][j] = img[pixel_x - 1 + i][pixel_y - 1 + j];
			cout << this->contexto[i][j] << " "; //para verifcar si se carga bien
			
		}
		cout << endl;
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

	this->extracto[12-(4+k)] = norte[0];
	this->extracto[12-(3+k)] = este[0];
	this->extracto[12-(2+k)] = sur[0];
	this->extracto[12-(1+k)] = oeste[0];

	int promedio = this->promedio();
	bitset<8> promedio_bin(promedio);
	if (k > 0) this->extracto[12-k] = norte[1];
	if (k > 1) this->extracto[12-(k-1)] = promedio_bin[0];
	if (k > 2) this->extracto[12-(k-2)] = oeste[1];
	if (k > 3) this->extracto[12-(k-3)] = promedio_bin[1];
	if (k > 4) this->extracto[12-(k-4)] = sur[1];
	if (k > 5) this->extracto[12-(k-5)] = promedio_bin[2];
	if (k > 6) this->extracto[12-(k-6)] = este[1];
	if (k > 7) this->extracto[12-(k-7)] = promedio_bin[3];
}

Context::~Context() {}