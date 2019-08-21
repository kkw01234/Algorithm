#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//BOJ1449
bool water[1001]; //막혀있으면 true
int main()
{
	int N, L, count=0;
	scanf("%d %d", &N, &L); //물이 새는 곳 N, 테이프 길이 L
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end()); //정렬
	for (int i = 0; i < N; i++) {
		if (water[arr[i]]) { //만약 테이프로 막혀있으면 붙일 필요가 없으므로 그냥 지나간다
			continue;
		}
		for (int j = 0; j < L; j++) { //테이프의 길이만큼 붙인다
			water[arr[i] + j] = true;
		}
		count++;
	}

	printf("%d", count);

	arr.clear();
}