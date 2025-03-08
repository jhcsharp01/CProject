#include <stdio.h>

//포인터를 이용해 구조체를 사용해봅니다.

struct item
{
	int code; //아이템 코드(아이템 식별용)
	char name[30];
	char description[50];
};

int main()
{
	//구조체 포인터 사용법
	//struct 구조체명 *변수명;
	struct item *item01;

	struct item item02 = { 2, "FBSX-0479","PLUG IN BRIDGE" };

	//가리킬 주소값을 적용
	item01 = &item02;

	//포인터로 가리킨 값은 기존의 구조체명.변수명이 아닌 구조체명->변수명으로 바뀌게 됩니다.
	//직관적으로 가리키고 있는 값을 ->로 명시하고 있어서 구분하기 쉽습니다.
	printf("코드 : %d 이름 : %s  %s", item01->code, item01->name, item01->description);

	return 0;
}