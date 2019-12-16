#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long lon

#define MAXN 1000100

int n, k;
int valor[MAXN];

void atualiza(int no, int i, int j, int posicao, int valor_atual){
	if(i == j) valor[no] = valor_atual;
	else{
		int meio = (i+j)/2;
		
		if(posicao > meio) atualiza(2*no + 2, meio + 1, j, posicao, valor_atual);
		else atualiza(2*no + 1, i, meio, posicao, valor_atual);
		
		int left = valor[2*no + 1], right = valor[2*no + 2];

		if(left*right == 0) valor[no] = 0;
		else if(left*right > 0) valor[no] = 1;
		else valor[no] = -1; 
	}
}

int consulta(int no, int i, int j, int a, int b){
	if(a <= i && b >= j) return valor[no];
	
	else if(a > j || b < i) return MAXN;

	else{
		int meio = (i+j)/2;

		int left = consulta(2*no + 1, i, meio, a, b), right = consulta(2*no + 2, meio+1, j, a, b);

		if(left == MAXN) return right;
		
		else if(right == MAXN) return left;

		if(left*right == 0) return 0;
		else if(left*right > 0) return 1;
		else return -1;
	}
}

int main(){
	while(scanf("%d %d", &n, &k) != EOF){
		frr(i, n){
			int x;
			cin >> x;

			atualiza(0, 1, n, i, x);
		}

		vector<int> resp;

		while(k--){
			char c;
			int a, b;

			cin >> c >> a >> b;

			if(c == 'C'){
				if(b > 0) b = 1;
				else if(b < 0) b = -1;

				atualiza(0, 1, n, a, b);
			}
			else{
				resp.pb(consulta(0, 1, n, a, b));
			}
		}

		fr(i, resp.size()){
			if(resp[i] == 0) cout << '0';
			else if(resp[i] > 0) cout << '+';
			else cout << '-';
		}

		cout << endl;
	}

}