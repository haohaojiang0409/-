#pragma once
#include "../config/config.h"
/*
	���ļ�����ʵ�ַɻ���ս�ı��������Լ������ƶ�
	������Ҫͨ��������������ͼƬ�м�λ�ô�������m_y����ʼ����Ϊ����ͨ�����������ƶ����ж����m_y > 0����ô��Ҫ���и���
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

	void move(int step);//Ƶ�ʣ��趨��ʱ��
};
