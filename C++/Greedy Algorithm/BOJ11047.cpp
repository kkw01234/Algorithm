#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//BOJ 11047

int main()
{
	int N, K, count = 0; // N = 준규가 가지고 있는 동전 종류. K = 현금, count = 동전 개수 최소값
	scanf("%d %d", &N, &K);
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	int i = N-1;
	while(K>0) {
		if (K < v[i]) { //K 가 현재 동전보다 클경우 그 동전을 택할 수 없음
			i--;
			continue;
		}
		K -= v[i];
		count++;
	}
	printf("%d", count);
	v.clear();
}