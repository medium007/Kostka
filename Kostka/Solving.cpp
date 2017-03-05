#include <stdio.h>
#include<iostream>
#include<iomanip>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <Windows.h>

#include "Pairs.h"
#include "Elements.h"
#include "Moves.h"
#include "OLL.h"
#include "PLL.h"

#define MAX_MOVES_C 7
#define MAX_MOVES_P 11

using namespace std;

const char z1 = 0xC9;
const char z2 = 0xBB;
const char z3 = 0xC8;
const char z4 = 0xBC;
const char z5 = 0xCE;
const char z6 = 0xCB;
const char z7 = 0xCA;
const char z8 = 0xCD;
const char z9 = 0xBA;

void moveU(char cube[55]);
void moveR(char cube[55]);
void moveF(char cube[55]);
void moveD(char cube[55]);
void moveL(char cube[55]);
void moveB(char cube[55]);

void moveUp(char cube[55]);
void moveRp(char cube[55]);
void moveFp(char cube[55]);
void moveDp(char cube[55]);
void moveLp(char cube[55]);
void moveBp(char cube[55]);

void moveU2(char cube[55]);
void moveR2(char cube[55]);
void moveF2(char cube[55]);
void moveD2(char cube[55]);
void moveL2(char cube[55]);
void moveB2(char cube[55]);

void doMoveP(char cube[55], int moveP);
void doMove(char cube[55], int moveP);
void scrambleCube(char cube[55]);
void prevState(char cube[55], bool doneMoves[][18], int vMove[], int& moveP, int& k);
void clearAllMoves(bool moves[18]);
void clearMovesForPairs(bool moves[18], int pair);
void clearMoves(bool moves[18], int moveP);
void showAll(int VMove[], bool table[][18], int maxMove);
void showSolution(int vMove[], int maxMove);
void showMove(int move);
void randMove(char cube[55], int maxMove, int& k, int& move, int& moveP, int vMove[], bool doneMoves[][18]);

void drawCube(char cube[55]);
char drawColor(char elm);
void initAndScrambleCube(char cube[55]);

bool allMovesDone(bool moves[18]);
bool checkMoves(int move, int moveP);

bool isWhiteCrossMade(char cube[55]);
bool isYellowCrossMade(char cube[55]);
bool isGreenCrossMade(char cube[55]);
bool isBlueCrossMade(char cube[55]);
bool isRedCrossMade(char cube[55]);
bool isOrangeCrossMade(char cube[55]);


bool isFirstYellowPair(char cube[55]);
bool isSecondYellowPair(char cube[55]);
bool isThirdYellowPair(char cube[55]);
bool isFourthYellowPair(char cube[55]);


void solveWhiteCross(char cube[55]);
void solveYellowCross(char cube[55]);
void solveGreenCross(char cube[55]);
void solveBlueCross(char cube[55]);
void solveRedCross(char cube[55]);
void solveOrangeCross(char cube[55]);

void solveFirstYellowPair(char cube[55]);
void solveSecondYellowPair(char cube[55]);
void solveThirdYellowPair(char cube[55]);
void solveFourthYellowPair(char cube[55]);

void doOLL(char cube[55]);
int getOLL(char cube[55]);
bool checkOLL(char cube[55], int oll[8]);

void doPLL(char cube[55]);
int getPLL(char cube[55]);
bool checkPLL(char cube[55], int pll[8]);

int main()
{

	//char cube[55] =  "UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB" ;
	char cube[55] = "WWWWWWWWWRRRRRRRRRGGGGGGGGGYYYYYYYYYOOOOOOOOOBBBBBBBBB";
	// initAndScrambleCube(cube);
	scrambleCube(cube);
	drawCube(cube);
	solveYellowCross(cube);
	/*
	solveFirstYellowPair(cube);
	solveSecondYellowPair(cube);
	solveThirdYellowPair(cube);
	solveFourthYellowPair(cube);
	doOLL(cube);
	doPLL(cube);
	printf("\n\n");
	drawCube(cube);*/

	/*solveWhiteCross(cube);

	initAndScrambleCube(cube);
	solveYellowCross(cube);

	initAndScrambleCube(cube);
	solveGreenCross(cube);

	initAndScrambleCube(cube);
	solveBlueCross(cube);

	initAndScrambleCube(cube);
	solveRedCross(cube);

	initAndScrambleCube(cube);
	solveOrangeCross(cube);*/

	system("Pause");

	return 0;
}

void moveU(char cube[55]){
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

void moveUp(char cube[55]){
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

void moveU2(char cube[55]){
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

void moveR(char cube[55]){
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

void moveRp(char cube[55]){
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

void moveR2(char cube[55]){
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

void moveF(char cube[55]){
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

void moveFp(char cube[55]){
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

void moveF2(char cube[55]){
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

void moveD(char cube[55]){
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

void moveDp(char cube[55]){
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

void moveD2(char cube[55]){
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

void moveL(char cube[55]){
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

void moveLp(char cube[55]){
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

void moveL2(char cube[55]){
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

void moveB(char cube[55]){
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

void moveBp(char cube[55]){
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

void moveB2(char cube[55]){
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

void drawCube(char cube[55]){
	cout << setw(7) << z1 << z8 << z8 << z8 << z8 << z8 << z2 << endl
		<< setw(7) << z9 << cube[0] << " " << cube[1] << " " << cube[2] << z9 << endl
		<< setw(7) << z9 << cube[3] << " " << cube[4] << " " << cube[5] << z9 << endl
		<< setw(7) << z9 << cube[6] << " " << cube[7] << " " << cube[8] << z9 << endl
		<< z1 << z8 << z8 << z8 << z8 << z8 << z5 << z8 << z8 << z8 << z8 << z8 << z5 << z8 << z8 << z8 << z8 << z8 << z6 << z8 << z8 << z8 << z8 << z8 << z2 << endl
		<< z9 << cube[36] << " " << cube[37] << " " << cube[38]
		<< z9 << cube[18] << " " << cube[19] << " " << cube[20]
		<< z9 << cube[9] << " " << cube[10] << " " << cube[11]
		<< z9 << cube[45] << " " << cube[46] << " " << cube[47]
		<< z9 << endl
		<< z9 << cube[39] << " " << cube[40] << " " << cube[41]
		<< z9 << cube[21] << " " << cube[22] << " " << cube[23]
		<< z9 << cube[12] << " " << cube[13] << " " << cube[14]
		<< z9 << cube[48] << " " << cube[49] << " " << cube[50]
		<< z9 << endl
		<< z9 << cube[42] << " " << cube[43] << " " << cube[44]
		<< z9 << cube[24] << " " << cube[25] << " " << cube[26]
		<< z9 << cube[15] << " " << cube[16] << " " << cube[17]
		<< z9 << cube[51] << " " << cube[52] << " " << cube[53]
		<< z9 << endl
		<< z3 << z8 << z8 << z8 << z8 << z8 << z5 << z8 << z8 << z8 << z8 << z8 << z5 << z8 << z8 << z8 << z8 << z8 << z7 << z8 << z8 << z8 << z8 << z8 << z4 << endl
		<< setw(7) << z9 << cube[27] << " " << cube[28] << " " << cube[29] << z9 << endl
		<< setw(7) << z9 << cube[30] << " " << cube[31] << " " << cube[32] << z9 << endl
		<< setw(7) << z9 << cube[33] << " " << cube[34] << " " << cube[35] << z9 << endl
		<< setw(7) << z3 << z8 << z8 << z8 << z8 << z8 << z4 << endl
		<< endl << "--------------------------------------------------------------" << endl;
}

/*char drawColor(char elm){
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
switch(elm){
case 'W':
SetConsoleTextAttribute(hOut, 15);
break;
case 'Y':
SetConsoleTextAttribute(hOut, 14);
break;
case 'G':
SetConsoleTextAttribute(hOut, 10); //2
break;
case 'B':
SetConsoleTextAttribute(hOut, 9); //1
break;
case 'R':
SetConsoleTextAttribute(hOut, 12); //4
break;
case 'O':
SetConsoleTextAttribute(hOut, 13);
break;
};
return elm;
}*/

void scrambleCube(char cube[55]){
	printf("Algorytm mieszajacy: \n");
	srand(time(NULL));
	int move = -1,
		moveP = -1;
	for (int i = 0; i < 25; i++){
		do{
			move = rand() % 18;
		} while (!checkMoves(move, moveP));
		doMove(cube, move);
		showMove(move);
		moveP = move;
	}
	printf("\n\n");
}

bool isWhiteCrossMade(char cube[55]){
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

bool isYellowCrossMade(char cube[55]){
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

bool isGreenCrossMade(char cube[55]){
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

bool isBlueCrossMade(char cube[55]){
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

bool isRedCrossMade(char cube[55]){
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

bool isOrangeCrossMade(char cube[55]){
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

void doMoveP(char cube[55], int moveP){
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

void doMove(char cube[55], int moveP){
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

bool allMovesDone(bool moves[18]){
	for (int i = 0; i < 18; i++){
		if (moves[i] == false)
			return false;
	}
	return true;
}

void prevState(char cube[55], bool doneMoves[][18], int vMove[], int& moveP, int& k){
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

void clearAllMoves(bool moves[18]){
	for (int i = 0; i < 18; i++){
		moves[i] = false;
	}
}

void clearMoves(bool moves[18], int moveP){
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

void clearMovesForPairs(bool moves[18], int pair){
	//clearAllMoves(moves);
	moves[D] = true;
	moves[DP] = true;
	moves[DD] = true;

	switch (pair){
	case 1:
		moves[B] = true;
		moves[BP] = true;
		moves[BB] = true;
		break;
	case 2:
		moves[R] = true;
		moves[RP] = true;
		moves[RR] = true;
		break;
	case 3:
		moves[F] = true;
		moves[FP] = true;
		moves[FF] = true;
		break;
		/*case 4:
		moves[L] = true;
		moves[LP] = true;
		moves[LL] = true;
		break;*/
	};

}

void showAll(int vMove[], bool table[][18], int maxMoves){

	printf("\n");
	for (int i = 0; i < maxMoves; i++){
		for (int j = 0; j < 18; j++){
			if (table[i][j])
				printf("1 ");
			else
				printf("_ ");
		}
		printf("  |%d\n", vMove[i]);
	}
}

bool checkMoves(int move, int moveP){
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

void showSolution(int vMove[], int maxMoves){
	for (int i = 0; i < maxMoves; i++){
		showMove(vMove[i]);
	}
	printf("\n");
}

void showMove(int move){
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

void randMove(char cube[55], int maxMoves, int& k, int& move, int& moveP, int vMove[], bool doneMoves[][18]){
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

void randMoveForPairs(char cube[55], int maxMoves, int pair, int& k, int& move, int& moveP, int vMove[], bool doneMoves[][18]){
	if (k == maxMoves){
		k--;
		doMoveP(cube, moveP);
		vMove[k] = -1;
		moveP = vMove[k - 1];
		if (allMovesDone(doneMoves[k])){
			prevState(cube, doneMoves, vMove, moveP, k);
		}
	}
	do{
		move = rand() % 18;
	} while (doneMoves[k][move] || !checkMoves(move, moveP));
	doMove(cube, move);
	doneMoves[k][move] = true;
	vMove[k] = move;
	moveP = move;
	k++;
	if (k < maxMoves){
		clearMoves(doneMoves[k], moveP);
		clearMovesForPairs(doneMoves[k], pair);
	}
}

void solveWhiteCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	srand(time(NULL));

	while (!isWhiteCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}

	printf("Bialy krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n");
}

void solveYellowCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	//srand(time(NULL));
	int move = -1,
		moveP = -1;
	int k = 0;
	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	while (!isYellowCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}
	printf("Zolty krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n\n");
}

void solveGreenCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	srand(time(NULL));

	while (!isGreenCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}

	printf("Zielony krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n");
}

void solveBlueCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	srand(time(NULL));

	while (!isBlueCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}

	printf("Niebieski krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n\n");
}

void solveRedCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	srand(time(NULL));

	while (!isRedCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}

	printf("Czerwony krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n\n");
}

void solveOrangeCross(char cube[55]){

	int vMove[MAX_MOVES_C];
	bool doneMoves[MAX_MOVES_C][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_C; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
	}

	srand(time(NULL));

	while (!isOrangeCrossMade(cube)){
		randMove(cube, MAX_MOVES_C, k, move, moveP, vMove, doneMoves);
	}

	printf("Pomaranczowy krzyz: ");
	showSolution(vMove, MAX_MOVES_C);
	printf("\n\n");
}

void initAndScrambleCube(char cube[55]){

	for (int i = 0; i < 54; i++){
		switch (i / 9){
		case 0:
			cube[i] = 'W';
			break;
		case 1:
			cube[i] = 'R';
			break;
		case 2:
			cube[i] = 'G';
			break;
		case 3:
			cube[i] = 'Y';
			break;
		case 4:
			cube[i] = 'O';
			break;
		case 5:
			cube[i] = 'B';
			break;
		};
	}

	moveU2(cube);  moveRp(cube); moveU(cube); moveL(cube); moveUp(cube); moveR(cube); moveU2(cube);
	moveLp(cube); moveU(cube); moveL(cube); moveU2(cube); moveLp(cube); moveU2(cube);

	//moveR(cube); moveU(cube); moveRp(cube); moveUp(cube); moveRp(cube); moveF(cube); moveR(cube); moveFp(cube); moveU2(cube);

	//moveR2(cube); moveD(cube);	moveF2(cube); moveR2(cube); moveU2(cube); moveL2(cube);
	//moveF2(cube); moveU2(cube); moveF2(cube); moveU(cube); moveFp(cube); moveR(cube); moveUp(cube); moveBp(cube);
	//	moveF2(cube); moveL2(cube); moveF(cube); moveDp(cube); moveFp(cube); moveDp(cube);
}

void solveFirstYellowPair(char cube[55]){
	int vMove[MAX_MOVES_P];
	bool doneMoves[MAX_MOVES_P][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_P; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
		clearMovesForPairs(doneMoves[i], 1);
	}

	srand(time(NULL));

	while (!(isFirstYellowPair(cube) && isYellowCrossMade(cube))){
		randMoveForPairs(cube, MAX_MOVES_P, 1, k, move, moveP, vMove, doneMoves);
	}

	printf("Zolta para 1: ");
	showSolution(vMove, MAX_MOVES_P);
	printf("\n\n");
}

bool isFirstYellowPair(char cube[55]){
	if (cube[12] != 'R')
		return false;
	if (cube[23] != 'G')
		return false;
	if (cube[15] != 'R')
		return false;
	if (cube[26] != 'G')
		return false;
	if (cube[29] != 'Y')
		return false;
	return true;
}

void solveSecondYellowPair(char cube[55]){
	int vMove[MAX_MOVES_P];
	bool doneMoves[MAX_MOVES_P][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_P; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
		clearMovesForPairs(doneMoves[i], 2);
	}

	srand(time(NULL));

	while (!(isSecondYellowPair(cube) && isFirstYellowPair(cube) && isYellowCrossMade(cube))){
		randMoveForPairs(cube, MAX_MOVES_P, 2, k, move, moveP, vMove, doneMoves);
	}

	printf("Zolta para 2: ");
	showSolution(vMove, MAX_MOVES_P);
	printf("\n\n");
}

bool isSecondYellowPair(char cube[55]){
	if (cube[21] != 'G')
		return false;
	if (cube[24] != 'G')
		return false;
	if (cube[27] != 'Y')
		return false;
	if (cube[41] != 'O')
		return false;
	if (cube[44] != 'O')
		return false;
	return true;
}

void solveThirdYellowPair(char cube[55]){
	int vMove[MAX_MOVES_P];
	bool doneMoves[MAX_MOVES_P][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_P; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
		clearMovesForPairs(doneMoves[i], 3);
	}

	srand(time(NULL));

	while (!(isThirdYellowPair(cube) && isSecondYellowPair(cube) && isFirstYellowPair(cube) && isYellowCrossMade(cube))){
		randMoveForPairs(cube, MAX_MOVES_P, 3, k, move, moveP, vMove, doneMoves);
	}

	printf("Zolta para 3: ");
	showSolution(vMove, MAX_MOVES_P);
	printf("\n\n");
}

bool isThirdYellowPair(char cube[55]){
	if (cube[D7] != 'Y')
		return false;
	if (cube[L7] != 'O')
		return false;
	if (cube[B9] != 'B')
		return false;
	if (cube[B6] != 'B')
		return false;
	if (cube[L4] != 'O')
		return false;
	return true;
}

void solveFourthYellowPair(char cube[55]){
	int vMove[MAX_MOVES_P];
	bool doneMoves[MAX_MOVES_P][18];
	int move = -1,
		moveP = -1;
	int k = 0;

	for (int i = 0; i < MAX_MOVES_P; i++){
		vMove[i] = -1;
		clearAllMoves(doneMoves[i]);
		clearMovesForPairs(doneMoves[i], 4);
	}

	srand(time(NULL));

	while (!(isFourthYellowPair(cube) && isThirdYellowPair(cube) && isSecondYellowPair(cube) && isFirstYellowPair(cube) && isYellowCrossMade(cube))){
		randMoveForPairs(cube, MAX_MOVES_P, 4, k, move, moveP, vMove, doneMoves);
	}

	printf("Zolta para 4: ");
	showSolution(vMove, MAX_MOVES_P);
	printf("\n\n");
}

bool isFourthYellowPair(char cube[55]){
	if (cube[D9] != 'Y')
		return false;
	if (cube[R9] != 'R')
		return false;
	if (cube[B7] != 'B')
		return false;
	if (cube[B4] != 'B')
		return false;
	if (cube[R6] != 'R')
		return false;
	return true;
}

void doOLL(char cube[55]){
	int oll = getOLL(cube);
	int uMoves = 0;
	while (oll == -1){
		uMoves++;
		moveU(cube);
		oll = getOLL(cube);
		cout << oll << endl;
	}
	printf("Orientacja: ");
	if (uMoves == 1)
		printf("U ");
	else if (uMoves == 2)
		printf("U2 ");
	else if (uMoves == 3)
		printf("U' ");
	int i = 0;
	while (solveOLL[oll][i] != -1){
		doMove(cube, solveOLL[oll][i]);
		showMove(solveOLL[oll][i]);
		i++;
	}
	printf("\n\n");
}

int getOLL(char cube[55]){
	for (int i = 0; i < 58; i++){
		if (checkOLL(cube, OLLs[i]))
			return i;
	}
	return -1;
}

bool checkOLL(char cube[55], int oll[8]){
	for (int i = 0; i < 8; i++){
		if (cube[oll[i]] != 'W')
			return false;
	}
	return true;
}

void doPLL(char cube[55]){
	int pll = getPLL(cube);
	int uMoves = 0;
	while (pll == -1){
		uMoves++;
		moveU(cube);
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
		doMove(cube, solvePLL[pll][i]);
		showMove(solvePLL[pll][i]);
		i++;
	}
	if (cube[F2] == 'O'){
		moveU(cube);
		printf("U ");
	}
	else if (cube[F2] == 'B'){
		moveU2(cube);
		printf("U2 ");
	}
	else if (cube[F2] == 'R'){
		moveUp(cube);
		printf("U' ");
	}
	printf("\n");
}

int getPLL(char cube[55]){
	for (int i = 0; i < 22; i++){
		if (checkPLL(cube, PLLs[i]))
			return i;
	}
	return -1;
}

bool checkPLL(char cube[55], int pll[12]){
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