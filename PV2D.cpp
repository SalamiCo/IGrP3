//Samuel Mendez Galán
//Pedro Morgado Alarcón

#include "PV2D.h"

PV2D::PV2D(){
	this->x = 0;
	this->y = 0;
	this->h = 1;
}

PV2D::PV2D(GLfloat x, GLfloat y, GLfloat h){
	this->x = x;
	this->y = y;
	this->h = h;
}

GLfloat PV2D::getX(){
	return this->x;
}

GLfloat PV2D::getY(){
	return this->y;
}

GLfloat PV2D::getH(){
	return this->h;
}

void PV2D::setX(GLfloat x){
	this->x = x;
}

void PV2D::setY(GLfloat y){
	this->y = y;
}

void PV2D::setH(GLfloat h){
	this->h = h;
}

GLfloat PV2D::vectorModule(){
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2));
}

PV2D PV2D::normalizeVector(){
	// Same direction but module = 1
	PV2D newV;
	GLfloat module = this->vectorModule();

	newV.setX((1 / module) * this->getX());
	newV.setY((1 / module) * this->getY());
	newV.setH(0);

	return newV;
}

GLfloat PV2D::dot(PV2D w){
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

std::vector<GLfloat> PV2D::vectorDecomposition(PV2D v, PV2D n){
	GLfloat a, b;
	std::vector<GLfloat> numbers;

	a = v.dot(n) / n.dot(n);
	numbers.push_back(a);
	b = v.dot(n.normalVector()) / n.normalVector().dot(n.normalVector());
	numbers.push_back(b);

	return numbers;
}