#ifndef PAIRS_HEADER
#define PAIRS_HEADER

#include "Elements.h"
#include "Cross.h"

#define MAX_MOVES_P 11

int firstPairs[60][5] = {
		{ D3, F9, R7, F6, R4 }, //
		{ D3, F9, R7, R4, F6 }, // R'FRF' RU'R'URU'R'U2RU'R'
		{ D3, F9, R7, U6, R2 }, // U' F' U F U R U' R'
		{ D3, F9, R7, R2, U6 }, // U2 R U' R' U' F' U F
		{ D3, F9, R7, U2, B2 },  // F' U F U R U' R'
		{ D3, F9, R7, B2, U2 }, // U' R U' R' U' F' U F
		{ D3, F9, R7, U4, L2 }, // U F' U F U R U' R'
		{ D3, F9, R7, L2, U4 }, // R U' R' U' F' U F
		{ D3, F9, R7, U8, F2 },  //U2 F' U F U R U' R'
		{ D3, F9, R7, F2, U8 }, // U R U' R' U' F' U F

		{ F9, R7, D3, F6, R4 }, // F' U' F U2 F' U F U' F' U' F
		{ F9, R7, D3, R4, F6 }, // F' U' F U  F' U F U2 R U R'
		{ F9, R7, D3, U6, R2 }, // R U' R' U R U' R'
		{ F9, R7, D3, R2, U6 }, // U F' U' F U F' U' L
		{ F9, R7, D3, U2, B2 }, // U R U' R' U R U' R'
		{ F9, R7, D3, B2, U2 }, //U2 F' U' F U F' U' L
		{ F9, R7, D3, U4, L2 }, //U2 R U' R' U R U' R'
		{ F9, R7, D3, L2, U4 }, // U' F' U' F U F' U' L
		{ F9, R7, D3, U8, F2 }, // U' R U' R' U R U' R'
		{ F9, R7, D3, F2, U8 }, // F' U' F U F' U' L


		{ R7, D3, F9, F6, R4 }, //R U R' U2 R U' R' U R U R'
		{ R7, D3, F9, R4, F6 }, // R U R' U'  R U' R' U2 F' U' F
		{ R7, D3, F9, U6, R2 }, // RU R' U' R U R'
		{ R7, D3, F9, R2, U6 }, // U F' U F U' F' U F
		{ R7, D3, F9, U2, B2 }, //URU R' U' R U R'
		{ R7, D3, F9, B2, U2 }, // U2 F' U F U' F' U F
		{ R7, D3, F9, U4, L2 },// U2 RU R' U' R U R'
		{ R7, D3, F9, L2, U4 },// U' F' U F U' F' U F
		{ R7, D3, F9, U8, F2 },// U' RU R' U' R U R'
		{ R7, D3, F9, F2, U8 },// F' U F U' F' U F

		//-------------------------
		{ U9, R1, F3, F6, R4 },
		{ U9, R1, F3, R4, F6 },
		{ U9, R1, F3, U6, R2 },
		{ U9, R1, F3, R2, U6 },
		{ U9, R1, F3, U2, B2 },
		{ U9, R1, F3, B2, U2 },
		{ U9, R1, F3, U4, L2 },
		{ U9, R1, F3, L2, U4 },
		{ U9, R1, F3, U8, F2 },
		{ U9, R1, F3, F2, U8 },

		{ R1, F3, U9, F6, R4 },
		{ R1, F3, U9, R4, F6 },
		{ R1, F3, U9, U6, R2 },
		{ R1, F3, U9, R2, U6 },
		{ R1, F3, U9, U2, B2 },
		{ R1, F3, U9, B2, U2 },
		{ R1, F3, U9, U4, L2 },
		{ R1, F3, U9, L2, U4 },
		{ R1, F3, U9, U8, F2 },
		{ R1, F3, U9, F2, U8 },

		{ F3, U9, R1, F6, R4 },
		{ F3, U9, R1, R4, F6 },
		{ F3, U9, R1, U6, R2 },
		{ F3, U9, R1, R2, U6 },
		{ F3, U9, R1, U2, B2 },
		{ F3, U9, R1, B2, U2 },
		{ F3, U9, R1, U4, L2 },
		{ F3, U9, R1, L2, U4 },
		{ F3, U9, R1, U8, F2 },
		{ F3, U9, R1, F2, U8 }
};

int solveFirstPair[60][16] = {
		{-1}, //
		{ RP, F, R, FP, R, UP, RP, U, R, UP, RP, UU, R, UP, RP, -1 }, // R'FRF' RU'R'URU'R'U2RU'R'
		{ UP, FP, UP, F, U, R, U, RP, -1 }, // U' F' U F U R U' R'
		{ UU, R, U, RP, UP, FP, U, F, -1 }, // U2 R U' R' U' F' U F
		{ FP, U, F, U, R, UP, RP, -1 },  // F' U F U R U' R'
		{ UP, R, UP, RP, UP, FP, U, F, -1 }, // U' R U' R' U' F' U F
		{ U, FP, U, F, U, R, UP, RP, -1 }, // U F' U F U R U' R'
		{ R, UP, RP, UP, FP, U, F, -1 }, // R U' R' U' F' U F
		{ UU, FP, U, F, U, R, UP, RP, - 1 },  //U2 F' U F U R U' R'
		{ U, R, UP, RP, UP, FP, U, F, -1 }, // U R U' R' U' F' U F

		{ FP, UP, F, UU, FP, U, F, UP, FP, UP, F, -1 }, // F' U' F U2 F' U F U' F' U' F
		{ FP, UP, F, U, FP, U, F, UU, R, U, RP, -1 }, // F' U' F U  F' U F U2 R U R'
		{ R, UP, RP, U, R, UP, RP, -1 }, // R U' R' U R U' R'
		{ U, FP, UP, F, U, FP, UP, L, -1 }, // U F' U' F U F' U' L
		{ U, R, UP, RP, U, R, UP, UP, -1 }, // U R U' R' U R U' R'
		{ UU, FP, UP, F, U, FP, UP, L, -1 }, //U2 F' U' F U F' U' L
		{ UU, R, UP, RP, U, R, UP, RP, -1}, //U2 R U' R' U R U' R'
		{ UP, FP, UP, F, U, FP, UP, L, -1 }, // U' F' U' F U F' U' L
		{ UP, R, UP, RP, U, R, UP, RP, -1 }, // U' R U' R' U R U' R'
		{ FP, UP, F, U, FP, UP, L, -1 }, // F' U' F U F' U' L


		{ R, U, RP, UU, R, UP, RP, U, R, U, RP, -1 }, //R U R' U2 R U' R' U R U R'
		{ R, U, RP, UP, R, UP, RP, UU, FP, UP, F, -1 }, // R U R' U'  R U' R' U2 F' U' F
		{ R, U, RP, UP, R, U, RP, -1 }, // RU R' U' R U R'
		{ U, FP, U, F, UP, FP, U, F, -1 }, // U F' U F U' F' U F
		{ U, R, U, RP, UP, R, U, RP, -1 }, //URU R' U' R U R'
		{ UU, FP, U, F, UP, FP, U, F, -1 }, // U2 F' U F U' F' U F
		{ UU, R, U, RP, UP, R, U, RP, -1 },// U2 RU R' U' R U R'
		{ UP, FP, U, F, UP, FP, U, F, -1 },// U' F' U F U' F' U F
		{ UP, R, U, RP, UP, R, U, RP, -1 },// U' RU R' U' R U R'
		{ FP, U, F, UP, FP, U, F, -1 },// F' U F U' F' U F

		//-------------------------
		{ R, U, RP, UU, R,  UU, RP, UU, R, U, RP, -1 },
		{ R, UP, RP, U, FP, U, F, -1 },
		{ R, UU, RP, UP, R, U, RP, -1 },
		{ R, UU, RP, FP, UU, F, UU, FP, U, F, -1 },
		{ FP, U, F, U, R, UU, RP, UU, R, UP, RP, -1},
		{ FP, U, F, UU, FP, UP, F, -1},
		{ R, UP, RP, UU, R, U, RP, -1 },
		{ R, UP, RP, UP, FP, UU, F, UU, FP, U, F, -1 },
		{ FP, U, F, U, R, U, RP, UU, R, UP, RP, -1 },
		{ FP, UU, F, U, FP, UP, F, -1 },

		{ U, R, U, RP, UU, R, U, RP, -1 },
		{ UU, FP, U, F, U, R, U, RP, -1 },
		{ UP, R, UP, RP, U, R, U, RP, -1 },
		{ R, UP, RP, UU, FP, UP, F, -1 },
		{ R, U, RP, -1 },
		{ U, FP, UU, F, UU, FP, U, F, -1 },
		{ U, FP, U, F, UP, R, U, RP, -1 },
		{ U, FP, UP, F, UU, FP, U, F, -1 },
		{ U, FP, UU, F, UP, R, U, RP, -1 },
		{ UP, FP, U, F, -1 },

		{ UP, FP, UP, F, UU, FP, UP, F, -1 },
		{ UU, R, UP, RP, UP, FP, UP, F },
		{ U, R, UP, RP, -1 },
		{ UP, R, U2,RP, U, FP, UP, F, -1 },
		{ UP, R, U, RP, UU, R, UP, RP, -1 },
		{ UP, R, UP, RP, U, FP, UP, F, -1 },
		{ UP, R, UU, RP, UU, R, UP, RP, -1 },
		{ FP, UP, F, -1 },
		{ FP, U, F, UU, R, U, RP, -1 },
		{ U, FP, U, F, UP, FP, UP, F, -1 }
};

int YellowPairs[384][5] = {
		// -------------------
		//      FR
		//--------------------
		{ D3, F9, R7, F6, R4}, //
		{ D3, F9, R7, R4, F6}, // R'FRF' RU'R'URU'R'U2RU'R'
		{ D3, F9, R7,  U6, R2}, // U' F' U F U R U' R'
		{ D3, F9, R7, R2,  U6}, // U2 R U' R' U' F' U F
		{ D3, F9, R7, U2, B2},  // F' U F U R U' R'
		{ D3, F9, R7, B2, U2}, // U' R U' R' U' F' U F
		{ D3, F9, R7, U4, L2}, // U F' U F U R U' R'
		{ D3, F9, R7, L2, U4}, // R U' R' U' F' U F
		{ D3, F9, R7, U8, F2},  //U2 F' U F U R U' R'
		{ D3, F9, R7, F2, U8}, // U R U' R' U' F' U F
		{ D3, F9, R7, F4, L6}, // L' U L F' U F U R U' R'
		{ D3, F9, R7, L6, F4}, // L' U L U' R U' R' U' F' U F
		{ D3, F9, R7, R6, B4}, // R' U2 R2 U' R' U' F' U F
		{ D3, F9, R7, B4, R6}, // R' U' R F' U F U R U' R'
		{ D3, F9, R7, B6, L4}, // L U L' F' U F U R U' R'
		{ D3, F9, R7, L4, B6}, // L U' L' U R U' R' U' F' U F

		{ F9, R7, D3, F6, R4 }, // F' U' F U2 F' U F U' F' U' F
		{ F9, R7, D3, R4, F6 }, // F' U' F U  F' U F U2 R U R'
		{ F9, R7, D3,  U6, R2 }, // R U' R' U R U' R'
		{ F9, R7, D3, R2,  U6 }, // U F' U' F U F' U' L
		{ F9, R7, D3, U2, B2 }, // U R U' R' U R U' R'
		{ F9, R7, D3, B2, U2 }, //U2 F' U' F U F' U' L
		{ F9, R7, D3, U4, L2 }, //U2 R U' R' U R U' R'
		{ F9, R7, D3, L2, U4 }, // U' F' U' F U F' U' L
		{ F9, R7, D3, U8, F2 }, // U' R U' R' U R U' R'
		{ F9, R7, D3, F2, U8 }, // F' U' F U F' U' L
		{ F9, R7, D3, F4, L6 }, // L' U2 L R U' R' U R U' R'
		{ F9, R7, D3, L6, F4 },// L' U' L F' U' F U F' U' L
		{ F9, R7, D3, R6, B4 }, // R' U R  F' U' F U F' U' L
		{ F9, R7, D3, B4, R6 },// R' U' R U R U' R' U R U' R'
		{ F9, R7, D3, B6, L4 },// L U2 L' R U' R' U R U' R'
		{ F9, R7, D3, L4, B6 },// L U' L' F' U' F U F' U' L

		{ R7, D3, F9, F6, R4 }, //R U R' U2 R U' R' U R U R'
		{ R7, D3, F9, R4, F6 }, // R U R' U'  R U' R' U2 F' U' F
		{ R7, D3, F9,  U6, R2 }, // RU R' U' R U R'
		{ R7, D3, F9, R2,  U6 }, // U F' U F U' F' U F
		{ R7, D3, F9, U2, B2 }, //URU R' U' R U R'
		{ R7, D3, F9, B2, U2 }, // U2 F' U F U' F' U F
		{ R7, D3, F9, U4, L2 },// U2 RU R' U' R U R'
		{ R7, D3, F9, L2, U4 },// U' F' U F U' F' U F
		{ R7, D3, F9, U8, F2 },// U' RU R' U' R U R'
		{ R7, D3, F9, F2, U8 },// F' U F U' F' U F
		{ R7, D3, F9, F4, L6 }, // L' U2 L RU R' U' R U R'
		{ R7, D3, F9, L6, F4 }, // L' U' L F' U F U' F' U F
		{ R7, D3, F9, R6, B4 }, // R' U R F' U F U' F' U F
		{ R7, D3, F9, B4, R6 }, // R' U R U' RU R' U' R U R'
		{ R7, D3, F9, B6, L4 }, // L U2 L' RU R' U' R U R'
		{ R7, D3, F9, L4, B6 }, // L U' L' F' U F U' F' U F
		//-------------------------
		{ U9, R1, F3, F6, R4 },
		{ U9, R1, F3, R4, F6 },
		{ U9, R1, F3,  U6, R2 },
		{ U9, R1, F3, R2,  U6 },
		{ U9, R1, F3, U2, B2 },
		{ U9, R1, F3, B2, U2 },
		{ U9, R1, F3, U4, L2 },
		{ U9, R1, F3, L2, U4 },
		{ U9, R1, F3, U8, F2 },
		{ U9, R1, F3, F2, U8 },
		{ U9, R1, F3, F4, L6 },
		{ U9, R1, F3, L6, F4 },
		{ U9, R1, F3, R6, B4 },
		{ U9, R1, F3, B4, R6 },
		{ U9, R1, F3, B6, L4 },
		{ U9, R1, F3, L4, B6 },

		{ R1, F3, U9, F6, R4 },
		{ R1, F3, U9, R4, F6 },
		{ R1, F3, U9,  U6, R2 },
		{ R1, F3, U9, R2,  U6 },
		{ R1, F3, U9, U2, B2 },
		{ R1, F3, U9, B2, U2 },
		{ R1, F3, U9, U4, L2 },
		{ R1, F3, U9, L2, U4 },
		{ R1, F3, U9, U8, F2 },
		{ R1, F3, U9, F2, U8 },
		{ R1, F3, U9, F4, L6 },
		{ R1, F3, U9, L6, F4 },
		{ R1, F3, U9, R6, B4 },
		{ R1, F3, U9, B4, R6 },
		{ R1, F3, U9, B6, L4 },
		{ R1, F3, U9, L4, B6 },

		{ F3, U9, R1, F6, R4 },
		{ F3, U9, R1, R4, F6 },
		{ F3, U9, R1,  U6, R2 },
		{ F3, U9, R1, R2,  U6 },
		{ F3, U9, R1, U2, B2 },
		{ F3, U9, R1, B2, U2 },
		{ F3, U9, R1, U4, L2 },
		{ F3, U9, R1, L2, U4 },
		{ F3, U9, R1, U8, F2 },
		{ F3, U9, R1, F2, U8 },
		{ F3, U9, R1, F4, L6 },
		{ F3, U9, R1, L6, F4 },
		{ F3, U9, R1, R6, B4 },
		{ F3, U9, R1, B4, R6 },
		{ F3, U9, R1, B6, L4 },
		{ F3, U9, R1, L4, B6 },

		//-------------------------
		//      FL
		//-------------------------
		{ D1, L9, F7 , F6, R4 },
		{ D1, L9, F7 , R4, F6 },
		{ D1, L9, F7 ,  U6, R2 },
		{ D1, L9, F7 , R2,  U6 },
		{ D1, L9, F7 , U2, B2 },
		{ D1, L9, F7 , B2, U2 },
		{ D1, L9, F7 , U4, L2 },
		{ D1, L9, F7 , L2, U4 },
		{ D1, L9, F7 , U8, F2 },
		{ D1, L9, F7 , F2, U8 },
		{ D1, L9, F7 , F4, L6 },
		{ D1, L9, F7 , L6, F4 },
		{ D1, L9, F7 , R6, B4 },
		{ D1, L9, F7 , B4, R6 },
		{ D1, L9, F7 , B6, L4 },
		{ D1, L9, F7 , L4, B6 },

		{ L9, F7 , D1, F6, R4 },
		{ L9, F7 , D1, R4, F6 },
		{ L9, F7 , D1,  U6, R2 },
		{ L9, F7 , D1, R2,  U6 },
		{ L9, F7 , D1, U2, B2 },
		{ L9, F7 , D1, B2, U2 },
		{ L9, F7 , D1, U4, L2 },
		{ L9, F7 , D1, L2, U4 },
		{ L9, F7 , D1, U8, F2 },
		{ L9, F7 , D1, F2, U8 },
		{ L9, F7 , D1, F4, L6 },
		{ L9, F7 , D1, L6, F4 },
		{ L9, F7 , D1, R6, B4 },
		{ L9, F7 , D1, B4, R6 },
		{ L9, F7 , D1, B6, L4 },
		{ L9, F7 , D1, L4, B6 },

		{ F7 , D1, L9, F6, R4 },
		{ F7 , D1, L9, R4, F6 },
		{ F7 , D1, L9,  U6, R2 },
		{ F7 , D1, L9, R2,  U6 },
		{ F7 , D1, L9, U2, B2 },
		{ F7 , D1, L9, B2, U2 },
		{ F7 , D1, L9, U4, L2 },
		{ F7 , D1, L9, L2, U4 },
		{ F7 , D1, L9, U8, F2 },
		{ F7 , D1, L9, F2, U8 },
		{ F7 , D1, L9, F4, L6 },
		{ F7 , D1, L9, L6, F4 },
		{ F7 , D1, L9, R6, B4 },
		{ F7 , D1, L9, B4, R6 },
		{ F7 , D1, L9, B6, L4 },
		{ F7 , D1, L9, L4, B6 },
		//-------------------------
		{6, F1, L3, F6, R4 },
		{6, F1, L3, R4, F6 },
		{6, F1, L3,  U6, R2 },
		{6, F1, L3, R2,  U6 },
		{6, F1, L3, U2, B2 },
		{6, F1, L3, B2, U2 },
		{6, F1, L3, U4, L2 },
		{6, F1, L3, L2, U4 },
		{6, F1, L3, U8, F2 },
		{6, F1, L3, F2, U8 },
		{6, F1, L3, F4, L6 },
		{6, F1, L3, L6, F4 },
		{6, F1, L3, R6, B4 },
		{6, F1, L3, B4, R6 },
		{6, F1, L3, B6, L4 },
		{6, F1, L3, L4, B6 },

		{ F1, L3, U7, F6, R4 },
		{ F1, L3, U7, R4, F6 },
		{ F1, L3, U7,  U6, R2 },
		{ F1, L3, U7, R2,  U6 },
		{ F1, L3, U7, U2, B2 },
		{ F1, L3, U7, B2, U2 },
		{ F1, L3, U7, U4, L2 },
		{ F1, L3, U7, L2, U4 },
		{ F1, L3, U7, U8, F2 },
		{ F1, L3, U7, F2, U8 },
		{ F1, L3, U7, F4, L6 },
		{ F1, L3, U7, L6, F4 },
		{ F1, L3, U7, R6, B4 },
		{ F1, L3, U7, B4, R6 },
		{ F1, L3, U7, B6, L4 },
		{ F1, L3, U7, L4, B6 },

		{ L3, U7, F1, F6, R4 },
		{ L3, U7, F1, R4, F6 },
		{ L3, U7, F1,  U6, R2 },
		{ L3, U7, F1, R2,  U6 },
		{ L3, U7, F1, U2, B2 },
		{ L3, U7, F1, B2, U2 },
		{ L3, U7, F1, U4, L2 },
		{ L3, U7, F1, L2, U4 },
		{ L3, U7, F1, U8, F2 },
		{ L3, U7, F1, F2, U8 },
		{ L3, U7, F1, F4, L6 },
		{ L3, U7, F1, L6, F4 },
		{ L3, U7, F1, R6, B4 },
		{ L3, U7, F1, B4, R6 },
		{ L3, U7, F1, B6, L4 },
		{ L3, U7, F1, L4, B6 },

		//-------------------------
		//      BL
		//-------------------------
		{ U1, L1, B3, F6, R4 },
		{ U1, L1, B3, R4, F6 },
		{ U1, L1, B3,  U6, R2 },
		{ U1, L1, B3, R2,  U6 },
		{ U1, L1, B3, U2, B2 },
		{ U1, L1, B3, B2, U2 },
		{ U1, L1, B3, U4, L2 },
		{ U1, L1, B3, L2, U4 },
		{ U1, L1, B3, U8, F2 },
		{ U1, L1, B3, F2, U8 },
		{ U1, L1, B3, F4, L6 },
		{ U1, L1, B3, L6, F4 },
		{ U1, L1, B3, R6, B4 },
		{ U1, L1, B3, B4, R6 },
		{ U1, L1, B3, B6, L4 },
		{ U1, L1, B3, L4, B6 },

		{ L1, B3, U1, F6, R4 },
		{ L1, B3, U1, R4, F6 },
		{ L1, B3, U1,  U6, R2 },
		{ L1, B3, U1, R2,  U6 },
		{ L1, B3, U1, U2, B2 },
		{ L1, B3, U1, B2, U2 },
		{ L1, B3, U1, U4, L2 },
		{ L1, B3, U1, L2, U4 },
		{ L1, B3, U1, U8, F2 },
		{ L1, B3, U1, F2, U8 },
		{ L1, B3, U1, F4, L6 },
		{ L1, B3, U1, L6, F4 },
		{ L1, B3, U1, R6, B4 },
		{ L1, B3, U1, B4, R6 },
		{ L1, B3, U1, B6, L4 },
		{ L1, B3, U1, L4, B6 },

		{ B3, U1, L1, F6, R4 },
		{ B3, U1, L1, R4, F6 },
		{ B3, U1, L1,  U6, R2 },
		{ B3, U1, L1, R2,  U6 },
		{ B3, U1, L1, U2, B2 },
		{ B3, U1, L1, B2, U2 },
		{ B3, U1, L1, U4, L2 },
		{ B3, U1, L1, L2, U4 },
		{ B3, U1, L1, U8, F2 },
		{ B3, U1, L1, F2, U8 },
		{ B3, U1, L1, F4, L6 },
		{ B3, U1, L1, L6, F4 },
		{ B3, U1, L1, R6, B4 },
		{ B3, U1, L1, B4, R6 },
		{ B3, U1, L1, B6, L4 },
		{ B3, U1, L1, L4, B6 },
		//-------------------------
		{ D7, B9, L7, F6, R4 },
		{ D7, B9, L7, R4, F6 },
		{ D7, B9, L7,  U6, R2 },
		{ D7, B9, L7, R2,  U6 },
		{ D7, B9, L7, U2, B2 },
		{ D7, B9, L7, B2, U2 },
		{ D7, B9, L7, U4, L2 },
		{ D7, B9, L7, L2, U4 },
		{ D7, B9, L7, U8, F2 },
		{ D7, B9, L7, F2, U8 },
		{ D7, B9, L7, F4, L6 },
		{ D7, B9, L7, L6, F4 },
		{ D7, B9, L7, R6, B4 },
		{ D7, B9, L7, B4, R6 },
		{ D7, B9, L7, B6, L4 },
		{ D7, B9, L7, L4, B6 },

		{ B9, L7, D7, F6, R4 },
		{ B9, L7, D7, R4, F6 },
		{ B9, L7, D7,  U6, R2 },
		{ B9, L7, D7, R2,  U6 },
		{ B9, L7, D7, U2, B2 },
		{ B9, L7, D7, B2, U2 },
		{ B9, L7, D7, U4, L2 },
		{ B9, L7, D7, L2, U4 },
		{ B9, L7, D7, U8, F2 },
		{ B9, L7, D7, F2, U8 },
		{ B9, L7, D7, F4, L6 },
		{ B9, L7, D7, L6, F4 },
		{ B9, L7, D7, R6, B4 },
		{ B9, L7, D7, B4, R6 },
		{ B9, L7, D7, B6, L4 },
		{ B9, L7, D7, L4, B6 },

		{ L7, D7, B9, F6, R4 },
		{ L7, D7, B9, R4, F6 },
		{ L7, D7, B9,  U6, R2 },
		{ L7, D7, B9, R2,  U6 },
		{ L7, D7, B9, U2, B2 },
		{ L7, D7, B9, B2, U2 },
		{ L7, D7, B9, U4, L2 },
		{ L7, D7, B9, L2, U4 },
		{ L7, D7, B9, U8, F2 },
		{ L7, D7, B9, F2, U8 },
		{ L7, D7, B9, F4, L6 },
		{ L7, D7, B9, L6, F4 },
		{ L7, D7, B9, R6, B4 },
		{ L7, D7, B9, B4, R6 },
		{ L7, D7, B9, B6, L4 },
		{ L7, D7, B9, L4, B6 },

		//-------------------------
		//      BR
		//-------------------------
		{ D9, R9, B7, F6, R4 },
		{ D9, R9, B7, R4, F6 },
		{ D9, R9, B7,  U6, R2 },
		{ D9, R9, B7, R2,  U6 },
		{ D9, R9, B7, U2, B2 },
		{ D9, R9, B7, B2, U2 },
		{ D9, R9, B7, U4, L2 },
		{ D9, R9, B7, L2, U4 },
		{ D9, R9, B7, U8, F2 },
		{ D9, R9, B7, F2, U8 },
		{ D9, R9, B7, F4, L6 },
		{ D9, R9, B7, L6, F4 },
		{ D9, R9, B7, R6, B4 },
		{ D9, R9, B7, B4, R6 },
		{ D9, R9, B7, B6, L4 },
		{ D9, R9, B7, L4, B6 },

		{ R9, B7, D9, F6, R4 },
		{ R9, B7, D9, R4, F6 },
		{ R9, B7, D9,  U6, R2 },
		{ R9, B7, D9, R2,  U6 },
		{ R9, B7, D9, U2, B2 },
		{ R9, B7, D9, B2, U2 },
		{ R9, B7, D9, U4, L2 },
		{ R9, B7, D9, L2, U4 },
		{ R9, B7, D9, U8, F2 },
		{ R9, B7, D9, F2, U8 },
		{ R9, B7, D9, F4, L6 },
		{ R9, B7, D9, L6, F4 },
		{ R9, B7, D9, R6, B4 },
		{ R9, B7, D9, B4, R6 },
		{ R9, B7, D9, B6, L4 },
		{ R9, B7, D9, L4, B6 },

		{ B7, D9, R9, F6, R4 },
		{ B7, D9, R9, R4, F6 },
		{ B7, D9, R9,  U6, R2 },
		{ B7, D9, R9, R2,  U6 },
		{ B7, D9, R9, U2, B2 },
		{ B7, D9, R9, B2, U2 },
		{ B7, D9, R9, U4, L2 },
		{ B7, D9, R9, L2, U4 },
		{ B7, D9, R9, U8, F2 },
		{ B7, D9, R9, F2, U8 },
		{ B7, D9, R9, F4, L6 },
		{ B7, D9, R9, L6, F4 },
		{ B7, D9, R9, R6, B4 },
		{ B7, D9, R9, B4, R6 },
		{ B7, D9, R9, B6, L4 },
		{ B7, D9, R9, L4, B6 },
		//-------------------------
		{ U3, B1, R3, F6, R4 },
		{ U3, B1, R3, R4, F6 },
		{ U3, B1, R3,  U6, R2 },
		{ U3, B1, R3, R2,  U6 },
		{ U3, B1, R3, U2, B2 },
		{ U3, B1, R3, B2, U2 },
		{ U3, B1, R3, U4, L2 },
		{ U3, B1, R3, L2, U4 },
		{ U3, B1, R3, U8, F2 },
		{ U3, B1, R3, F2, U8 },
		{ U3, B1, R3, F4, L6 },
		{ U3, B1, R3, L6, F4 },
		{ U3, B1, R3, R6, B4 },
		{ U3, B1, R3, B4, R6 },
		{ U3, B1, R3, B6, L4 },
		{ U3, B1, R3, L4, B6 },

		{ B1, R3, U3, F6, R4 },
		{ B1, R3, U3, R4, F6 },
		{ B1, R3, U3,  U6, R2 },
		{ B1, R3, U3, R2,  U6 },
		{ B1, R3, U3, U2, B2 },
		{ B1, R3, U3, B2, U2 },
		{ B1, R3, U3, U4, L2 },
		{ B1, R3, U3, L2, U4 },
		{ B1, R3, U3, U8, F2 },
		{ B1, R3, U3, F2, U8 },
		{ B1, R3, U3, F4, L6 },
		{ B1, R3, U3, L6, F4 },
		{ B1, R3, U3, R6, B4 },
		{ B1, R3, U3, B4, R6 },
		{ B1, R3, U3, B6, L4 },
		{ B1, R3, U3, L4, B6 },

		{ R3, U3, B1, F6, R4 },
		{ R3, U3, B1, R4, F6 },
		{ R3, U3, B1,  U6, R2 },
		{ R3, U3, B1, R2,  U6 },
		{ R3, U3, B1, U2, B2 },
		{ R3, U3, B1, B2, U2 },
		{ R3, U3, B1, U4, L2 },
		{ R3, U3, B1, L2, U4 },
		{ R3, U3, B1, U8, F2 },
		{ R3, U3, B1, F2, U8 },
		{ R3, U3, B1, F4, L6 },
		{ R3, U3, B1, L6, F4 },
		{ R3, U3, B1, R6, B4 },
		{ R3, U3, B1, B4, R6 },
		{ R3, U3, B1, B6, L4 },
		{ R3, U3, B1, L4, B6 }
};

class Pairs{
public:

	static void doPair(char cube[55]){
		int pair = getPair(cube);
		int i = 0;
		while (solveFirstPair[pair][i] != -1){
			Moves::doMove(cube, solveFirstPair[pair][i]);
			Moves::showMove(solveFirstPair[pair][i]);
			i++;
		}
		printf("\n\n");
	}

	static int getPair(char cube[55]){
		for (int i = 0; i < 60; i++){
			if (checkPair(cube, firstPairs[i]))
				return i;
		}
		return -1;
	}

	static bool checkPair(char cube[55],int pair[5]){
		if (cube[pair[0]] != 'Y')
			return false;
		if (cube[pair[1]] != 'G')
			return false;
		if (cube[pair[2]] != 'R')
			return false;
		if (cube[pair[3]] != 'G')
			return false;
		if (cube[pair[4]] != 'R')
			return false;
		return true;
	}

	static void randMoveForPairs(char cube[55], int maxMoves, int pair, int& k, int& move, int& moveP, int vMove[], bool doneMoves[][18]){
		if (k == maxMoves){
			k--;
			Moves::doMoveP(cube, moveP);
			vMove[k] = -1;
			moveP = vMove[k - 1];
			if (Moves::allMovesDone(doneMoves[k])){
				Moves::prevState(cube, doneMoves, vMove, moveP, k);
			}
		}
		do{
			move = rand() % 18;
		} while (doneMoves[k][move] || !Moves::checkMoves(move, moveP));
		Moves::doMove(cube, move);
		doneMoves[k][move] = true;
		vMove[k] = move;
		moveP = move;
		k++;
		if (k < maxMoves){
			Moves::clearMoves(doneMoves[k], moveP);
			clearMovesForPairs(doneMoves[k], pair);
		}
	}

	static void clearMovesForPairs(bool moves[18], int pair){
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
		case 4:
			moves[L] = true;
			moves[LP] = true;
			moves[LL] = true;
			break;
		};

	}

	static void solveFirstYellowPair(char cube[55]){
		system("Pause");
		printf("Zolta para 1: ");
		doPair(cube);
		system("Pause");

		/*int vMove[MAX_MOVES_P];
		bool doneMoves[MAX_MOVES_P][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_P; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
			clearMovesForPairs(doneMoves[i], 1);
		}

		srand(time(NULL));

		while (!(isFirstYellowPair(cube) && Cross::isYellowCrossMade(cube))){
			randMoveForPairs(cube, MAX_MOVES_P, 1, k, move, moveP, vMove, doneMoves);
		}

		printf("Zolta para 1: ");
		Moves::showSolution(vMove, MAX_MOVES_P);
		printf("\n\n");*/
	}

	static bool isFirstYellowPair(char cube[55]){
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

	static void solveSecondYellowPair(char cube[55]){
		int vMove[MAX_MOVES_P];
		bool doneMoves[MAX_MOVES_P][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_P; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
			clearMovesForPairs(doneMoves[i], 2);
		}

		srand(time(NULL));

		while (!(isSecondYellowPair(cube) && Cross::isYellowCrossMade(cube))){
			randMoveForPairs(cube, MAX_MOVES_P, 2, k, move, moveP, vMove, doneMoves);
		}

		printf("Zolta para 2: ");
		Moves::showSolution(vMove, MAX_MOVES_P);
		printf("\n\n");
	}

	static bool isSecondYellowPair(char cube[55]){
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

	static void solveThirdYellowPair(char cube[55]){
		int vMove[MAX_MOVES_P];
		bool doneMoves[MAX_MOVES_P][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_P; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
			clearMovesForPairs(doneMoves[i], 3);
		}

		srand(time(NULL));

		while (!(isThirdYellowPair(cube) && isSecondYellowPair(cube) && Cross::isYellowCrossMade(cube))){
			randMoveForPairs(cube, MAX_MOVES_P, 3, k, move, moveP, vMove, doneMoves);
		}

		printf("Zolta para 3: ");
		Moves::showSolution(vMove, MAX_MOVES_P);
		printf("\n\n");
	}

	static bool isThirdYellowPair(char cube[55]){
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

	static void solveFourthYellowPair(char cube[55]){
		int vMove[MAX_MOVES_P];
		bool doneMoves[MAX_MOVES_P][18];
		int move = -1,
			moveP = -1;
		int k = 0;

		for (int i = 0; i < MAX_MOVES_P; i++){
			vMove[i] = -1;
			Moves::clearAllMoves(doneMoves[i]);
			clearMovesForPairs(doneMoves[i], 4);
		}

		srand(time(NULL));

		while (!(isFourthYellowPair(cube) && isThirdYellowPair(cube) && isSecondYellowPair(cube) && Cross::isYellowCrossMade(cube))){
			randMoveForPairs(cube, MAX_MOVES_P, 4, k, move, moveP, vMove, doneMoves);
		}

		printf("Zolta para 4: ");
		Moves::showSolution(vMove, MAX_MOVES_P);
		printf("\n\n");
	}

	static bool isFourthYellowPair(char cube[55]){
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
};

#endif