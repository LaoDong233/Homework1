// M == 16
#include"cs.h"
#include"func.h"
PIMAGE n[16];
void load_img(void);
void flush_block(void);
void check_map(int* map);
void create_map(void);
int map[4][4] = { 0 };
void right(void);
void upper(void);
void down(void);
void left(void);
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
		rechar:char mod = getch();

		switch (mod)
		{
		case 'a':
			printf("左\n");
			left();
			break;
		case 's':
			printf("下\n");
			down();
			break;
		case 'w':
			printf("上\n");
			upper();
			break;
		case 'd':
			printf("右\n");
			right();
			break;
		default:
			goto  rechar;
		}
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
void left(void) {
	for (int dd = 0; dd < 3; dd++) {
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				int b = 0;
				if (map[j][i - 1] == 0)
				{
					map[j][i - 1] = map[j][i];//右面移动到左面
					map[j][i] = 0;//清空
				}
				else
				{
					if (dd ==0 &&map[j][i - 1] == map[j][i]&&b<2)
					{
						map[j][i - 1] = map[j][i - 1] + map[j][i];
						map[j][i] = 0;
						b++;
					}
				}
			}
		}
	}
}
void down(void) {
	for (int dd = 0; dd < 3; dd++) {
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				int b = 0;
				if (map[j + 1][i] == 0 && j != 3)
				{
					map[j + 1][i] = map[j][i];//上面移动到下面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j + 1][i] == map[j][i] && dd == 0 && b < 2)
					{
						map[j + 1][i] = map[j + 1][i] + map[j][i];
						map[j][i] = 0;
						b++;
					}
				}
			}
		}
	}
}
void upper(void) {
	for (int dd = 0; dd < 3; dd++) {
		for (int j = 3; j > 0; j--)
		{
			for (int i = 0; i < 4; i++)
			{
				int b = 0;
				if (map[j - 1][i] == 0)
				{
					map[j - 1][i] = map[j][i];//下面移动到上面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j - 1][i] == map[j][i] && dd == 0 && b < 2)
					{
						b++;
						map[j - 1][i] = map[j - 1][i] + map[j][i];
						map[j][i] = 0;
					}
				}
			}
		}
	}
}
void right(void) {
	for (int dd = 0; dd < 3; dd++) {
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				int b = 0;
				if (map[j][i + 1] == 0)
				{
					map[j][i + 1] = map[j][i];//左面移动到右面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j][i + 1] == map[j][i] && dd == 0 && b < 2)
					{
						b++;
						map[j][i + 1] = map[j][i + 1] + map[j][i];
						map[j][i] = 0;
					}
				}
			}
		}
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