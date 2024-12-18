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


int a=117440,b=0,c=0;
int get_value(int operand){
  if(operand<4){
    return operand;
  }
  if(operand == 4){
    return a;
  }
  if(operand == 5){
    return b;
  }
  if(operand ==6){
    return c;
  }
  assert(false);
  return -1;
}

void solve(){

  string s;
  cin>>s;
  int i=0;
  int len = s.size();
  while(i<len){
    char opcode = s[i];
    if(opcode=='0'){
      int operand = s[i+1]-'0';
      int val = get_value(operand);
      a = a/(pow(2,val));
      i+=2;
    } else if(opcode == '1'){
      int operand = s[i+1]-'0';
      b = b^operand;
      i+=2;
    }else if(opcode == '2'){
      int operand = s[i+1]-'0';
      int val = get_value(operand);
      b = val%8;
      i+=2;
    } else if(opcode == '3'){
      if(a==0){
        i+=2;
      } else {
        int operand = s[i+1]-'0';
        i = operand;
      }
    } else if(opcode == '4'){
      b = b^c;
      int operand = s[i+1]-'0';
      i+=2;
    } else if(opcode=='5'){
      int operand = s[i+1]-'0';
      int val = get_value(operand);
      cout<<val%8<<",";
      i+=2;
    } else if(opcode=='6'){
      int operand = s[i+1]-'0';
      int val = get_value(operand);
      b = a/(pow(2,val));
      i+=2;
    } else if(opcode == '7'){
      int operand = s[i+1]-'0';
      int val = get_value(operand);
      c = a/(pow(2,val));
      i+=2;
    }
  }
  cout<<endl;
  cout<<"a: "<<a<<endl;
  cout<<"b: "<<b<<endl;
  cout<<"c: "<<c<<endl;
  
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
