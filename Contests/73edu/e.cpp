#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

    int q;
    cin >> q;

    int a, b;
    string s;

    while(q--){
        vector<int> sizes;

        cin >> a >> b;
        cin >> s;

        int maiores_que_a = 0;
        int maiores_que_2b = 0;
		int maiores_que_b = 0;
		int maiores_que_b_e_menores_que_a = 0;
		int grandao = 0;

        int i = 0;
        while(i < s.size()){
            int len = 0;

			if(s[i] == 'X'){
				i++;
				continue;
			}

			while(i < s.size() && s[i] == '.') {
				i++;
				len++;
			}


            if(len >= a) maiores_que_a++;
            if(len >= b) maiores_que_b++;

			if(len >= 2*b) maiores_que_2b++;
			if(len < a && len >= b) maiores_que_b_e_menores_que_a++;
			if(len > grandao) grandao = len;

			sizes.pb(len);
        }

        if(maiores_que_2b > 1){

			//cout << 3 << endl;
			cout << "NO" << endl;
            continue;
        }
        if(maiores_que_b_e_menores_que_a > 0){

			//cout << 4 << endl;
			cout << "NO" << endl;
            continue;
        }
		if(maiores_que_a < maiores_que_b){
			cout << "NO" << endl;
			continue;
		}

		int deu = 0;
		for(int i = 0; i <= grandao - a; i++){
			if(i < b && grandao - a - i < b){
				deu = 1;
				break;
			}

		}

		cout << "YES" << endl;
    }
}
