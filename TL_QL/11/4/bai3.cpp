#include<bits/stdc++.h>
using namespace std;
int a, b;
void getInput(){
      cin>>a>> b;

}
int solve(){
      if(b == 0) return a;
      return solve(b, a % b);
}
void main (){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      cout<<solve()<<endl;
}