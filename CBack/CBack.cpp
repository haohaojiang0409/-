#include "CBack.h"

CBack::CBack():m_x(0),m_y(0)
{

}

CBack::~CBack()
{

}

void CBack::init()
{
	//1.�ȼ��ر���ͼƬ
	::loadimage(&m_img, L"./res/back.jpg");
	m_x = 0;
	m_y = -BACK_H;

}

void CBack::show()
{
	//2.����ͼƬ��ָ��λ��
	::putimage(m_x, m_y, &m_img);
}

void CBack::move(int step)
{
	//3.�����ƶ�
	m_y += step;
	//3.1�ж��ٽ����������������һ��ͼƬ�ĳ��ȴ�С����ô��ˢ��������
	if (m_y >= 0) {
		m_y = -BACK_H;
	}
}
