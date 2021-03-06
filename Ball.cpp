//Samuel Mendez Galán
//Pedro Morgado Alarcón

#include "Ball.h"

Ball::Ball(){
	// To calculate the edge size using radius => edge = 2 * radius * sin(0.157079)
	Pencil pen;
	GLdouble centerX=0, centerY=0;
	// Center
	center = PV2D(centerX, centerY, 1);
	// Radius
	radius = 1;
	numSides = 20;
	GLdouble edge = 2 * radius * sin(0.157079);

	PV2D p1 = PV2D(centerX+edge/2, centerY-radius, 1);

	// Angle
	angle = 0.0;

	// Dir
	dir = 0;

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
	} while (randomX == 0 || randomY == 0);
	vectorMov.setX((GLdouble) randomX);
	vectorMov.setY((GLdouble) randomY);
	vectorMov.setH(0);
	//vectorMov.setX(1);
	//vectorMov.setY(-2);
}

PV2D Ball::getCenter(){
	return this->center;
}

PV2D Ball::getV(){
	return this->vectorMov;
}

int Ball::getDir(){
	return this->dir;
}

void Ball::setDir(int dir){
	this->dir = dir;
}

void Ball::drawBall(){
	std::vector<PV2D>::iterator it;
	it = vertex.begin();

	glPushMatrix();
	glTranslatef(center.getX(), center.getY(), 0);
    glScalef(15.0, 15.0, 1.0);
    glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	for (int i=1; i<=numSides; ++i, ++it){
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(it->getX(), it->getY());
	}
	glEnd();
	//The line for movement. From center to right edge
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	//glVertex2f(center.getX(), center.getY());
	//glVertex2f(center.getX()+radius, center.getY());
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glEnd();

	glPopMatrix();
}

void Ball::step(double t){
	//std::vector<PV2D>::iterator it;
	//it = vertex.begin();

	/*for(int i=1;i<=numSides; ++i, ++it){
		it->setX(it->getX() + t * vectorMov.getX());
		it->setY(it->getY() + t * vectorMov.getY());
		it->setH(1);
	}*/

	//Set center
	center.setX(center.getX() + t * vectorMov.getX());
	center.setY(center.getY() + t * vectorMov.getY());
	center.setH(1);

	//Set angle
	if(dir == 0){
		angle += 1;
	} else {
		angle -= 1;
	}
	
}

void Ball::rebound(PV2D normal){
	//r = v - 2an
	std::vector<GLdouble> ab = vectorMov.vectorDecomposition(vectorMov,normal);

	vectorMov.setX(vectorMov.getX() - 2 * ab.at(0) * normal.getX());
	vectorMov.setY(vectorMov.getY() - 2 * ab.at(0) * normal.getY());
	vectorMov.setH(0);
}