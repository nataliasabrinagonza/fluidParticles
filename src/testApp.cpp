#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//ofSetVerticalSync(true);

    blendMode = OF_BLENDMODE_ADD;
	int num = 400;
	p.assign(num, Particulas());

    for(int i = 0; i < p.size(); i++){
		p[i].reset();
		blanco.loadImage("blanco.png");
		color.loadImage("color.png");
	}
}

//--------------------------------------------------------------
void testApp::resetParticles(){

	for(int i = 0; i < p.size(); i++){
		p[i].reset();
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0; i < p.size(); i++){
		p[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

    ofSetColor(230);
    ofDrawBitmapString("Natalia Sabrina Gonza", ofGetWidth() - 180 , ofGetHeight() - 10);

	for(int i = 0; i < p.size(); i++){
		p[i].draw(&color);
	}

	//ofSetColor(230);
	//ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-4 to change mode.", 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){


	if( key == ' ' ){
		resetParticles();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
