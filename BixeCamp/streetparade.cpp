#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

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

    int n;
    cin >> n;

		while(n!=0){
    queue<int> st;
    stack<int> side;

    int a;
    fr(i, n){
      cin >> a;
      st.push(a);
    }

    int last = 0;

    while(true){

      if(!side.empty() && side.top() == last+1){
        last++;
        side.pop();
        continue;
      }

      while(!st.empty() && st.front() != last + 1){
        side.push(st.front());
        st.pop();

//				cout << "OK" << endl;

			}

      if(st.empty()) break;

      last++;
      st.pop();

		}

    if(last == n) cout << "yes"<< endl;
    else cout << "no" << endl;

		cin >> n;
	}
}
