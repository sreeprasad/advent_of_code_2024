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

void solve(){

  string s;
  cin>>s;
  string result="";
  int len = s.size();
  ll id=0;
  vector<ll> input;
  for(int i=0;i<len;i++){
    ll val = s[i]-'0';
    if(i%2==0){
      for(int j=0;j<val;j++){
        input.push_back(id);
      }
      id++;
    } else {
      for(int j=0;j<val;j++){
        input.push_back(-1);
      }
    }
  }
  len = input.size();
  int left=0,right=len-1;
  ll ans2=0;
  
  while(left<right){
      if(input[left]!=-1){
        ans2 += (input[left]*1LL*left);
        left++;
        continue;
      }
    while(right>=0 && input[right]==-1){
      right--;
    }
    if(left<right){
      swap(input[left],input[right]);
        if(input[left]!=-1)
          ans2 += (input[left]*1LL*left*1LL);
      left++;
      right--;
    }
  
  }
  while(left<input.size() && input[left]!=-1){
    ans2 += (input[left]*1LL*left*1LL);
    left++;
  }
  cout<<"ans2: "<<ans2<<endl;

    
  
  
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
