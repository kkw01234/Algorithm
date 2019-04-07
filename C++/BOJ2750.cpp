#include <iostream>
#include <stdio.h>
using namespace std;
int arr[1001];

void selection(int n, int index); // 2번문제
int minIndexSelect(int n, int index); // 3번문제



int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	selection(n, 0); //2번문제
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

void selection(int n, int index) { //Selection Sort Recursive
	if (index == n)
		return;

	int j = minIndexSelect(n, index);

	if (arr[j] < arr[index]) {
		swap(arr[index], arr[j]);
	}
	selection(n, index + 1);
}

int minIndexSelect(int n, int index) { 

	if (n-1 == index)
		return n-1;
	int j = minIndexSelect(n,index+1);
	return arr[index] < arr[j] ? index : j;

}