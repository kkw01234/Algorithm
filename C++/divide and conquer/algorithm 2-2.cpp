/*
2.2 최대합 부분배열
길이가 n 인 정수의 배열 A[0..n-1]가 있다. A[a] + A[a+1] + … + A[b]의 값을 최대화하는 (a, b)를
찾는 방법을 Divide-and-Conquer 전략을 이용하여 고안하고, 그 시간복잡도를 분석하라.
예를 들어, 배열 A 가 아래와 같이 주어졌을 경우 (n = 10),
31 -41 59 26 -53 58 97 -93 -23 84
답은 a = 2, b = 6 인 경우의 59+26-53+58+97=187 가 된다.

1.분할정복 이용
T(n) = T(n/2) + O(n) => O(nlogn)
2.동적계획법 이용
T(n) = T(n) + O(1) => O(n)
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dacmax(vector<int>& arr, int start, int end) {
	printf("%d %d \n", start, end);
	if (start == end) { //종료
		return arr[start];
	}
	int mid = (start + end) / 2; //절반 나누기-> 왼쪽과 오른쪽

	int leftmax = dacmax(arr, start, mid); //왼쪽 재귀
	int rightmax = dacmax(arr, mid + 1, end); // 오른쪽 재귀
	int a = max(leftmax, rightmax); //둘중에 최대값

	//중간값시작 왼쪽 최대합 찾기
	int left = 0, right = 0;
	int sum = 0;
	for (int i = mid; i >= start; i--) {
		sum += arr[i];
		left = max(left, sum); //어디까지가 최대값인지 모르니까 우선 sum값은 다구해놓고 max값비교
	}

	sum = 0; //sum 초기화 후 오른쪽부분 최대합 찾기
	for (int j = mid + 1; j < end; j++) {
		sum += arr[j];
		right = max(right, sum);
	}

	return max(left + right, a);//왼쪽 배열과 오른쪽배열과 중간에서 뻗어나간 값중에서 최대값 반환
}

int dpmax(vector<int>& arr) { //동적계획법 이용
	int sum = 0, ret = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum = max(sum, 0) + arr[i];
		ret = max(sum, ret);
	}
	return ret;
}

int main() {
	int n;
	scanf_s("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int max = dacmax(arr, 0, n - 1); //분할정복
	int max = dpmax(arr);//동적계획법
	printf("%d", max);
}

