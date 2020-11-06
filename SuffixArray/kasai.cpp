#inclue<bits/stdc++.h>

using namespaces std;

#define mp make_pair

/*
    Calcula o LCP(longest common prefix) de quaisquer cois sufixos em tempo log n
*/

vector<int> suffixArray(string s){
    int n = s.size();
    
    vector<int> p(n), r(n), aux(n);


    /* Construir o caso base dos ranks(de tamanho 2^0)*/
    for(int i = 0; i < n; i++){
        p[i] = i;
        r[i] = (int)s[i];
    }

    /*
        Construir ranks das string de tamanho 2^k com base nos ranks das strings de 
        tamanho 2^(k-1)
    */
    for(int d = 1; d <= n; d *= 2){
        sort(p, p + n, [&](int a, int b){return mp(r[a], r[a + d]) < mp(r[b], r[b + d])});
    
        aux[p[0]] = 0;

        for(int i = 1, j = 0; i < n; i++, j++){
            aux[p[i]] = aux[p[j]] + (mp(r[i], r[i + d]) != mp(r[j], r[j + d]) );
        }

        for(int i = 0; i < n; i++){
            r[i] = aux[i];
        }

        if(r[p[n-1]] == n - 1) break;
    }
}

/*Constroi o vetor em que v[p[i]] é o lcp entre p[i] e p[i] + 1.*/
vector<int> build_lcp(string s){
    vector<int> p = suffixArray(s), r(n), lcp(n);

    for(int i = 0; i < n; i++) r[p[i]] = i;

    int h = 0;
    int j = p[r[0] + 1]

    while(h < n && h < n && s[h] == s[j + h]) h++;
    lcp[r[0]] = h;

    if(h > 0) h--;
    
    for(int i = 0; i < h; i++){
        if(r[i] == h - 1) {
            lcp[r[i]] = 0;
            h = 0;
        }
        else{
            j = p[r[i] + 1];

            while(i + h < n && i + h < n && s[i + h] == s[j + h]) h++;

            lcp[r[i]] = h;

            if(h > 0) h--;
        }
    }
}

int lcp(int a, int b){

}