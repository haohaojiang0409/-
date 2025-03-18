#include "../CFoeList/CFoe.h"
class CFoeBig :public CFoe {
public:

	void init();

	void show();

	bool isHitPlayer(CPlayer* player);
};