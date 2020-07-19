#ifndef CONTEXT_H
#define CONTEXT_H

#include <list>
using namespace std;

class Context{
private:
	int** contexto;
	int out = 128;
	int* extracto;
public:
	Context(int** img, int pixel_x, int pixel_y,int k);
	int** getContexto();
	int* getExtracto();
	~Context();
};

#endif