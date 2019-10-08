#include "ofApp.h"
#include "iostream"
#include "math.h"

using namespace std;
//--------------------------------------------------------------
void ofApp::setup() {


	button.addListener(this, &ofApp::buttonPressed);
	button2.addListener(this, &ofApp::button2Pressed);
	button3.addListener(this, &ofApp::button3Pressed);
	button4.addListener(this, &ofApp::button4Pressed);
	ofBackground(0, 0, 0, 0);
	gui.setup();
	gui.add(button.setup("empezar a poner puntos"));
	gui.add(button2.setup("dibujar curva"));
	gui.add(button3.setup("resetear"));
	gui.add(button4.setup("pasos"));

	gui2.setup();
	gui2.setPosition(700, 0);
	gui2.add(x.setup("x", 1, 5, 20));
	gui2.add(y.setup("y", 1, 5, 20));
	gui2.add(z.setup("z", 1, 5, 20));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	
	box.set(x, y, z);
	ofSetColor(255, 0, 0);
	ofPushMatrix();
		
		ofTranslate(matriz[steps][0], matriz[steps][1]);
		box.draw();
	ofPopMatrix();
	if (!dibujando) {
		int i = 0;

		ofSetColor(0, 0, 255);
		while (i < contador) {

			ofDrawLine(matriz[i][0], matriz[i][1], matriz[i + 1][0], matriz[i + 1][1]);
			ofDrawSphere(matriz2[i][0], matriz2[i][1], 3, 10);
			i++;
		}
		ofDrawSphere(matriz2[i][0], matriz2[i][1], 3, 10);


		
	}


	else {

		int cont = 0;


		while (cont <= contador) {

			ofDrawSphere(matriz[cont][0], matriz[cont][1], 3, 10);
			cont++;
		}

	}
	
	gui.draw();
	gui2.draw();
	

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
	if (dibujando) {
		contador = contador + 1;
		matriz[contador][0] = x;
		matriz[contador][1] = y;

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
	dibujando = true;

}

void ofApp::button2Pressed() {
	division = 1.0 / (contador);
	copiaMatriz();
	bezi();
	dibujando = false;

}
void ofApp::button3Pressed() {
	int j = 0;
	int k = 0;
	steps = 0;
	contador = -1;
	while (j < 100) {
		while (k < 2) {
			matriz[k][j] = 0;
			k++;
		}
		j++;
	}
	dibujando = true;

}
void ofApp::exit() {
	button.removeListener(this, &ofApp::buttonPressed);
	button2.removeListener(this, &ofApp::button2Pressed);
	button3.removeListener(this, &ofApp::button3Pressed);
	button4.removeListener(this, &ofApp::button4Pressed);
}

void ofApp::bezi() {

	float tfinal = 0.0;
	float potencia = 0.0;
	int i = 0;
	while (i < contador) {
		cout << matriz[i][0];
		cout << "\n";
		cout << matriz[i][1];
		cout << "\n";
		potencia = pow(1 - tfinal, contador - i);
		matriz[i][0] = combinatoria(i) * (matriz[i][0] * potencia) * pow(tfinal, i);
		matriz[i][1] = combinatoria(i) * (matriz[i][1] * potencia) * pow(tfinal, i);
		cout << matriz[i][0];
		cout << "\n";
		cout << matriz[i][1];
		cout << "\n";
		i++;
		cout << "cuota: ";
		cout << tfinal;
		cout << "\n";
		tfinal = tfinal + division;
	}
}
int ofApp::combinatoria(int i) {

	return (factorial(contador)) / (factorial(i) * factorial(contador - i));
}

int ofApp::factorial(int n) {
	if (n < 0) return 0;
	else if (n > 1) return n * factorial(n - 1);
	return 1;

}
void ofApp::copiaMatriz() {
	int i = 0;
	int j = 0;
	while (i < 100) {
		while (j < 2) {
			matriz2[i][j] = matriz[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
void ofApp::button4Pressed() {
	steps++;
}