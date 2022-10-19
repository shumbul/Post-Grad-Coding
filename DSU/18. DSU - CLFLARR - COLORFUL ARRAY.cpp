// https://www.spoj.com/problems/CLFLARR/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{
public:
    vector<ll> par;
    DSU(ll n){
        par.resize(n);
        for(ll i=0;i<n;i++){
            par[i]=i;
        }
    }
    ll find(ll a){
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
    void union_(ll a, ll b){
        a=find(a), b=find(b);
        ll idx=max(a, b);
        par[a]=idx, par[b]=idx;
    }
};

int main(){
    ll n, q;
    cin>>n>>q;
    vector<ll> l(n), r(n), c(n), ans(n);
    for(ll i=0;i<q;i++){
        cin>>l[i]>>r[i]>>c[i];
    }
    DSU dsu(300000);
    for(ll i=q-1; i>=0; i--){
        ll left=dsu.find(l[i]);
        while(left<=r[i]){
            ans[left]=c[i];
            dsu.union_(left, left+1);
            left=dsu.find(left);
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}