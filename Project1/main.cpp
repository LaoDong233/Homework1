#include"cs.h"
#include"func.h"
void create_map(void);
int map[4][4] = { 0 };
int main(void)
{
	srand((unsigned int)time(0));
	int* pmap = &map[0][0];
	int e = docheck(pmap);
	dorand(pmap);
	create_map();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	if (e != 0) {
		printf("you lose the game!");
		system("pause");
		return 0;
	}
	getch();
	return 0;

}
void create_map(void) {
	initgraph(1120, 630);
	PIMAGE bak = newimage();
	getimage(bak, ".\\img\\backblock.png");
	putimage(0, 0, bak);
	delimage(bak);
	PIMAGE n0 = newimage();
	getimage(n0, A_);
	PIMAGE n1 = newimage(), n2 = newimage(), n3 = newimage(), n4 = newimage(), n5 = newimage(), n6 = newimage(), n7 = newimage(), n8 = newimage(), n9 = newimage();
	PIMAGE n10 = newimage(), n11 = newimage(), n12 = newimage(), n13 = newimage(), n14 = newimage(), n15 = newimage();
	putimage(36, 164, n0);
	putimage(206, 164, n1);
}