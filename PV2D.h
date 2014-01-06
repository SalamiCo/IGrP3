//Samuel Mendez Galán
//Pedro Morgado Alarcón

#ifndef PV2DH
#define PV2DH

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <vector>

class PV2D{
    private:
    	GLdouble x;
    	GLdouble y;
        GLdouble h;
    public:
        PV2D();
        PV2D(GLdouble x, GLdouble y, GLdouble h);
        GLdouble getX();
        GLdouble getY();
        GLdouble getH();
        void setX(GLdouble x);
        void setY(GLdouble y);
        void setH(GLdouble h);
        GLdouble vectorModule();
        PV2D normalizeVector();
        GLdouble dot(PV2D w);
        PV2D normalVector();
        std::vector<GLdouble> vectorDecomposition(PV2D v, PV2D n);
};

#endif