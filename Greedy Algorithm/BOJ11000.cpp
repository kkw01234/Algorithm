#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//BOJ 1931



int main()
{
	int N, x,y;
	scanf("%d", &N);

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		v[i] = make_pair(x, y);
	}

	sort(v.begin(), v.end()); // 시작을 오름 차순으로 nlogn

	priority_queue<int, vector<int>, greater<int>> pq;  //greater => 작은 수부터
	int count = 0;
	int end = 0;

	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() > v[i].first) {
			pq.push(v[i].second);
		}
		else
		{
			pq.pop();
			pq.push(v[i].second);
		}
	}

	printf("%d", pq.size());
	return 0;
}