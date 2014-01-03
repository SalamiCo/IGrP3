//Samuel Méndez Galán
//Pedro Morgado Alarcón

#include "Ellipsis.h"
 

Ellipsis::Ellipsis(){
	circle = Circle();
} 

void Ellipsis::drawEllipsis(){
	circle.drawCircle();
}

bool Ellipsis::intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn){
	//Transformaciones y llamar al de Circle
	//this es la elipse que hay que transformar en un circulo con radio 1 en el centro
	
	return circle.intersection2Ball(p,v,tIn,normalIn);
}