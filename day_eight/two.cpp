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

ll dist(int x1,int y1,int x2,int y2){
  ll xdist = abs(x1-x2);
  ll ydist = abs(y1-y2);
  return xdist*xdist + ydist*ydist;
}


void solve(){
  int len = 50;
  vector<vector<char>> input(len,vector<char>(len));
  map<char,vector<pair<int,int>>> graph;
  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      cin>>input[i][j];
      if(input[i][j]!='.'){
        if(graph.find(input[i][j])==graph.end()){
          graph[input[i][j]] = {{i,j}};
        } else {
          graph[input[i][j]].push_back({i,j});
        }
      }
    }
  }
  ll result =0;
  vector<vector<bool>> visited(len,vector<bool>(len,false));

  for(auto z:graph){
    vector<pair<int,int>> cordinates = z.second;
    for(int i=0;i<cordinates.size();i++){
      int x1 = cordinates[i].first;
      int y1 = cordinates[i].second;
      for(int j=i+1;j<cordinates.size();j++){
        int x2 = cordinates[j].first;
        int y2 = cordinates[j].second;

        if((x2-x1)==0) continue;

        for(int x=0;x<len;x++){
          int top = (y2-y1)*(x-x1);
          if (top%(x2-x1)!=0) continue;
          int y = top/(x2-x1)+y1;
          
          if(y<0 || y>=len) continue;
          if(visited[x][y]) continue;
          visited[x][y] = true;
          result++;
        }
      }
    }
  }
  cout<<"result: "<<result<<endl;
  
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
