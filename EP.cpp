/*++

Vegetables Team, FTI 21317

File name:
	EP.cpp
	
Abstract:
	Define entry point
	
Author:
	KIRAY
	
--*/

// EP.cpp

#include <SFML\Graphics.hpp>

#pragma comment(lib, "sfml-system-d")
#pragma comment(lib, "sfml-window-d")
#pragma comment(lib, "sfml-graphics-d")

using namespace sf;

void KeyPress(Sprite& act) {
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		act.move(-0.1f, 0.f);
		act.setTextureRect(IntRect(0, 96, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right)) {
		act.move(0.1f, 0.f);
		act.setTextureRect(IntRect(0, 192, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		act.move(0.f, -0.1f);
		act.setTextureRect(IntRect(0, 288, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Down)) {
		act.move(0.f, 0.1f);
		act.setTextureRect(IntRect(0, 0, 96, 96));
	}
	
	if(Mouse::isButtonPressed(Mouse::Left)) {
		act.setColor(Color::Red);
	}
}

void main() {
	VideoMode mode = VideoMode::getDesktopMode();
	RenderWindow wnd(VideoMode(640, 480, mode.bitsPerPixel), "TestWnd");
	
	Texture textu;
	textu.loadFromFile("./test.png");
	
	Sprite actor;
	actor.setTexture(textu);
	actor.setTextureRect(IntRect(0, 192, 96, 96));
	actor.setPosition(50, 25);
	
	Event event;
	while(wnd.isOpen()) {
		while(wnd.pollEvent(event)) {
			if(event.type == Event::Closed) wnd.close();
		}
		
		KeyPress(actor);
		
		wnd.clear();
		wnd.draw(actor);
		wnd.display();
	}
}