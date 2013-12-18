//Samuel Mendez Galán
//Pedro Morgado Alarcón

#include "Ball.h"

Ball::Ball(){
	// To calculate the edge size using radius => edge = 2 * radius * sin(0.157079)
	Pencil pen;
	GLfloat centerX=0, centerY=0;
	// Center
	center = PV2D(centerX, centerY, 1);
	// Radius
	radius = 20;
	numSides = 20;
	GLfloat edge = 2 * radius * sin(0.157079);

	PV2D p1 = PV2D(centerX+edge/2, centerY-radius, 1);

	// Generate the ball
	vertex.push_back(p1);
	pen.setPos(p1);
	pen.setDir(0.31415);
	pen.forward(edge);

	for(int i=1; i<numSides; i++){
		PV2D p = pen.getPos();
		vertex.push_back(p);

		pen.turn(0.31415);
		pen.forward(edge);
	}

	// Movement vector
	int randomX, randomY;
	do{
		// initialize random seed
	  	srand (time(NULL));
	  	// Random number between -4 and 4 (creo...)
		randomX = rand() % 4 - 3;
		randomY = rand() % 4 - 3;
	} while (randomX == 0 && randomY == 0);
	vectorMov.setX((GLfloat) randomX);
	vectorMov.setY((GLfloat) randomY);
	vectorMov.setH(0);
	//vectorMov.setVectorX(-2);
	//vectorMov.setVectorY(-2);
}

PV2D Ball::getCenter(){
	return this->center;
}

PV2D Ball::getV(){
	return this->vectorMov;
}

void Ball::drawBall(){
	std::vector<PV2D>::iterator it;
	it = vertex.begin();

	glBegin(GL_POLYGON);
	for (int i=1; i<=numSides; ++i, ++it){
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(it->getX(), it->getY());
	}
	glVertex2f(center.getX(), center.getY());	
	glEnd();
}

void Ball::step(double t){
	std::vector<PV2D>::iterator it;
	it = vertex.begin();

	for(int i=1;i<=numSides; ++i, ++it){
		it->setX(it->getX() + t * vectorMov.getX());
		it->setY(it->getY() + t * vectorMov.getY());
		it->setH(1);
	}
	center.setX(center.getX() + t * vectorMov.getX());
	center.setY(center.getY() + t * vectorMov.getY());
	center.setH(1);
}

void Ball::rebound(PV2D normal){
	//r = v - 2an
	std::vector<GLfloat> ab = vectorMov.vectorDecomposition(vectorMov,normal);

	vectorMov.setX(vectorMov.getX() - 2 * ab.at(0) * normal.getX());
	vectorMov.setY(vectorMov.getY() - 2 * ab.at(0) * normal.getY());
	vectorMov.setH(0);
}