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

ll solve_inner(){

  string line;
  getline(cin, line);
  size_t pos = 0;
  ll result = 0;
  size_t len = line.size();;

  while((pos = line.find("mul(", pos)) != string::npos) {
      size_t start = pos +4;  
      size_t end = start;
      if(end>=len){
        break;
      }
      //cout<<"start: "<<start<<" end: "<<end<<endl;
      ll first = 0;
      while(end<len && isdigit(line[end])){
        first = first*10LL + (line[end]-'0');
        end++;
      }
      //cout<<"end: "<<line[end]<<endl;
      if(line[end]!=','){
        pos = end;
        continue;
      }
      //cout<<"first: "<<first<<endl;
      end++;
      ll second = 0;
      while(end<len && isdigit(line[end])){
        second = second*10LL + (line[end]-'0');
        end++;
      }
      if(line[end]!=')'){
        pos = end;
        continue;
      }
      if(line[end]==')'){
        result += first*second;
      }
      //cout<<"first: "<<first<<" second: "<<second<<endl;
      pos = end;
      
  }
  //cout<<"result: "<<result<<endl;

  #ifdef ONPC
    cout << "__________________________" << endl;
  #endif
  return result;
  
}
void solve(){
  ll result = 0;
  for(int i=0;i<6;i++){
    ll total = solve_inner();
    result += total;
    cout<<"total: "<<total<<endl;

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
