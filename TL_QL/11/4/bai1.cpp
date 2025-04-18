#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

void getInput(){
      cin>> n;

}
long solve1(){
      if(n == 1) return 1;
      if(n == 2) return 1;
      return solve1(n-1) + solve1(n-2);
}
void solve2(){
      a.push_back(1);
      a.push_back(1);
      for(int i = 2;i<=n;i++){
            a.push_back(a[i-1] + a[i-2]);
      }
}
int main (){

      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      cout<<solve1()<<endl;
      solve2();
      for(int i = 0;i<n;i++){
            cout<<a[i]<<" ";
      }
      
      
}