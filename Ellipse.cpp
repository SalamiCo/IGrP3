//Samuel M�ndez Gal�n
//Pedro Morgado Alarc�n

#include "Ellipse.h"
 

Ellipse::Ellipse(){
	circle = Circle();
} 

void Ellipse::drawEllipse(){
	circle.drawCircle();
}

bool Ellipse::intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn){
	//Transformaciones y llamar al de Circle
	return circle.intersection2Ball(p,v,tIn,normalIn);
}