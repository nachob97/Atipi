#ifndef CONTEXT_H
#define CONTEXT_H
#include <bitset>


using namespace std;

class Context{
private:
	int** contexto;
	int out = 128;
	bitset<12> extracto;
public:
	Context(int** img, int pixel_x, int pixel_y,int k);
	int** getContexto();
	bitset<12> getExtracto();
	int promedio();
	void setExtracto(int k);
	~Context();
};

#endif