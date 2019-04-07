#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	
	string str;
	
	cin >> str;
	vector<char> arr(str.size());
	for (int i = 0; i < str.size(); i++) {
		arr[i] = str.at(i);
	}

	sort(arr.begin(), arr.end(),greater<char>());

	for (int i = 0; i < arr.size(); i++) {
		printf("%c", arr[i]);
	}
	

	
}