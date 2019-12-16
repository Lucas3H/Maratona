#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, d;
	scanf("%d %d", &n, &d);

	while(n != 0 || d != 0){

		vector<int> r;
		vector<int> apagados;

		char numero[100010];
		scanf(" %s", numero);

		for(int i = 0; i < n; i++) r.push_back(int(numero[i] - 48));

		stack<int> resp;
		int j = 0;
		while(apagados.size() < d && j < n){

			if(resp.empty()){
				resp.push(r[j]);
				j++;
			}

			else if(r[j] > resp.top()){
				apagados.push_back(resp.top());
				resp.pop();
			}
			else{
				resp.push(r[j]);
				j++;
			}
		}

		for(int i = j; i < n; i++) resp.push(r[i]);

		vector<int> R;

		while(resp.size() > n-d)resp.pop();

		for(int i = 0; i < n - d; i++){
			R.push_back(resp.top());
			resp.pop();
		}


		
		for(int i = n-1-d; i >= 0; i--) printf("%d", R[i]);

		printf("\n");

		scanf("%d %d", &n ,&d);
	}

	return 0;
}