#define  _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>

// 1401. 圆和矩形是否有重叠
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
	double dx, dy;
	if (x1 <= xCenter && xCenter <= x2) {
		dx = 0;
	}
	else if (xCenter < x1) {
		dx = x1 - xCenter;
	}
	else {
		dx = xCenter - x2;
	}
	if (y1 <= yCenter && yCenter <= y2) {
		dy = 0;
	}
	else if (yCenter < y1) {
		dy = y1 - yCenter;
	}
	else {
		dy = yCenter - y2;
	}
	double s = (double)(dy * dy) + (double)(dx * dx);
	if (s <= (double)(radius * radius)) {
		return true;
	}
	else {
		return false;
	}
}