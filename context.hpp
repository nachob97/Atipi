#ifndef CONTEXT_H
#define CONTEXT_H

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
	int promedio();
	void setExtracto(int k);
	~Context();
};

#endif