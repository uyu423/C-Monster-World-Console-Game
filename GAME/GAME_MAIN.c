#include "Game_header.h"

void main()
{
	srand(time(NULL));
	printf("\n\t=========================================\n");
	printf("\t======����� ������ ���� �����?=====\n");
	printf("\t=========================================\n\n\n");
	printf("\n\tLoading...\n\n");
	printf("\t\tĳ���� �ʱ� �� ���� ��... ");
	MAKE_user();
	printf("�Ϸ�!\n");
	printf("\t\t���� �ʱ� �� ���� ��... ");
	MAKE_mon();
	printf("�Ϸ�!\n");
	SELECT_MENU();
	printf("\n\t\t����� ����� %d m �Դϴ�.\n\n", NOW_det);
}