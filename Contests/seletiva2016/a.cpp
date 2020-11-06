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

    double h, w;
    cin >> h >> w;

    double x[4], y[4];

    frr(i, 4){
        cin >> x[i] >> y[i];
    }

    double num, den;

    if((abs(x[1] - x[2]) - abs(y[1] + y[4]))*(w - h) >= 0.0){

      double num = w*y[2]*x[1];
      double den = y[1]*w + y[2]*x[1] - y[1]*x[2];

      printf("%.10lf ", num/den);

      num = w*y[1]*y[2];
      den = -y[1]*x[2] + x[1]*y[1] + y[1]*w;

      printf("%.10lf\n", num/den);
    }
    else{
        double a = x[1] - y[1]*(x[2] - x[1])/(y[2] - y[1]);
        double b = y[1] - x[1]*(y[1] - y[4])/(x[1] - x[4]);
        double H = x[3] + (h-y[3])*(x[3] - x[4])/(y[3] - y[4]);
        double c = h;

        num = a*(h-a)*c + b*c*c;
        den = c*c - (h-a)*(h-a);

        printf("%.10lf ", num/den);

        num = a*(h-a)*(h-a) + b*c*(h-a) + a*(den);

        printf("%.10lf\n", num/den);
    }


                cout << num << " " << den << endl;
}
