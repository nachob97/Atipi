#ifndef read_H
#define read_H
#include <sstream>
#include <stdio.h>
#include <errno.h>
#include "context.hpp"
#include <string>


int** readFile(string path, int cols, int rows, int range);
void readHead(string path, int& cols, int& rows, int& range);
void createImage(int** image, int cols, int rows);

#endif