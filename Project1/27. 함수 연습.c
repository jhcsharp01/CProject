#include <stdio.h>
//연습 문제 '백준 알고리즘 2587번 대표값2'
//첫 째 줄부터 다섯 번째 줄까지 한 줄씩 자연수를 입력할 수 있습니다.
//입력이 완료될 경우 첫째 줄에는 평균을 출력합니다.
//둘째 쭐에서는 중앙 값을 출력합니다.

//평균은 주어진 모든 수의 합 / 수의 개수로 표현합니다.
//중앙 값은 주어진 수를 크기 순서대로 정리했을 경우, 가장 중앙에 잇는 값을 의미

//ex)입력 값이 10 40 30 60 30 일 경우   (10 + 40 + 30 + 60 + 30) / 5 = 34
//   중앙 값을 계산하는 경우 10 30 30 40 60 중 가운데 값인 30
//위의 조건을 만족하는 함수를 설계해 프로그램을 완성하세요.
int avg(int sum, int count)
{
	return sum / count;
}
//배열 전체의 값을 조사해서 중앙 값 확인(배열 정렬)
int center(int numbers[], int size)
{
	int result = 0; //중앙 값
	int temp; //임시 값(값 교환용)
	//전체 횟수 반복
	for (int i = 0; i < size; i++)
	{
		//전체 사이즈보다 1 작은 범위부터 시작(처음 값과 다음 값을 비교하기 때문)
		for (int j = 0; j < (size - 1) - i; j++)
		{
			//i번째 값과 i+1번째 값을 비교해 i번째 값이 더 클 경우라면 변경한다.
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j]; //기존 값 저장
				numbers[j] = numbers[j + 1]; //다음 값 저장
				numbers[j + 1] = temp;//기존 값 넘겨줌
			}
		}
	}
	//정렬이 끝난 후 중앙 값 = 배열의 개수 /2 위치에 해당하는 값
	return result = numbers[size / 2];
}
int sum(int numbers[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += numbers[i];
	}
	return result;
}
int main()
{
	int numbers[5]; //숫자 5개에 대한 입력

	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &numbers[i]);
	}
	int sum_value = sum(numbers, 5); //배열의 합 = sum(배열,배열개수);
	int avg_value = avg(sum_value, 5);//배열의 평균 = avg(합, 배열개수);
	int center_value = center(numbers, 5);//배열의 중앙값 = center(배열,배열개수);

	printf("%d\n", avg_value);
	printf("%d\n", center_value);

	return 0;
}