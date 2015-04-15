#include "Game_header.h"

void MAKE_user()
{
	user_LEV = 1;
	user_AP = 80;
	user_DP = 10;
	user_MAX_HP = 350;
	user_NOW_HP = user_MAX_HP;
	NOW_EXP = 0;
	MAX_EXP = 100;
	NOW_det = 0;
	user_PNT = 0;
}

void MAKE_mon()
{
	mon_LEV = 1;
	mon_AP = 20;
	mon_DP = 5;
	mon_NOW_HP = 100;
	mon_MAX_HP = 100;
	mon_EXP = 30;
}