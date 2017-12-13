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
					m_fDx(0.f), m_fDy(0.f), m_fSpeed(0.f), m_nDir(-1),
					m_pszMap(NULL) {
	m_szFileName = "";
}

CActor::CActor(std::string szFileName, std::string* szMap, float fX, float fY, float fW, float fH) {
	m_szFileName = szFileName;
	m_pszMap = szMap;
	
	m_fW = fW; m_fH = fH;
	
	m_Img.loadFromFile(RES_DIR+szFileName);
	m_Img.createMaskFromColor(Color(41, 33, 59));
	m_Texture.loadFromImage(m_Img);
	
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(IntRect(0, 0, 98, 98));
	
	m_fX = fX; m_fY = fY;
	m_fDx = 0.f; m_fDy = 0.f; 
	
	m_fSpeed = 0.f; 
	m_nDir = -1;
}

CActor::~CActor() {
	m_pszMap = NULL;
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
	
	Collision();
}

void CActor::Collision() {
	for(int i = m_fY/32; i < (m_fY+m_fH)/32; i++)
		for(int j = m_fX/32; j < (m_fX+m_fW)/32; j++) {
			 if(m_pszMap[i][j] == '0') {
				if(m_fDy > 0) m_fY = i*32 - m_fH; 
				else if(m_fDy < 0) m_fY = i*32 + 32;
				else if(m_fDx > 0) m_fX = j*32 - m_fW;
				else m_fX = j*32 + 32;
			}
		}
}