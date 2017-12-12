/*++

Vegetables Team, FTI 21317

File name:
	Actor.cpp
	
Abstract:
	Actor class implementation
	
Author:
	KIRAY
	
--*/

// Actor.cpp

#include "Actor.hpp"

#define RES_DIR "Data/tails/"

CActor::CActor() : m_fX(0.f), m_fY(0.f), m_fW(0.f), m_fH(0.f),
					m_fDx(0.f), m_fDy(0.f), m_fSpeed(0.f), m_nDir(-1) {
	m_szFileName = "";
}

CActor::CActor(std::string szFileName, float fX, float fY, float fW, float fH) {
	m_szFileName = szFileName;
	
	m_fW = fW; m_fH = fH;
	
	m_Img.loadFromFile(RES_DIR+szFileName);
	m_Img.createMaskFromColor(Color(41, 33, 59));
	m_Texture.loadFromImage(m_Img);
	
	m_Sprite.setTexture(m_Texture);
	
	m_fX = fX; m_fY = fY;
	m_fDx = 0.f; m_fDy = 0.f; 
	
	m_fSpeed = 0.f; 
	m_nDir = -1;
}

void CActor::Frame(float& fTime) {
	switch(m_nDir) {
		case RIGHT:
			m_fDx = m_fSpeed;
			m_fDy = 0.f;
			break;
		case LEFT:
			m_fDx = -m_fSpeed;
			m_fDy = 0.f;
			break;
		case UP:
			m_fDy = m_fSpeed;
			m_fDx = 0.f;
			break;
		case DOWN:
			m_fDy = -m_fSpeed;
			m_fDx = 0.f;
			break;
	}
	
	m_fX += m_fDx*fTime; m_fY += m_fDy*fTime;
	m_fSpeed = 0.f;
	m_Sprite.setPosition(m_fX, m_fY);
}