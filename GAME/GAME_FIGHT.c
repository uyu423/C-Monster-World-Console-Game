#include "GAME_HEADER.h"

void FIGHT()
{
	int select;
	int ATT, DAM;
	srand(time(NULL));
	printf("\n\t\t!!!!!!���� ����!!!!\n");
	while(1)
	{
		printf("\n\t\tUSER lv.%d AP : %d, DP : %d, HP : %d/%d\n",user_LEV, user_AP, user_DP, user_NOW_HP, user_MAX_HP);
		printf("\n\t\tMONSTER lv.%d AP : %d, DP : %d, HP : %d/%d\n",mon_LEV, mon_AP, mon_DP, mon_NOW_HP, mon_MAX_HP);
		printf("\n\t\t1. ����\n");
		printf("\n\t\t2. ����\n");
		printf("\n\t���� : ");
		scanf("%d", &select);
		if(select == 1)
		{
			ATT = ((rand()%20)+(user_AP-10))-mon_DP;
			printf("\n\t\t���Ϳ��� %d�� �������� �־���!\n", ATT);
			mon_NOW_HP = mon_NOW_HP-ATT;
			DAM = ((rand()%20)+(mon_AP-10))-user_DP;
			if(mon_NOW_HP <= 0)	DAM=0;
			printf("\n\t\t���ͷκ��� %d�� �������� �Ծ���!\n", DAM);
			user_NOW_HP = user_NOW_HP-DAM;
			if(user_NOW_HP <= 0)
			{
				printf("\n\t\t�й� �߽��ϴ�.");
				return;
			}
			if(mon_NOW_HP <= 0)
			{
				printf("\n\t\t���Ͱ� �׾����ϴ�.");
				printf("\n\t\t���� ������ �� ���� ���Ͱ� ��Ÿ���ϴ�.\n");
				printf("\n\t\t����ġ ȹ�� : EXP+%d", mon_EXP);
				NOW_EXP = NOW_EXP + mon_EXP;
				printf("\n\t\t���� ����ġ : %d/%d\n", NOW_EXP, MAX_EXP);
				QUE_LEVUP();
				mon_LEVUP();
				return;
			}
		}
		else if(select == 2)
		{
			if((rand()%100)<4)
			{
				printf("\n\t\t������ ����!\n");
				return;
			}
			else
			{
				printf("\n\t\t���� ����! ���� ���մϴ�!");
				DAM = ((rand()%20)+mon_AP)-user_DP;
				printf("\n\t\t���ͷκ��� %d�� �������� �Ծ���!\n", DAM);
				user_NOW_HP = user_NOW_HP-DAM;
			}
		}
	}
}
