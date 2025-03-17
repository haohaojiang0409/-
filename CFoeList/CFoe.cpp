#include "CFoe.h"

CFoe::CFoe() :m_x(0), m_y(0), m_blood(0), m_showIndex(0)
{
}
CFoe::~CFoe()
{
}


void CFoe::move(int step)
{
	m_y += step;
}

void CFoe::reduceBlood(int hurt)
{
	m_blood -= hurt;
}
random_device CFoe::rd;//随机设置，这个对象可以产生随机数
