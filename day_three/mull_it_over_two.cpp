#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <regex>
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

ll calculateSum(string line) {
    ll result = 0;
    int len= line.size();
    bool enable = true;
    for(int i=0;i<len;i++){
      if(line.substr(i,4)=="do()"){
        enable = true;
      }
      if(line.substr(i,7)=="don't()"){  
        enable = false;
      }
      if(enable && line.substr(i, 4)=="mul("){
        int j= i+4;
        ll first =0;
        while(isdigit(line[j])){
          first = first*10 + (line[j]-'0');
          j++;
        }
        if(line[j]!=','){
          continue;
        }
        j++;
        ll second = 0;
        while(isdigit(line[j])){
          second = second*10 + (line[j]-'0');
          j++;
        }
        if(line[j]!=')'){
          continue;
        }
        result += (first*second);
        i=j;
      }
    }
    return result;
}

void solve() {
    ll result = 0;
    string input="";
    for (int i = 0; i < 6; i++) { // Assume 6 lines of input
        string line;
        getline(cin, line);
        input+=line+" "; 
    }
    result = calculateSum(input);
    cout << "result: " << result << endl;
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
