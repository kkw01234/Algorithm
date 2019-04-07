// 4주차 알고리즘.cpp
/*
다음을 해결하는 함수를 자신이 좋아하는 프로그래밍 언어로 반복문(while, for 등)을 사용하지 말고 작성하시오.
  1. n개의 수(정수 혹은 실수)의 총합을 계산하기
  2. selection sort
  3. bubble sort
*/
#include "pch.h"

#include <iostream>
#include <cstdio>
using namespace std;
int arr[1001];

int sum(int n); // 1번문제
void selection(int n, int index); // 2번문제
int minIndexSelect(int n, int index); // 3번문제
void bubble(int n, int index);
void bubbleSwap(int n, int index);


int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", arr + i);
	}
	//printf("%d", sum(n-1)); //1번문제
	selection(n, 0); //2번문제
	
	//bubble(n, 0); //3번문제
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

int sum(int n) {  //n개의 개수의 총합을 계산
	if (n==0)
		return arr[0];
	return arr[n]+sum(n-1);
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


void bubble(int n, int index) { //BubbleSort Recursive
	if (n == 0)
		return;
	bubbleSwap(n, index);
	
	bubble(n - 1, index);
}

void bubbleSwap(int n, int index) {
	if (n-1 == index)
		return;
	if (arr[index] > arr[index + 1]) {
		swap(arr[index], arr[index + 1]);
	}
	bubbleSwap(n, index + 1);

	
}



