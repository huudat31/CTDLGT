#include<bits/stdc++.h>
using namespace std;

int n;
void getInput(){
      cin>> n;
}

void solve(){
      int sum = 0;
      for(int i = 0;i<=n;i++){
            sum += 2*i+1;
      }
      cout<< sum;
}
void solve2(){
      int sum = 0;
      for(int i = 0;i<=n;i++){
            sum += 2*i;
      }
      cout<< sum;
}
void solve3(){
      int sum = 0;
      for(int i = 0;i<=n;i++){
            sum += 2*i+2;
      }
      cout<< sum;
}
int main (){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      solve();
      cout<<endl;
      solve2();
      cout<<endl;
      solve3();
      cout<<endl;
      return 0;
}