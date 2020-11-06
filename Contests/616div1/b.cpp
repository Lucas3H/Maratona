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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
#define LOGN 20
int q;
string s;

class BIT{
    public:
        int v[MAXN], bit[MAXN];
        int n;

        void update(int i, int val){
            while(i <= n){
                bit[i] += val;
                i += i & (-i);
            }
        }

        int query(int i){
            int sum = 0;

            while(i > 0){
                sum += bit[i];
                i -= i & (-i);
            }

            return sum;
        }

        int binary_search(int v){
	        int sum = 0, pos = 0;
	
            int i = LOGN;

        	while(i >= 0){
		        if(pos + (1 << i) < n && sum + bit[pos + (1 << i)] < v){
			        sum += bit[pos + (1 << i)];
			        pos += (1 << i);
		        }

                i--;
	        }

	        return pos + 1; 
        }

        void build(){
            fr(i, n+1) bit[i] = 0;
            frr(i, n) update(i, v[i]);
        }
};

BIT b[30];

int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	cin >> q;

	fr(i, 26){
		b[i].build();
		b[i].n = s.size();
	}

	fr(i, s.size()){
		b[s[i] - 'a'].update(i + 1, 1);
		//cout << b[s[i] - 'a'].query(i + 1) << endl;
	}


	while(q--){
		int l, r;
		cin >> l >> r;

		if(l == r){
			cout << "Yes\n";
			continue;
		}

		if(s[l - 1] == s[r - 1]){
			int deu = 0;
			fr(j, 26){
				if((int)s[l-1] == ((int)'a' + j))  continue;

				//cout << b[j].query(r) << " " << b[j].query(l - 1) << endl;

				if(b[j].query(r) > b[j].query(l - 1)){
					deu++;
				}

				if(deu == 2){
					break;
				}
			}

			if(deu == 2) cout << "Yes\n";
			else cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
}
