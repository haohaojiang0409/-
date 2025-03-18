#include "../CFoeList/CFoe.h"
class CFoeMid :public CFoe {
public:

	void init();

	void show();

	bool isHitPlayer(CPlayer* player);
};