#ifndef PLL_HEADER
#define PLL_HEADER

#include "Elements.h"
#include "Moves.h"

int PLLs[22][12]{
		{ R1, R2, R3, F1, F2, F3, L1, L2, L3, B1, B2, B3 },
		//--------------PERM A-----------------------------
		{ R1, R2, B3, B1, F2, F3, F1, L2, R3, L1, B2, L3 },
		{ L1, R2, F3, F1, F2, B3, B1, L2, L3, R1, B2, R3 },
		//-------------PERM E------------------------------
		{ B1, R2, F3, L1, F2, R3, F1, L2, B3, R1, B2, L3 },
		//-------------PERM F------------------------------
		{ R1, L2, B3, F1, F2, F3, B1, R2, L3, L1, B2, R3 },
		//-------------PERM G------------------------------
		{ R1, B2, L3, L1, F2, F3, B1, R2, B3, F1, L2, R3 },
		{ R1, R2, B3, B1, L2, F3, F1, B2, R3, L1, F2, L3 },
		{ R1, L2, B3, B1, F2, F3, L1, B2, R3, L1, R2, L3 },
		{ L1, B2, F3, F1, F2, B3, B1, R2, L3, R1, L2, R3 },
		//-------------PERM H------------------------------
		{ R1, L2, R3, F1, B2, F3, L1, R2, L3, B1, F2, B3 },
		//-------------PERM J------------------------------
		{ R1, R2, R3, L1, F2, F3, F1, B2, B3, B1, L2, L3 },
		{ B1, B2, F3, F1, F2, R3, L1, L2, L3, R1, R2, B3 },
		//-------------PERM N------------------------------
		{ R1, R2, L3, B1, B2, F3, L1, L2, R3, F1, F2, B3 },
		{ L1, R2, R3, F1, B2, B3, R1, L2, L3, B1, F2, F3 },
		//-------------PERM R------------------------------
		{ R1, F2, B3, F1, R2, F3, B1, L2, L3, L1, B2, R3 },
		{ R1, R2, B3, F1, L2, F3, B1, F2, L3, L1, B2, R3 },
		//-------------PERM T------------------------------
		{ B1, L2, B3, F1, F2, R3, L1, R2, L3, R1, B2, B3 },
		//-------------PERM U------------------------------
		{ R1, B2, R3, F1, F2, F3, L1, R2, L3, B1, L2, B3 },
		{ R1, L2, R3, F1, F2, F3, L1, B2, L3, B1, R2, B3 },
		//-------------PERM V------------------------------
		{ L1, R2, R3, F1, L2, B3, R1, F2, L3, B1, B2, F3 },
		//-------------PERM Y------------------------------
		{ L1, R2, R3, F1, F2, B3, R1, B2, L3, B1, L2, F3 },
		//-------------PERM Z------------------------------
		{ R1, F2, R3, F1, R2, F3, L1, B2, L3, B1, L2, B3 },
};

int solvePLL[22][18]{
		{ -1 },
		//--------------PERM A-----------------------------
		{ BP, R, BP, LL, B, RP, BP, LL, BB, -1 },
		{ B, LP, B, RR, BP, L, B, RR, BB, -1 },
		//-------------PERM E------------------------------
		{ R, BP, RP, F, R, B, RP, FP, R, B, RP, F, R, BP, RP, FP, -1 },
		//-------------PERM F------------------------------
		{ RP, U, R, UP, RR, FP, UP, F, U, R, F, RP, FP, RR, UP, -1 },
		//-------------PERM G------------------------------
		{ FP, UP, F, RR, D, BP, U, B, UP, B, DP, RR, -1 },
		{ R, U, RP, F2, DP, L, UP, LP, U, LP, D, FF, -1 },
		{ RR, D, BP, U, BP, UP, B, DP, RR, FP, U, F, -1 },
		{ LL, DP, B, UP, B, U, BP, D, LL, F, UP, FP, -1 },
		//-------------PERM H------------------------------
		{ RR, UU, RP, UU, RR, UU, RR, UU, RP, UU, RR, -1 },
		//-------------PERM J------------------------------
		{ RP, U, L, UP, R, UU, LP, U, L, UU, LP, -1 },
		{ L, UP, RP, UP, LP, UU, R, UP, RP, U2, R, -1 },
		//-------------PERM N------------------------------
		{ RP, U, LP, UU, R, UP, L, RP, U, LP, UU, R, UP, L, U, -1 },
		{ L, UP, R, UU, LP, U, RP, L , UP, R, UU, LP, U, RP, UP, -1 },
		//-------------PERM R------------------------------
		{ RP, UU, R, UU, RP, F, R, U, RP, UP, RP, FP, RR, UP, -1},
		{ L, UU, LP, UU, L, FP, LP, UP, L, U, L, F, LL, U, -1},
		//-------------PERM T------------------------------
		{ R, U, RP, UP, RP, F, R2, UP, RP, UP, R, U, RP, FP, -1 },
		//-------------PERM U------------------------------
		{ RP, U, RP, UP, RP, UP, RP, U, R, U, RR, -1 },
		{ RR, UP, RP, UP, R, U, R, U, R, UP, R, -1 },
		//-------------PERM V------------------------------
		{ LP, U, LP, UP, FP, LP, FF, UP, FP, U, FP, L, F, L, -1 },
		//-------------PERM Y------------------------------
		{ F, R, UP, RP, UP, R, U, RP, FP, R, U, RP, UP, RP, F, R, FP, -1},
		//-------------PERM Z------------------------------
		{ RP, UP, RR, U, R, U, RP, UP, R, U, R, UP, R, UP, RP, -1},
};

class PLL{
public:
	static void doPLL(char cube[55]){
		int pll = getPLL(cube);
		int uMoves = 0;
		while (pll == -1){
			uMoves++;
			Moves::doMove(cube, U);
			pll = getPLL(cube);
		}
		printf("Permutacja: ");
		if (uMoves == 1)
			printf("U ");
		else if (uMoves == 2)
			printf("U2 ");
		else if (uMoves == 3)
			printf("U' ");
		int i = 0;
		while (solvePLL[pll][i] != -1){
			Moves::doMove(cube, solvePLL[pll][i]);
			Moves::showMove(solvePLL[pll][i]);
			i++;
		}
		if (cube[F2] == 'O'){
			Moves::doMove(cube, U);
			printf("U ");
		}
		else if (cube[F2] == 'B'){
			Moves::doMove(cube, UU);
			printf("U2 ");
		}
		else if (cube[F2] == 'R'){
			Moves::doMove(cube, UP);
			printf("U' ");
		}
		printf("\n");
	}

	static int getPLL(char cube[55]){
		for (int i = 0; i < 22; i++){
			if (checkPLL(cube, PLLs[i]))
				return i;
		}
		return -1;
	}

	static bool checkPLL(char cube[55], int pll[12]){
		char tmp[4] = { 'R', 'G', 'O', 'B' };
		bool a = false;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 12; j++){
				if (cube[pll[j]] != tmp[j / 3]){
					a = false;
					break;
				}
				a = true;
			}
			if (a)
				return a;
			else {
				char c = tmp[0];
				tmp[0] = tmp[1];
				tmp[1] = tmp[2];
				tmp[2] = tmp[3];
				tmp[3] = c;
			}
		}
		return false;
	}
};

#endif