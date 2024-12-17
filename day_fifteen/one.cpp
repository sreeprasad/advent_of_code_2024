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
    //cout << "-------------" << endl;
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


bool is_inside(int x,int y,vector<vector<char>>&board){
  int len = board.size(),width=board[0].size();
  return x>=0 && x<len && y>=0 && y<width;
}

void push_right(int final_x,int final_y, int start_x,int start_y,vector<vector<char>> &board){
  while(final_y!=start_y){
    board[final_x][final_y]='O';
    final_y++;
  }
  //cout<<"final_x: "<<final_x<<" final_y: "<<final_y<<" start_x: "<<start_x<<" start_y: "<<start_y<<endl;
  board[start_x][start_y]='@';
}



void push_left(int final_x,int final_y, int start_x,int start_y,vector<vector<char>> &board){
  //cout<<"final_x: "<<final_x<<" final_y: "<<final_y<<" start_x: "<<start_x<<" start_y: "<<start_y<<endl;
  while(final_y!=start_y){
    board[final_x][final_y]='O';
    final_y--;
  }
  board[start_x][start_y]='@';
}

void push_up(int final_x,int final_y, int start_x,int start_y,vector<vector<char>> &board){
  while(final_x!=start_x){
    board[final_x][final_y]='O';
    final_x--;
  }
  board[start_x][start_y]='@';
}

void push_down(int final_x,int final_y, int start_x,int start_y,vector<vector<char>> &board){
  while(final_x!=start_x){
    board[final_x][final_y]='O';
    final_x++;;
  }
  board[start_x][start_y]='@';
}


void move_left(int &sx,int &sy,vector<vector<char>> &board){
  int nx=sx,ny=sy-1;
  if(!is_inside(nx,ny,board) || board[nx][ny]=='#'){
    cout<<"Invalid move"<<endl;
  } else if(board[nx][ny]=='.'){
    board[nx][ny]='@';
    board[sx][sy]='.';
    sx=nx;
    sy=ny;
  } else if(board[nx][ny]=='O'){
    int temp_nx=nx,temp_ny=ny;
    while(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='O'){
      temp_ny--;
    }
    if(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='.'){
      push_right(temp_nx,temp_ny,nx,ny,board);
      board[sx][sy]='.';
      sx=nx;
      sy=ny;
    } else {
      cout<<"Could not move"<<endl;
    }
  } else {
    cout<<"sps"<<endl;
  }
  //print(board);
}

void move_up(int &sx,int &sy,vector<vector<char>> &board){
  int nx=sx-1,ny=sy;
  if(!is_inside(nx,ny,board) || board[nx][ny]=='#'){
    cout<<"Invalid move"<<endl;
  } else if(board[nx][ny]=='.'){
    board[sx][sy]='.';
    board[nx][ny]='@';
    sx=nx;
    sy=ny;
  } else if(board[nx][ny]=='O'){
    int temp_nx=nx,temp_ny=ny;
    while(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='O'){
      temp_nx--;
    }
    if(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='.'){
      push_down(temp_nx,temp_ny,nx,ny,board);
      board[sx][sy]='.';
      sx=nx;
      sy=ny;
    } else {
      cout<<"Could not move"<<endl;
    }
  } else{ 
    cout<<"sps"<<endl;
  }
  //print(board);
}


void move_right(int &sx,int &sy,vector<vector<char>> &board){
  int nx=sx,ny=sy+1;
  if(!is_inside(nx,ny,board) || board[nx][ny]=='#'){
    cout<<"Invalid move"<<endl;
  } else if(board[nx][ny]=='.'){
    board[sx][sy]='.';
    board[nx][ny]='@';
    sx=nx;
    sy=ny;
  } else if(board[nx][ny]=='O'){
    int temp_nx=nx,temp_ny=ny;
    //cout<<"nx: "<<nx<<" ny: "<<ny<<endl;
    //cout<<"temp_nx: "<<temp_nx<<" temp_ny: "<<temp_ny<<endl;
    while(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='O'){
      temp_ny++;
    }
    if(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='.'){
      push_left(temp_nx,temp_ny,nx,ny,board);
      board[sx][sy]='.';
      sx=nx;
      sy=ny;
    } else {
      cout<<"Could not move"<<endl;
    }
  } else {
    cout<<"sps"<<endl;
  }
  //print(board);

} 


void move_down(int &sx, int &sy, vector<vector<char>>&board){
  int nx=sx+1,ny=sy;
  if(!is_inside(nx,ny,board) || board[nx][ny]=='#'){
    cout<<"Invalid move"<<endl;
  } else if(board[nx][ny]=='.'){
    board[sx][sy]='.';
    board[nx][ny]='@';
    sx=nx;
    sy=ny;
  } else if(board[nx][ny]=='O'){
    int temp_nx=nx,temp_ny=ny;
    while(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='O'){
      temp_nx++;
    }
    if(is_inside(temp_nx,temp_ny,board) && board[temp_nx][temp_ny]=='.'){
      push_up(temp_nx,temp_ny,nx,ny,board);
      board[sx][sy]='.';
      sx=nx;
      sy=ny;
    } else {
      cout<<"Could not move"<<endl;
    }
  } else {
    cout<<"sps"<<endl;
  }
  //print(board);

}

void solve(){

  int len=50,width=50;
  vector<vector<char>> board(len,vector<char>(width));
  int sx=0,sy=0;
  for(int i=0;i<len;i++){
    for(int j=0;j<width;j++){
      cin>>board[i][j];
      if(board[i][j]=='@'){
        sx=i;
        sy=j;
      }
    }
  }
  //print(board);

  string s="";
  getline(cin,s);
  getline(cin,s);
  s="";
  for(int i=0;i<20;i++){
    string input;
    getline(cin,input);
    s+=input;
  }
  cout<<s<<endl;

  for(size_t i=0;i<s.size();i++){
    //cout<<"i: "<<i<<endl;
    if(s[i]=='<'){
      //cout<<"moving left"<<endl;
      move_left(sx,sy,board);
    } else if(s[i]=='^'){
      //cout<<"moving up"<<endl;
      move_up(sx,sy,board);
    } else if(s[i]=='>'){
      //cout<<"moving right"<<endl;
      move_right(sx,sy,board);
    } else if(s[i]=='v'){
      //cout<<"moving down"<<endl;
      move_down(sx,sy,board);
    }
  }
  ll result=0;
  for(size_t i=0;i<len;i++){
    for(size_t j=0;j<width;j++){
      if(board[i][j]=='O'){
        result+=(i)*100+(j);
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
