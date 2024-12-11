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



int dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited,vector<vector<int>> &cache, string path, set<string> &seen){
  int len = grid.size();
  path = path+to_string(x)+to_string(y);
  if(grid[x][y]=='9' && seen.find(path)==seen.end()){
    cout<<"finally reached 9"<<endl;
    seen.insert(path);
    return 1;
  }
  if(cache[x][y]!=-1){
    return cache[x][y];
  }

  int result =0;
  for(auto dir: directions){
    int new_x = x+dir[0];
    int new_y = y+dir[1];
    if(new_x>=0 && new_y>=0 && new_x<len && new_y<len && grid[new_x][new_y]-grid[x][y]==1){
      //cout<<"grid[new_x][new_y] "<<grid[new_x][new_y]<<" grid[x][y] "<<grid[x][y]<<endl;
      cout<<"going from "<<x<<" "<<y<<" to "<<new_x<<" "<<new_y<<endl;
      result+=dfs(new_x,new_y,grid, visited,cache, path, seen);
    }
  }
  cout<<"result for "<<x<<" "<<y<<" is "<<result<<endl;
  return cache[x][y] = result;
}

void solve(){

  int len = 42;
  vector<vector<char>> grid(len,vector<char>(len));
  vector<pair<char,char>> starts;
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      cin>>grid[i][j];
      if(grid[i][j]=='0'){
        starts.push_back({i,j});
      }
    }
  }

  print(grid);
  //return;

  int result =0;

  for(auto p: starts){
    int x = p.first;
    int y = p.second;
    set<string> seen;
    vector<vector<int>> cache(len,vector<int>(len,-1));
    vector<vector<bool>> visited(len,vector<bool>(len,false));


    dfs(x,y,grid,visited,cache,"",seen);
    if(cache[x][y]==-1){
      cout<<"no path found for "<<x<<" "<<y<<endl;
      
    } else{
      result+=cache[x][y];
      cout<<"count for "<<x<<" "<<y<<" is "<<cache[x][y]<<endl;
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
