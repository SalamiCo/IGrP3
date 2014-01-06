//Samuel Méndez Galán
//Pedro Morgado Alarcón

#ifndef EllipsisH
#define EllipsisH

#include "Circle.h" 
#include "Matr.h"

class Ellipsis : public Obstacle {
	private:
		Circle circle;
		float tx, ty, fx, fy;
	public:
		Ellipsis(float tx, float ty, float fx, float fy); // t->translate f->scale
		void drawEllipsis(); 

		virtual bool intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn);
};
#endif
 