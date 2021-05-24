#include"cs.h"
void create_map(void) {
	initgraph(1120, 630);
	PIMAGE bak = newimage();
	getimage(bak, BLOCK_);
	putimage(0, 0, bak);
	delimage(bak);
}