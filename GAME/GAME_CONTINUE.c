#include "GAME_HEADER.h"

void SELECT_MENU()
{
	int select;
	while(1)
	{
		printf("---------------------------------------------------\n");
		printf("\n\n\t������ �����մϴ�!!\n\t���Ͻô� �޴��� �����ϼ���.\n\n");
		printf("\n\t\t1. ���� ī�� ����\n");
		printf("\n\t\t2. ���� ���� Ȯ��\n");
		printf("\n\t\t3. ���� ����Ʈ ����\n");
		printf("\n\t���� : ");
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
			printf("\t\t�ٽü����Ͻʼ�.\n");
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
		printf("\n\t\t������� �ɾ�� �Ÿ� : %d m", NOW_det);
		printf("\n\t\tü�� : %d/%d\n", user_NOW_HP, user_MAX_HP);
		printf("\n\t\t����� �� ���� ��\n\t\t�� ������ ���� �� �� �ֽ��ϴ�.\n\n");
		printf("\n\t\t1 : ����\n");
		printf("\n\t\t2 : ���\n");
		printf("\n\t\t3 : ������\n");
		printf("\n\t\t0 : �ڷ�\n");
		printf("\n\t���� : ");
		scanf("%d", &select);
		if(select == 0)	return;
		card = ((rand()+select)%20)+1;
		if(card >= 1 && card <= 6)	//���� �߰�
		{
			NOW_det = NOW_det + ((rand()%100)+50);
			printf("\n\t\t=====================================");
			printf("\n\t\tLV.%d ���͸� �߰��߽��ϴ�. ������ ���۵˴ϴ�!",mon_LEV);
			printf("\n\t\t=====================================\n");
			FIGHT();
			if(user_NOW_HP <= 0)	return;
			ENTER();
		}
		else if(card == 7 || card == 8)	//����ġ �߰�
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t������ å�� �߰��߽��ϴ�. ����ġ ����");
			printf("\n\t\tEXP+%d\n\n", MAX_EXP/10);
			NOW_EXP = NOW_EXP + (MAX_EXP/10);
			printf("\n\t\t���� ����ġ : %d/%d\n", NOW_EXP, MAX_EXP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
			QUE_LEVUP();
			ENTER();
		}
		else if(card >= 9 && card <= 16)	//���� �߰�
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t���͸� �߰��߽��ϴ�.");
			printf("\n\t\t�ణ�� ����ġ�� ����մϴ�. EXP+%d", MAX_EXP/(rand()%10+35));
			NOW_EXP = NOW_EXP + MAX_EXP/(rand()%10+35);
			printf("\n\t\t���� ����ġ : %d/%d", NOW_EXP, MAX_EXP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
			ENTER();
		}
		else if(card == 17)	//������ �߰�
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t�������� �߰��߽��ϴ�.");
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + (((rand()%100)+50)*2);
			ENTER();
		}
		else if(card == 18 || card == 19)	//ü�� ȸ�� 10%
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t���� ����� ������ ���� �߰��߽��ϴ�.");
			user_NOW_HP = user_NOW_HP + (user_MAX_HP/10);
			if(user_NOW_HP > user_MAX_HP)
			{
				user_NOW_HP = user_MAX_HP;
			}
			printf("\n\t\tü��ȸ�� 10%%. ���� HP : %d/%d\n",user_NOW_HP, user_MAX_HP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
		}
		else if(card == 20)	//ü�� ȸ�� 30%
		{
			printf("\n\t\t=====================================");
			printf("\n\t\t�ݺ� ����� ������ ���� �߰��߽��ϴ�.");
			user_NOW_HP = user_NOW_HP + (user_MAX_HP/30);
			if(user_NOW_HP > user_MAX_HP)
			{
				user_NOW_HP = user_MAX_HP;
			}
			printf("\n\t\tü��ȸ�� 30%%. ���� HP : %d/%d\n",user_NOW_HP, user_MAX_HP);
			printf("\n\t\t=====================================\n");
			NOW_det = NOW_det + ((rand()%100)+50);
		}
		else
		{
			printf("\n\n���װ� �߻��߽��ϴ٤̤� WHERE?:SELECT_CARD()\n");
			exit(0);
		}
	}
}