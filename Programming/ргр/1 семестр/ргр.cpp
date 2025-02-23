#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
int board[BOARD_HEIGHT][BOARD_WIDTH] = { 0 };

int currentPiece[4][4] = { 0 };
int currentPieceX = 0;
int currentPieceY = 0;

int nextPiece[4][4] = { 0 };

int gameRunning = 1;
 
void clearPiece()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			currentPiece[i][j] = 0;
		}
	}
}
void clearBoard() {
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			board[i][j] = 0;
		}
	}
}
void drawPiece(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (currentPiece[i][j] != 0)
			{
				board[y + i][x + j] = currentPiece[i][j];
			}
		}
	}
}
void erasePiece(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (currentPiece[i][j] != 0)
			{
				board[y + i][x + j] = 0;
			}
		}
	}
}
int checkCollision(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (currentPiece[i][j] != 0)
			{
				if (x + j < 0 || x + j >= BOARD_WIDTH || y + i >= BOARD_HEIGHT || (y + i >= 0 && board[y + i][x + j] != 0))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
void rotatePiece()
{
	int tempPiece[4][4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempPiece[i][j] = tempPiece[3 - j][i];
		}
	}
}
void spawnPiece() {
    clearPiece();

    currentPieceX = BOARD_WIDTH / 2 - 2;
    currentPieceY = 0;

    if (checkCollision(currentPieceX, currentPieceY)) {
        gameRunning = 0;
    }
}

void drawBoard() {
    system("cls");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] != 0) {
                printf("[]");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void gameLoop() {
    while (gameRunning) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'a') {
                if (!checkCollision(currentPieceX - 1, currentPieceY)) {
                    erasePiece(currentPieceX, currentPieceY);
                    currentPieceX--;
                    drawPiece(currentPieceX, currentPieceY);
                }
            }
            if (key == 'd') {
                if (!checkCollision(currentPieceX + 1, currentPieceY)) {
                    erasePiece(currentPieceX, currentPieceY);
                    currentPieceX++;
                    drawPiece(currentPieceX, currentPieceY);
                }
            }
            if (key == 's') {
                if (!checkCollision(currentPieceX, currentPieceY + 1)) {
                    erasePiece(currentPieceX, currentPieceY);
                    currentPieceY++;
                    drawPiece(currentPieceX, currentPieceY);
                }
            }
            if (key == 'w') {
                rotatePiece();
                if (checkCollision(currentPieceX, currentPieceY)) {
                    rotatePiece();
                }
                else {
                    erasePiece(currentPieceX, currentPieceY);
                    drawPiece(currentPieceX, currentPieceY);
                }
            }
        }

       

        drawBoard();
        Sleep(500);
    }
}

int main() {
    clearBoard();
    spawnPiece();

    gameLoop();

    return 0;
}