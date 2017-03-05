#include "Elements.h"
#include "Moves.h"

int OLLs[58][8]{
		//--------- KRZYZ -------------------
		{ U1, U3, U7, U9, U2, U4, U6, U8 },
		{ B3, B1, F1, F3, U2, U4, U6, U8 },
		{ L1, B1, L3, L3, U2, U4, U6, U8 },
		{ B3, U3, U7, R1, U2, U4, U6, U8 },
		{ B3, B1, U7, U9, U2, U4, U6, U8 },
		{ U1, U3, L3, R1, U2, U4, U6, U8 },
		{ L1, U3, F1, R1, U2, U4, U6, U8 },
		{ B3, R3, U7, F3, U2, U4, U6, U8 },
		//-----------KROPKA------------------
		{ L1, R3, L3, R1, B2, L2, R2, F2 },
		{ U1, R3, F1, U9, B2, L2, R2, F2 },
		{ L1, U3, L3, U9, B2, L2, R2, F2 },
		{ L1, B1, L3, F3, B2, L2, R2, F2 },
		{ U1, U3, L3, R1, B2, L2, R2, F2 },
		{ B3, R3, U7, F3, B2, L2, R2, F2 },
		{ L1, B1, F1, U9, B2, L2, R2, F2 },
		{ U1, U3, U7, U9, B2, L2, R2, F2 },
		//----------P---------------------
		{ B3, U3, F1, U9, U2, L2, U6, F2 },
		{ U1, B1, U7, F3, U2, U4, R2, F2 },
		{ U1, R3, U7, R1, U2, U4, R2, F2 },
		{ L1, U3, L3, U9, U2, L2, U6, F2 },
		//-----------W---------------------
		{ U1, B1, L3, U9, U2, L2, U6, F2 },
		{ B3, U3, U7, R1, U2, U4, R2, F2 },
		//------------MA£E L----------------
		{ L1, R3, L3, R1, U2, U4, R2, F2 },
		{ L1, R3, L3, R1, U2, L2, U6, F2 },
		{ B3, R3, F1, R1, U2, L2, U6, F2 },
		{ L1, B1, L3, F3, U2, U4, R2, F2 },
		{ L1, B1, L3, F3, B2, L2, U6, U8 },
		{ B3, R3, F1, R1, B2, U4, R2, U8 },
		{ U1, B1, F1, R1, B2, L2, U6, U8 },
		{ B3, U3, L3, F3, B2, U4, R2, U8 },
		//-------------C-------------------
		{ U1, U3, L3, R1, B2, U4, U6, F2 },
		{ U1, R3, U7, R1, U2, L2, R2, U8 },
		//-------------T--------------------
		{ B3, U3, F1, U9, B2, U4, U6, F2 },
		{ L1, U3, L3, U9, B2, U4, U6, F2 },
		//------------KRESKA---------------
		{ L1, R3, L3, R1, U2, L2, R2, U8 },
		{ B3, R3, F1, R1, B2, U4, U6, F2 },
		{ L1, R3, L3, R1, B2, U4, U6, F2 },
		{ B3, R3, F1, R1, U2, L2, R2, U8 },
		//------------KWADRAT-------------
		{ U1, R3, L3, F3, U2, U4, R2, F2 },
		{ L1, U3, F1, R1, U2, L2, U6, F2 },
		{ B3, U3, U7, R1, U2, L2, U6, F2 },
		{ U1, R3, F1, U9, U2, U4, R2, F2 },
		//------------PIORUN-------------
		{ B3, R3, U7, F3, U2, U4, R2, F2 },
		{ L1, B1, F1, U9, U2, L2, U6, F2 },
		{ B3, U3, L3, F3, U2, U4, R2, F2 },
		{ U1, B1, F1, R1, U2, L2, U6, F2 },
		{ L1, R3, U7, U9, U2, L2, U6, F2 },
		{ L1, R3, U7, U9, U2, U4, R2, F2 },
		{ U1, R3, U7, R1, U2, L2, U4, F2 },
		{ L1, U3, L3, U9, U2, U4, R2, F2 },
		//-------------S-------------------
		{ B3, U3, U7, R1, B2, U4, U6, F2 },
		{ U1, B1, L3, U9, B2, U4, U6, F2 },
		//-------------DUZE L-------------
		{ B3, R3, U7, F3, B2, U4, U6, F2 },
		{ L1, B1, F1, U9, B2, U4, U6, F2 },
		{ B3, R3, L3, U9, B2, U4, U6, F2 },
		{ L1, B1, U7, R1, B2, U4, U6, F2 },
		//----------H F-------------------
		{ U1, U3, U7, U9, B2, U4, U6, F2 },
		{ U1, U3, U7, U9, U2, U4, R2, F2 },
};

int solveOLL[58][16]{
	//--------- KRZYZ -------------------
		{ -1 },
		{ R, UU, RP, UP, R, U, RP, UP, R, UP, RP, -1 },
		{ R, UU, RR, UP, RR, UP, RR, UU, R, -1 },
		{ R, BP, RP, F, R, B, RP, FP, -1 },
		{ RR, DP, R, UU, RP, D, R, UU, R, -1 },
		{ R, B , RP, F, R, BP, RP, FP , -1 },
		{ R, UU, RP, UP, R, UP, RP, -1 },
		{ R, U, RP, U, R, UU, RP, -1 },
		//-----------KROPKA------------------
		{ R, UU, RR, F, R, FP, UU, RP, F, R, FP, -1 },
		{ L, FP , LP, F, UU, F, UP, R, UP, RP, FP, - 1 },
		{ R, UU, RR, F, R, FP, UU, RP, L, F, R, FP, LP, -1 },
		{ F, R, U, RP, UP, FP, B, U, L, UP, LP, BP, -1 },
		{ RP, UU, F, R, U, RP, UP, FF, UU, F, R, -1 },
		{ R, U, B, UP, BP, RP, U, R, B, U, BP, UP, RP, -1 },
		{ R, U, B, UP, BP, RP, UP, R, B, U, BP, UP, RP, -1 },
		{ F, RP, F, RR, U, RP, UP, FF, UP, L, FP, LP, F, -1 },
		//----------P---------------------
		{ RP, UP, F, U, R, UP, RP, FP, R, -1 },
		{ L, U , FP, UP, LP, U, L, F, LP, -1 },
		{ F, U, R, UP, RP, FP, -1 },
		{ FP, UP, LP, U, L, F, -1 },
		//-----------W---------------------
		{ LP, UP, L, UP, LP, U, L, U, L, FP, LP, F, -1 },
		{ R, U, RP, U, R, UP, RP, UP, RP, F, R, FP, -1 },
		//------------MA£E L----------------
		{ RP, FP, L, FP, LP, F, L, FP, LP, FF, R, -1 },
		{ L, F, RP, F, R, FP, RP, F, R, FF, LP, -1 },
		{ FP, LP, UP, L, U, LP, UP, L, U, F, -1 },
		{ F, R, U, RP, UP, R, U, RP, UP, FP, -1 },
		{ R, BP, R, B, RR, UU, F, RP, FP, R, -1 },
		{ R, BP, RR, F, RR, B, RR, FP, R, -1 },
		{ LP, UP, L, B, LP, BP, U, B, L, BP, -1},
		{ R, U, RP, BP, R, B, UP, BP, RP, B, -1 },
		//-------------C-------------------
		{ RP, UP, R, U, F, R, BP, RP, B, FP, -1 },
		{ RP, UP, RP, F, R, FP, U, R, -1 },
		//-------------T--------------------
		{ R, U, RP, UP, RP, F, R, FP, -1 },
		{ F, R, U, RP, UP, F, -1 },
		//------------KRESKA---------------
		{ R, UU, RR, UP, R, UP, RP, UU, F, R, FP, -1 },
		{ F, U, R, UP, RP, U, R, UP, RP, FP, -1 },
		{ F, R, U, RP, UP, R, FP, L, F, RP, FP, LP, -1 },
		{ RP, UP,R, UP, RP, U, FP, U, F, R, -1 },
		//------------KWADRAT-------------
		{ RP, FF, L, F, LP, F, R, -1 },
		{ L,FF, RP, FP, R, FP, LP, -1 },
		{ RP, UU, RR,  BP, RP, B, RP, UU, R, -1},
		{ F, RP, FP, R, U, R, UP, RP, -1 },
		//------------PIORUN-------------
		{ L, F, RP, F, R, FF, LP, -1 },
		{ RP, FP, L, FP, LP, FF, R, -1 },
		{ RP, LL, F, LP, F, L, FF, LP, F, LP, R, -1 },
		{ L, RR, FP, R, FP, RP, FF, R, FP, LP, R, -1 },
		{ FP, L, FP, LL, U, L, U, LP, UP, L, FF, -1 },
		{ F, RP, F, RR, UP, RP, UP, R, U, RP, FF, -1 },
		{ L, FP, LP, F, L, FP, LP, F, LP, UP, L, U, LP, UP, L, -1 },
		{ RP, F, R, FP, RP, F, R, FP, R, U, RP, UP, R, U, RP, -1 },
		//-------------S-------------------
		{ L, FP, LP, UP, L, U, F, UP, L, -1 },
		{ RP, F, R, U, RP, UP, FP, U, R, -1 },
		//-------------DUZE L-------------
		{ L, FP, LP, UP, L, F, LP, FP, U, F, -1 },
		{ RP, F, R, U, RP, FP, R,  F, UP, FP, -1 },
		{ LP, BP, L, RP, UP, R, U, LP, B, L, -1 },
		{ R, B, RP, L, U, LP, UP, R, BP, RP, -1 },
		//----------H F-------------------
		{ R, U, RP, UP, L, RP, F, R, FP, LP, -1 },
		{ L, F, RP, FP, LP, R, U, R, UP, RP, -1 },
};