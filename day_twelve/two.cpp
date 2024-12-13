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
        cout << x;
    }
    cout << endl;
    for(int i=0;i<a.size();i++){
      cout<<"-";
    }
    cout<<endl;
}
template <typename T>
void print(const vector<vector<T>> &a) {
    for (const auto &row : a) {
        print(row); 
    }
}



void dfs(vector<vector<char>> &grid,int x,int y,char c,vector<vector<bool>>&visited, vector<ll> &details){
  int len = grid.size();
  visited[x][y]=true;
  details[0]++;
  auto ok = [&](vector<int> dir){
    int new_x = x+dir[0];
    int new_y = y+dir[1];
    if(new_x<0 || new_x>=len || new_y<0 || new_y>=len) return false;
    return grid[new_x][new_y]==grid[x][y];
  };
  for(int i=0;i<4;i++){
    vector<int> dir_one = directions[i];
    vector<int> dir_two = directions[(i+1)%4];
    if(!ok(dir_one) && !ok(dir_two)){
      details[1]++;
    }
    vector<int> dir_three = {dir_one[0]+dir_two[0],dir_one[1]+dir_two[1]};
    if(ok(dir_one) && ok(dir_two) && !ok(dir_three)){
      details[1]++;
    }
  }
  for(auto dir: directions){
      int new_x = x+dir[0];
      int new_y = y+dir[1];

    if(ok(dir) && !visited[new_x][new_y]){
      dfs(grid,new_x,new_y,c,visited,details);
    }
  }
  
}


void solve(){

  int len=140;

  vector<vector<char>> grid(len,vector<char>(len));
  for(int i=0;i<len;i++){
    string s;
    cin>>s;
    for(int j=0;j<len;j++){
      grid[i][j]=s[j];
    }
  }
  print(grid);
  ll result=0;

  vector<vector<bool>> visited(len,vector<bool>(len,false));
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      if(visited[i][j]) continue;
      char c = grid[i][j];
      if(c>='A' && c<='Z' && !visited[i][j]){
        vector<ll> details(2,0);
        dfs(grid,i,j,c,visited,details);
        ll area = details[0];
        ll perimeter = details[1];
        cout<<c<<" area: "<<area<<" perimeter "<<perimeter<<endl;
        result += (area*perimeter);
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
