#include "Game_header.h"

void main()
{
	srand(time(NULL));
	printf("\n\t=========================================\n");
	printf("\t======당신은 어디까지 갈수 있을까여?=====\n");
	printf("\t=========================================\n\n\n");
	printf("\n\tLoading...\n\n");
	printf("\t\t캐릭터 초기 값 설정 중... ");
	MAKE_user();
	printf("완료!\n");
	printf("\t\t몬스터 초기 값 설정 중... ");
	MAKE_mon();
	printf("완료!\n");
	SELECT_MENU();
	printf("\n\t\t당신의 기록은 %d m 입니다.\n\n", NOW_det);
}