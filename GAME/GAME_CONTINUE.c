#include "GAME_HEADER.h"

void SELECT_MENU()
{
	int select;
	while(1)
	{
		printf("---------------------------------------------------\n");
		printf("\n\n\t게임을 시작합니다!!\n\t원하시는 메뉴를 선택하세요.\n\n");
		printf("\n\t\t1. 진행 카드 선택\n");
		printf("\n\t\t2. 유저 상태 확인\n");
		printf("\n\t\t3. 스탯 포인트 투자\n");
		printf("\n\t선택 : ");
		scanf("%d", &select);
		printf("---------------------------------------------------\n");
		if(select == 1)
		{
			SELECT_CARD();
			if(user_NOW_HP <= 0)	return;
			continue;
		}
		else if(select == 2)	
		{	
			SHOW_user();
			continue;
		}
		else if(select == 3)
		{
			STAT_up();
			continue;
		}
		else
		{
			printf("\t\t다시선택하십쇼.\n");
		}
	}
}

void SELECT_CARD()
{
	int select, card, tmp;
	srand(time(NULL));
	while(1)
	{
		printf("---------------------------------------------------\n");
		printf("\n\t\t현재까지 걸어온 거리 : %d m", NOW_det);
		printf("\n\t\t체력 : %d/%d\n", user_NOW_HP, user_MAX_HP);
		printf("\n\t\t당신은 세 방향 중\n\t\t한 방향을 선택 할 수 있습니다.\n\n");
		printf("\n\t\t1 : 왼쪽\n");
		printf("\n\t\t2 : 가운데\n");
		printf("\n\t\t3 : 오른쪽\n");
		printf("\n\t\t0 : 뒤로\n");
		printf("\n\t선택 : ");
		scanf("%d", &select);
		if(select == 0)	return;
		card = ((rand()+select)%20)+1;
		if(card >= 1 && card <= 6)	//몬스터 발견
		{
			NOW_det = NOW_det + ((rand()%100)+50);
			printf("\n\t\t=====================================");
			printf("\n\t\tLV.%d 몬스터를 발견했습니다. 전투가 시작됩니다!",mon_LEV);
			printf("\n\t\t=====================================\n");
			FIGHT();
			if(user_NOW_HP <= 0)	return;
			ENTER();
		}
		else if(card == 7 || card == 8)	//경험치 발견
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t지식의 책을 발견했습니다. 경험치 증가");
			printf("\n\t\tEXP+%d\n\n", MAX_EXP/10);
			NOW_EXP = NOW_EXP + (MAX_EXP/10);
			printf("\n\t\t현재 경험치 : %d/%d\n", NOW_EXP, MAX_EXP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
			QUE_LEVUP();
			ENTER();
		}
		else if(card >= 9 && card <= 16)	//공터 발견
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t공터를 발견했습니다.");
			printf("\n\t\t약간의 경험치가 상승합니다. EXP+%d", MAX_EXP/(rand()%10+35));
			NOW_EXP = NOW_EXP + MAX_EXP/(rand()%10+35);
			printf("\n\t\t현재 경험치 : %d/%d", NOW_EXP, MAX_EXP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
			ENTER();
		}
		else if(card == 17)	//지름길 발견
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t지름길을 발견했습니다.");
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + (((rand()%100)+50)*2);
			ENTER();
		}
		else if(card == 18 || card == 19)	//체력 회복 10%
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t은빛 기운이 감도는 샘를 발견했습니다.");
			user_NOW_HP = user_NOW_HP + (user_MAX_HP/10);
			if(user_NOW_HP > user_MAX_HP)
			{
				user_NOW_HP = user_MAX_HP;
			}
			printf("\n\t\t체력회복 10%%. 현재 HP : %d/%d\n",user_NOW_HP, user_MAX_HP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
		}
		else if(card == 20)	//체력 회복 30%
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t금빛 기운이 감도는 샘를 발견했습니다.");
			user_NOW_HP = user_NOW_HP + (user_MAX_HP/30);
			if(user_NOW_HP > user_MAX_HP)
			{
				user_NOW_HP = user_MAX_HP;
			}
			printf("\n\t\t체력회복 30%%. 현재 HP : %d/%d\n",user_NOW_HP, user_MAX_HP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
		}
		else
		{
			printf("\n\n버그가 발생했습니다ㅜㅜ WHERE?:SELECT_CARD()\n");
			exit(0);
		}
	}
}