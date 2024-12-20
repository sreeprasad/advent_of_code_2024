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


template <typename T>
void print(const vector<T> &a) {
    for (const auto &x : a) {
        cout << x << " ";
    }
    cout << endl;
    cout << "-------------" << endl;
}
template <typename T>
void print(const vector<vector<T>> &a) {
    for (const auto &row : a) {
        print(row); 
    }
    cout << "=============" << endl;
}

struct Point {
  ll x,y;
  Point(ll x, ll y):x(x),y(y){}
  bool operator<(const Point &p) const {
    if(x==p.x){
      return y<p.y;
    }
    return x<p.x;
  }
  
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}



ll can_be_formed(string word, vector<string> colors, int word_index, map<int,ll> &cache){
  if(word_index==(int)word.size()){
    return 1ll;
  }
  if(cache.find(word_index)!=cache.end()){
    return cache[word_index];
  }
  ll result =0;

  for(size_t i=0;i<colors.size();i++){
    string color = colors[i];
    bool ok = true;
    if((word_index+color.size())>word.size()){
        continue;
    }
    for(size_t j=0;j<color.size();j++){
      
      if(color[j]!=word[word_index+j]){
        ok = false;
        break;
      }    
    }
    if(ok){
      result += can_be_formed(word,colors,word_index+color.size(),cache);
    }
  }
    
  //cout<<"word_index: "<<word_index<<" result: "<<result<<endl;
  cache[word_index] = result;
  return result;
}

int len = 400;
void solve(){
  string s;
  getline(cin,s);
  //cout<<"s: "<<s<<endl;
  istringstream tokenstream(s);
  string token;
  vector<string> colors;
  while(getline(tokenstream, token, ',')){
    size_t i=0;
    for(i=0;i<token.size();i++){
      if(token[i]!=' '){
        break;
      }
    }
    colors.push_back(token.substr(i));
  }
  s="";
  getline(cin,s);
  vector<string> words;
  for(int i=0;i<len;i++){
    getline(cin,s);
    //cout<<"word: "<<s<<endl;
    words.push_back(s);
  }
  ll result =0;
  //int ans = can_be_formed("gbbr",colors,0, cache);
  //cout<<"ans: "<<ans<<endl;
  for(auto x: words){
    map<int,ll> cache;
    result += can_be_formed(x,colors,0,cache);
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
