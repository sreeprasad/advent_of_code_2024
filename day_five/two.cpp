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

unordered_map<ll, vector<ll>> build_graph(){
  unordered_map<ll,vector<ll>> graph;
  for (int j = 0; j < 1176; j++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string token;
        string source, dest;
        getline(ss, source, '|');
        getline(ss, dest);
        graph[stoll(source)].push_back(stoll(dest));
  }
  return graph;
};
 
void solve(){
  unordered_map<ll,vector<ll>> graph=build_graph();
  unordered_map<ll, ll> indegree;
  ll result = 0;
  string s;
  getline(cin,s);
  unordered_map<ll,ll> positions;
  while(getline(cin,s)){
    if(s.size()==0) continue;
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
            break;
        }
      }
      if(!valid) break;
    }
    if(!valid){
      indegree.clear();
      for(ll num: input){
        indegree[num]=0;
      }
      for(auto [key, value]: graph){
        if(indegree.find(key)!=indegree.end()){
          for(auto dest: value){
            if(indegree.find(dest)!=indegree.end()){
              indegree[dest]++;
            }
          }
        }
      }
      vector<ll> topo_order;
      queue<ll> q;
      for(auto [key, value]: indegree){
        if(value==0){
          q.push(key);
        }
      }
      while(!q.empty()){
        ll node = q.front();
        q.pop();
        topo_order.push_back(node);
        for(auto dest: graph[node]){
          indegree[dest]--;
          if(indegree[dest]==0){
            q.push(dest);
          }
        }
      }
      result+= topo_order[topo_order.size()/2];
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
