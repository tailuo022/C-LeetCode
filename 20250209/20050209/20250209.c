#define  _CRT_SECURE_NO_WARNINGS

// 289. 生命游戏

//int countLiveNeighbors(int** board, int i, int j, int rows, int cols) {
//	if (rows <= 0 || cols <= 0) {
//		return 0; 
//	}
//	int count = 0;
//	for (int x = (i - 1 < 0) ? 0 : i - 1; x <= (i + 1 <rows) ? i + 1 : rows - 1; x++) {
//		for (int y = (j - 1 < 0) ? 0 : j - 1; y <= (j + 1 < cols) ? j + 1 : cols - 1; y++) {
//			if (x >= 0 && x < rows && y >= 0 && y < cols && (x != i || y != j)) {
//				count += board[x][y] & 1;
//			}
//		}
//	}
//	return count;
//}
//
//void gameOfLife(int** board, int boardSize, int* boardColSize) {
//	int rows = boardSize;
//	int cols = *boardColSize;
//	int** nextBoard = (int**)malloc(sizeof(int*) * rows);
//	for (int i = 0; i < rows; i++) {
//		nextBoard[i] = (int*)malloc(sizeof(int) * cols);
//	}
//	for (int i = 0; i < boardSize; i++) {
//		for (int j = 0; j < *boardColSize; j++) {
//			int liveNeighbors = countLiveNeighbors(board, i, j, rows, cols);
//			if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
//				nextBoard[i][j] = 0;
//			}
//			else if (board[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
//				nextBoard[i][j] = 1;
//			}
//			else if (board[i][j] == 0 && liveNeighbors == 3) {
//				nextBoard[i][j] = 1;
//			}
//			else {
//				nextBoard[i][j] = 0;
//			}
//		}
//	}
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			board[i][j] = nextBoard[i][j];
//		}
//		free(nextBoard[i]);
//	}
//	free(nextBoard);
//}

//超时了

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int Count(int** board, int boardSize, int* boardColSize, int x, int y) {
	int sum = 0;
	int rx, ry;
	for (int i = 0; i < 8; i++) {
		rx = x + dx[i];
		ry = y + dy[i];
		if (rx < 0 || rx >= boardSize || ry < 0 || ry >= *boardColSize) {
			continue;
		}
		sum = sum + (board[rx][ry] & 1);
	}
	return sum;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			int num_live = Count(board, boardSize, boardColSize, i, j);
			if ((board[i][j] && num_live == 2) || num_live == 3) {
				board[i][j] |= 2;
			}
		}
	}
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			board[i][j] >>= 1;
		}
	}
}