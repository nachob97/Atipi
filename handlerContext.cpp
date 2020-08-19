#include "handlerContext.hpp"
#include <iterator>
#include <iostream>
#include <cmath>
//#include <utility>

using namespace std;

HandlerContext::HandlerContext() {}

HandlerContext* HandlerContext::instance = NULL;

HandlerContext* HandlerContext::getInstance() {
	if (instance == NULL)
		instance = new HandlerContext();
	return (instance);
}

list<int> HandlerContext::getContextos() {
	return (this->contextos);
}

map<int, int*> HandlerContext::getDist() {
	return this->distribution;
}

bool HandlerContext::isequal(int* contexto1, int* contexto2) {
	int i = 0;
	while ((contexto1[i] != NULL) && (contexto1[i] != NULL)) {
		if (contexto1[i] != contexto2[i]) return false;
		i++;
	}
	return true;
}


bool HandlerContext::addContToDist(int contexto) {
	int* counter = new int[256];
	for (int i = 0; i <= 255; i++) {
		counter[i] = 0;
	}
	bool res = this->distribution.insert({contexto, counter}).second;
	return res;
}


bool HandlerContext::add(int contexto) {
	bool existe = false;
	int element;
	list<int>::iterator i = this->contextos.begin();
	//porque no usar "find" que implementa stl?
	while (!existe && i != this->contextos.end()){ //aca seria while para cortar antes
		element = *i;
		if (contexto == element) { 
			existe = true; 
		}
		i++;
	}
	if (!existe) {
		this->contextos.push_front(contexto);
		this->addContToDist(contexto);
		return true;
	}
	return false;
}


void HandlerContext::sum1(int contexto, int value_pixel) {
	this->distribution[contexto][value_pixel] = this->distribution[contexto][value_pixel] + 1;
}

int HandlerContext::predict(int pixel, int extracto, float delta) {
	//cout << pixel << "  " << extracto << "  " << endl;
	float ocurrencias = 0;
	for(int i = 0; i < 256; i++){
		ocurrencias += (float)this->distribution[extracto][i];
	}

	float pz = (float)this->distribution[extracto][pixel] / ocurrencias;// calculo de pz
	
	float Ez = 0;//caluclo Ez
	for(int i = 0; i < 256; i++){
		Ez += ((float)this->distribution[extracto][i]/ocurrencias) * (float)i;
	}
	cout << pz << "  " << Ez << endl;
	float aux1 = (1 - (delta / (255 * pz))) * pixel;
	float aux2 = delta / (((1 - delta) * (256) - 1) * pz);
	float aux3 = Ez - ((delta * 256) / 2);
	int epsilon = round(aux1 + (aux2 * aux3));
	return epsilon;
}