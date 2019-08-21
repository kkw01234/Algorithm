#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a.compare(b) < 0;
	}
	else {//다를 경우
		return a.size() < b.size();
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<string> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(),compare);
	string duplicate;
	for (int i = 0; i < n; i++) {
		if (duplicate == vec[i]) {
			continue;
		}
		cout << vec[i] << endl;
		duplicate = vec[i];
	}
}
