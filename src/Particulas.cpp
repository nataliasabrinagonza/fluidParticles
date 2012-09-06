#include "Particulas.h"


//------------------------------------------------------------------
Particulas::Particulas(){
	attractPoints = NULL;
	hCycle  = 200;
}

//------------------------------------------------------------------
void Particulas::reset(){
	//the unique val allows us to set properties slightly differently for each particle
	uniqueVal = ofRandom(-10000, 10000);

	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();

	vel.x = ofRandom(-3.9, 3.9);
	vel.y = ofRandom(-3.9, 3.9);

	frc   = ofPoint(0,0,0);

	scale = ofRandom(0.5, 1.0);
	//drag  = 0.1;
    drag  = ofRandom(0.1, 0.5);
}

//------------------------------------------------------------------
void Particulas::update(){

		ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
		frc = attractPt-pos;

		//let get the distance and only repel points close to the mouse
		float dist = frc.length();
		frc.normalize();

		vel *= drag;
		if( dist < 100 ){
			vel += -frc * 0.6; //notice the frc is negative
		}else{
			//if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
			frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
			frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
			vel += frc * 0.04;
		}

	//2 - UPDATE OUR POSITION

	pos += vel;

	if( pos.x > ofGetWidth() ){
		pos.x = ofGetWidth();
		vel.x *= -1.0;
	}else if( pos.x < 0 ){
		pos.x = 0;
		vel.x *= -1.0;
	}
	if( pos.y > ofGetHeight() ){
		pos.y = ofGetHeight();
		vel.y *= -1.0;
	}
	else if( pos.y < 0 ){
		pos.y = 0;
		vel.y *= -1.0;
	}

}

//------------------------------------------------------------------
void Particulas::draw(ofImage* _imagen){


	if (hCycle < 255) hCycle += 0.03;
	else hCycle = 0;

	color.setHue(hCycle);
	color.setHsb(hCycle, 255, 255);

    ofSetColor(color);
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
	_imagen->draw( pos.x, pos.y, scale * 80, scale * 80);
	ofDisableBlendMode();
	ofPopStyle();
}

