#include "handlerContext.hpp"
#include <iterator>
//#include <utility>

using namespace std;

HandlerContext::HandlerContext() {}

HandlerContext* HandlerContext::instance = NULL;

HandlerContext* HandlerContext::getInstance() {
	if (instance == NULL)
		instance = new HandlerContext();
	return (instance);
}

list<int*> HandlerContext::getContextos() {
	return (this->contextos);
}

map<int*, int*> HandlerContext::getDist() {
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


bool HandlerContext::addContToDist(int* contexto) {
	int* counter = new int[256];
	for (int i = 0; i <= 255; i++) {
		counter[i] = 0;
	}
	bool res = this->distribution.insert(pair <int*, int*>((contexto, counter), 0)).second;
	return res;
}


bool HandlerContext::add(int* contexto) {
	bool existe = false;
	int* element;
	list<int*>::iterator i = this->contextos.begin();
	while (!existe && i != this->contextos.end()){ //aca seria while para cortar antes
		element = *i;
		if (this->isequal(contexto, element)) { 
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
