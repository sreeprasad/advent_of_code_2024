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


struct Node {
  int x,y,curr_dir;
  ll cost;
  Node(int x, int y, int curr_dir, ll cost):x(x),y(y),curr_dir(curr_dir),cost(cost){}
  bool operator<(const Node &p) const {
    return cost>p.cost;
  }
};

ll minimum_cost= LLONG_MAX;

ll min_cost(vector<vector<char>> &grid, int sr, int sc, int er, int ec, set<pair<int,int>> &path_tiles){
  int len = grid.size();
  vector<vector<vector<ll>>> dist(len, vector<vector<ll>>(len,vector<ll>(4,INT_MAX)));
  priority_queue<Node> pq;
  vector<vector<vector<vector<Node>>>> pred(len,
        vector<vector<vector<Node>>>(len,
        vector<vector<Node>>(4)));

  pq.push(Node(sr,sc,1,0ll));
  while(!pq.empty()){
    Node curr = pq.top();
    pq.pop();
    if(curr.x==er && curr.y==ec){
      minimum_cost = min(minimum_cost,curr.cost);
      continue;
    }
    if(dist[curr.x][curr.y][curr.curr_dir]<curr.cost){
      continue;
    }
    for(int i=0;i<4;i++){
      int x = curr.x+directions[i][0];
      int y = curr.y+directions[i][1];
      if(x<0 || x>=len || y<0 || y>=len){
        continue;
      }
      if(grid[x][y]=='#'){
        continue;
      }
      ll cost = curr.cost;
      if(curr.curr_dir!=i){
        cost += 1000;
      }
      cost += 1;
      if(cost<dist[x][y][i]){
        pred[x][y][i].clear();
        dist[x][y][i] = cost;
        pq.push(Node(x,y,i,cost));
        pred[x][y][i].push_back(curr);
      } else if(cost==dist[x][y][i]){
        pred[x][y][i].push_back(curr);
      }
    }
  }
  function<void(int,int,int)> markPaths = [&](int x, int y, int dir) {
        path_tiles.insert({x, y});
        
        for(const auto& p : pred[x][y][dir]) {
            markPaths(p.x, p.y, p.curr_dir);
        }
    };
    
  for(int dir = 0; dir < 4; dir++) {
        if(dist[er][ec][dir] == minimum_cost) {
            markPaths(er, ec, dir);
        }
  }
  return -1;
}


void solve(){
  int len =141;
  vector<vector<char>> grid(len, vector<char>(len));
  int sr=0,sc=0;
  int er=0,ec=0;
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      cin>>grid[i][j];
      if(grid[i][j]=='S'){
        sr = i;
        sc = j;
      }
      if(grid[i][j]=='E'){
        er = i;
        ec = j;
      }
    }
  }
  set<pair<int,int>> path_tiles;
  min_cost(grid,sr,sc,er,ec,path_tiles);
  cout<<path_tiles.size()<<endl;
  
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
