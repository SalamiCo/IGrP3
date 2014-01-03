//Samuel Méndez Galán
//Pedro Morgado Alarcón
 
#ifndef MATRH
#define MATRH

#include <array>
#define WIDTH 3
#define HEIGHT 3

class Matr {
	private:
		float data [WIDTH][HEIGHT];
	public:
		Matr();
		Matr prodMatr(Matr m2);
		PV2D prodVect(PV2D vect);

};

#endif