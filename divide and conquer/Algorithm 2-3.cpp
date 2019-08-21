/*
https://algospot.com/judge/problem/read/FENCE
T(n) = 2T(n/2) + O(n) => O(nlogn) 하지만 최악의 경우 T(n) = T(n-1) + O(n) => O(n^2)
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
int func3(vector<int> arr, int start, int end) { //Divide and Conquer 이용 (무조건 O(nlogn))
	if (start == end) {
		return arr[start];
	}
	int mid = (start + end) / 2; // 7/2 =3


	

	int count = 0;
	int s = 0;
	int size=0;
	int left = mid, right = mid, x = 0;
	int maxarea = 0;
	bool lr = false; // false 이면 left, true 이면 right
	int minH = min(arr[left], arr[right]);
	while (true) {
		size = right - left;
		if (left >= start && right <= end) {
			if (arr[left] > arr[right]) {
				minH = min(minH, arr[left]);
				s = minH * size;
				maxarea = max(maxarea, s);
				left--;
			}
			else {
				minH = min(minH, arr[right]);
				s = minH * size;
				maxarea = max(maxarea, s);
				right++;
			}
		}
		else if (left >= start) {
			minH = min(minH, arr[left]);
			s = minH * size;
			maxarea = max(maxarea, s);
			left--;
		}
		else if (right <= end) {
			minH = min(minH, arr[right]);
			s = minH * size;
			maxarea = max(maxarea, s);
			right++;
		}
		else {
			break;
		}
	}
	int l = func3(arr, start, mid);

	int r = func3(arr, mid + 1, end);

	int good = max(l, r);
	
	return max(good, maxarea);

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
