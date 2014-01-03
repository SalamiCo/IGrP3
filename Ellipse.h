//Samuel Méndez Galán
//Pedro Morgado Alarcón

#ifndef ELLIPSEH
#define ELLIPSEH

#include "Circle.h" 

class Ellipse : public Obstacle {
	private:
		Circle circle;
	public:
		Ellipse();
		void drawEllipse();

		virtual bool intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn);
};
#endif
 