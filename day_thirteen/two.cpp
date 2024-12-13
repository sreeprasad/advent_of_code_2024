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


ll parse_xcord(string s){
  ll val=0;
  for(int i=2;i<s.size();i++){
    if(s[i]==',') break;
    val = val*10ll + (s[i]-'0');
  }
  return val;
}

ll parse_ycord(string s){
  ll val=0;
  for(int i=2;i<s.size();i++){
    val = val*10 + (s[i]-'0');
  }
  return val;
}


ll parse_prize_xcord(string s){
  ll val=0;
  int len = s.size();
  for(int i=2;i<len;i++){
    if(s[i]==',') break;
    val = val*10ll + (s[i]-'0');
  }
  return val;
}

ll parse_prize_y_cord(string s){
  return stoll(s.substr(2));
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

ll machine_one(Point a, Point b, Point p){
  ll score = 0;
  ll sx=0,sy=0;
  /*
   * m*a.x + n* b.x=p.x 
   * m*a.y + n*b.y=p.y
   * ------------------
   *  m*a.x*b.y + n*b.x*b.y = p.x*b.y
   *  m*a.y*b.x + n*b.y*b.x = p.y*b.x
   * ------------------
   *  m*(a.x*b.y)-m*(a.y*b.x) = p.x*b.y - p.y*b.x
   *  ------------------
   *  m = (p.x*b.y - p.y*b.x)/(a.x*b.y - a.y*b.x)
   *  ------------------
   *  here m has to be an integer because m is the number of times button was pressed
   *  and button cannot be pressed negative number of times.
   * 
   *
  */
  ll top = (p.x*b.y)-(p.y*b.x);
  ll bottom = (a.x*b.y)-(a.y*b.x);
  
  if((top%bottom)==0){
    ll m = top/bottom;
    top = p.x-(m*a.x);
    if(top%b.x==0){
      ll n = top/b.x;
      //cout<<"sp m "<<m<<" n "<<n<<endl;
      return m*3ll+n;
    }
  } 
  return score;
}

void solve(){

  vector<Point> points;
  ll result =0;

  for(int i=0;i<1279;i++){
    string s;
    getline(cin,s);
    if(i%4==0 || i%4==1){
      istringstream ss(s);
      string token;
      int j=0;
      Point p(0,0);
      while(getline(ss,token,' ')){
        if(j==2){
          p.x=parse_xcord(token);
        }else if(j==3){
          p.y=parse_ycord(token);
        }
        j++;
      }
      points.push_back(p);
    } else if(i%4==2){
      istringstream ss(s);
      string token;
      int j=0;
      Point prize(0,0);
      while(getline(ss,token,' ')){
        if(j==1){
          prize.x=parse_prize_xcord(token);
          prize.x+=10000000000000ll;
        }else if(j==2){
          prize.y=parse_prize_y_cord(token);
          prize.y+=10000000000000ll;
        }
        j++;
      }
      points.push_back(prize);
    } 

    if(points.size()==3){
      Point a = points[0];
      Point b = points[1];
      Point prize = points[2];
      /*cout<<"a.x "<<a.x<<" a.y "<<a.y<<endl;
      cout<<"b.x "<<b.x<<" b.y "<<b.y<<endl;
      cout<<"p.x "<<prize.x<<" p.y "<<prize.y<<endl;
      */
      ll score = machine_one(a,b,prize);
      result+=score;
      //cout<<result<<endl;
      points.clear();
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
