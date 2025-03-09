#include <stdio.h>
//전체에서 두 숫자의 합 조사
//N : 범위
//M : 횟수
//idx : 인덱스(두 조합의 위치를 알아야 하기 때문)
//sum : 총합(두 합의 조건이 6 이상임을 알아야 하기 때문

//준비물 : 배열 {1,2,3,4}
//조건 : M이 2면(선택된 값이 2개면) 두 숫자의 조합 분석
//      합이 조건에 맞으면 출력
//		아니면 종료

int arr[] = { 1,2,3,4 };

void Backtracking(int N, int M, int idx, int sum)
{
	if (M == 2)
	{
		if (sum > 6)
		{
			printf("%d %d", arr[idx - 1], arr[idx - 2]);
		}
		return;
	}

	for (int i = idx; i < N; i++)
	{
		Backtracking(N, M+1, i + 1, sum + arr[i]);
	}

}

int main()
{
	Backtracking(4, 0, 0, 0);
	return 0;
}