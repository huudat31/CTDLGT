#include<bits/stdc++.h>

#define Struct st;
#define push_back pb;
using namespace std;
// enum GioiTinh{
//       Nam,
//       Nu
// };
int n;
st SinhVien{
      string ten;
      string gioitinh;
      int namsinh;
      float diemTK;

}
SinhVien sv;
vector<SinhVien> a;
void getInput(){
      cin >>n;

      for(int i = 0;i<n;i++){
            SinhVien x;
            cin >> x.ten >> x.gioitinh >> x.namsinh >> x.diemTK;
            a.pb(x);
      }
      cin >> sv.ten >> sv.gioitinh >> sv.namsinh >> sv.diemTK;



      sort(a.begin(),a.end(),[](SinhVien a,SinhVien b){
            if(a.ten == b.ten){
                  return a.diemTK > b.diemTK;
            }
            return a.ten < b.ten;
      });
}

// search tuan tu 
int  search(vector<SinhVien> &a,SinhVien x){
      for(int i = 0;i<a.size();i++){   
            if(a[i].ten == x.ten && a[i].diemTK == x.diemTK){
                  return  i+1;
                  break;
            }
      }
      return 0;
}
int binarySearch(vector<SinhVien> &a,int l,int r,SinhVien x){
      while(l <= r){
            int mid = (l+r)/2;
            if(a[mid].ten == x.ten && a[mid].diemTK == x.diemTK){
                  return mid;
            }
            else if(a[mid].ten < x.ten){
                  l = mid + 1;
            }
            else{
                  r = mid - 1;
            }
      }
      return -1;
}







// tuan tu 
void solve(){
      cout<< search(a,sv);
     cout<< binarySearch(a,0,a.size()-1,sv);
}


int main (){
getInput();
solve();
}