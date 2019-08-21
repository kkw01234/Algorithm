/*
2.1 정렬후 회전된 배열에서 최댓값 찾기
“정렬후 회전된 배열”이란 (5, 8, 9, 2, 3, 4)와 같은 배열을 말한다. 즉, 정렬이 된 후에 회전 연산이
0 회 이상 적용된 배열이다. 회전 연산이란 배열의 마지막 원소가 처음으로 이동하고 나머지
원소들이 오른쪽으로 한 칸씩 이동하는 것을 말한다. 예를 들어, (2, 3, 4, 5, 8, 9)는 정렬된
배열이고 여기에 회전 연산을 1 회 적용하면 (9, 2, 3, 4, 5, 8)이 되고 여기에 회전 연산을 추가로
2 회 적용하면 (5, 8, 9, 2, 3, 4)가 된다. 따라서 (5, 8, 9, 2, 3, 4)는 정렬후 회전된 배열이다.
길이가 n 인 정렬후 회전된 배열 A[0..n-1]가 주어질 때, 이 배열 A 에서 최댓값을 찾는
알고리즘을 고안하고, 시간복잡도를 분석하시오.

이분탐색 변형
시간복잡도 T(n) = T(n/2) + O(1) => O(logn)

*/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


int func(vector<int> arr,int start,int end) {
	printf("%d %d\n", start, end);
	if (start == end)
		return arr[start];
	int mid = (start + end) / 2; //6이면 2가나오네여
	int good = 0;
	if (arr[start] > arr[mid+1]) {
		good = func(arr, start, mid);
	}
	else
		good =  func(arr, mid+1, end);
	return good;
}

int main()
{
	int N;

	scanf_s("%d", &N);
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("%d",func(arr,0,N-1));
}


