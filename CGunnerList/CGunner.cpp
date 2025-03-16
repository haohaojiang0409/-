#include "CGunner.h"

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
				, &m_img, 0, 0/*��ԭͼ���ĸ�λ�ÿ�ʼ��ʾ*/, SRCPAINT);
	//2.����ԭͼ��λ��
	::putimage(m_x, m_y/*��ʾ��Ŀ�괰�ڵ��Ǹ�λ��*/
		, GUNNER_W, GUNNER_H/*��ʾ�Ĵ�С*/
		, &m_img, 0, 0/*��ԭͼ���ĸ�λ�ÿ�ʼ��ʾ*/, SRCAND);
}

void CGunner::move(int step)
{
	m_y -= step;
}

//bool CGunner::isHitFoe(CFoe* pFoe)
//{
//	return false;
//}
