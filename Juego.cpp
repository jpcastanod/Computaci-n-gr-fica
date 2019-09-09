#include <SFML/Graphics.hpp>
/*Libreria usada solo en Windows - debe ir antes que las demás librerias*/
#include<windows.h>
/*Libreria del OpenGL*/
#include <stdlib.h>
#include <time.h>
//#include<GL/glut.h>
#include <iostream>
using namespace sf;
using namespace std;
int aleatorio();
void drawline(int, int, int, int);
boolean clippingArea(Vector2f), murioPorSoles(Vector2f, Vector2f, Vector2f, Vector2f);


int vidas;
boolean var = false;
Image image;

void translacion(Vector2f speed, VertexArray &vertex) {
	for (int i = 0; i < vertex.getVertexCount(); i++) {
		vertex[i].position += speed;

	}

}
void rotacion(float angle, VertexArray &vertex) {
	float radianes = angle * (float)3.416f / 180.0f;
	for (int i = 0; i < vertex.getVertexCount(); i++) {
		vertex[i].position.x = vertex[i].position.x* cos(radianes) - vertex[i].position.y*sin(radianes);
		vertex[i].position.y = vertex[i].position.x* sin(radianes) + vertex[i].position.y*cos(radianes);;

	}
}

int main(int argc, char** argv)

{
	VertexArray triangle(sf::Triangles, 3);
	triangle[0].position = sf::Vector2f(100.f, 100.f);
	triangle[1].position = sf::Vector2f(70.f, 130.f);
	triangle[2].position = sf::Vector2f(130.f, 130.f);
	VertexArray triangle2(sf::Triangles, 3);
	triangle2[0].position = sf::Vector2f(100.f, 160.f);
	triangle2[1].position = sf::Vector2f(70.f, 190.f);
	triangle2[2].position = sf::Vector2f(130.f, 190.f);
	VertexArray triangle3(sf::Triangles, 3);
	triangle3[0].position = sf::Vector2f(100.f, 220.f);
	triangle3[1].position = sf::Vector2f(70.f, 250.f);
	triangle3[2].position = sf::Vector2f(130.f, 250.f);
	String tiempoActual = "0";
	boolean pierde = false;
	vidas = 3;
	VideoMode vm = VideoMode::getDesktopMode();
	RenderWindow pantalla(vm, "Juego", Style::Default);
	pantalla.setFramerateLimit(60);
	Color blackPixel(255, 255, 0, 255);
	image.create(vm.width, vm.height, Color::Black);
	drawline(100, 200, 700, 200);
	drawline(100, 1100, 700, 1100);
	Texture  texture, texture2, sol1, sol2, sol3;
	Font font;
	Clock clock;
	texture.loadFromImage(image);
	font.loadFromFile("Assets/SFTransRobotics.ttf");
	texture2.loadFromFile("Assets/ice-cube-309205_960_720.png");
	sol1.loadFromFile("Assets/pngocean.com-id-zwgtn.png");
	sol2.loadFromFile("Assets/pngocean.com-id-zwgtn.png");
	sol3.loadFromFile("Assets/pngocean.com-id-zwgtn.png");
	Sprite spSol1(sol1);
	Sprite spSol2(sol2);
	Sprite spSol3(sol3);
	Sprite sprite(texture);
	Sprite sprite2(texture2);
	Vector2f velocidadSoles(0, 3);
	Vector2f poSol1(aleatorio(), 100);
	Vector2f poSol2(300, 100);
	Vector2f poSol3(800, 100);
	Vector2f posicion(580, 550);
	Vector2f velocidad(5, 0);
	Vector2f cambio(0, 1);
	Vector2f copiaposicion = posicion;
	Vector2f speed(0.0f, 5.0f);
	sprite2.scale(0.2f, 0.2f);
	spSol1.scale(0.01f, 0.01f);
	spSol2.scale(0.01f, 0.01f);
	spSol3.scale(0.01f, 0.01f);
	sprite2.setPosition(posicion);

	Text text("vidas: " + std::to_string(vidas)+ "  Tiempo: ", font, 50);
	Text tiempo;
	tiempo.setCharacterSize(50);
	tiempo.setFont(font);
	tiempo.setPosition(500, 10);
	text.setPosition(10, 10);
	
	while (pantalla.isOpen()) {	
		rotacion(0.5, triangle);
		rotacion(0.25, triangle2);
		rotacion(0.125, triangle3);
		translacion(velocidadSoles, triangle);
		translacion(velocidadSoles, triangle2);
		translacion(velocidadSoles, triangle3);
		if (clippingArea(posicion) or murioPorSoles(poSol1, poSol2, poSol3, posicion)) {
			vidas = vidas - 1;
			posicion = copiaposicion;
			poSol1.x = aleatorio();
			poSol2.x = 300;
			poSol3.x = 800;
			poSol1.y = 100;
			poSol2.y = 100;
			poSol3.y = 100;
			
		}
		if (vidas <= 0) {
			Text textFinal("Has perdido, tu tiempo fue: " + tiempoActual + " Presionar espacio para jugar de nuevo o escape para salir", font, 20);
			textFinal.setPosition(100, 450);
			pantalla.clear();
			pantalla.draw(textFinal);
			pantalla.display();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				pantalla.close();
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				main(argc, argv);
				
			}
		}
		else {
			if (poSol1.y >= 900) {
				triangle[0].position = sf::Vector2f(100.f, 100.f);
				triangle[1].position = sf::Vector2f(70.f, 130.f);
				triangle[2].position = sf::Vector2f(130.f, 130.f);
				triangle2[0].position = sf::Vector2f(100.f, 160.f);
				triangle2[1].position = sf::Vector2f(70.f, 190.f);
				triangle2[2].position = sf::Vector2f(130.f, 190.f);
				triangle3[0].position = sf::Vector2f(100.f, 220.f);
				triangle3[1].position = sf::Vector2f(70.f, 250.f);
				triangle3[2].position = sf::Vector2f(130.f, 250.f);
				poSol1.x = aleatorio();
				poSol2.x = 300;
				poSol3.x = 800;
				poSol1.y = 100;
				poSol2.y = 100;
				poSol3.y = 100;
				velocidadSoles = velocidadSoles + cambio;
			}

			spSol1.setPosition(poSol1);
			spSol2.setPosition(poSol2);
			spSol3.setPosition(poSol3);
			tiempoActual = std::to_string(clock.getElapsedTime().asSeconds());
			text.setString("vidas: " + std::to_string(vidas) + "  Tiempo : ");
			tiempo.setString(tiempoActual);
			sprite2.setPosition(posicion);
			pantalla.clear();
			pantalla.draw(sprite);
			pantalla.draw(sprite2);
			pantalla.draw(spSol1);
			pantalla.draw(spSol2);
			pantalla.draw(spSol3);
			pantalla.draw(text);
			pantalla.draw(tiempo);
			pantalla.draw(triangle);
			pantalla.draw(triangle2);
			pantalla.draw(triangle3);
			pantalla.display();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				pantalla.close();

			}
			poSol1 = poSol1 + velocidadSoles;
			poSol2 = poSol2 + velocidadSoles;
			poSol3 = poSol3 + velocidadSoles;
			if (Keyboard::isKeyPressed(Keyboard::Right)) {

				posicion = (posicion + velocidad);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				posicion = (posicion - velocidad);
			}
		}
	}
}

void drawline(int x0, int y0, int x1, int y1)
{
	
	Color whitePixel(0, 255, 255, 255);

	int dx, dy, p, x, y, count = 0;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x < x1)
	{
		if (p >= 0)
		{
			image.setPixel(y, x, whitePixel);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			image.setPixel(y, x,whitePixel );
			p = p + 2 * dy;
		}
		x = x + 1;
	}

}

boolean clippingArea(Vector2f posicion) {
	int clippingAreaAceptada = 0000;
	int clippingAreaReal = 0;
	if (posicion.x > 960) {
		clippingAreaReal = 1000;
	}
	else if (posicion.x< 200 ) {
		clippingAreaReal = 0001;
	}
	else {
		clippingAreaReal = 0000;
	}
	int i = 0;
	if (!(clippingAreaReal or clippingAreaAceptada)) {
		return false;
	}
	else {
		return true;
		
	}
}
int aleatorio() {
	int num, c;
	srand(time(NULL));

	for (c = 1; c <= 50; c++)
	{
		num = 200 + rand() % (960 - 200);
		if (c == 5 and var == false) {
			return num;
			var = true;
		}
		
	}
	var = false;
	return num;

	
}
boolean murioPorSoles(Vector2f sol1, Vector2f sol2, Vector2f sol3, Vector2f hielo) {
	if (sol1.y > 520 and sol1.y < 680 and ((abs(sol1.x-hielo.x) < 65) or abs(sol2.x - hielo.x) < 65 or abs(sol3.x - hielo.x) < 65)) {
		return true;
	}
	return false;
}
