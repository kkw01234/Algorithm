/*
https://algospot.com/judge/problem/read/FENCE
T(n) = 2T(n/2) + O(n) => O(nlogn)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int allmin(vector<int>& arr, int start, int end) { //제일 최솟값을 구함

	int min = arr[start + 1];
	int minindex = start + 1;
	for (int i = start + 2; i <= end; i++) {
		if (min > arr[i]) {
			min = arr[i];
			minindex = i;
		}
	}

	return minindex;
}
int fence(vector<int>& arr, int start, int end) {
	if (start == end) { // 기저 사례 (start보다 end가 작을 경우 종료시킴)
		return arr[start];
	}
	int div = allmin(arr, start, end); //최소값을 받아옴
	int area = arr[div] * (end - start); // 현재의 넓이를 구함 (세로 = 최솟값 , 가로는 최솟값이 세로일때가능한 가로)
	int left = fence(arr, start, div - 1); // 최소값이 있는 곳의 왼쪽을 재구호출
	int right = fence(arr, div, end); //최소값이 있느 곳의 오른쪽으로 재귀호출
	int a = max(left, right);
	int b = max(area, a); //셋중에 최대값을 구함
	return b;
}
int main3() {
	int ans[50];
	int k = 0;

	scanf_s("%d", &k);

	for (int a = 0; a < k; a++) {
		int n;
		scanf_s("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &arr[i]);
		}
		int max = fence(arr, 0, n - 1);
		ans[a] = max;
	}
	for (int i = 0; i < k; i++) {
		printf("%d\n", ans[i]);
	}
}
