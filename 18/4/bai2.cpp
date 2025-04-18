      #include<bits/stdc++.h>
using namespace std;

int n,b;
vector<int> a;



void getInput(){
      cin >> n>> b;
      for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
      }
}
void solve(){
      for(int i = 0;i<n;i++){
            if(a[i] == b){
                  cout<< i;
                  break;
            }
      }
}
int main (){
getInput();
solve();
}