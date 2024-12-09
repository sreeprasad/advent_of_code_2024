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
  vector<pair<int,int>> free_pos_to_count;
  vector<tuple<int,int,int>> file_pos_to_count;
  int pos =0;
  for(int i=0;i<len;i++){

    int val = s[i]-'0';
    if(i%2==0){
      file_pos_to_count.push_back({pos,val,id});
      for(int j=0;j<val;j++){
        input.push_back(id);
        pos++;
      }
      id++;
    } else {
      if(val>0)
              free_pos_to_count.push_back({pos,val});

      for(int j=0;j<val;j++){
        pos++;
        input.push_back(-1);
      }
    }
  }
  len = input.size();
  for(int k=file_pos_to_count.size()-1;k>=0;k--){
    
    int file_pos = get<0>(file_pos_to_count[k]);
    int file_size = get<1>(file_pos_to_count[k]);
    int file_id = get<2>(file_pos_to_count[k]);

    for(int j=0;j<free_pos_to_count.size();j++){

      int free_pos = free_pos_to_count[j].first;
      int free_size = free_pos_to_count[j].second;

      if(free_pos<file_pos && free_size>=file_size){

        for(int i=0;i<file_size;i++){
          input[file_pos+i]=-1;
          input[free_pos+i]=file_id;
        }
        free_pos_to_count[j]={free_pos+file_size,free_size-file_size};
        break;

      }
    }
  }
  ll ans=0;
  for(int i=0;i<input.size();i++){
    if(input[i]==-1) continue;
    ans += (input[i]*i);
  }
  cout<<"ans: "<<ans<<endl;
   
  
  
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
