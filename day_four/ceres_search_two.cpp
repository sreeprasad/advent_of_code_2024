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


bool valid(vector<vector<char>> &grid,int i,int j){
  int len = grid.size();
  if((i+2)<len && (j+2)<len){
    if(grid[i][j]=='S' && grid[i][j+2]=='S' && grid[i+1][j+1]=='A' && grid[i+2][j]=='M' && grid[i+2][j+2]=='M') return true;
    if(grid[i][j]=='M' && grid[i][j+2]=='S' && grid[i+1][j+1]=='A' && grid[i+2][j]=='M' && grid[i+2][j+2]=='S') return true;
    if(grid[i][j]=='S' && grid[i][j+2]=='M' && grid[i+1][j+1]=='A' && grid[i+2][j]=='S' && grid[i+2][j+2]=='M') return true;
    if(grid[i][j]=='M' && grid[i][j+2]=='M' && grid[i+1][j+1]=='A' && grid[i+2][j]=='S' && grid[i+2][j+2]=='S') return true;
  }
  return false;

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
  vector<vector<bool>> visited(len,vector<bool>(len,false));
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      if(valid(grid,i,j)){
        cout<<"i: "<<i<<" j: "<<j<<endl;
        result++;
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
