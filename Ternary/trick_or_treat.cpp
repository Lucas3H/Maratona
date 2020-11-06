// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3349

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

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

double dist(pair<double, double> p, double l){
    return (p.f - l)*(p.f - l) + p.s*p.s;
}

int main(){
    int n;
    cin >> n;

    while(n!=0){

        pair<double, double> p[50010];

        double x, y;
        fr(i, n) {
            cin >> x >> y;
            p[i] = mp(x, y);
        }    



        sort(p, p+n);

        double l = p[0].f, r = p[n-1].f;

        int cont = 40;

        while(cont--){
            double t1 = l + (r - l)/3;
            double t2 = r - (r - l)/3;

            double m1 = 0, m2 = 0;
            fr(i, n){
                m1 = max(m1, dist(p[i], t1));
                m2 = max(m2, dist(p[i], t2));
            }

            if(m1 < m2) r = t2;
            else l = t1;

        //    cout << l << " " << r << endl;        

        }

        double ans = 0;
        fr(i, n){
            ans = max(ans, dist(p[i], (l+r)/2));
        }


        printf("%.10lf %.10lf\n", (l+r)/2, sqrt(ans));

        cin >> n;
    }

}
