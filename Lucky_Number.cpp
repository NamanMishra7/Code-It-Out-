#include <bits/stdc++.h>
using namespace std;

void put4n7(char arr[], int no4, int no7, int start) {
	while (no4--)
		arr[start++] = '4';
	while (no7--)
		arr[start++] = '7';
	arr[start] = '\0';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char str[100];
	char ans[100];
	cin >> str;
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len++;
	}
	if (len & 1) {
		put4n7(ans, (len+1)/2, (len+1)/2, 0);
	}
	else {
		int cnt4, cnt7;
		cnt4 = cnt7 = len/2;
		for (int i = 0; i < len; i++) {
			if (str[i] == '4') {
				if (cnt4) {
					ans[i] = '4';
					cnt4--;
				}
				else {
					put4n7(ans, cnt4, cnt7, i);
					break;
				}
			}
			else if (str[i] == '7') {
				if (cnt7) {
					ans[i] = '7';
					cnt7--;
				}
				else if (cnt4 != len/2){
					for (int j = i-1; j >= 0; j--) {
						if (ans[j] == '4') {
							cnt4++;
							if (cnt7) {
								ans[j] = '7';
								cnt7--;
								put4n7(ans, cnt4, cnt7, j+1);
								break;
							}
						}
						else {
							cnt7++;
						}
					}
					break;
				}
				else {
					cnt4 = cnt7 = (len/2) + 1;
					put4n7(ans, cnt4, cnt7, 0);
					break;
				}
			}
			else if (str[i] < '4') {
				put4n7(ans, cnt4, cnt7, i);
				break;
			}
			else if (str[i] < '7') {
				if (cnt7) {
					ans[i] = '7';
					cnt7--;
					put4n7(ans, cnt4, cnt7, i+1);
					break;
				}
				else if (cnt4 != len/2) {
					for (int j = i-1; j >= 0; j--) {
						if (ans[j] == '4') {
							cnt4++;
							if (cnt7) {
								ans[j] = '7';
								cnt7--;
								put4n7(ans, cnt4, cnt7, j+1);
								break;
							}
						}
						else {
							cnt7++;
						}
						if (j == 0) {
							cnt4 = cnt7 = (len/2) + 1;
							put4n7(ans, cnt4, cnt7, 0);
						}
					}
					break;
				}
				else {
					cnt4 = cnt7 = (len/2) + 1;
					put4n7(ans, cnt4, cnt7, 0);
					break;
				}
			}
			else {
				if (cnt4 == len/2) {
					cnt4 = cnt7 = (len/2) + 1;
					put4n7(ans, cnt4, cnt7, 0);
				}
				else {
					for (int j = i-1; j >= 0; j--) {
						if (ans[j] == '4') {
							cnt4++;
							if (cnt7) {
								ans[j] = '7';
								cnt7--;
								put4n7(ans, cnt4, cnt7, j+1);
								break;
							}
						}
						else {
							cnt7++;
						}
						if (j == 0) {
							cnt4 = cnt7 = (len/2) + 1;
							put4n7(ans, cnt4, cnt7, 0);
						}
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		if (ans[i] == '7' || ans[i] == '4')
			cout << ans[i];
		else
			break;
	}
	cout << "\n";
	return 0;
}
