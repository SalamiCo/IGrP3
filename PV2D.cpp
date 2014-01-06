//Samuel Mendez Galán
//Pedro Morgado Alarcón

#include "PV2D.h"

PV2D::PV2D(){
	this->x = 0;
	this->y = 0;
	this->h = 1;
}

PV2D::PV2D(GLdouble x, GLdouble y, GLdouble h){
	this->x = x;
	this->y = y;
	this->h = h;
}

GLdouble PV2D::getX(){
	return this->x;
}

GLdouble PV2D::getY(){
	return this->y;
}

GLdouble PV2D::getH(){
	return this->h;
}

void PV2D::setX(GLdouble x){
	this->x = x;
}

void PV2D::setY(GLdouble y){
	this->y = y;
}

void PV2D::setH(GLdouble h){
	this->h = h;
}

GLdouble PV2D::vectorModule(){
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2));
}

PV2D PV2D::normalizeVector(){
	// Same direction but module = 1
	PV2D newV;
	GLdouble module = this->vectorModule();

	newV.setX((1 / module) * this->getX());
	newV.setY((1 / module) * this->getY());
	newV.setH(0);

	return newV;
}

GLdouble PV2D::dot(PV2D w){
	return (this->getX() * w.getX()) + (this->getY() * w.getY());
}

PV2D PV2D::normalVector(){
	// Perpendicular vector to v with same module as v. Result by turning v to the left.
	PV2D normal;

	normal.setX(-this->getY());
	normal.setY(this->getX());
	normal.setH(0);

	return normal;
}

std::vector<GLdouble> PV2D::vectorDecomposition(PV2D v, PV2D n){
	GLdouble a, b;
	std::vector<GLdouble> numbers;

	a = v.dot(n) / n.dot(n);
	numbers.push_back(a);
	b = v.dot(n.normalVector()) / n.normalVector().dot(n.normalVector());
	numbers.push_back(b);

	return numbers;
}