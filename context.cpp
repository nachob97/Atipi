#include "context.hpp"
#include <iostream>

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
			cout << this->contexto[i][j] << " ";
			
		}
		cout << endl;
	}

}



int** Context::getContexto() {
	return this->contexto;
}
int* Context::getExtracto() {
	return this->extracto;
}


Context::~Context() {}