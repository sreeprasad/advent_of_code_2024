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
vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
ll result = 0;

void print(vector<vector<char>> &a){
  for(auto x:a){
    for(auto y:x){
      cout<<y;
    }
    cout<<endl;
  }
  cout<<endl;
}

void map_guards_path(vector<vector<char>> &grid,int bi, int bj,int x,int y,int dir, set<tuple<int, int, int>> &cache){
  int len = grid.size();
  if(cache.count({x,y,dir})){
    result++;
    return ;
  }
  cache.insert({x,y,dir});
  int nx = x+directions[dir][0];
  int ny = y+directions[dir][1];
  if(nx<0 || ny<0 || nx>=len || ny>=len) return;
  if(grid[nx][ny]=='#' || (nx==bi && ny==bj)){
    dir = (dir+1)%4;
    nx = x;
    ny = y;
  }  
  map_guards_path(grid,bi,bj, nx,ny,dir,cache);
} 



void solve() {
    int len = 130;
    vector<vector<char>> grid(len, vector<char>(len));
    int sx = -1, sy = -1, curr_dir = -1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '^') {
                sx = i;
                sy = j;
                curr_dir = 0;
            } else if (grid[i][j] == '>') {
                sx = i;
                sy = j;
                curr_dir = 1;
            } else if (grid[i][j] == 'v') {
                sx = i;
                sy = j;
                curr_dir = 2;
            } else if (grid[i][j] == '<') {
                sx = i;
                sy = j;
                curr_dir = 3;
            }
        }
    }


    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            //if (grid[i][j] == '#' || (i == sx && j == sy)) continue;
            set<tuple<int, int, int>> cache;
            map_guards_path(grid,i,j,sx,sy,curr_dir,cache);
        }
    }

    cout << "result: " << result << endl;
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
