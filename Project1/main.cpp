// M == 16
#include"cs.h"
#include"func.h"
PIMAGE n[16];
void load_img(void);
void flush_block(void);
void check_map(int* map);
void create_map(void);
int map[4][4] = { 0 };
int main(void)
{
	load_img();
	create_map();
	srand((unsigned int)time(0));
	int* pmap = &map[0][0];
	dorand(pmap);
	while (1) {
		int e = docheck(pmap);
		dorand(pmap);
		check_map(pmap);
		flush_block();
		if (e != 0) {
			printf("you lose the game!");
			system("pause");
			return 0;
		}
		char mod = getch();
	}
	return 0;

}
void check_map(int* map) {
	for (int p = 0; p < M; p++)
	{
		if (map[p] == 2)
			getimage(n[p], A_);
		else if (map[p] == 4)
			getimage(n[p], B_);
		else if (map[p] == 8)
			getimage(n[p], C_);
		else if (map[p] == 16)
			getimage(n[p], D_);
		else if (map[p] == 32)
			getimage(n[p], E_);
		else if (map[p] == 64)
			getimage(n[p], F_);
		else if (map[p] == 128)
			getimage(n[p], G_);
		else if (map[p] == 256)
			getimage(n[p], H_);
		else if (map[p] == 512)
			getimage(n[p], I_);
		else if (map[p] == 1024)
			getimage(n[p], J_);
		else if (map[p] == 2048)
			getimage(n[p], K_);
		else
			getimage(n[p], BLOCK);
	}
}
void load_img(void) {
	for (int i = 0; i < M; i++) {
		n[i] = newimage();
	}
}
void flush_block(void) {
	putimage(36, 164, n[0]);
	putimage(206, 164, n[1]);
	putimage(376, 164, n[2]);
	putimage(546, 164, n[3]);
	putimage(36, 266, n[4]);
	putimage(206, 266, n[5]);
	putimage(376, 266, n[6]);
	putimage(546, 266, n[7]);
	putimage(36, 366, n[8]);
	putimage(206, 366, n[9]);
	putimage(376, 366, n[10]);
	putimage(546, 366, n[11]);
	putimage(36, 467, n[12]);
	putimage(206, 467, n[13]);
	putimage(376, 467, n[14]);
	putimage(546, 467, n[15]);
}