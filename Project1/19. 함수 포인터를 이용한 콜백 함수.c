#include <stdio.h>

//콜백 함수(callback)은 다른 코드의 인수로 넘겨주는 실행 가능한 코드를 의미합니다.
//콜백으로 넘겨받은 코드는 설계에 따라 즉시 실행하거나, 나중에 실행하는게 가능합니다.
//특정 이벤트가 발생했을 때, 사용자가 원하는 기능을 수행하도록 하기 위한 용도로 설계합니다.

//콜백 함수를 만드는 방법
//1. 콜백 함수에 대한 정의
//typedef는 자료형 대신 지어준 이름으로, 대신 표현할 수 있게 도와주는 기능입니다.
typedef void (*callback)(void);
//2. 콜백 함수에 대한 설정을 진행할 함수 정의
void setCallback(callback);
//3. 콜백 함수에 대한 사용을 진행할 함수 정의
void useCallback(void);
//4. 사용자가 쓸 함수에 대한 정의
void useFunction(void);

//5. 콜백에 대한 전역 변수 선언
callback user_callback = NULL;

int main()
{
	printf("콜백 함수 설정 전 호출 진행\n");
	useCallback();

	//콜백 함수 설정(함수 포인터)
	setCallback(useFunction);

	printf("콜백 함수 설정 후 호출 진행\n");
	useCallback();

	return 0;
}
//6. 아래에 함수 구현
void setCallback(callback fp)
{
	user_callback = fp;
}

void useCallback(void)
{
	//user_callback에 값이 설정되어있다면
	if (user_callback)
	{
		//콜백 함수를 실행합니다.
		user_callback();
	}
	else
	{
		//아닌 경우라면 메세지만 전달합니다.
		printf("None Callback\n");
	}
}

void useFunction(void)
{
	printf("callback function completed\n");
}
