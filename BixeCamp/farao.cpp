    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define fr(i, n) for(int i = 0; i < n; i++) 
    #define frr(i, n) for(int i = 1; i <= n; i++)
    #define frm(i, n) for(int i = n-1; i >= 0; i--) 
     
    #define pb push_back
     
    typedef pair<int,int> pii;
     
    typedef pair<int, int> ponto;
     
    #define mem(v, k) memset(v, k, sizeof(v));
     
    #define mp make_pair
    #define pq priority_queue
        
    #define ll long long
     
    #define MAXN 100010
    #define INF 1000000001
    ll conta[MAXN];
    ll max_left[4*MAXN], max_right[4*MAXN], sum_total[4*MAXN];
    ll num_max_left[4*MAXN], num_max_right[4*MAXN], num_total[4*MAXN], maximo[4*MAXN], num_maximo[4*MAXN];
    int n;
     
    struct trio{
        ll l;
        ll nl;
        ll r;
        ll nr;
        ll t;
        ll nt;
        ll resp;
        ll nresp;
    };
     
    void build(int i, int l, int r){
        if(l == r){
            max_left[i] = conta[l];
            max_right[i] = conta[l];
            num_max_left[i] = 1;
            num_max_right[i] = 1;
            sum_total[i] = conta[l];
            num_total[i] = 1;
            maximo[i] = conta[l];
            num_maximo[i] = 1;
        }
        else{
            int mid = (l+r)/2;
     
            build(2*i, l, mid);
            build(2*i+1, mid+1, r);
     
            sum_total[i] = sum_total[2*i] + sum_total[2*i+1];
            num_total[i] = num_total[2*i] + num_total[2*i+1];
     
            if(max_left[2*i] > sum_total[2*i] + max_left[2*i+1]){
                max_left[i] = max_left[2*i];
                num_max_left[i] = num_max_left[2*i];
            }
            else{
                max_left[i] = sum_total[2*i] + max_left[2*i+1];
                num_max_left[i] = num_total[2*i] + num_max_left[2*i+1];
            }
     
            if(max_right[2*i+1] > sum_total[2*i+1] + max_right[2*i]){
                max_right[i] = max_right[2*i+1];
                num_max_right[i] = num_max_right[2*i+1];
            }
            else{
                max_right[i] = sum_total[2*i+1] + max_right[2*i];
                num_max_right[i] = num_total[2*i+1] + num_max_right[2*i];
            }
     
            pq<pair<ll, ll>> R;
            R.push(mp(max_right[i], num_max_right[i]));
            R.push(mp(max_left[i], num_max_left[i]));
            R.push(mp(sum_total[i], num_total[i]));
            R.push(mp(max_right[2*i]+max_left[2*i+1], num_max_right[2*i]+num_max_left[2*i+1]));
     
            maximo[i] = R.top().first;
            num_maximo[i] = R.top().second;
        }
    }
     
    trio query(int i, int l, int r, int ql, int qr){
        trio q;
        if(ql <= l && r <= qr){
            q.l = max_left[i];
            q.nl = num_max_left[i];
            q.r = max_right[i];
            q.nr = num_max_right[i];
            q.t = sum_total[i];
            q.nt = num_total[i];
            q.resp = maximo[i];
            q.nresp = num_maximo[i]; 
        }
        else if(ql > r || l > qr){
            q.l = -INF;
            q.nl = -MAXN;
            q.r = -INF;
            q.nr = -MAXN;
            q.t = -INF;
            q.nt = -MAXN;
            q.resp = -INF;
            q.nresp = -MAXN;
        }
        else{
            int mid = (l+r)/2;
     
            trio left = query(2*i, l, mid, ql, qr), right = query(2*i+1, mid+1, r, ql, qr);
            q.t =left.t + right.t;
            q.nt = left.nt + right.nt;
     
            if(left.l > left.t + right.l){
                q.l = left.l;
                q.nl = left.nl;
            }
            else{
                q.l = left.t + right.l;
                q.nl = left.nt + right.nl;
            }
     
     
            if(right.r > right.t + left.r){
                q.r = right.r;
                q.nr = right.nr;
            }
            else{
                q.r = left.r + right.t;
                q.nr = left.nr + right.nt;
            }
            
        //  cout << "JESUS " << left.nr << " " << right.nt << endl;
     
            pq<pair<ll, ll>> R;
            R.push(mp(q.l, q.nl));
            R.push(mp(q.r, q.nr));
            R.push(mp(q.t, q.nt));
            R.push(mp(left.r + right.l, left.nr+ right.nl));
            q.resp = R.top().first;
            q.nresp = R.top().second;
        }
    /*
            cout << "q1 " << left.r <<" "<< left.nr << " okok " <<right.l << " "<< right.nl << endl;
            cout << "q2 "<< q.l << " " << q.nl << endl;
            cout << "q3 " << q.r << " " << q.nr << endl;
            cout << "Q4 " << q.t << " " << q.nt << endl;
        }
     
        //cout << i << " l " << l << " r " << r << endl;
    //  cout << q.l << " " << q.r <<" "<< q.t << endl;
     
        cout << q.resp << " " << q.nresp << endl;
        */return q;
    }
     
    int main(){
        int instancias;
        scanf("%d", &instancias);

        while(instancias--){
            cin >> n;
            
            frr(i, n) scanf("%Ld", &conta[i]);
            build(1, 1, n);
     
        //  frr(i, 30) cout << max_left[i] << " " << max_right[i] << " " << sum_total[i] << endl;
     
            int k;
            scanf("%d", &k);
     
            fr(i, k){
                int a, b;
                scanf("%d %d", &a, &b);
     
                trio re = query(1, 1, n, a, b);
     
                //cout << re.r << " " << re.l << ' ' << re.t << endl;
     
                printf("%Ld %Ld\n", re.resp, re.nresp);
     //           cout << re.resp << " " << re.nresp << endl;
            }
        }
    } 