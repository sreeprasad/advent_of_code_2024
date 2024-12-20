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



bool can_be_formed(string word, vector<string> colors, int word_index){
  //cout<<"word: "<<word<<" word_index: "<<word_index<<endl;
  if(word_index==(int)word.size()){
    //cout<<"got here"<<endl;
    return true;
  }

  for(size_t i=0;i<colors.size();i++){
    string color = colors[i];
    bool ok = true;
    int k = word_index;
    //cout<<"color: "<<color<<endl;
    for(size_t j=0;j<color.size();j++){
      //cout<<"color[j]: "<<color[j]<<" word[k]: "<<word[k]<<endl;
      if(color[j]==word[k]){
        k++;
      }else{
        ok = false;
        break;
      }
    }
    //cout<<"ok: "<<ok<<endl;
    //cout<<"k: "<<k<<endl;
    if(ok){
      bool ans = can_be_formed(word,colors,k);
      if(ans){
        return true;
      }
    }
  }
    
  return false;
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
  int result =0;
  //bool ans = can_be_formed("bwurrg",colors,0);
  //cout<<"ans: "<<ans<<endl;
  for(auto x: words){
    bool ans = can_be_formed(x,colors,0);
    if(ans){
      //cout<<"can form word: "<<x<<endl;
      result++;
    }
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
