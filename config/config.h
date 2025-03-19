#include <easyx.h>
#include <iostream>
using namespace std;

//背景长宽
#define BACK_H				    800 
#define BACK_W				    600
							    
#define BACK_TIMER_INTERVAL		70
#define BACK_MOVE_TIMERID	    1
#define BACK_MOVE_STEP		    10
#define PLAYER_MOVE_STEP	    5

//检测 
#define CHECK_KEYDOWN_TIMERID	2
#define CHECK_KEYDOWN_INTERVAL	20

//飞机长宽
#define PLAYER_W				60
#define PLAYER_H				60

//炮弹发射器的宽度
#define GUNNER_W				6
#define GUNNER_H				20

//炮弹定时器的频率，时间ID
#define GUNNER_MOVE_STEP		3
#define GUNNER_SEND_TIMERID		3
#define GUNNER_SEND_INTERVAL	5

//敌人飞机的移动频率
#define FOE_MOVE_TIMERID		4
#define FOE_MOVE_INTERVAL		80
//敌人飞机的出现频率
#define FOE_CREATE_TIMERID		5
#define FOE_CREATE_INTERVAL		2000
//攻击定时器
#define FOE_HIT_TIMERID			6
#define FOE_HIT_INTERVAL		5

#define CHANGE_PIC_TIMERID		7
#define CHANGE_PIC_INTERVAL		200

//敌人飞机的宽度高度
//大号
#define FOEBIG_W				150				
#define FOEBIG_H				100
//移动的步长
#define FOEBIG_MOVE_STEP		2
//中号
#define FOEMID_W				80			
#define FOEMID_H				60
//移动的步长
#define FOEMID_MOVE_STEP		4

//小号
#define FOESMA_W				60				
#define FOESMA_H				40
//移动的步长
#define FOESMA_MOVE_STEP		5

//炮弹每次的伤害
#define GUNNER_BLOOD			1

//敌人飞机的血量
#define FOEBIG_BLOOD			(GUNNER_BLOOD * 5)
#define FOEMID_BLOOD			(GUNNER_BLOOD * 3)
#define FOESMA_BLOOD			(GUNNER_BLOOD * 1)

//敌人飞机的下标
#define BIGINIT_SHOWID				4
#define MIDINIT_SHOWID				3
#define SMAINIT_SHOWID				2