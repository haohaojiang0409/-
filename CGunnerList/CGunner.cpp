#include "CGunner.h"
#include <typeinfo>
#include "../CFoeList/CFoe.h"
#include "../CFoeList/CFoeBig.h"
#include "../CFoeList/CFoeMid.h"
#include "../CFoeList/CFoeSma.h"
CGunner::CGunner():m_x(0),m_y(0)
{
}

CGunner::~CGunner()
{
}

void CGunner::init(int x, int y)
{
	::loadimage(&m_img, L"./res/gunner.jpg");

	m_x = x;

	m_y = y;
}

void CGunner::show()
{
	//1.��������ͼ������λ��
	::putimage(m_x, m_y/*��ʾ��Ŀ�괰�ڵ��Ǹ�λ��*/
				, GUNNER_W, GUNNER_H/*��ʾ�Ĵ�С*/
				, &m_img, GUNNER_W, 0/*��ԭͼ���ĸ�λ�ÿ�ʼ��ʾ*/, SRCPAINT);
	//2.����ԭͼ��λ��
	::putimage(m_x, m_y/*��ʾ��Ŀ�괰�ڵ��Ǹ�λ��*/
		, GUNNER_W, GUNNER_H/*��ʾ�Ĵ�С*/
		, &m_img, 0, 0/*��ԭͼ���ĸ�λ�ÿ�ʼ��ʾ*/, SRCAND);
}

void CGunner::move(int step)
{
	m_y -= step;
}

bool CGunner::isHitFoe(CFoe* pFoe)
{
	if (pFoe) {
		//���õ�λ���ڵ�����
		int x = m_x + GUNNER_W / 2;
		int y = m_y + GUNNER_H / 2;
		//�ж������ַɻ�:typeid����
		if (typeid(*pFoe) == typeid(CFoeBig)) {
			if (m_x <= x && x <= m_x + FOEBIG_W &&
				m_y <= y && y <= m_y + FOEBIG_H) {
				return true;
			}
		}
		else if (typeid(*pFoe) == typeid(CFoeMid)) {
			if (m_x <= x && x <= m_x + FOEMID_W &&
				m_y <= y && y <= m_y + FOEMID_H) {
				return true;
			}
		}
		else if (typeid(*pFoe) == typeid(CFoeSma)) {
			if (m_x <= x && x <= m_x + FOESMA_W &&
				m_y <= y && y <= m_y + FOESMA_H) {
				return true;
			}
		}
	}
	return false;
}
