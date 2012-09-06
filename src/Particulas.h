#ifndef PARTICULAS_H
#define PARTICULAS_H

#pragma once
#include "ofMain.h"

class Particulas
{
    public:
        Particulas();
		void setAttractPoints( vector <ofPoint> * attract );

		void reset();
		void update();
		void draw(ofImage* burbuja);

		ofPoint pos;
		ofPoint vel;
		ofPoint frc;
		ofColor color;

		float drag;
		float uniqueVal;
		float scale;
		float hCycle;

		vector <ofPoint> * attractPoints;

};

#endif // PARTICULAS_H
