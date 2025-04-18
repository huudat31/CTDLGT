#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
void getInput(){
      cin>> n;
      for(int i = 0;i<n;i++){
            int x;
            cin>> x;
            a.push_back(x);
      }
}
long slove(int left,int right){
      if(left == right){
            return a[left];
      }
      if(left + 1 == right){
            return max(a[left],a[right]);
      }
      int mid = (left + right) / 2;
      long leftMax = slove(left,mid);
      long rightMax = slove(mid+1,right);
      return max(leftMax,rightMax);
}
int main (){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      getInput();
      int left = 0;
      int right = n - 1;
      cout<<slove(left, right)<<endl;
}



