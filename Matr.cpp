//Samuel Méndez Galán
//Pedro Morgado Alarcón
#include "Matr.h"

Matr::Matr(){
	// Identity  Matrix
	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			if(i==j){
				data[i][j] = 1.0;
			} else{
				data[i][j] = 0.0;	
			} 
		}
	}
}

Matr Matr::prodMatr(Matr m2){
	Matr m3;

	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			m3.data[i][j]= 0.0;
			for(int k=0; k<WIDTH; k++){
				m3.data[i][j] += this->data[i][k] * m2.data[k][j];
			}
		}
	}

	return m3;
} 

PV2D Matr::prodVect(PV2D vect){
	float vectArray[3] = {vect.getX(), vect.getY(), vect.getH()};
	float vectResult[3];

	for(int i=0; i<WIDTH; i++){
		vectResult[i] = 0.0;
		for (int k=0; k<WIDTH; k++){
			vectResult[i] += this->data[i][k] * vectArray[k];
		}
	} 

	return PV2D(vectResult[0], vectResult[1], vectResult[2]);
}
 