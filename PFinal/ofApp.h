#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	ofVideoGrabber webCam;
	ofLight light;
	ofEasyCam camar;
	ofxPanel gui;
	ofxPanel gui2;
	ofxPanel gui3;
	ofxButton button;
	ofxButton button2;
	ofxButton button3;
	ofxButton button4;
	ofxButton actCam;
	ofxButton desCam;
	ofxButton menu;
	ofxFloatSlider cx;
	ofxFloatSlider cy;
	ofxFloatSlider cz;
	ofBoxPrimitive box;
	ofBoxPrimitive box2;
	ofConePrimitive cone;
	ofCylinderPrimitive cylinder;
	BOOLEAN boxD = false;
	BOOLEAN conD = false;
	BOOLEAN cylD = false;
	BOOLEAN doNothing = true;
	BOOLEAN cam = false;
	BOOLEAN men = false;
	int matriz[3][2];
	int posX;
	int posY;
	float division;
	void setup();
	void update();
	void draw();
	void buttonPressed();
	void button2Pressed();
	void button3Pressed();
	void button4Pressed();
	void actCamPressed();
	void desCamPressed();
	void menuPressed();

	void exit();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

};