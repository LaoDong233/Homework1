#if 0
#include <time.h>
#include<stdlib.h>
void dorand(int *map) {
	int x = 0, y = 0;
	do {
		y = rand() % 4;
		x = rand() % 4;
	} while (map[y][x] != 0);
	map[y][x] = 2;
}
#endif