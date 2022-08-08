#include <SFML/Graphics.hpp>

int main() {
	const int FPS = 60;
	const int XRES = 1280; //frame size
	const int YRES = 720;
	const int XSIZE = 300; //size of the rectangle
	const int YSIZE = 100;
	const int OUTLINE = 15;
	const sf::Color red(255, 0, 0);
	const sf::Color blue(0,0,255);
	float xVel = 3;    //initial velocity
	float yVel = 3;

	sf::RenderWindow window(sf::VideoMode(XRES,YRES), "screen-save");
	
	window.setFramerateLimit(FPS);

	sf::RectangleShape rect;
	rect.setFillColor(blue);
	rect.setOutlineThickness(OUTLINE);
	rect.setOutlineColor(red);


	sf::Vector2f rectPos(XRES / 2, YRES / 2);
	rect.setPosition(rectPos);
	rect.setSize(sf::Vector2f(XSIZE,YSIZE));

	while (window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//bounce off the frame
		if (rectPos.x < OUTLINE || rectPos.x > XRES - XSIZE - OUTLINE)
			xVel *= -1;

		if (rectPos.y < OUTLINE || rectPos.y > YRES - YSIZE - OUTLINE)
			yVel *= -1;

		//move the shape
		rectPos.x += xVel;
		rectPos.y += yVel;
		rect.setPosition(rectPos);

		window.clear();
		window.draw(rect);
		window.display();
	}

	return 0;
}
