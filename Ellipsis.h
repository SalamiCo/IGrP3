//Samuel Méndez Galán
//Pedro Morgado Alarcón

#ifndef EllipsisH
#define EllipsisH

#include "Circle.h" 

class Ellipsis : public Obstacle {
	private:
		Circle circle;
	public:
		Ellipsis();
		void drawEllipsis();

		virtual bool intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn);
};
#endif
 