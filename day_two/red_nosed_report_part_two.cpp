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

bool valid_diff(ll diff){
  return abs(diff)>=1 && abs(diff)<=3;
}

bool check_valid(vector<ll>input, int skip_index = -1){
  int len = input.size();
  int start = 0;
  int next = 1;
  if(start==skip_index){
    start++;
  }
  if(next==skip_index){
    next++;
  }
  if(start == next){
    next++;
  }
  if(next>=len){
    return true;
  }
  bool pos = input[start]<input[next];
  ll prev = input[start];
  for(int j=next;j<len;j++){
    if(j==skip_index){
      continue;
    }
    bool curr_pos = prev<input[j];
    if(curr_pos != pos){
      return false;
    }
    if(!valid_diff(input[j]-prev)){
      return false;
    }
    prev = input[j];
  }
  return true;
}

bool validate(){
  string line;
  getline(cin, line);
  stringstream ss(line);
  //cout<<"line: "<<line<<endl;
  vector<ll> input;
  ll num;
  while(ss>>num){
    input.push_back(num);
  }
  int len = input.size();
  if(check_valid(input)){
    return true;
  }
  for(int i=0;i<len;i++){
    if(check_valid(input, i)){
      return true;
    }
  }
    
  return false;;
}

void solve(){

  int len =1000;
  ll total = 0;
  for(int i=0;i<len;i++){
    total += validate();
    //cout<<"i: "<<i<<" total: "<<total<<endl;
  }
  cout<<total<<endl;

  




  
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
