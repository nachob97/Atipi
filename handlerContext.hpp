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
	map<int*, int*> distribution;

	
public:
	//setters
	bool add(int* contexto);
	bool addContToDist(int* contexto);

	
	//getters
	static HandlerContext* getInstance();
	list<int*> getContextos();
	bool isequal(int* contexto1, int* contexto2);
	map<int*, int*> getDist();
	void remove() {}; //por ahora no se cuando eliminaría un contexto

};


#endif