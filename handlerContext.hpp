#ifndef HANDLERCONTEXT_H
#define HANDLERCONTEXT_H

#include <list> 
#include <map> 

using namespace std;

class HandlerContext {
private:
	HandlerContext();
	static HandlerContext* instance;
	list<int> contextos;
	map<int, int*> distribution;

	map<int, int> ocurrencias; // cantidad de ocurrencias segun el extracto

	
public:
	//setters
	bool add(int contexto);
	bool addContToDist(int contexto);
	void sum1(int contexto, int value_pixel);

	
	//getters
	static HandlerContext* getInstance();
	list<int> getContextos();
	bool isequal(int* contexto1, int* contexto2);
	map<int, int*> getDist();
	void remove() {}; //por ahora no se cuando eliminar�a un contexto

	int predict(int pixel, int extracto, double delta);

};


#endif