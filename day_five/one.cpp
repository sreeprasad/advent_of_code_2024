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
vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

void solve(){
  unordered_map<ll,vector<ll>> graph;
  unordered_map<ll, ll> in_degree;
  for (int j = 0; j < 20; j++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string token;
        string source, dest;
        getline(ss, source, '|');
        getline(ss, dest);
        graph[stoll(source)].push_back(stoll(dest));
        in_degree[stoll(source)]=0;
        in_degree[stoll(dest)]=0;
        //cout<<"source: "<<source<<" dest: "<<dest<<endl;
    }
  ll result = 0;
  string s;
  getline(cin,s);
  unordered_map<ll,ll> positions;
  while(getline(cin,s)){
    if(s.size()==0) continue;
    //cout<<"s: "<<s<<endl;
    positions.clear();
    stringstream ss(s);
    string token;
    vector<ll> input;
    while (getline(ss, token, ',')) {
      input.push_back(stoi(token));
    }
    for(int i=0;i<input.size();i++){
      positions[input[i]]=i;
    }
    bool valid = true;
    for(auto [key, value]: graph){
      for(auto dest: value){
        if(positions.find(key)!=positions.end() 
    && positions.find(dest)!=positions.end() 
    && positions[key]>positions[dest]){
            valid = false;
            //cout<<"key: "<<key<<" dest: "<<dest<<endl;
            break;
        }
      }
      if(!valid) break;
    }
    if(!valid){
      //cout<<"Invalid sequence"<<endl;
      for(auto x: input){
        cout<<x<<" ";
      }
      cout<<endl;
    }
    if(valid){
      result+=input[input.size()/2];
    }

  }
  cout<<"Result: "<<result<<endl;
  

  
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
