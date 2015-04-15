#include "GAME_HEADER.h"

void FIGHT()
{
	int select;
	int ATT, DAM;
	srand(time(NULL));
	printf("\n\t\t!!!!!!몬스터 출현!!!!\n");
	while(1)
	{
		printf("\n\t\tUSER lv.%d AP : %d, DP : %d, HP : %d/%d\n",user_LEV, user_AP, user_DP, user_NOW_HP, user_MAX_HP);
		printf("\n\t\tMONSTER lv.%d AP : %d, DP : %d, HP : %d/%d\n",mon_LEV, mon_AP, mon_DP, mon_NOW_HP, mon_MAX_HP);
		printf("\n\t\t1. 공격\n");
		printf("\n\t\t2. 도망\n");
		printf("\n\t선택 : ");
		scanf("%d", &select);
		if(select == 1)
		{
			ATT = ((rand()%20)+(user_AP-10))-mon_DP;
			printf("\n\t\t몬스터에게 %d의 데미지를 주었다!\n", ATT);
			mon_NOW_HP = mon_NOW_HP-ATT;
			DAM = ((rand()%20)+(mon_AP-10))-user_DP;
			if(mon_NOW_HP <= 0)	DAM=0;
			printf("\n\t\t몬스터로부터 %d의 데미지를 입었다!\n", DAM);
			user_NOW_HP = user_NOW_HP-DAM;
			if(user_NOW_HP <= 0)
			{
				printf("\n\t\t패배 했습니다.");
				return;
			}
			if(mon_NOW_HP <= 0)
			{
				printf("\n\t\t몬스터가 죽었습니다.");
				printf("\n\t\t다음 번에는 더 강한 몬스터가 나타납니다.\n");
				printf("\n\t\t경험치 획득 : EXP+%d", mon_EXP);
				NOW_EXP = NOW_EXP + mon_EXP;
				printf("\n\t\t현재 경험치 : %d/%d\n", NOW_EXP, MAX_EXP);
				QUE_LEVUP();
				mon_LEVUP();
				return;
			}
		}
		else if(select == 2)
		{
			if((rand()%100)<4)
			{
				printf("\n\t\t도망에 성공!\n");
				return;
			}
			else
			{
				printf("\n\t\t도망 실패! 공격 당합니다!");
				DAM = ((rand()%20)+mon_AP)-user_DP;
				printf("\n\t\t몬스터로부터 %d의 데미지를 입었다!\n", DAM);
				user_NOW_HP = user_NOW_HP-DAM;
			}
		}
	}
}
