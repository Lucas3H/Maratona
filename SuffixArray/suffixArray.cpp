#inclue<bits/stdc++.h>

using namespaces std;

#define mp make_pair

/*
    Retorna um array em que suffixArray[i] é a posição do sufixo que [i ... n-1]
    ao ordenar os sufixos em ordem lexicográfica.

    Complexidade O(n Log(n))
    Memória: 3n
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