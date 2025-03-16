#include "CBack.h"

CBack::CBack():m_x(0),m_y(0)
{

}

CBack::~CBack()
{

}

void CBack::init()
{
	//1.先加载背景图片
	::loadimage(&m_img, L"./res/back.jpg");
	m_x = 0;
	m_y = -BACK_H;

}

void CBack::show()
{
	//2.加载图片到指定位置
	::putimage(m_x, m_y, &m_img);
}

void CBack::move(int step)
{
	//3.向下移动
	m_y += step;
	//3.1判断临界条件，如果超出了一个图片的长度大小，那么就刷新纵坐标
	if (m_y >= 0) {
		m_y = -BACK_H;
	}
}
