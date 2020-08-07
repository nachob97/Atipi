#ifndef HANDLERCONTEXT_H
#define HANDLERCONTEXT_H

#include <list> 
#include <map> 

using namespace std;

class HandlerContext {
private:
	HandlerContext();
	static HandlerContext* instance;
	list<int*> contextos;
	map<int*, int[256]> tabla;
public:
	static HandlerContext* getInstance();
	bool add(int* contexto);
	list<int*> getContextos();
	bool isequal(int* contexto1, int* contexto2);
	void remove() {}; //por ahora no se cuando eliminaría un contexto

};


#endif