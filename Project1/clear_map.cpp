#include "cs.h"
#include "func.h"
void clear_map(int* map) {
	for (int i = 0; i < M + 1; i++) {
		map[i] = 0;
	}
}