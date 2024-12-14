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
bool is_qudrant1(Point p){
  return p.x<mid_width && p.y<mid_height;
}
bool is_qudrant2(Point p){
  return p.x>mid_width && p.y<mid_height;
}

bool is_qudrant3(Point p){
  return p.x<mid_width && p.y>mid_height;
}

bool is_qudrant4(Point p){
  return p.x>mid_width && p.y>mid_height;
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
 
  ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
  for(size_t i=0;i<points.size();i++){
    points[i].x += (speed[i].x*100);
    points[i].y += (speed[i].y*100);
  
    points[i].x %=width;
    points[i].y %=height;
    if(points[i].x<0){
      points[i].x += width;
    }
    if(points[i].y<0){
      points[i].y += height;
    }
    
    if(is_qudrant1(points[i])){
      q1++;
    } else if(is_qudrant2(points[i])){
      q2++;
    } else if(is_qudrant3(points[i])){
      q3++;
    } else if(is_qudrant4(points[i])){
      q4++;
    }
  }
  //cout<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<endl;

  cout<<(q1*q2*q3*q4)<<endl;
  
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
