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

Matr::Matr(float data[WIDTH][HEIGHT]){
	for(int i=0; i<WIDTH; i++){
		for(int j=0; j<HEIGHT; j++){
			this->data[i][j] = data[i][j];
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

Matr Matr::getScaleMatr(float fx, float fy){
	float data[3][3] = {fx, 0.0, 0.0, 
						0.0, fy, 0.0, 
						0.0, 0.0, 1.0};
	return Matr(data);
}

Matr Matr::getTranslateMatr(float tx, float ty){
	float data[3][3] = {1.0, 0.0, tx,
						0.0, 1.0, ty, 
						0.0, 0.0, 1.0};
	return Matr(data);
}

Matr Matr::getTrasposedMatr(){
	Matr result;
	for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            result.data[j][i] = this->data[i][j];
        }
    }
    return result;
}
 