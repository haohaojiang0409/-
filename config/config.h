#include <easyx.h>
#include <iostream>
using namespace std;
//#include "../CBack/CBack.h"
//#include "../CPlayer/CPlayer.h"
//#include "../CGameFrame/CGameFrame.h"
//#include "../CPlaneApp/CPlaneApp.h"
//#include "../CGunnerList/CGunner.h"
//��������
#define BACK_H				    800 
#define BACK_W				    600
							    
#define BACK_TIMER_INTERVAL		80
#define BACK_MOVE_TIMERID	    1
#define BACK_MOVE_STEP		    2
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
#define GUNNER_MOVE_STEP		3