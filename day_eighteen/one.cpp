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

struct Node{
  int x,y,step;
  Node(int x, int y, int step):x(x),y(y),step(step){}
};

int bfs(Node &start, vector<vector<char>> &grid){
  int n = grid.size();
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  queue<Node> q;
  q.push(start);
  visited[start.x][start.y] = true;
  while(!q.empty()){
    Node current = q.front();
    q.pop();
    if(current.x==70 && current.y==70) return current.step;

    for(auto dir: directions){
      int x = current.x + dir[0];
      int y = current.y + dir[1];
      if(x<0 || x>=n || y<0 || y>=n || grid[x][y]=='#' || visited[x][y]) continue;
      visited[x][y] = true;
      q.push(Node(x,y,current.step+1));
    }
  }
  return -1;
}

void solve(){
  vector<vector<char>> grid(71, vector<char>(71));
  int len=1024;
  for(int i=0;i<len;i++){
    string s;
    cin>>s;
    //cout<<"s: "<<s<<endl;
    istringstream tokenstream(s);
    string token;
    int x=0,j=0,y=0;
    while(getline(tokenstream, token, ',')){
      if(j==0) x = stoi(token);
      else y = stoi(token);
      j++;
    }
    //cout<<x<<" "<<y<<endl;
    grid[x][y] = '#';
  }
  //print(grid);
  Node start = Node(0,0,0);
  int steps = bfs(start, grid);
  cout<<steps<<endl;

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
