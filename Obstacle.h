//Samuel M�ndez Gal�n
//Pedro Morgado Alarc�n

#ifndef OBSTACLEH
#define OBSTACLEH

#include "PV2D.h"

class Obstacle{
	public:
		virtual ~Obstacle(){}
		virtual bool intersection2Ball(PV2D p, PV2D v, double& tIn, PV2D& normalIn) = 0;
};

#endif 