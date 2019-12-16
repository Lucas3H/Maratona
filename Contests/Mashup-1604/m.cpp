#include<bits/stdc++.h>
#define eps .00000008

using namespace std;

int main(){
	int m, n;

	scanf("%d %d", &m, &n);

	long long t[1010], d[1010];

	for(int i = 0; i < m; i++) scanf("%lld", &t[i]);
	for(int i = 0; i < n; i++) scanf("%lld", &d[i]);


	vector<long long> resp;

	for(int i = 0; i < n - m + 1; i++){
		double v = (d[i+1] - d[i])/((double)t[1] - t[0]);
		int ok = 1;

		for(int j = i+1; j < i + m - 1; j++){
			double V = (d[j+1] - d[j])/((double)t[j - i + 1] - t[j - i]);
			if(abs(V-v) > eps){
				ok = 0;
				break; 
			}
		}

		if(ok){
			resp.push_back(d[i+1] - d[i]);
		}
	}

	sort(resp.begin(), resp.end());
	resp.erase(unique(resp.begin(), resp.end()), resp.end());

	printf("%d\n", resp.size());

	for(long long x: resp){
		printf("%lld ", x);
	}
}