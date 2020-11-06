#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define ll long long

int weights[MAXN], values[MAXN];
ll pd[MAXN][MAXN];

int n, s;

ll solve(int item, int weight) {
	//cout << "item = " << item << " weight = " << weight << endl;
	if (pd[item][weight] != -1) return pd[item][weight];
	if (item == n || weight < 0) return pd[item][weight] = 0;
	
	ll maxPicked = solve(item+1, weight);
	int toPick = 1;
	while (weight - toPick*weights[item] >= 0) {
		ll pickedNow = toPick*values[item] + solve(item+1, weight - toPick*weights[item]);
		maxPicked = max(maxPicked, pickedNow);
		toPick++;
	}
	return pd[item][weight] = maxPicked;
}

int main() {
	memset(pd, -1, sizeof pd);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> weights[i] >> values[i];
	}
	cout << solve(0, s) << endl;
}
