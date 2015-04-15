#include "GAME_HEADER.h"

void SHOW_user()
{
	printf("\n\tUSER STATUS\n\n");
	printf("\t\t거리\t: %d m\n", NOW_det);
	printf("\t\tLEVEL\t: %d\n", user_LEV);
	printf("\t\tAP\t: %d\n", user_AP);
	printf("\t\tDP\t: %d\n", user_DP);
	printf("\t\tHP\t: %d/%d\n", user_NOW_HP, user_MAX_HP);
	printf("\t\tEXP\t: %d/%d\n\n", NOW_EXP, MAX_EXP);
	printf("\n\t\tSTAT_PNT\t: %d\n\n", user_PNT);
}

void QUE_LEVUP()
{
	int tmp;
	if(NOW_EXP >= MAX_EXP)
	{
		printf("\n\t\tLEVEL UP!!\n");
		user_LEV++;
		user_PNT = user_PNT+3;
		tmp = NOW_EXP - MAX_EXP;
		MAX_EXP = MAX_EXP + 20;
		NOW_EXP = tmp;
		return;
	}
	else return;
}

void mon_LEVUP()
{
	mon_LEV++;
	mon_AP = mon_AP + 10;
	mon_DP = mon_DP + 5;
	mon_MAX_HP = mon_MAX_HP + (mon_MAX_HP/10);
	mon_NOW_HP = mon_MAX_HP;
	mon_EXP = mon_EXP + (mon_EXP/10);
}

void STAT_up()
{
	int select;
	if(user_PNT == 0)
	{
		printf("\n\t\t사용 가능한 STAT PNT가 없습니다.\n\n");
		return;
	}
	while(1)
	{
		if(user_PNT == 0)
		{
			printf("\n\t\t사용 가능한 STAT PNT가 없습니다.");
			printf("\n\t\t되돌아 갑니다.\n");
			break;
		}
		printf("\n\t\t현재 STAT PNT : %d", user_PNT);
		printf("\n\t\t어떤 능력치를 UP?\n");
		printf("\n\t\t1. AP+10\n");
		printf("\n\t\t2. DP+5\n");
		printf("\n\t\t3. HP+50\n");
		printf("\n\t\t0. 취소\n\n");
		printf("\n\t선택 : ");
		scanf("%d", &select);
		if(select == 1)
		{
			user_AP = user_AP+10;
			user_PNT--;
			printf("\n\t\t공격력이 10증가하였습니다.");
			printf("\n\t\tAP : %d\n", user_AP);
		}
		else if(select == 2)
		{
			printf("\n\t\t방어력이 5증가하였습니다.");
			user_DP = user_DP+5;
			user_PNT--;
			printf("\n\t\tDP : %d\n", user_DP);
		}
		else if(select == 3)
		{
			printf("\n\t\t체력이 50증가하였습니다.");
			user_MAX_HP = user_MAX_HP+50;
			user_NOW_HP = user_NOW_HP+50;
			user_PNT--;
			printf("\n\t\tHP : %d/%d\n", user_NOW_HP, user_MAX_HP);
		}
		else
		{
			printf("\n\t\t되돌아 갑니다.\n");
			return;
		}
	}
}

void ENTER()
{
	int tmp;
	printf("\n\t\t1. 네. 알겠습니다.\n");
	printf("\n\t선택 : ");
	scanf("%d", &tmp);
}