#ifndef PARTICULAS_H
#define PARTICULAS_H

#pragma once
#include "ofMain.h"


class Particulas
{
    public:
        Particulas();

		void reset();
		void update();
		void draw();

		ofPoint pos;
		ofPoint vel;
		ofPoint frc;

		float drag;
		float uniqueVal;
		float scale;

		Particulas mode;

};

#endif // PARTICULAS_H
