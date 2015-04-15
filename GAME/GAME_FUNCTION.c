#include "GAME_HEADER.h"

void SHOW_user()
{
	printf("\n\tUSER STATUS\n\n");
	printf("\t\t�Ÿ�\t: %d m\n", NOW_det);
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
		printf("\n\t\t��� ������ STAT PNT�� �����ϴ�.\n\n");
		return;
	}
	while(1)
	{
		if(user_PNT == 0)
		{
			printf("\n\t\t��� ������ STAT PNT�� �����ϴ�.");
			printf("\n\t\t�ǵ��� ���ϴ�.\n");
			break;
		}
		printf("\n\t\t���� STAT PNT : %d", user_PNT);
		printf("\n\t\t� �ɷ�ġ�� UP?\n");
		printf("\n\t\t1. AP+10\n");
		printf("\n\t\t2. DP+5\n");
		printf("\n\t\t3. HP+50\n");
		printf("\n\t\t0. ���\n\n");
		printf("\n\t���� : ");
		scanf("%d", &select);
		if(select == 1)
		{
			user_AP = user_AP+10;
			user_PNT--;
			printf("\n\t\t���ݷ��� 10�����Ͽ����ϴ�.");
			printf("\n\t\tAP : %d\n", user_AP);
		}
		else if(select == 2)
		{
			printf("\n\t\t������ 5�����Ͽ����ϴ�.");
			user_DP = user_DP+5;
			user_PNT--;
			printf("\n\t\tDP : %d\n", user_DP);
		}
		else if(select == 3)
		{
			printf("\n\t\tü���� 50�����Ͽ����ϴ�.");
			user_MAX_HP = user_MAX_HP+50;
			user_NOW_HP = user_NOW_HP+50;
			user_PNT--;
			printf("\n\t\tHP : %d/%d\n", user_NOW_HP, user_MAX_HP);
		}
		else
		{
			printf("\n\t\t�ǵ��� ���ϴ�.\n");
			return;
		}
	}
}

void ENTER()
{
	int tmp;
	printf("\n\t\t1. ��. �˰ڽ��ϴ�.\n");
	printf("\n\t���� : ");
	scanf("%d", &tmp);
}