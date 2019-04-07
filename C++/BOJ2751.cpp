#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> vec;
void heap(int n, int i);
void heapSort(int n);
int main()
{
	scanf("%d", &n);
	//vec.reserve(n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d",&x);
		vec.push_back(x);
	}

	heapSort(n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", vec[i]);
	}
}
void heap(int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2, largest = i;
	if (left<n&&vec[left] > vec[largest]) largest = left;
	if (right<n&&vec[right] > vec[largest]) largest = right;
	if (largest == i) return;
	swap(vec[i], vec[largest]);
	heap(n, largest);

}

void heapSort(int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heap(n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(vec[0], vec[i]);
		heap(i, 0);
	}
}
