#pragma once
#include "../config/config.h"
/*
	本文件用于实现飞机大战的背景加载以及背景移动
	背景主要通过将窗口设置在图片中间位置处，所以m_y的起始坐标为负，通过不断向下移动，判断如果m_y > 0，那么需要进行更新
*/
class CBack {
public:
	IMAGE m_img;

	int m_x;

	int m_y;
public:
	CBack();

	~CBack();

	void init();

	void show();

	void move(int step);//频率，设定定时器
};
