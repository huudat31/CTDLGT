#include<bits/stdc++.h>
using namespace std;

int n;
void getInput(){
      cin>> n;
}

long long solve1(int n){
      if(n == 0) return 1;
      if(n== 1) return 2;
      else{
            if(n % 2 == 0){
                  return solve1(n/2)*solve1(n/2);
            }
            else{
                  return solve1(n-1)*solve1(n-1)*2;
            }
      }
}
int main (){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      cout<<solve1(n)<<endl;
}