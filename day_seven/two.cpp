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

typedef long long int ll;
vector<vector<int>> all_directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

void print(vector<vector<char>> &a){
  for(auto x:a){
    for(auto y:x){
      cout<<y;
    }
    cout<<endl;
  }
  cout<<endl;
}

bool is_valid(ll lhs,vector<ll> rhs, ll value, int index){
  int len = rhs.size();
  //cout<<"value: "<<value<<" index: "<<index<<endl;
  if(index==len){
    return lhs == value;
  }
  ll concatenated_value = stoll(to_string(value) + to_string(rhs[index]));

  return is_valid(lhs,rhs,value+rhs[index],index+1) || is_valid(lhs,rhs,value*rhs[index],index+1) || is_valid(lhs,rhs,concatenated_value,index+1);
}


void solve(){

  ll result = 0;
  int len = 850;
  for(int i=0;i<len;i++){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string token;
    ll lhs = 0;
    ss>>lhs;

    ss.ignore(1,':');
    vector<ll> rhs;
    ll value;
    while(ss>>value){
      rhs.push_back(value);
    }
    bool ok = is_valid(lhs,rhs,rhs[0]+rhs[1],2) || is_valid(lhs,rhs,rhs[0]*rhs[1],2) || is_valid(lhs,rhs,stoll(to_string(rhs[0]) + to_string(rhs[1])),2);
    if(ok){
      result+=lhs;
    }
  }
  cout<<"result: "<<result<<endl;

  
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
