#include<bits/stdc++.h>

using namespace std;

int main(){
	int c, n;

	cin >> c >> n;

	priority_queue<long long> caixa;

	int resp = 0;

	for(int i = 0; i < n; i++){
		int entrada, atendimento;

		cin >> entrada >> atendimento;

		if(caixa.size() == c){
			long long fim = caixa.top();
			caixa.pop();

			if(-fim - 20 > entrada){
				resp++;
			}

			if(entrada > -fim) caixa.push(-entrada - atendimento);
			else caixa.push(fim - atendimento);

		}
		else{
			caixa.push(-entrada - atendimento);
		}
	}

	cout << resp << endl;

	return 0;
}