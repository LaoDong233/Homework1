// M == 16
#include"cs.h"
#include"func.h"
void load_img(void);
void flush_block(void);
void check_map(int* map);
void create_map(void);
int map[4][4] = { 0 };		
PIMAGE n[16];
void right(int* score);
void upper(int* score);
void down(int* score);
void left(int* score);
int main(int* score)
{
	int dscore = 0;		//创建两个积分用函数，char函数用于打印
	char cscore[2048] = { 0 };
	int* ps = &dscore;	//创建指针方便修改
	create_map();		//建立背景图片
	load_img();		//建立图片变量
	int e = 0;
	srand((unsigned int)time(0));		//生成随机数
	int* pmap = &map[0][0];		//创建地图指针方便调用
	for (int i = 0; i < 2; i++)		//起始两个随机值生成
		dorand(pmap);
	setcolor(EGERGB(0x00, 0x00, 0x00));		//设置文字颜色
	setfont(30, 0, "宋体");		//设置字体
	setbkmode(TRANSPARENT);		//设置文字背景透明
	outtextxy(860, 250, cscore);	//打印分数
	sprintf_s(cscore, "%d", dscore);	//将分数转换为字符串
	setfillcolor(EGERGB(0x9F, 0xEC, 0xFF));	//不要动！！！！！！
	while (1) {
		bar(817, 255, 989, 280);	//文字逻辑，不要动！！！
		int xClick, yClick;
		sprintf_s(cscore, "%d", dscore);
		outtextxy(860, 250, cscore);
		check_map(pmap);	//判断胜利失败
		if (e == -1) {
			system("msg %username% /time:10 \"你失败了\"");	//调用系统弹窗
			system("pause");
			return 0;
		}
		else if (e == 255) {
			system("msg %username% /time:10 \"你失败了\"");	//调用系统弹窗
			system("pause");
			return 0;
		}
		mouse_msg msg1 = { 0 };
		while (mousemsg())
		{
			msg1 = getmouse();
		}
		mousepos(&xClick, &yClick);		//调用鼠标位置123
		char str[32];
		sprintf(str, "%4d %4d", xClick, yClick);
		if ((int)msg1.is_left() && (int)msg1.is_up()) {		//检查鼠标左键是否按下
			if ((xClick > 805 && xClick < 862) && (yClick > 416 && yClick < 477)) {		//检查鼠标是否在左侧
				left(ps);
				e = docheck(pmap);
				dorand(pmap);
			}
			else if ((xClick > 928 && xClick < 982) && (yClick > 416 && yClick < 477)) {		//检查鼠标是否在右侧
				right(ps);
				e = docheck(pmap);
				dorand(pmap);
			}
			else if ((xClick > 870 && xClick < 920) && (yClick > 373 && yClick < 416)) {		//检查鼠标是否在上面
				upper(ps);
				e = docheck(pmap);
				dorand(pmap);
			}
			else if ((xClick > 870 && xClick < 920) && (yClick > 477 && yClick < 520)) {		//检查鼠标是否在下面
				down(ps);
				e = docheck(pmap);
				dorand(pmap);
			}
			else if ((xClick > 871 && xClick < 920) && (yClick > 421 && yClick < 473)) {		//检查鼠标是否在中间
				clear_map(pmap);		//清除地图内所有数据
				dscore = 0;				//清除分数
				for (int i = 0; i < 2; i++)		//重新随机
					dorand(pmap);
			}
		}
		if (kbhit()) {		//非阻塞方式等待
		rechar:char mod = getch();	//获取按键

			switch (mod)
			{
			case 'a':
				printf("左\n");
				left(ps);
				e = docheck(pmap);
				dorand(pmap);
				break;
			case 's':
				printf("下\n");
				down(ps);
				e = docheck(pmap);
				dorand(pmap);
				break;
			case 'w':
				printf("上\n");
				upper(ps);
				e = docheck(pmap);
				dorand(pmap);
				break;
			case 'd':
				printf("右\n");
				right(ps);
				e = docheck(pmap);
				dorand(pmap);
				break;
			case 'r':
				clear_map(pmap);
				dscore = 0;
				for (int i = 0; i < 2; i++)
					dorand(pmap);
				break;
			default:
				goto  rechar;
			}
		}
		flush_block();	//刷新地图
	}
	closegraph();		//关闭地图
	return 0;
}
void check_map(int* map) {		//检察地图位置并填充对应的图片
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
void load_img(void) {			//初始化函数
	for (int i = 0; i < M; i++) {
		n[i] = newimage();
	}
}
void left(int* score) {			//向左移动
	for (int dd = 0; dd < 3; dd++) {
		int b = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				if (map[j][i - 1] == 0)
				{
					map[j][i - 1] = map[j][i];//右面移动到左面
					map[j][i] = 0;//清空
				}
				else
				{
					if (dd == 0 && map[j][i - 1] == map[j][i] && b == 0)
					{
						map[j][i - 1] = map[j][i - 1] + map[j][i];
						map[j][i] = 0;
						*score = *score + map[j][i - 1];
						b++;
					}
					else if (b == 1)
					{
						b = 0;
					}
				}
				b = 0;
			}
		}
	}
}
void down(int* score) {		//向下移动
	for (int dd = 0; dd < 3; dd++) {
		int b = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (map[j + 1][i] == 0 && j != 3)
				{
					map[j + 1][i] = map[j][i];//上面移动到下面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j + 1][i] == map[j][i] && dd == 0 && b == 0)
					{
						map[j + 1][i] = map[j + 1][i] + map[j][i];
						map[j][i] = 0;
						*score = *score + map[j + 1][i];
						b++;
					}
					else if (b == 1)
					{
						b = 0;
					}
				}
				b = 0;
			}
		}
	}
}
void upper(int* score) {		//向上移动
	for (int dd = 0; dd < 3; dd++) {
		int b = 0;
		for (int j = 3; j > 0; j--)
		{
			for (int i = 0; i < 4; i++)
			{
				if (map[j - 1][i] == 0)
				{
					map[j - 1][i] = map[j][i];//下面移动到上面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j - 1][i] == map[j][i] && dd == 0 && b == 0)
					{
						b++;
						map[j - 1][i] = map[j - 1][i] + map[j][i];
						map[j][i] = 0;
						*score = *score + map[j - 1][i];
					}
					else if (b == 1) {
						b = 0;
					}
				}
				b = 0;
			}
		}
	}
}
void right(int* score) {		//向右移动
	for (int dd = 0; dd < 3; dd++) {
		int b = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (map[j][i + 1] == 0)
				{
					map[j][i + 1] = map[j][i];//左面移动到右面
					map[j][i] = 0;//清空
				}
				else
				{
					if (map[j][i + 1] == map[j][i] && dd == 0 && b == 0)
					{
						b++;
						map[j][i + 1] = map[j][i + 1] + map[j][i];
						map[j][i] = 0;
						*score = *score + map[j][i + 1];
					}
					else if (b == 1)
					{
						b = 0;
					}
				}
				b = 0;
			}
		}
	}
}
void flush_block(void) {		//刷新格子上的图片
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