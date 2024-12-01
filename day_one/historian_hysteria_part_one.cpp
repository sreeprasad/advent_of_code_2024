#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
//#define sz(a) ((int)((a).size()))
//#define char unsigned char
#define endl '\n'

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



/*  
 istringstream tokenstream(s);
 string token;
 string result;
 while(getline(tokenstream, token, '.')){
   result = token;
} 
 */

typedef long long ll;

void solve(){
  vector<ll> first,second;
  for(int i=0;i<1000;i++){
    ll f,s;
    cin>>f>>s;
    first.push_back(f);
    second.push_back(s);
  }
  sort(first.begin(),first.end());
  sort(second.begin(),second.end());
  ll total = 0;
  for(int i=0;i<1000;i++){
    total += abs(first[i]-second[i]);
  }
  cout<<total<<endl;
  







  
  #ifdef ONPC
    cout << "__________________________" << endl;
  #endif
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //int test = 0; cin>>test;while(test--)
    solve();
       
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
