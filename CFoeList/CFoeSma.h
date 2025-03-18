#include "../CFoeList/CFoe.h"
class CFoeSma :public CFoe {
public:

	void init();

	void show();

	bool isHitPlayer(CPlayer* player);
};