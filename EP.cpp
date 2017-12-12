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

#include "Actor.hpp"

#pragma comment(lib, "sfml-system-d")
#pragma comment(lib, "sfml-window-d")
#pragma comment(lib, "sfml-graphics-d")

using namespace sf;

void KeyPress(CActor& act, float& fTime, float& fFrame) {
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		act.m_nDir = 1; act.m_fSpeed = 0.1f;
	
		fFrame += 0.005f*fTime;
		if(fFrame > 3.f) fFrame -= 3.f; // ACHTUNG !!!!
	
		act.m_Sprite.setTextureRect(IntRect(96*static_cast<int>(fFrame), 96, 96, 96)); // !
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Right)) {
		act.m_nDir = 0; act.m_fSpeed = 0.1f;
	
		fFrame += 0.005f*fTime;
		if(fFrame > 3.f) fFrame -= 3.f;
		
		act.m_Sprite.setTextureRect(IntRect(96*static_cast<int>(fFrame), 192, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		act.m_nDir = 3; act.m_fSpeed = 0.1f;
		
		fFrame += 0.005f*fTime;
		if(fFrame > 3.f) fFrame -= 3.f;
		
		act.m_Sprite.setTextureRect(IntRect(96*static_cast<int>(fFrame), 288, 96, 96));
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Down)) {
		act.m_nDir = 2; act.m_fSpeed = 0.1f;
		
		fFrame += 0.005f*fTime;
		if(fFrame > 3.f) fFrame -= 3.f;

		act.m_Sprite.setTextureRect(IntRect(96*static_cast<int>(fFrame), 0, 96, 96));
	}
	
	if(Mouse::isButtonPressed(Mouse::Left)) {
		act.m_Sprite.setColor(Color::Red);
	}
}

void main() {
	float fCurrFrame = 0.f;

	VideoMode mode = VideoMode::getDesktopMode();
	RenderWindow wnd(VideoMode(640, 480, mode.bitsPerPixel), "TestWnd");
	
	CActor actor("Actor.png", 250, 250, 96.f, 96.f);
	
	Event event;
	Clock clock;
	while(wnd.isOpen()) {
		float fTime = clock.getElapsedTime().asMicroseconds();
		fTime /= 400;
		clock.restart();
	
		while(wnd.pollEvent(event)) {
			if(event.type == Event::Closed) wnd.close();
		}
		
		KeyPress(actor, fTime, fCurrFrame);
		actor.Frame(fTime);
		
		wnd.clear();
		wnd.draw(actor.m_Sprite);
		wnd.display();
	}
}