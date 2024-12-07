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

void map_guards_path_part_two(vector<vector<char>> &grid,int bi, int bj,int x,int y,int dir, vector<vector<vector<int>>> &cache){
  int len = grid.size();
  if(cache[x][y][dir]==1){
    result++;
    return ;
  }
  cache[x][y][dir] = 1;
  int nx = x+directions[dir][0];
  int ny = y+directions[dir][1];
  if(nx<0 || ny<0 || nx>=len || ny>=len) return;
  if(grid[nx][ny]=='#' || (nx==bi && ny==bj)){
    dir = (dir+1)%4;
    nx = x;
    ny = y;
  }  
  map_guards_path_part_two(grid,bi,bj, nx,ny,dir,cache);
} 

void map_guards_path(vector<vector<char>> &grid,int x,int y,int dir,vector<vector<bool>> &visited,vector<pair<int,int>> &path){
  int len = grid.size();
  if(x<0 || x>=len || y<0 || y>=len){
    return;
  }
  if(!visited[x][y]){
    path.push_back({x,y});
    visited[x][y] = true;
  }
  int nx = x+directions[dir][0];
  int ny = y+directions[dir][1];
  if(nx<0 || ny<0 || nx>=len || ny>=len) return;
  if(grid[nx][ny]=='#'){
    dir = (dir+1)%4;
    nx = x;
    ny = y;
  } 
  map_guards_path(grid,nx,ny,dir,visited,path);
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

    vector<pair<int,int>> path;
    vector<vector<bool>> visited(len, vector<bool>(len, false));
    grid[sx][sy] = '.';
    map_guards_path(grid, sx, sy, curr_dir, visited, path);
    
    for(auto [x,y]:path){
      vector<vector<vector<int>>> cache(len, vector<vector<int>>(len, vector<int>(4, -1)));
      map_guards_path_part_two(grid,x,y,sx,sy,curr_dir,cache);
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
