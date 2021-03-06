#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

    int p1, p2, y1, y2, n;
    cin >> p1 >> p2 >> y1 >> y2 >> n;

    if(y1 > y2){
        swap(y1, y2);
        swap(p1, p2);
    }

    int minimo = max(0, n - p1*(y1 - 1) - p2*(y2 - 1));
    int maximo;

    if(n > p1*y1){
        maximo = (n-p1*y1)/y2 + p1;
    }
    else{
        maximo = n/y1;
    }

    cout << minimo << " " << maximo << endl;
}
