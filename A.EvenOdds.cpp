#include <bits/stdc++.h> 
using namespace std; 
 
int main() 
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, k, tmp, ans;
	cin >> n >> k;
	tmp = n/2;
	if (n & 1) {
		tmp++;
	}
	if (k > tmp) {
		ans = 2 + (k-tmp-1)*2;
	}
	else {
		ans = 1 + (k-1)*2;
	}
	cout << ans << "\n";
	return 0; 
} 
