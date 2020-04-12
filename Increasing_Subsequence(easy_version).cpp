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
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	char str[n];
	int front = 0, back = n-1, len = -1, lastval;
	if (arr[front] > arr[back]) {
		str[++len] = 'R';
		lastval = arr[back--];
	}
	else {
		str[++len] = 'L';
		lastval = arr[front++];
	}
	while (front <= back) {
		if (arr[front] < lastval && arr[back] < lastval) {
			break;
		}
		if (arr[front] < lastval && arr[back] > lastval) {
			lastval = arr[back--];
			str[++len] = 'R';
		}
		else if (arr[front] > lastval && arr[back] < lastval) {
			lastval = arr[front++];
			str[++len] = 'L';
		}
		else {
			if (arr[front] > arr[back]) {
				str[++len] = 'R';
				lastval = arr[back--];
			}
			else {
				str[++len] = 'L';
				lastval = arr[front++];
			}
		}
	}
	cout << len+1 << "\n";
	for (int i = 0; i < len+1; i++) {
		if (str[i] == 'L' || str[i] == 'R')
			cout << str[i];
		else
			break;
	}
	cout << "\n";
	return 0;
}
