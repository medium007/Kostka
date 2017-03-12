#ifndef MOVES_HEADER
#define MOVES_HEADER

#define U 0
#define UP 1
#define UU 2
#define D 3
#define DP 4
#define DD 5
#define B 6
#define BP 7
#define BB 8
#define F 9
#define FP 10
#define FF 11
#define R 12
#define RP 13
#define RR 14
#define L 15
#define LP 16
#define LL 17

class Moves{
public:

	static void showSolution(int vMove[], int maxMoves){
		for (int i = 0; i < maxMoves; i++){
			showMove(vMove[i]);
		}
		printf("\n");
	}

	static void prevState(char cube[55], bool doneMoves[][18], int vMove[], int& moveP, int& k){
		clearAllMoves(doneMoves[k]);
		vMove[k] = -1;
		if (k > 0){
			k--;
			doMoveP(cube, moveP);
			vMove[k] = -1;
			moveP = vMove[k - 1];
			if (allMovesDone(doneMoves[k])){
				prevState(cube, doneMoves, vMove, moveP, k);
			}
		}
	}

	static void randMove(char cube[55], int maxMoves, int& k, int& move, int& moveP, int vMove[], bool doneMoves[][18]){
		if (k == maxMoves){
			k--;
			doMoveP(cube, moveP);
			vMove[k] = -1;
			moveP = vMove[k - 1];
			if (allMovesDone(doneMoves[k])){
				prevState(cube, doneMoves, vMove, moveP, k);
			}
		}
		move = -1;
		do{
			//move = rand() % 18;
			move++;
		} while (doneMoves[k][move] || !checkMoves(move, moveP));
		doMove(cube, move);
		doneMoves[k][move] = true;
		vMove[k] = move;
		moveP = move;
		k++;
		if (k < maxMoves)
			clearMoves(doneMoves[k], moveP);
	}

	static void showMove(int move){
		switch (move){
		case U:
			printf("U ");
			break;
		case UP:
			printf("U' ");
			break;
		case UU:
			printf("U2 ");
			break;
		case R:
			printf("R ");
			break;
		case RP:
			printf("R' ");
			break;
		case RR:
			printf("R2 ");
			break;
		case F:
			printf("F ");
			break;
		case FP:
			printf("F' ");
			break;
		case FF:
			printf("F2 ");
			break;
		case D:
			printf("D ");
			break;
		case DP:
			printf("D' ");
			break;
		case DD:
			printf("D2 ");
			break;
		case L:
			printf("L ");
			break;
		case LP:
			printf("L' ");
			break;
		case LL:
			printf("L2 ");
			break;
		case B:
			printf("B ");
			break;
		case BP:
			printf("B' ");
			break;
		case BB:
			printf("B2 ");
			break;
		};
	}

	static bool checkMoves(int move, int moveP){
		switch (move){
		case U:
		case UP:
		case UU:
			if (moveP == U || moveP == UP || moveP == UU)
				return false;
			break;
		case D:
		case DP:
		case DD:
			if (moveP == D || moveP == DP || moveP == DD)
				return false;
			break;
		case B:
		case BP:
		case BB:
			if (moveP == B || moveP == BP || moveP == BB)
				return false;
			break;
		case F:
		case FP:
		case FF:
			if (moveP == F || moveP == FP || moveP == FF)
				return false;
			break;
		case R:
		case RP:
		case RR:
			if (moveP == R || moveP == RP || moveP == RR)
				return false;
			break;
		case L:
		case LP:
		case LL:
			if (moveP == L || moveP == LP || moveP == LL)
				return false;
			break;
		};
		return true;
	}

	static bool allMovesDone(bool moves[18]){
		for (int i = 0; i < 18; i++){
			if (moves[i] == false)
				return false;
		}
		return true;
	}

	static void clearAllMoves(bool moves[18]){
		for (int i = 0; i < 18; i++){
			moves[i] = false;
		}
	}

	static void clearMoves(bool moves[18], int moveP){
		clearAllMoves(moves);
		switch (moveP){
		case U:
		case UP:
		case UU:
			moves[U] = true;
			moves[UP] = true;
			moves[UU] = true;
			break;
		case D:
		case DP:
		case DD:
			moves[D] = true;
			moves[DP] = true;
			moves[DD] = true;
			break;
		case B:
		case BP:
		case BB:
			moves[B] = true;
			moves[BP] = true;
			moves[BB] = true;
			break;
		case F:
		case FP:
		case FF:
			moves[F] = true;
			moves[FP] = true;
			moves[FF] = true;
			break;
		case R:
		case RP:
		case RR:
			moves[R] = true;
			moves[RP] = true;
			moves[RR] = true;
			break;
		case L:
		case LP:
		case LL:
			moves[L] = true;
			moves[LP] = true;
			moves[LL] = true;
			break;
		};
	}

	static void doMoveP(char cube[55], int moveP){
		switch (moveP){
		case U:
			moveUp(cube);
			break;
		case UP:
			moveU(cube);
			break;
		case UU:
			moveU2(cube);
			break;
		case D:
			moveDp(cube);
			break;
		case DP:
			moveD(cube);
			break;
		case DD:
			moveD2(cube);
			break;
		case B:
			moveBp(cube);
			break;
		case BP:
			moveB(cube);
			break;
		case BB:
			moveB2(cube);
			break;
		case F:
			moveFp(cube);
			break;
		case FP:
			moveF(cube);
			break;
		case FF:
			moveF2(cube);
			break;
		case R:
			moveRp(cube);
			break;
		case RP:
			moveR(cube);
			break;
		case RR:
			moveR2(cube);
			break;
		case L:
			moveLp(cube);
			break;
		case LP:
			moveL(cube);
			break;
		case LL:
			moveL2(cube);
			break;
		};
	}

	static void doMove(char cube[55], int moveP){
		switch (moveP){
		case U:
			moveU(cube);
			break;
		case UP:
			moveUp(cube);
			break;
		case UU:
			moveU2(cube);
			break;
		case D:
			moveD(cube);
			break;
		case DP:
			moveDp(cube);
			break;
		case DD:
			moveD2(cube);
			break;
		case B:
			moveB(cube);
			break;
		case BP:
			moveBp(cube);
			break;
		case BB:
			moveB2(cube);
			break;
		case F:
			moveF(cube);
			break;
		case FP:
			moveFp(cube);
			break;
		case FF:
			moveF2(cube);
			break;
		case R:
			moveR(cube);
			break;
		case RP:
			moveRp(cube);
			break;
		case RR:
			moveR2(cube);
			break;
		case L:
			moveL(cube);
			break;
		case LP:
			moveLp(cube);
			break;
		case LL:
			moveL2(cube);
			break;
		};
	}

	static void scrambleTest(char cube[55]){
		moveU2(cube);  moveRp(cube); moveU(cube); moveL(cube); moveUp(cube); moveR(cube); moveU2(cube);
		moveLp(cube); moveU(cube); moveL(cube); moveU2(cube); moveLp(cube); moveU2(cube);
	}

private:
	static void moveU(char cube[55]){
		char tmp = cube[0];
		cube[0] = cube[6];
		cube[6] = cube[8];
		cube[8] = cube[2];
		cube[2] = tmp;

		tmp = cube[1];
		cube[1] = cube[3];
		cube[3] = cube[7];
		cube[7] = cube[5];
		cube[5] = tmp;

		tmp = cube[9];
		cube[9] = cube[45];
		cube[45] = cube[36];
		cube[36] = cube[18];
		cube[18] = tmp;

		tmp = cube[11];
		cube[11] = cube[47];
		cube[47] = cube[38];
		cube[38] = cube[20];
		cube[20] = tmp;

		tmp = cube[10];
		cube[10] = cube[46];
		cube[46] = cube[37];
		cube[37] = cube[19];
		cube[19] = tmp;
	}

	static void moveUp(char cube[55]){
		char tmp = cube[0];
		cube[0] = cube[2];
		cube[2] = cube[8];
		cube[8] = cube[6];
		cube[6] = tmp;

		tmp = cube[1];
		cube[1] = cube[5];
		cube[5] = cube[7];
		cube[7] = cube[3];
		cube[3] = tmp;

		tmp = cube[9];
		cube[9] = cube[18];
		cube[18] = cube[36];
		cube[36] = cube[45];
		cube[45] = tmp;

		tmp = cube[11];
		cube[11] = cube[20];
		cube[20] = cube[38];
		cube[38] = cube[47];
		cube[47] = tmp;

		tmp = cube[10];
		cube[10] = cube[19];
		cube[19] = cube[37];
		cube[37] = cube[46];
		cube[46] = tmp;
	}

	static void moveU2(char cube[55]){
		char tmp = cube[0];
		cube[0] = cube[8];
		cube[8] = tmp;

		tmp = cube[2];
		cube[2] = cube[6];
		cube[6] = tmp;

		tmp = cube[1];
		cube[1] = cube[7];
		cube[7] = tmp;

		tmp = cube[3];
		cube[3] = cube[5];
		cube[5] = tmp;

		tmp = cube[9];
		cube[9] = cube[36];
		cube[36] = tmp;

		tmp = cube[18];
		cube[18] = cube[45];
		cube[45] = tmp;

		tmp = cube[11];
		cube[11] = cube[38];
		cube[38] = tmp;

		tmp = cube[20];
		cube[20] = cube[47];
		cube[47] = tmp;

		tmp = cube[10];
		cube[10] = cube[37];
		cube[37] = tmp;

		tmp = cube[19];
		cube[19] = cube[46];
		cube[46] = tmp;
	}

	static void moveR(char cube[55]){
		char tmp = cube[9];
		cube[9] = cube[15];
		cube[15] = cube[17];
		cube[17] = cube[11];
		cube[11] = tmp;

		tmp = cube[10];
		cube[10] = cube[12];
		cube[12] = cube[16];
		cube[16] = cube[14];
		cube[14] = tmp;

		tmp = cube[2];
		cube[2] = cube[20];
		cube[20] = cube[29];
		cube[29] = cube[51];
		cube[51] = tmp;

		tmp = cube[8];
		cube[8] = cube[26];
		cube[26] = cube[35];
		cube[35] = cube[45];
		cube[45] = tmp;

		tmp = cube[5];
		cube[5] = cube[23];
		cube[23] = cube[32];
		cube[32] = cube[48];
		cube[48] = tmp;
	}

	static void moveRp(char cube[55]){
		char tmp = cube[9];
		cube[9] = cube[11];
		cube[11] = cube[17];
		cube[17] = cube[15];
		cube[15] = tmp;

		tmp = cube[10];
		cube[10] = cube[14];
		cube[14] = cube[16];
		cube[16] = cube[12];
		cube[12] = tmp;

		tmp = cube[2];
		cube[2] = cube[51];
		cube[51] = cube[29];
		cube[29] = cube[20];
		cube[20] = tmp;

		tmp = cube[8];
		cube[8] = cube[45];
		cube[45] = cube[35];
		cube[35] = cube[26];
		cube[26] = tmp;

		tmp = cube[5];
		cube[5] = cube[48];
		cube[48] = cube[32];
		cube[32] = cube[23];
		cube[23] = tmp;
	}

	static void moveR2(char cube[55]){
		char tmp = cube[9];
		cube[9] = cube[17];
		cube[17] = tmp;

		tmp = cube[11];
		cube[11] = cube[15];
		cube[15] = tmp;

		tmp = cube[10];
		cube[10] = cube[16];
		cube[16] = tmp;

		tmp = cube[12];
		cube[12] = cube[14];
		cube[14] = tmp;

		tmp = cube[2];
		cube[2] = cube[29];
		cube[29] = tmp;

		tmp = cube[20];
		cube[20] = cube[51];
		cube[51] = tmp;

		tmp = cube[8];
		cube[8] = cube[35];
		cube[35] = tmp;

		tmp = cube[26];
		cube[26] = cube[45];
		cube[45] = tmp;

		tmp = cube[5];
		cube[5] = cube[32];
		cube[32] = tmp;

		tmp = cube[23];
		cube[23] = cube[48];
		cube[48] = tmp;
	}

	static void moveF(char cube[55]){
		char tmp = cube[18];
		cube[18] = cube[24];
		cube[24] = cube[26];
		cube[26] = cube[20];
		cube[20] = tmp;

		tmp = cube[19];
		cube[19] = cube[21];
		cube[21] = cube[25];
		cube[25] = cube[23];
		cube[23] = tmp;

		tmp = cube[6];
		cube[6] = cube[44];
		cube[44] = cube[29];
		cube[29] = cube[9];
		cube[9] = tmp;

		tmp = cube[8];
		cube[8] = cube[38];
		cube[38] = cube[27];
		cube[27] = cube[15];
		cube[15] = tmp;

		tmp = cube[7];
		cube[7] = cube[41];
		cube[41] = cube[28];
		cube[28] = cube[12];
		cube[12] = tmp;
	}

	static void moveFp(char cube[55]){
		char tmp = cube[18];
		cube[18] = cube[20];
		cube[20] = cube[26];
		cube[26] = cube[24];
		cube[24] = tmp;

		tmp = cube[19];
		cube[19] = cube[23];
		cube[23] = cube[25];
		cube[25] = cube[21];
		cube[21] = tmp;

		tmp = cube[6];
		cube[6] = cube[9];
		cube[9] = cube[29];
		cube[29] = cube[44];
		cube[44] = tmp;

		tmp = cube[8];
		cube[8] = cube[15];
		cube[15] = cube[27];
		cube[27] = cube[38];
		cube[38] = tmp;

		tmp = cube[7];
		cube[7] = cube[12];
		cube[12] = cube[28];
		cube[28] = cube[41];
		cube[41] = tmp;
	}

	static void moveF2(char cube[55]){
		char tmp = cube[18];
		cube[18] = cube[26];
		cube[26] = tmp;

		tmp = cube[20];
		cube[20] = cube[24];
		cube[24] = tmp;

		tmp = cube[19];
		cube[19] = cube[25];
		cube[25] = tmp;

		tmp = cube[21];
		cube[21] = cube[23];
		cube[23] = tmp;

		tmp = cube[6];
		cube[6] = cube[29];
		cube[29] = tmp;

		tmp = cube[9];
		cube[9] = cube[44];
		cube[44] = tmp;

		tmp = cube[8];
		cube[8] = cube[27];
		cube[27] = tmp;

		tmp = cube[15];
		cube[15] = cube[38];
		cube[38] = tmp;

		tmp = cube[7];
		cube[7] = cube[28];
		cube[28] = tmp;

		tmp = cube[12];
		cube[12] = cube[41];
		cube[41] = tmp;
	}

	static void moveD(char cube[55]){
		char tmp = cube[27];
		cube[27] = cube[33];
		cube[33] = cube[35];
		cube[35] = cube[29];
		cube[29] = tmp;

		tmp = cube[28];
		cube[28] = cube[30];
		cube[30] = cube[34];
		cube[34] = cube[32];
		cube[32] = tmp;

		tmp = cube[15];
		cube[15] = cube[24];
		cube[24] = cube[42];
		cube[42] = cube[51];
		cube[51] = tmp;

		tmp = cube[17];
		cube[17] = cube[26];
		cube[26] = cube[44];
		cube[44] = cube[53];
		cube[53] = tmp;

		tmp = cube[16];
		cube[16] = cube[25];
		cube[25] = cube[43];
		cube[43] = cube[52];
		cube[52] = tmp;
	}

	static void moveDp(char cube[55]){
		char tmp = cube[27];
		cube[27] = cube[29];
		cube[29] = cube[35];
		cube[35] = cube[33];
		cube[33] = tmp;

		tmp = cube[28];
		cube[28] = cube[32];
		cube[32] = cube[34];
		cube[34] = cube[30];
		cube[30] = tmp;

		tmp = cube[15];
		cube[15] = cube[51];
		cube[51] = cube[42];
		cube[42] = cube[24];
		cube[24] = tmp;

		tmp = cube[17];
		cube[17] = cube[53];
		cube[53] = cube[44];
		cube[44] = cube[26];
		cube[26] = tmp;

		tmp = cube[16];
		cube[16] = cube[52];
		cube[52] = cube[43];
		cube[43] = cube[25];
		cube[25] = tmp;
	}

	static void moveD2(char cube[55]){
		char tmp = cube[27];
		cube[27] = cube[35];
		cube[35] = tmp;

		tmp = cube[29];
		cube[29] = cube[33];
		cube[33] = tmp;

		tmp = cube[28];
		cube[28] = cube[34];
		cube[34] = tmp;

		tmp = cube[30];
		cube[30] = cube[32];
		cube[32] = tmp;

		tmp = cube[15];
		cube[15] = cube[42];
		cube[42] = tmp;

		tmp = cube[24];
		cube[24] = cube[51];
		cube[51] = tmp;

		tmp = cube[17];
		cube[17] = cube[44];
		cube[44] = tmp;

		tmp = cube[26];
		cube[26] = cube[53];
		cube[53] = tmp;

		tmp = cube[16];
		cube[16] = cube[43];
		cube[43] = tmp;

		tmp = cube[25];
		cube[25] = cube[52];
		cube[52] = tmp;
	}

	static void moveL(char cube[55]){
		char tmp = cube[36];
		cube[36] = cube[42];
		cube[42] = cube[44];
		cube[44] = cube[38];
		cube[38] = tmp;

		tmp = cube[37];
		cube[37] = cube[39];
		cube[39] = cube[43];
		cube[43] = cube[41];
		cube[41] = tmp;

		tmp = cube[0];
		cube[0] = cube[53];
		cube[53] = cube[27];
		cube[27] = cube[18];
		cube[18] = tmp;

		tmp = cube[6];
		cube[6] = cube[47];
		cube[47] = cube[33];
		cube[33] = cube[24];
		cube[24] = tmp;

		tmp = cube[3];
		cube[3] = cube[50];
		cube[50] = cube[30];
		cube[30] = cube[21];
		cube[21] = tmp;
	}

	static void moveLp(char cube[55]){
		char tmp = cube[36];
		cube[36] = cube[38];
		cube[38] = cube[44];
		cube[44] = cube[42];
		cube[42] = tmp;

		tmp = cube[37];
		cube[37] = cube[41];
		cube[41] = cube[43];
		cube[43] = cube[39];
		cube[39] = tmp;

		tmp = cube[0];
		cube[0] = cube[18];
		cube[18] = cube[27];
		cube[27] = cube[53];
		cube[53] = tmp;

		tmp = cube[6];
		cube[6] = cube[24];
		cube[24] = cube[33];
		cube[33] = cube[47];
		cube[47] = tmp;

		tmp = cube[3];
		cube[3] = cube[21];
		cube[21] = cube[30];
		cube[30] = cube[50];
		cube[50] = tmp;
	}

	static void moveL2(char cube[55]){
		char tmp = cube[36];
		cube[36] = cube[44];
		cube[44] = tmp;

		tmp = cube[38];
		cube[38] = cube[42];
		cube[42] = tmp;

		tmp = cube[37];
		cube[37] = cube[43];
		cube[43] = tmp;

		tmp = cube[39];
		cube[39] = cube[41];
		cube[41] = tmp;

		tmp = cube[0];
		cube[0] = cube[27];
		cube[27] = tmp;

		tmp = cube[18];
		cube[18] = cube[53];
		cube[53] = tmp;

		tmp = cube[6];
		cube[6] = cube[33];
		cube[33] = tmp;

		tmp = cube[24];
		cube[24] = cube[47];
		cube[47] = tmp;

		tmp = cube[3];
		cube[3] = cube[30];
		cube[30] = tmp;

		tmp = cube[21];
		cube[21] = cube[50];
		cube[50] = tmp;
	}

	static void moveB(char cube[55]){
		char tmp = cube[45];
		cube[45] = cube[51];
		cube[51] = cube[53];
		cube[53] = cube[47];
		cube[47] = tmp;

		tmp = cube[46];
		cube[46] = cube[48];
		cube[48] = cube[52];
		cube[52] = cube[50];
		cube[50] = tmp;

		tmp = cube[0];
		cube[0] = cube[11];
		cube[11] = cube[35];
		cube[35] = cube[42];
		cube[42] = tmp;

		tmp = cube[2];
		cube[2] = cube[17];
		cube[17] = cube[33];
		cube[33] = cube[36];
		cube[36] = tmp;

		tmp = cube[1];
		cube[1] = cube[14];
		cube[14] = cube[34];
		cube[34] = cube[39];
		cube[39] = tmp;
	}

	static void moveBp(char cube[55]){
		char tmp = cube[45];
		cube[45] = cube[47];
		cube[47] = cube[53];
		cube[53] = cube[51];
		cube[51] = tmp;

		tmp = cube[46];
		cube[46] = cube[50];
		cube[50] = cube[52];
		cube[52] = cube[48];
		cube[48] = tmp;

		tmp = cube[0];
		cube[0] = cube[42];
		cube[42] = cube[35];
		cube[35] = cube[11];
		cube[11] = tmp;

		tmp = cube[2];
		cube[2] = cube[36];
		cube[36] = cube[33];
		cube[33] = cube[17];
		cube[17] = tmp;

		tmp = cube[1];
		cube[1] = cube[39];
		cube[39] = cube[34];
		cube[34] = cube[14];
		cube[14] = tmp;
	}

	static void moveB2(char cube[55]){
		char tmp = cube[45];
		cube[45] = cube[53];
		cube[53] = tmp;

		tmp = cube[47];
		cube[47] = cube[51];
		cube[51] = tmp;

		tmp = cube[46];
		cube[46] = cube[52];
		cube[52] = tmp;

		tmp = cube[48];
		cube[48] = cube[50];
		cube[50] = tmp;

		tmp = cube[0];
		cube[0] = cube[35];
		cube[35] = tmp;

		tmp = cube[11];
		cube[11] = cube[42];
		cube[42] = tmp;

		tmp = cube[2];
		cube[2] = cube[33];
		cube[33] = tmp;

		tmp = cube[17];
		cube[17] = cube[36];
		cube[36] = tmp;

		tmp = cube[1];
		cube[1] = cube[34];
		cube[34] = tmp;

		tmp = cube[14];
		cube[14] = cube[39];
		cube[39] = tmp;
	}

};

#endif