#include "cs.h"
#include"func.h"
void dorand(int* map) {
	if (docheck(map) == 0) {
		while (true)
		{
			int a = rand() % M;
			if (map[a] == 0) {
				map[a] = 2;
				break;
			}
		}
	}
}