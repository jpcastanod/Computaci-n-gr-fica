#include "ofApp.h"
#include "iostream"
#include "math.h"

using namespace std;
//--------------------------------------------------------------
void ofApp::setup() {


	webCam.setup(320, 240);

	ofSetVerticalSync(true);
	camar.setDistance(800);
	button.addListener(this, &ofApp::buttonPressed);
	button2.addListener(this, &ofApp::button2Pressed);
	button3.addListener(this, &ofApp::button3Pressed);
	button4.addListener(this, &ofApp::button4Pressed);
	actCam.addListener(this, &ofApp::actCamPressed);
	desCam.addListener(this, &ofApp::desCamPressed);
	menu.addListener(this, &ofApp::menuPressed);
	ofBackground(0, 0, 0, 0);
	gui.setup();
	gui.add(button.setup("Dibujar caja"));
	gui.add(button2.setup("Dibujar cono"));
	gui.add(button3.setup("Dibujar cilindro"));
	gui.add(button4.setup("Resetear"));
	gui.add(actCam.setup("Camara On"));
	gui.add(desCam.setup("Camara off"));
	gui2.setup();
	gui2.setPosition(700, 0);
	gui2.add(cx.setup("x o radio", 5, 5, 300));
	gui2.add(cy.setup("y o altura", 5, 5, 300));
	gui2.add(cz.setup("z", 5, 5, 300));
	gui3.setup();
	gui3.setPosition(0, 600);
	gui3.add(menu.setup("Cambiar menu"));
}

//--------------------------------------------------------------
void ofApp::update() {
	webCam.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (men) {
		ofSetColor(0, 0, 0);
		webCam.draw(ofGetWidth() / 2, ofGetHeight() / 2);
		gui3.draw();
	}
	else {
		if (doNothing) {
			box2.set(0, 0, 0);
			box.set(0, 0, 0);
			cone.set(0, 0);
			cylinder.set(0, 0);
		}


		if (cam) {
			light.setSpotlight();
			light.setSpotlightCutOff(50);

			light.setDiffuseColor(ofColor::white);

			light.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 500);
			light.lookAt(box.getPosition());
			light.enable();
			camar.begin();

		}


		ofSetColor(255, 0, 0);
		ofPushMatrix();

		ofTranslate(matriz[0][0], matriz[0][1]);
		box.draw();

		ofPopMatrix();
		ofSetColor(0, 255, 0);
		ofPushMatrix();
		ofTranslate(matriz[1][0], matriz[1][1]);
		cone.draw();
		ofPopMatrix();
		ofSetColor(0, 0, 255);
		ofPushMatrix();
		ofTranslate(matriz[2][0], matriz[2][1]);
		cylinder.draw();
		ofPopMatrix();
		if (cam) {
			camar.end();
		}

		gui.draw();
		gui2.draw();
		gui3.draw();
		light.disable();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	if (cam) {

		}
	else {
		if (boxD) {
			box.set(cx, cy, cz);
			matriz[0][0] = x;
			matriz[0][1] = y;
		}
		else if (conD) {
			cone.set(cx, cy);
			matriz[1][0] = x;
			matriz[1][1] = y;
		}
		else if (cylD) {
			cylinder.set(cx, cy);
			matriz[2][0] = x;
			matriz[2][1] = y;

		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::buttonPressed() {
	boxD = true;
	conD = false;
	cylD = false;
	doNothing = false;
}

void ofApp::button2Pressed() {
	boxD = false;
	conD = true;
	cylD = false;
	doNothing = false;

}
void ofApp::button3Pressed() {
	boxD = false;
	conD = false;
	cylD = true;
	doNothing = false;

}
void ofApp::exit() {
	button.removeListener(this, &ofApp::buttonPressed);
	button2.removeListener(this, &ofApp::button2Pressed);
	button3.removeListener(this, &ofApp::button3Pressed);
	button4.removeListener(this, &ofApp::button4Pressed);
}

void ofApp::button4Pressed() {
	boxD = false;
	conD = false;
	cylD = false;
	doNothing = true;
}
void ofApp::actCamPressed() {
	cam = true;
}
void ofApp::desCamPressed() {
	cam = false;
}
void ofApp::menuPressed() {
	men = !men;
}