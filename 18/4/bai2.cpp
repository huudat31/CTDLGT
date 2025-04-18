      #include<bits/stdc++.h>
using namespace std;

int n,b;
vector<int> a;

// selectionSort
void selectionSort(vector<int> &a){
      for(int i = 0;i<a.size();i++){
            int minIndex = i;
            for(int j = i+1;j<a.size();j++){
                  if(a[j] < a[minIndex]){
                        minIndex = j;
                  }
            }
      }
            swap(a[i],a[minIndex]);
      }
// bubblesort
void bubblesort(vector<int> &a){
      for(int i = 0;i<a.size();i++){
            for(int j = 0;j<a.size()-i-1;j++){
                  if(a[j] > a[j+1]){
                        swap(a[j],a[j+1]);
                  }
            }
      }
}
// insertionSort
void insertionSort(vector<int> &a){
      for(int i = 1;i<a.size();i++){
            int key = a[i];
            int j = i-1;
            while(j >= 0 && a[j] > key){
                  a[j+1] = a[j];
                  j--;
            }
            a[j+1] = key;
      }
}
void getInput(){
      cin >> n>> b;
      for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
      }
      sort(a.begin(),a.end());
      // selectionSort(a);
      // bubblesort(a);
      // insertionSort(a);
}
// binarySearch
int binarySearch(vector<int> &a,int l,int r,int x){
      while(l <= r){
            int mid = (l+r)/2;
            if(a[mid] == x){
                  return mid;
            }
            else if(a[mid] < x){
                  l = mid + 1;
            }
            else{
                  r = mid - 1;
            }
      }
      return -1;
}
void solve(){
      binarySearch(a,0,n-1,b);
      cout << binarySearch(a,0,n-1,b);
}
int main (){
getInput();
solve();

}