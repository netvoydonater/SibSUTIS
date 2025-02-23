#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define min(i, j) (((i) < (j)) ? (i) : (j))
#define max(i, j) (((i) > (j)) ? (i) : (j))

#define BOARD_SIZE 3

//функция проверки окончания игры
//возвращает 0, если игра не завершена, 1 если игрок выиграл, 2 если ничья, и 3 если компьютер выиграет
int Check_Win(char board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++) //проверка строк
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X') return 1;
			else if (board[i][0] == 'O') return 3;
		}
	}
	for (j = 0; j < BOARD_SIZE; j++) //проверка столбцов
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] == 'X') return 1;
			else if (board[0][j] == 'O') return 3;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X') return 1;
		else if (board[0][0] == 'O') return 3;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X') return 1;
		else if (board[0][2] == 'O') return 3;
	}
	for (i = 0; i < BOARD_SIZE; i++) //проверка на ничью
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
		}
	}
	return 2;
}

void Board_Initializer(char board[][BOARD_SIZE])
{
	char index = '-';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = index;
		}
	}
}

void Print_Board(char board[][BOARD_SIZE])
{
	printf("+-----+-----+\n");
	printf("|");
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			printf(" %c |", board[i][j]);
		}
		puts("");
		printf("+-----+-----+\n");
		if (i < BOARD_SIZE - 1)
		{
			printf("|");
		}
	}
}

//приветствие
int Welcome(char board[][BOARD_SIZE])
{
	char choise = 0;
	while (choise != 's')
	{
		printf("Welcome to Tic-Tac-Toe game!\nPress 's' to start, 'q' to exit, 'r' to rules\n");
		scanf_s("%c", &choise);
		if (choise == 'q')
		{
			exit(0);
		}
		else if (choise == 'r')
		{
			puts("Rules:\nThe board has the form");
			Print_Board(board);
			puts("You choose row and column where do you want to put 'X'");
			puts("The game ends when someone wins or a tie");
			puts("Good luck!");
		}
	}
}

//выбор позиции игрока
void get_user_move(char board[][BOARD_SIZE], int* row, int* col)
{
	int valid_move = 0;
	while (!valid_move)
	{
		printf("Enter row and column (1-%d): ", BOARD_SIZE);
		scanf_s("%d %d", row, col);
		(*row)--;
		(*col)--;
		if (*row < 0 || *row >= BOARD_SIZE || *col < 0 || *col >= BOARD_SIZE)
		{
			printf("Invalid move. Please try again.\n");

		}
		else if (board[*row][*col] == 'X' || board[*row][*col] == 'O')
		{
			printf("That square is already taken. Please try again.\n");
		}
		else valid_move = 1;
	}

}

////функция оценки результатов на поле
int evalute_board(char board[][BOARD_SIZE]) 
{
	int i, j, score = 0;
	for (i = 0; i < BOARD_SIZE; i++) //проверка строк
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'O') score += 10;
			else if (board[i][0] == 'X') score -= 10;
		}
	}
	for (j = 0; j < BOARD_SIZE; j++) //проверка столбцов
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] == 'O') score += 10;
			else if (board[0][j] == 'X') score -= 10;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) //проверка диагоналей
	{
		if (board[0][0] == 'O') score += 10;
		else if (board[0][0] == 'X') score -= 10;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'O') score += 10;
		else if (board[0][2] == 'X') score -= 10;
	}
	return score;
}

//Функция поиска лучшего хода для компьютера с использованием алгоритма альфа-бета.
int find_best_move(char board[][BOARD_SIZE], int depth, int alpha, int beta, int is_max, int MAX_DEPTH)// MAX_DEPTH цифры соответствуют максимальной глубине просмотра вариантов.
{
	int i, j, score, best_score, best_row = -1, best_col = -1;
	int game_result = Check_Win(board);
	if (depth == 0 || game_result != 0)
	{
		return evalute_board(board);
	}
	if (is_max)
	{
		best_score = INT_MIN;
		for (i = 0; i < BOARD_SIZE; i++)
		{
			for (j = 0; j < BOARD_SIZE; j++)
			{
				if (board[i][j] != 'X' && board[i][j] != 'O')
				{
					board[i][j] = 'O';
					score = find_best_move(board, depth - 1, alpha, beta, ~is_max, MAX_DEPTH); //~is_max = !is_max;
					board[i][j] = '-';
					if (score > best_score)
					{
						best_score = score;
						best_row = i;
						best_col = j;
					}
					alpha = max(alpha, best_score);
					if (alpha >= beta) break;
				}
			}
			if (alpha >= beta) break;
		}
		if (depth == MAX_DEPTH)
		{
			printf("Computer chooses (%d, %d)\n", best_row + 1, best_col + 1);
			board[best_row][best_col] = 'O';
		}
		return best_score;
	}
	else
	{
		best_score = INT_MAX;
		for (i = 0; i < BOARD_SIZE; i++)
		{
			for (j = 0; j < BOARD_SIZE; j++)
			{
				if (board[i][j] != 'X' && board[i][j] != 'O')
				{
					board[i][j] = 'X';
					score = find_best_move(board, depth - 1, alpha, beta, ~is_max, MAX_DEPTH); //~is_max = !is_max;
					board[i][j] = '-';
					if (score < best_score)
					{
						best_score = score;
					}
					beta = min(beta, best_score);
					if (alpha >= beta) break;
				}
			}
			if (alpha >= beta) break;
		}
		return best_score;
	}
}

//выбор уровня сложности игры
void difficulty(int* MAX_DEPTH)
{
	printf("Choose the difficulty from 1 to 10:\n");
	scanf_s("%d", MAX_DEPTH);
	if (*MAX_DEPTH < 1 || *MAX_DEPTH > 10)
	{
		printf("Difficulty must be form 1 to 10, try again\n");
		difficulty(MAX_DEPTH);
	}
	else *MAX_DEPTH = *MAX_DEPTH;
}

int main()
{
	int row, col, MAX_DEPTH;
	char board[BOARD_SIZE][BOARD_SIZE];
	Board_Initializer(board);
	Welcome(board);
	difficulty(&MAX_DEPTH);

	Print_Board(board);

	while (1) //игровой цикл
	{
		get_user_move(board, &row, &col); //очередь пользователя
		board[row][col] = 'X';
		Print_Board(board);
		if (Check_Win(board) != 0) break;
		find_best_move(board, MAX_DEPTH, INT_MIN, INT_MAX, 1, MAX_DEPTH); //очередь компьютера
		Print_Board(board);
		if (Check_Win(board) != 0) break;
	}
	//игра окончена
	int game_result = Check_Win(board);
	if (game_result == 1)
	{
		printf("You win!\n");

	}
	else if (game_result == 3)
	{
		printf("Computer wins!\n");
	}
	else printf("It's a draw!\n");
	return 0;
}