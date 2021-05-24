#include"cs.h"
int docheck(int* map) {
	int b = 0;
	for (int i = 0; i < M+1; i++) {
		if (map[i] == 0) {
			b = 0;
			return 0;
		}
		else if (map[i] == 2048)
		{
			return 255;
		}
		else
		{
			b++;
		}
		if (b == M)
		{
			return -1;
		}
	}
	return 0;
}