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

#define MAP_HEIGHT 15
#define MAP_WIDTH 15

#pragma comment(lib, "sfml-system-d")
#pragma comment(lib, "sfml-window-d")
#pragma comment(lib, "sfml-graphics-d")

using namespace sf;

std::string szMap[MAP_HEIGHT] = {
	"0000000000000000",
	"0111111111111110",
	"0111112111111110",
	"0111211111111110",
	"0111121111111110",
	"0111112111111110",
	"0111111111111110",
	"0111111111111110",
	"0111111110000000",
	"0111111110112110",
	"0111111210111110",
	"0111111110111110",
	"0111111210011110",
	"0111111111111110",
	"0000000000000000",
};

void DrawMap(RenderWindow& wnd, Sprite& map) {
	for(int i=0; i<MAP_HEIGHT; i++)
		for(int j=0; j<MAP_WIDTH; j++) {
			if(szMap[i][j] == '0') map.setTextureRect(IntRect(64, 0, 32, 32));
			if(szMap[i][j] == '1') map.setTextureRect(IntRect(0, 0, 32, 32));
			if(szMap[i][j] == '2') map.setTextureRect(IntRect(32, 0, 32, 32));
			
			map.setPosition(j*32, i*32);
			wnd.draw(map);
		}
}

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
	
	// Map
	Texture mapText;
	mapText.loadFromFile("./Data/tails/Level0.png");
	Sprite map;
	map.setTexture(mapText);
	
	CActor actor("Actor.png", szMap, 100.f, 100.f, 96.f, 96.f);
	
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
		DrawMap(wnd, map);
		wnd.draw(actor.m_Sprite);
		wnd.display();
	}
}