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

void main() {
	VideoMode mode = VideoMode::getDesktopMode();
	RenderWindow wnd(VideoMode(200, 200, mode.bitsPerPixel), "TestWnd");
	
	CircleShape circle(50.f);
	circle.setFillColor(Color::Green);
	
	Event event;
	while(wnd.isOpen()) {
		while(wnd.pollEvent(event)) {
			if(event.type == Event::Closed) wnd.close();
		}
		
		wnd.clear();
		wnd.draw(circle);
		wnd.display();
	}
}