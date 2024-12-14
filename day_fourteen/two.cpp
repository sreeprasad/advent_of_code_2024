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


Point parse_point(string token){
  Point point(0,0);
  ll x =0;
  size_t j=0;
  for(j=2;j<token.size();j++){
    if(token[j]==','){
      x = stoll(token.substr(2,j-2));
      break;
    } 
  }
  ll y = stoll(token.substr(j+1));
  point.x = x;
  point.y = y;
  return point;
}

ll height = 103;
ll width = 101;
ll mid_width = width/2;
ll mid_height = height/2;

void print_christmas_tree(vector<vector<int>> &grid){
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      if(grid[j][i]==0){
        cout<<".";
      } else {
        cout<<"#";
      }
    }
    cout<<endl;
  }
}

void solve(){

  int len =500;
  vector<Point> points;
  vector<Point> speed;
  for(int i=0;i<2*len;i++){
    string s;
    cin>>s;
    if((i%2)==0){
      points.push_back(parse_point(s));
    } else {
      speed.push_back(parse_point(s));
    }
  }
    
  for(int t=0;t<100000;t++){
    vector<vector<int>> grid(width,vector<int>(height,0));
    ll total=0;
    for(size_t i=0;i<points.size();i++){
      ll new_x = points[i].x + (speed[i].x*t*1ll);
      ll new_y = points[i].y + (speed[i].y*t*1ll);
      new_x %=width;
      new_y %=height;
      if(new_x<0){
        new_x += width;
      }
      if(new_y<0){
        new_y += height;
      }
      grid[new_x][new_y]++;
      if(grid[new_x][new_y]>1){
        break;
      }
      total++;
    }
    if(total==len){
      cout<<"found at time: "<<t<<endl;
      print_christmas_tree(grid);
      return;
    }
  }
  cout<<"not found"<<endl;
  
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
