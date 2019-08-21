/*
모든 4이상의 자연수를 N이라고 하면 모든 수는 1+ (N-1), 2+(N-2), 3+(N-3) 이루어집니다.
그러므로 현재 N에서 1, 2, 3의 합을 표현할 때 방법은 N-1개를 1, 2, 3의 합으로 표현할 수는 있는 방법과 N-2개를 1, 2, 3의 합으로 표현할 수는 있는 방법과 N-3개를 1, 2, 3의 합으로 표현할 수는 있는 방법의 합을 구하면 됩니다.

*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[100001] = { 0, };


int func1(int n) {
	//1의 부분합 -1
	//2의 부분합 -2
	//3의 부분합 - 1+1+1 1+2 2+1 3 ->4
	//4 -> 7
	//Base case
	arr1[1] = 1;
	arr1[2] = 2;
	arr1[3] = 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	int sum = 0;
	for (int i = 5; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= 3; j++) {
			sum += arr1[i - j];
		}
		arr1[i] = sum;
	}
	

	return arr1[n];
}


int main()
{
	int T;
	scanf("%d", &T);
	vector<int> result;
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);

		result.push_back(func1(N));
	}

	for (int i : result) {
		printf("%d\n", i);
	}
	

	

}

