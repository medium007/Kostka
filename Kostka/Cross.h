#ifndef CROSS_HEADER
#define CROSS_HEADER

#define MAX_MOVES_C 7
#include "Moves.h"

class Cross{
public:
	static void solveWhiteCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		srand(time(NULL));

		while (!isWhiteCrossMade(cube)){
			Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}

		printf("Bialy krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n");
	}

	static void solveYellowCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		//srand(time(NULL));
		int move = -1,
			moveP = -1;
		int k = 0;
		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		while (!isYellowCrossMade(cube)){
		Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}
		printf("Zolty krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n\n");
	}

	static void solveGreenCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		srand(time(NULL));

		while (!isGreenCrossMade(cube)){
			Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}

		printf("Zielony krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n");
	}

	static void solveBlueCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		srand(time(NULL));

		while (!isBlueCrossMade(cube)){
			Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}

		printf("Niebieski krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n\n");
	}

	static void solveRedCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		srand(time(NULL));

		while (!isRedCrossMade(cube)){
			Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}

		printf("Czerwony krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n\n");
	}

	static void solveOrangeCross(char cube[55]){

		int vMove[MAX_MOVES_C];
		bool doneMoves[MAX_MOVES_C][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_C; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
		}

		srand(time(NULL));

		while (!isOrangeCrossMade(cube)){
			Moves::randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
		}

		printf("Pomaranczowy krzyz: ");
		Moves::showSolution(vMove, MAX_MOVES_C);
		printf("\n\n");
	}

	static bool isWhiteCrossMade(char cube[55]){
		if (cube[1] != 'W')
			return false;
		if (cube[3] != 'W')
			return false;
		if (cube[5] != 'W')
			return false;
		if (cube[7] != 'W')
			return false;
		if (cube[10] != 'R')
			return false;
		if (cube[19] != 'G')
			return false;
		if (cube[37] != 'O')
			return false;
		if (cube[46] != 'B')
			return false;
		return true;
	}

	static bool isYellowCrossMade(char cube[55]){
		if (cube[28] != 'Y')
			return false;
		if (cube[30] != 'Y')
			return false;
		if (cube[32] != 'Y')
			return false;
		if (cube[34] != 'Y')
			return false;
		if (cube[16] != 'R')
			return false;
		if (cube[25] != 'G')
			return false;
		if (cube[43] != 'O')
			return false;
		if (cube[52] != 'B')
			return false;
		return true;
	}

	static bool isGreenCrossMade(char cube[55]){
		if (cube[19] != 'G')
			return false;
		if (cube[21] != 'G')
			return false;
		if (cube[23] != 'G')
			return false;
		if (cube[25] != 'G')
			return false;
		if (cube[12] != 'R')
			return false;
		if (cube[7] != 'W')
			return false;
		if (cube[41] != 'O')
			return false;
		if (cube[28] != 'Y')
			return false;
		return true;
	}

	static bool isBlueCrossMade(char cube[55]){
		if (cube[46] != 'B')
			return false;
		if (cube[48] != 'B')
			return false;
		if (cube[50] != 'B')
			return false;
		if (cube[52] != 'B')
			return false;
		if (cube[14] != 'R')
			return false;
		if (cube[1] != 'W')
			return false;
		if (cube[39] != 'O')
			return false;
		if (cube[34] != 'Y')
			return false;
		return true;
	}

	static bool isRedCrossMade(char cube[55]){
		if (cube[10] != 'R')
			return false;
		if (cube[12] != 'R')
			return false;
		if (cube[14] != 'R')
			return false;
		if (cube[16] != 'R')
			return false;
		if (cube[5] != 'W')
			return false;
		if (cube[23] != 'G')
			return false;
		if (cube[32] != 'Y')
			return false;
		if (cube[48] != 'B')
			return false;
		return true;
	}

	static bool isOrangeCrossMade(char cube[55]){
		if (cube[37] != 'O')
			return false;
		if (cube[39] != 'O')
			return false;
		if (cube[41] != 'O')
			return false;
		if (cube[43] != 'O')
			return false;
		if (cube[3] != 'W')
			return false;
		if (cube[21] != 'G')
			return false;
		if (cube[30] != 'Y')
			return false;
		if (cube[50] != 'B')
			return false;
		return true;
	}
};

#endif