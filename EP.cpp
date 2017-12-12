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

void KeyPress(Sprite& act, float& fTime) {
	float fCurrFrame = 0.f;

	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		fCurrFrame += 0.005f*fTime;
		if(fCurrFrame > 3.f) fCurrFrame -= 3.f; // ACHTUNG !!!!
	
		act.setTextureRect(IntRect(96*static_cast<int>(fCurrFrame), 96, 96, 96));
		act.move(-0.1f*fTime, 0.f);
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right)) {
		act.move(0.1f*fTime, 0.f);
		act.setTextureRect(IntRect(0, 192, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		act.move(0.f*fTime, -0.1f);
		act.setTextureRect(IntRect(0, 288, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Down)) {
		act.move(0.f*fTime, 0.1f);
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
	Clock clock;
	while(wnd.isOpen()) {
		float fTime = clock.getElapsedTime().asMicroseconds();
		fTime /= 400;
		clock.restart();
	
		while(wnd.pollEvent(event)) {
			if(event.type == Event::Closed) wnd.close();
		}
		
		KeyPress(actor, fTime);
		
		wnd.clear();
		wnd.draw(actor);
		wnd.display();
	}
}