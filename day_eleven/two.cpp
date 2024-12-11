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

struct Node{
  ll value;
  int times;
  Node(ll value, int times):value(value),times(times){}
  bool operator<(const Node& other) const {
    if (value != other.value) return value < other.value;
    return times < other.times;
  }
};


ll get_size(Node node, map<Node,ll> &cache){
  if(cache.find(node)!=cache.end()){
    return cache[node];
  }
  ll result=0;
  if(node.times==0){
    result =1ll;
  }
  else if(rule_1(node.value)){
    result = get_size(Node(1, node.times-1), cache);
  } else if(rule_2(node.value)){
    string s = to_string(node.value);
    int slen = s.size();
    ll val1 = stoll(s.substr(0, slen / 2));
    ll val2 = stoll(s.substr(slen / 2));
    result = get_size(Node(val1, node.times-1), cache) + get_size(Node(val2, node.times-1), cache);
  } else{
     result = get_size(Node(node.value*2024ll,node.times-1), cache);
  }
  cache[node] = result;
  return result;

}

void solve(){

  int len = 8;
  ll result =0;
  map<Node,ll> cache;
  for(int i=0;i<len;i++){
    ll val;
    cin>>val;
    result+=get_size(Node(val, 75), cache);
  }
  cout<<result<<endl;
  
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
