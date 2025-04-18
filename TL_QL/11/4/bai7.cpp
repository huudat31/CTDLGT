#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int> a;
void getInput(){
      cin>> n>> e;
      for(int i = 0;i<n;i++){
            int x;
            cin>> x;
            a.push_back(x);
      }
}


int solve(int left, int right){
    if(left == right){
        return (a[left] == e) ? 1 : 0;
    }
    int mid = (left + right) / 2;
    int leftCount = solve(left, mid);
    int rightCount = solve(mid + 1, right);
    return leftCount + rightCount;
}

int main (){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      int left = 0;
      int right = n - 1;
      cout<<solve(left , right)<<endl;
}     