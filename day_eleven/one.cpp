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



bool rule_1(ll val){
  return val==0;
}

bool rule_2(ll val){
  int result=0;
  while(val){
    val/=10;
    result++;
  }
  return result%2==0;
}

void print(vector<ll> &a){
  for(auto x:a){
    cout<<x<<" ";
  }
  cout<<endl;
  cout<<"-------------"<<endl;
}


void solve(){

  int len = 8;
  int times =75;
  vector<ll> input;
  for(int i=0;i<len;i++){
    ll val;
    cin>>val;
    input.push_back(val);
  }
  vector<ll> transformed;
  for(int j=0;j<times;j++){
    for(int i=0;i<input.size();i++){
      if(rule_1(input[i])){
        transformed.push_back(1);
      } else if(rule_2(input[i])){
        string s = to_string(input[i]);
        int slen = s.size();
        ll val = stoll(s.substr(0, slen / 2));
        transformed.push_back(val);
        val = stoll(s.substr(slen / 2));
        transformed.push_back(val);
      } else{
        transformed.push_back(input[i]*2024ll);
      }
    }
    input.clear();
    input = transformed;
    transformed.clear();
  }
 cout<<input.size()<<endl;
  
 
  
  
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
