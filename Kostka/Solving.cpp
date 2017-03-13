#include <stdio.h>
#include<iostream>
#include<iomanip>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <Windows.h>

#include "Pairs.h"
#include "OLL.h"
#include "PLL.h"
#include "Cross.h"

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

void scrambleCube(char cube[55]);
void prevState(char cube[55], bool doneMoves[][18], int vMove[], int& moveP, int& k);
void showAll(int VMove[], bool table[][18], int maxMove);
void showSolution(int vMove[], int maxMove);

void drawCube(char cube[55]);
char drawColor(char elm);
void initAndScrambleCube(char cube[55]);

Moves moves;
Cross cross;

int main()
{

	//char cube[55] =  "UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB" ;
	char cube[55] = "WWWWWWWWWRRRRRRRRRGGGGGGGGGYYYYYYYYYOOOOOOOOOBBBBBBBBB";
	// initAndScrambleCube(cube);
	scrambleCube(cube);
	drawCube(cube);
	cross.solveYellowCross(cube);
	
	Pairs::solveSecondYellowPair(cube);
	Pairs::solveThirdYellowPair(cube);
	Pairs::solveFourthYellowPair(cube);
	Pairs::solveFirstYellowPair(cube);

	OLL::doOLL(cube);
	PLL::doPLL(cube);
	printf("\n\n");
	drawCube(cube);

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
		} while (!moves.checkMoves(move, moveP));
		moves.doMove(cube, move);
		moves.showMove(move);
		moveP = move;
	}
	printf("\n\n");
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

	moves.scrambleTest(cube);

	//moveR(cube); moveU(cube); moveRp(cube); moveUp(cube); moveRp(cube); moveF(cube); moveR(cube); moveFp(cube); moveU2(cube);

	//moveR2(cube); moveD(cube);	moveF2(cube); moveR2(cube); moveU2(cube); moveL2(cube);
	//moveF2(cube); moveU2(cube); moveF2(cube); moveU(cube); moveFp(cube); moveR(cube); moveUp(cube); moveBp(cube);
	//	moveF2(cube); moveL2(cube); moveF(cube); moveDp(cube); moveFp(cube); moveDp(cube);
}
