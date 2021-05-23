#include"cs.h"
#include"func.h"
int main(void)
{
	int map[4][4] = { 0 };
	int* pmap = &map[0][0];
	int e = docheck(pmap);
	dorand(pmap);
	if (e != 0) {
		printf("you lose the game!");
		show_map(pmap);
		system("pause");
		return 0;
	}

}