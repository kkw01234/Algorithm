#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//BOJ 1931


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) { //종료시간이 같을 때
		return a.first < b.first;
	}	//종료시간이 다를 때
	return a.second < b.second;
}

int main()
{
	int N;
	int x, y;
	scanf("%d", &N);
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++) {
		
		scanf("%d %d", &x, &y);
		pair<int, int> p = make_pair(x, y);
		arr[i] = p;
	}

	sort(arr.begin(), arr.end(), cmp);


	int count = 0;
	int maxtime = 0;
	for (int i = 0; i < N; i++) {
		if (maxtime <= arr[i].first) {
			maxtime = arr[i].second;
			count++;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
