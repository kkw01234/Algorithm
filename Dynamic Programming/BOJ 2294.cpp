#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//BOJ 2294
const int NF = 1000000000;

int main() 
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	vector<int> vec(n+1);
	
	vec[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &vec[i]);
	}
	vector<vector<int>> arr(n+1, vector<int>(k+1));
	
	for (int i = 0; i <= n; i++) { //최대수로 모두 초기화
		for (int j = 1; j <= k; j++) {
			arr[i][j] = NF;
		}
	}

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= k; j++) {
			if (j - vec[i] >= 0)// j-vec[i] 음수 가능성!!
				arr[i][j] = min(arr[i][j - vec[i]] + 1, arr[i - 1][j]);
			else
				arr[i][j] = arr[i - 1][j];
		}
	}

	if (arr[n][k] >= NF) { //구하지 못할경우 -1 출력
		printf("-1");
	}else
		printf("%d", arr[n][k]);
	
	return 0;
}