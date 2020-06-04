#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "chess.h"


void main(){
	char o_col, n_col, o_col2, n_col2;
	int o_row, n_row, o_row2, n_row2;
	int x = 0; int y = 0;

	init_chessboard();
	print_chessboard();

	while (1 == 1) {

		while (x == 0) {
			o_col = 0; n_col = 0;
			printf(" Biely hrac: ");
			scanf("%c%d%c%d", &o_col, &o_row, &n_col, &n_row);
			getchar();
			o_col = o_col - 'a' + 1; n_col = n_col - 'a' + 1;
			if (move(o_col, o_row, n_col, n_row, WHITE_PLAYER_ID) == 1) {
				chessboard[n_col][n_row] = chessboard[o_col][o_row]; chessboard[o_col][o_row] = 0;
				CLEAR_SCREEN();
				print_chessboard();
				x = 1;
			}
			else {
				printf("Neplatny tah!!");
				getchar();
				CLEAR_SCREEN();
				print_chessboard();
			}		
		}
		while (y == 0) {
			o_col2 = 0; n_col2 = 0;
			printf(" Cierny hrac: ");
			scanf("%c%d%c%d", &o_col2, &o_row2, &n_col2, &n_row2);
			getchar();
			o_col2 = o_col2 - 96; n_col2 = n_col2 - 96;
			if (move(o_col2, o_row2, n_col2, n_row2, BLACK_PLAYER_ID) == 1) {
				chessboard[n_col2][n_row2] = chessboard[o_col2][o_row2]; chessboard[o_col2][o_row2] = 0;
				CLEAR_SCREEN();
				print_chessboard();
				y = 1;
			}
			else {
				printf("Neplatny tah!!");
				getchar();
				CLEAR_SCREEN();
				print_chessboard();
			}
		}
		x = 0; y = 0;
	}
	getchar();getchar();
}