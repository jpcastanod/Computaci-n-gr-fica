#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		ofxPanel gui;
		ofxButton button;
		ofxButton button2;
		ofxButton button3;
		ofxIntSlider t;
		BOOLEAN dibujando = false;
		float matriz[20][2];
		int contador = -1;
		float division;
		int combinatoria(int i);
		int factorial(int n);
		void bezi();
		void setup();
		void update();
		void draw();
		void buttonPressed();
		void button2Pressed();
		void button3Pressed();
		void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
