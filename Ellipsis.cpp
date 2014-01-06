//Samuel Méndez Galán
//Pedro Morgado Alarcón

#include "Ellipsis.h"
 

Ellipsis::Ellipsis(float tx, float ty, float fx, float fy){
	circle = Circle();
	this->tx = tx;
	this->ty = ty;
	this->fx = fx;
	this->fy = fy;
} 

void Ellipsis::drawEllipsis(){
	glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(fx, fy, 1.0);
	circle.drawCircle();

    glPopMatrix();
}

bool Ellipsis::intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn){
	//Transformaciones y llamar al de Circle
	//this es la elipse que hay que transformar en un circulo con radio 1 en el centro
	Matr scale = Matr::getScaleMatr(1/fx, 1/fy);
	Matr translate = Matr::getTranslateMatr(tx, ty);

	PV2D pos = (scale.prodMatr(translate)).prodVect(p);
	PV2D vel = scale.prodVect(v);

	return circle.intersection2Ball(pos,vel,tIn,normalIn);
}