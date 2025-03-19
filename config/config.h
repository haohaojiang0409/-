#include <easyx.h>
#include <iostream>
using namespace std;

//��������
#define BACK_H				    800 
#define BACK_W				    600
							    
#define BACK_TIMER_INTERVAL		70
#define BACK_MOVE_TIMERID	    1
#define BACK_MOVE_STEP		    10
#define PLAYER_MOVE_STEP	    5

//��� 
#define CHECK_KEYDOWN_TIMERID	2
#define CHECK_KEYDOWN_INTERVAL	20

//�ɻ�����
#define PLAYER_W				60
#define PLAYER_H				60

//�ڵ��������Ŀ��
#define GUNNER_W				6
#define GUNNER_H				20

//�ڵ���ʱ����Ƶ�ʣ�ʱ��ID
#define GUNNER_MOVE_STEP		3
#define GUNNER_SEND_TIMERID		3
#define GUNNER_SEND_INTERVAL	5

//���˷ɻ����ƶ�Ƶ��
#define FOE_MOVE_TIMERID		4
#define FOE_MOVE_INTERVAL		80
//���˷ɻ��ĳ���Ƶ��
#define FOE_CREATE_TIMERID		5
#define FOE_CREATE_INTERVAL		2000
//������ʱ��
#define FOE_HIT_TIMERID			6
#define FOE_HIT_INTERVAL		5

#define CHANGE_PIC_TIMERID		7
#define CHANGE_PIC_INTERVAL		200

//���˷ɻ��Ŀ�ȸ߶�
//���
#define FOEBIG_W				150				
#define FOEBIG_H				100
//�ƶ��Ĳ���
#define FOEBIG_MOVE_STEP		2
//�к�
#define FOEMID_W				80			
#define FOEMID_H				60
//�ƶ��Ĳ���
#define FOEMID_MOVE_STEP		4

//С��
#define FOESMA_W				60				
#define FOESMA_H				40
//�ƶ��Ĳ���
#define FOESMA_MOVE_STEP		5

//�ڵ�ÿ�ε��˺�
#define GUNNER_BLOOD			1

//���˷ɻ���Ѫ��
#define FOEBIG_BLOOD			(GUNNER_BLOOD * 5)
#define FOEMID_BLOOD			(GUNNER_BLOOD * 3)
#define FOESMA_BLOOD			(GUNNER_BLOOD * 1)

//���˷ɻ����±�
#define BIGINIT_SHOWID				4
#define MIDINIT_SHOWID				3
#define SMAINIT_SHOWID				2