#include "chess.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>



int chessboard[L][L];

void init_chessboard(){
	int r,s;

	for (r = L; r >= 1; r--) {
		for (s = 1; s <= L; s++) {

			if (r != 3 && r != 6)
				chessboard[s][r] = EMPTY_SQUARE;
			if (r == 2)
				chessboard[s][r] = W_PAWN;
			if (r == 7)
				chessboard[s][r] = B_PAWN;
		}
	}
	chessboard[1][1] = W_ROOK; 		chessboard[8][1] = W_ROOK;
	chessboard[2][1] = W_KNIGHT; 	chessboard[7][1] = W_KNIGHT;
	chessboard[3][1] = W_BISHOP; 	chessboard[6][1] = W_BISHOP;
	chessboard[5][1] = W_QUEEN; 	chessboard[4][1] = W_KING;

	chessboard[1][8] = B_ROOK; 		chessboard[8][8] = B_ROOK;
	chessboard[2][8] = B_KNIGHT; 	chessboard[7][8] = B_KNIGHT;
	chessboard[3][8] = B_BISHOP; 	chessboard[6][8] = B_BISHOP;
	chessboard[4][8] = B_QUEEN; 	chessboard[5][8] = B_KING;
}

void print_chessboard() {
	int r, s;
	printf("	    CIERNY\n");
	for (r = L; r >= 1; r--) {
		printf("\n");
		for (s = 1; s <= L; s++) {
			if (s == 1)
				printf("%d   ", r);
			if (chessboard[s][r] == EMPTY_SQUARE)
				printf("[ ]");

			if (chessboard[s][r] == W_PAWN)
				printf("[P]");
			if (chessboard[s][r] == W_ROOK)
				printf("[V]");
			if (chessboard[s][r] == W_KNIGHT)
				printf("[J]");
			if (chessboard[s][r] == W_BISHOP)
				printf("[S]");
			if (chessboard[s][r] == W_QUEEN)
				printf("[D]");
			if (chessboard[s][r] == W_KING)
				printf("[K]");

			if (chessboard[s][r] == B_PAWN)
				printf("[p]");
			if (chessboard[s][r] == B_ROOK)
				printf("[v]");
			if (chessboard[s][r] == B_KNIGHT)
				printf("[j]");
			if (chessboard[s][r] == B_BISHOP)
				printf("[s]");
			if (chessboard[s][r] == B_QUEEN)
				printf("[d]");
			if (chessboard[s][r] == B_KING)
				printf("[k]");
		}
	}
	printf("\n\n     a  b  c  d  e  f  g  h");
	printf("\n\n	    BIELY\n");
}


int knight(int scol, int srow, int tcol, int trow){
	if (abs(scol-tcol)==2 && abs(srow - trow) == 1 || abs(scol - tcol) == 1 && abs(srow - trow) == 2)
		return 1;
	else return 0;
}

int king(int scol, int srow, int tcol, int trow){
	if (abs(tcol - scol) <= 1 && abs(trow - srow) <= 1)
		return 1;
	else return 0;
}

int bishop(int scol, int srow, int tcol, int trow) {
	int row;
	if (abs(tcol - scol) == abs(trow - srow)) {

		if (tcol > scol && trow > srow) {
			row = srow + 1;
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][row] != 0)
					return 0;
				else row++;
			}
		}
		if (tcol < scol && trow < srow) {
			row = srow - 1;
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row--;
				}
			}
		}
		if (tcol > scol && trow < srow) {
			row = srow - 1;
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row--;
				}
			}
		}
		if (tcol < scol && trow > srow) {
			row = srow + 1;
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row++;
				}
			}
		}
		return 1;
	}

	return 0;
}

int rook(int scol, int srow, int tcol, int trow){
	if (scol == tcol || srow == trow) {

		if (tcol == scol && trow > srow) {
			for (int i = srow + 1; i <= trow - 1; i++) {
				if (chessboard[scol][i] != 0)
					return 0;
			}
		}
		if (tcol == scol && trow < srow) {
			for (int i = srow - 1; i >= trow + 1; i--) {
				if (chessboard[scol][i] != 0)
					return 0;
			}
		}
		if (tcol > scol && trow == srow) {
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][srow] != 0)
					return 0;
			}
		}
		if (tcol < scol && trow == srow) {
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][srow] != 0)
					return 0;
			}
		}
		return 1;
	}
	return 0;
}

int queen(int scol, int srow, int tcol, int trow){

	if (scol == tcol || srow == trow || abs(tcol - scol) == abs(trow - srow)) {
		
		int row;
		if (tcol == scol && trow > srow) {
			for (int i = srow + 1; i <= trow - 1; i++) {
				if (chessboard[scol][i] != 0)
					return 0;
			}
		}
		if (tcol == scol && trow < srow) {
			for (int i = srow - 1; i >= trow + 1; i--) {
				if (chessboard[scol][i] != 0)
					return 0;
			}
		}
		if (tcol > scol && trow == srow) {
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][srow] != 0)
					return 0;
			}
		}
		if (tcol < scol && trow == srow) {
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][srow] != 0)
					return 0;
			}
		}

		if (tcol > scol && trow > srow) {
			row = srow + 1;
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][row] != 0)
					return 0;
				else row++;
			}
		}
		if (tcol < scol && trow < srow) {
			row = srow - 1;
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row--;
				}
			}
		}
		if (tcol > scol && trow < srow) {
			row = srow - 1;
			for (int i = scol + 1; i <= tcol - 1; i++) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row--;
				}
			}
		}
		if (tcol < scol && trow > srow) {
			row = srow + 1;
			for (int i = scol - 1; i >= tcol + 1; i--) {
				if (chessboard[i][row] != 0)
					return 0;
				else {
					row++;
				}
			}
		}
		return 1;
	}
	return 0;
}

int pawn(int scol, int srow, int tcol, int trow){
	if (srow == 2 || srow == 7) {
		if (trow - srow - chessboard[scol][srow] == 1 || trow - srow - chessboard[scol][srow] == -1 || trow - srow - chessboard[scol][srow] == 0) {
			if (scol == tcol) {
				if (chessboard[tcol][trow] == 0)
					return 1;
			}
		}
	}
	else if (trow - srow - chessboard[scol][srow] == 0) {
		if (scol == tcol) {
			if (chessboard[tcol][trow] == 0)
				return 1;
		}
	}	
	if (abs(tcol - scol) == 1 && chessboard[tcol][trow] != 0)
		return 1;

	else return 0;
}


int move(int scol, int srow, int tcol, int trow, int p_id) {
	int i = 0;

	if (srow > 8 || srow < 1 || trow > 8 || trow < 1 || scol > 8 || scol < 1 || tcol > 8 || tcol < 1)
		return 0;
	if (chessboard[scol][srow] == 0) 
		return 0;
	if (scol == tcol && srow == trow) 
		return 0;
	if (p_id == WHITE_PLAYER_ID && (chessboard[scol][srow] < 0 || chessboard[tcol][trow] > 0))
		return 0;
	if (p_id == BLACK_PLAYER_ID && (chessboard[scol][srow] > 0 || chessboard[tcol][trow] < 0))
		return 0;

	switch (abs(chessboard[scol][srow])) {
	case W_KNIGHT:
		if (knight(scol, srow, tcol, trow) == 0) 
			return 0;
		else return 1;
		break;

	case W_KING:
		if (king(scol, srow, tcol, trow) == 0)
			return 0;
		else return 1;
		break;
	
	case W_BISHOP:
		if (bishop(scol, srow, tcol, trow) == 0)
			return 0;
		else return 1;
		break;
	
	case W_ROOK:
		if (rook(scol, srow, tcol, trow) == 0)
			return 0;
		else return 1;
		break;
	
	case W_QUEEN:
		if (queen(scol, srow, tcol, trow) == 0) 
			return 0;
		else return 1;
		break;

	case W_PAWN:
		if (pawn(scol, srow, tcol, trow) == 0)
			return 0;
		else return 1;
		break;

	}
	return 1;
}