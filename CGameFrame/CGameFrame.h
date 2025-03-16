//#pragma once
//#include<easyx.h>
//#include<Windowsx.h>
//#include<map>
//using namespace std;
//
//#define MSGMAP(MSGID,MSGTYPE,CLASS)\
//m_msgMap[MSGID].MsgType = MSGTYPE;\
//m_msgMap[MSGID].p_fun_##MSGTYPE = (P_FUN_##MSGTYPE)&CLASS::On_##MSGID;
//
//class CGameFrame
//{
//public:
//	HWND m_hwnd;
//	bool m_isquit;
//
////#define EX_MOUSE	1
////#define EX_KEY		2
////#define EX_CHAR		4
////#define EX_WINDOW	8
//
//
//
//	//ָ��On_WM_LBUTTONDOWN�����Ա����ָ��
//	typedef void (CGameFrame::*P_FUN_EX_MOUSE)(int, int);
//	typedef void (CGameFrame::* P_FUN_EX_KEY)(int);
//	typedef void (CGameFrame::* P_FUN_EX_WINDOW)(int, int);
//	virtual void ADDMSGMAP();
//	struct MsgTypeFun {
//		UINT MsgType;
//		union {
//			P_FUN_EX_MOUSE p_fun_EX_MOUSE;//������ĺ���ָ��
//			P_FUN_EX_KEY p_fun_EX_KEY;
//			P_FUN_EX_WINDOW p_fun_EX_WINDOW;
//		};
//	};
//
//	//��ֵ:  ��Ϣid    ʵֵ  { ��� �� ���Ա����ָ�� }
//	map<UINT, MsgTypeFun> m_msgMap;
//
//
//	CGameFrame();
//	~CGameFrame();
//	//1.InitGame
//	void InitGame(int width, int length, int x, int y,const WCHAR* p);
//
//	//2.PanitGame
//	void PanitGame();
//
//	//3.RunGame
//	//void RunGame();
//	static LRESULT CALLBACK RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//	//4.CloseGame
//
//	void On_WM_CLOSE(int, int);
//
//	//-------------������Ϸ�ӿڵĺ���--------------------------
//	virtual void On_Init() = 0;
//	virtual void On_Paint() = 0;
//	virtual void On_Close() = 0;
//
//
//#define WND_PARAM(W,H,X,Y,TITLE)\
//int width=W;\
//int height = H;\
//int x = X;\
//int y = Y;\
//const WCHAR* p = L##TITLE;
//
//
//	
//};
//

#pragma once
#include<easyx.h>
#include<iostream>
#include<Windowsx.h>

#include<map>
using namespace std;

#define ADD_MSG_MAP(MSGID,MSGTYPE,CLASS)\
m_msgMap[MSGID].MsgType = MSGTYPE;\
m_msgMap[MSGID].p_fun_##MSGTYPE=(P_FUN_##MSGTYPE)&CLASS::On_##MSGID;

class CGameFrame{
public:
	bool m_isQuit;
	HWND m_hwnd;

	typedef void (CGameFrame::* P_FUN_EX_MOUSE)(int, int);
	typedef void (CGameFrame::* P_FUN_EX_KEY)(int);

	typedef void(CGameFrame::* P_FUN_EX_WINDOW)(WPARAM, LPARAM);

	struct MsgTypeFun {
		UINT MsgType;
  		union 
		{//����  ����һ��ռ�
			P_FUN_EX_MOUSE p_fun_EX_MOUSE;  //������͵ĺ���ָ��
			P_FUN_EX_KEY p_fun_EX_KEY;      //�������ĺ���ָ��
			P_FUN_EX_WINDOW p_fun_EX_WINDOW;
		};
		
	};
	//��ֵ:��Ϣid   ʵֵ:{��� �� ���Ա����ָ��}
	map<UINT, MsgTypeFun> m_msgMap;
	



	CGameFrame();
	virtual ~CGameFrame();
 	//1.InitGame
	void InitGame(int width,int height,int x,int y,const WCHAR*p);

	//2.PaintGame
	void PaintGame();

	//3.RunGame
	//void RunGame();
	static LRESULT CALLBACK RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:	
	//4.CloseGame
	void On_WM_CLOSE(WPARAM w, LPARAM l);

	virtual void AddMsgMap();


	//����ӿں���

	virtual void On_Init() = 0;  //���麯��Ҫ�����������������дʵ��
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;

};

#define WND_PARAM(W,H,X,Y,TITLE)\
int width = W;\
int height = H;\
int pos_x = X;\
int pos_y = Y;\
const WCHAR* pTitle = TITLE;

#define CREATE_OBJECT(CLASS)\
CGameFrame* CreatObject() {\
	return new CLASS;\
}




