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
    //cout << "-------------" << endl;
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


bool is_inside(int x,int y,vector<vector<char>>&board){
  int len = board.size(),width=board[0].size();
  return x>=0 && x<len && y>=0 && y<width;
}

void solve(){

  int len=50,width=50;
  vector<vector<char>> board(len,vector<char>(2*width));
  int sr=0,sc=0;
  for(int i=0;i<len;i++){
    for(int j=0;j<2*width;j+=2){
      char c;
      cin>>c;
      if(c=='.'){
        board[i][j]='.';
        board[i][j+1]='.';
      } else if(c=='#'){
        board[i][j]='#';
        board[i][j+1]='#';
      } else if(c=='@'){
        board[i][j]='@';
        board[i][j+1]='.';
        sr=i;
        sc=j;
      } else if(c=='O'){
        board[i][j]='[';
        board[i][j+1]=']';
      }
    }
  }
  //print(board);

  string s="";
  getline(cin,s);
  getline(cin,s);
  s="";
  for(int i=0;i<20;i++){
    string input;
    getline(cin,input);
    s+=input;
  }
  //cout<<s<<endl;
  map<char,pair<int,int>> operations ={
    {'^',{-1,0}},
    {'>',{0,1}},
    {'v',{1,0}},
    {'<',{0,-1}}
  };
  for(size_t i=0;i<s.size();i++){
    //print(board);
    pair<int,int>dir = operations[s[i]];
    deque<pair<int,int>> dq;
    dq.push_back({sr,sc});
    int curr_x=sr,curr_y=sc;
    set<pair<int,int>> seen;
    seen.insert({sr,sc});
    bool ok = true;
    //cout<<"moving "<<s[i]<<endl;
    //int cnt=0;
    for(auto it=dq.begin();it!=dq.end();it++){
      //cnt++;
      curr_x=it->first;
      curr_y=it->second;
      curr_x+=dir.first;
      curr_y+=dir.second;
      if(seen.find({curr_x,curr_y})!=seen.end()){
        continue;
      }
      char c = board[curr_x][curr_y];
      //cout<<"dir: "<<dir.first<<" "<<dir.second<<" curr_x: "<<curr_x<<" curr_y: "<<curr_y<<" c: "<<c<<endl;
      if(c=='#') {
        ok = false;
        break;
      }
      if(c=='['){
        dq.push_back({curr_x,curr_y});
        dq.push_back({curr_x,curr_y+1});
        seen.insert({curr_x,curr_y});
        seen.insert({curr_x,curr_y+1});
      }
      if(c==']'){
        dq.push_back({curr_x,curr_y});
        dq.push_back({curr_x,curr_y-1});
        seen.insert({curr_x,curr_y});
        seen.insert({curr_x,curr_y-1});
      }
      //if(cnt==10) break;
      //cout<<"loop"<<endl;
    }
    /*
    for(auto p:dq){
      cout<<p.first<<" "<<p.second<<endl;
    }
    break;
    */
    if(!ok){
      //cout<<"not ok"<<endl;
      continue;
    }
    //cout<<"ok"<<endl;
    vector<vector<char>> new_board = board;

    board[sr][sc]='.';
    board[sr+dir.first][sc+dir.second]='@';
    sr = dq.front().first;
    sc = dq.front().second;
    dq.pop_front();
    for(auto p:dq){
      board[p.first][p.second]='.';
    }
    for(auto p:dq){
      board[p.first+dir.first][p.second+dir.second]=new_board[p.first][p.second];
    }
    sr = sr+dir.first;
    sc = sc+dir.second;
  }
  ll result=0;
  for(int i=0;i<len;i++){
    for(int j=0;j<2*width;j++){
      if(board[i][j]=='['){
        result += ((i*100)+j);
      }
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
