#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define abs1 8002 //4000+i
using namespace std;
int n;
int list[abs1];
int main()
{

	scanf("%d", &n);
	vector<int> vec(n);
	vector<int> lowest(n);
	int x;
	int sum=0;
	int min=4000;
	int max=-4000;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
		if (min > x) {
			min = x;
		}
		if (max < x) {
			max = x;
		}
		list[4000 + x]++;
	}
	int count = 0;
	int maxc=0;
	for (int i = 0; i < abs1; i++) {
		for (int j = 0; j < list[i]; j++) {
			vec[count] = i-4000;
			count++;
			
		}
		if (maxc < list[i]) {
			maxc = list[i];
			lowest.clear();
			lowest.push_back(i-4000);
		}
		else if (maxc == list[i]) {
			lowest.push_back(i-4000);
		}
		if (count == n)
			break;
	}

	printf("%.0f\n%d\n%d\n%d", round((double)sum/n),vec[vec.size()/2],lowest[lowest.size()>1?1:0],max-min);

}