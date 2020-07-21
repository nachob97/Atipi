#include "context.hpp"
#include <iostream>
#include <bitset>

using namespace std;

Context::Context(int** img, int pixel_x, int pixel_y, int k) {
	this->extracto = new int[4 + k];
	this->contexto = new int* [3];
	for (int i = 0; i < 3; i++) {
		this->contexto[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((pixel_x - 1 + i) < 0 || (pixel_y - 1 + j) < 0) {
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



int** Context::getContexto() {
	return this->contexto;
}
int* Context::getExtracto() {
	return this->extracto;
}

int Context::promedio() {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i!=2) & (j!=2)) {
				res = res + this->contexto[i][j];
			}
		}
	}
	res = floor((res / 8) + 0.5);
	return res;
}

void Context::setExtracto(int k) {
	bitset<8> norte(this->contexto[0][1]);//pixel NORTE en binario
	bitset<8> este(this->contexto[1][2]);//pixel ESTE en binario
	bitset<8> sur(this->contexto[2][1]);//pixel SUR en binario
	bitset<8> oeste(this->contexto[1][0]);//pixel OESTE en binario

	this->extracto[0] = norte[0];
	this->extracto[1] = este[0];
	this->extracto[2] = sur[0];
	this->extracto[3] = oeste[0];

	int promedio = this->promedio();
	bitset<8> promedio_bin(promedio);
	if (k > 0) this->extracto[4] = norte[1];
	if (k > 1) this->extracto[5] = promedio_bin[0];
	if (k > 2) this->extracto[6] = este[1];
	if (k > 3) this->extracto[7] = promedio_bin[1];
	if (k > 4) this->extracto[8] = sur[1];
	if (k > 5) this->extracto[9] = promedio_bin[2];
	if (k > 6) this->extracto[10] = oeste[1];
	if (k > 7) this->extracto[11] = promedio_bin[3];
}

Context::~Context() {}