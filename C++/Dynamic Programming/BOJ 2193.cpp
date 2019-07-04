#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//BOJ 2193d

long long arr[100][2]; //0 => 첫자리가 0일때 , 1=> 첫자리가 1일 때
//int 형으로는 값이 초과됨 => longlong 이용

int main() //
{
	int n;
	scanf("%d", &n);
	
	arr[0][0] = 0, arr[0][1] = 1;
	arr[1][0] = 1, arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0]; //첫자리가 1일 때는 뒤에 무조건 0이 되어야함 (2번 규칙에 의해)
	}
	printf("%lld", arr[n][1]);


	return 0;
}