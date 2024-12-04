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
ll result = 0;
vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

void dfs(vector<vector<char>> &grid,int i,int j,int curr_len,vector<vector<bool>> &visited,string target,int dx,int dy){
  int len = (int)grid.size();
  int width = (int)grid[0].size();
  if(curr_len==(int)target.size()){
    result++;
    return;
  }
  int x = i+dx;
  int y = j+dy;
  if(x>=0 && x<len && y>=0 && y<width && !visited[x][y] && grid[x][y]==target[curr_len]){
    visited[x][y]=true;
    dfs(grid,x,y,curr_len+1,visited,target,dx,dy);
    visited[x][y]=false;
  }

}

void solve(){
  int len =140;
  vector<vector<char>> grid(len,vector<char>(len));
  for(int i=0;i<len;i++){
    string s;
    cin>>s;
    for(int j=0;j<(int)s.size();j++){
      grid[i][j]=s[j];
    }
  }
  map<pair<int,int>,int> cache;
  string target = "XMAS";
  vector<vector<bool>> visited(len,vector<bool>(len,false));
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      //cout<<"grid[i][j]: "<<grid[i][j]<<endl;
      if(grid[i][j]==target[0]){ 
        for(auto dir: directions){
          int dx = dir[0];
          int dy = dir[1];
          visited[i][j]=true;
          dfs(grid,i,j,1,visited,target,dx,dy);
          visited[i][j]=false;
        }
      }
    }
  }
  cout<<result<<endl;
  

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
