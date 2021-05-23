#include"cs.h"
void create_map(void) {
	initgraph(1120, 630);
	PIMAGE bak = newimage();
	getimage(bak, ".\\img\\backblock.png");
	putimage(0, 0, bak);
	delimage(bak);
}