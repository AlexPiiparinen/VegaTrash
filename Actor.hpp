#pragma once

#include <SFML\Graphics.hpp>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace sf;

class CActor {
public:
	CActor();
	CActor(std::string, std::string*, float, float, float, float);
	~CActor();
	
	void Frame(float& fTime);
	void Collision();
	
	int m_nDir;
	float	m_fSpeed;
	Sprite	m_Sprite;
	
private:
	float m_fX, m_fY, m_fW, m_fH, m_fDx, m_fDy;
	
	std::string m_szFileName;
	std::string* m_pszMap;
	Image m_Img;
	Texture m_Texture;
};