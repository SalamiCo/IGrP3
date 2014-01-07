//Samuel Méndez Galán
//Pedro Morgado Alarcón
 
#ifndef MATRH
#define MATRH

#include "PV2D.h"

#define WIDTH 3
#define HEIGHT 3

class Matr {
	private:
		float data [WIDTH][HEIGHT];
		float getData(int i);
	public:
		Matr();
		Matr(float data[WIDTH][HEIGHT]);
		Matr prodMatr(Matr m2);
		PV2D prodVect(PV2D vect);
		Matr static getScaleMatr(float fx, float fy);
		Matr static getTranslateMatr(float tx, float ty);
		Matr getTrasposedMatr();

};

#endif