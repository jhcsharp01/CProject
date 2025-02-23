#include <stdio.h>

//void 함수
//반환 타입이 void 형태인 함수를 의미합니다.
//이 함수는 따로 return 값을 가지지 않습니다.
void sample()
{
	printf("Hello\n");
}
void add(int a, int b)
{
	int result = a + b;
	printf("result = %d\n", result);
}
//매개변수로 정수형 변수를 가지는 함수
void setAvalue(int a, int value)
{
	a = value;
}
//매개변수로 정수 포인터 변수를 가지는 함수 
void setAvalue2(int* a, int value)
{
	*a = value;
}
int main()
{
	sample();
	add(1, 5);

	int a = 7;
	setAvalue(a, 10);
	//1. 인자 값 (a : 7) , 10을 setAvalue에 전달합니다.
	//2. 매개변수 a에 인자값(a)의 값을 적용합니다.  value에는 10을 적용합니다.
	//3. a에 value의 값을 적용합니다.
	//4. 함수가 종료되면 매개변수 a의 값은 삭제됩니다.

	printf("a = %d\n", a);
	//바꾼건 인자 값(a)가 아닌 함수 내부의 값(매개변수) a이기 때문에 변화가 없습니다.

	setAvalue2(&a, 10); //매개변수가 int*이니 인자는 해당 형태가 받을 수 있는 주소의 형태로 받아야합니다.
	//1. 인자 값(a의 주소와 10)을 함수에 전달합니다.
	//2. 매개변수 a에는 a의 주소가, value에는 10이 적용됩니다.
	//3. a에 value의 값을 적용합니다.
	//4. 함수가 종료되면 매개변수 a의 값은 삭제됩니다.

	//단 a는 인자 값(a)의 주소를 가지고 있기 때문에, 값을 수정할 경우 실제 위치에 적용이 됩니다.
	//내부에서 a가 삭제되더라도, 값 자체의 수정은 적용이 됩니다.

	//결론) 1. 값으로 전달을 할 경우는 내부에서 값을 수정해도, 원본의 값은 변경되지 않습니다.(call by value)
	//		2. 주소로 전달을 할 경우에는 내부에서 수정하면, 실제 위치의 값도 수정이 됩니다.(call by reference)
	printf("a = %d\n", a);

	return 0;
}