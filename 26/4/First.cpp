#include<bits/stdc++.h>
using namespace std;
struct sinhVien{
	string maSV;
	string hoDem;
	string ten;
	string gioiTinh;
	int namSinh;
	float diemTK;
	sinhVien(){
		maSV = "001";
		hoDem = "Nguyen Van";
		ten = "A";
		gioiTinh = "Nam";
		namSinh = 2000;
		diemTK = 10;
	}
	sinhVien(string ma, string ho, string name, string gt, int n, float d){
		maSV = ma;
		hoDem = ho;
		ten = name;
		gioiTinh = gt;
		namSinh = n;
		diemTK = d;
	}
	void nhap(){
		cout<<"Nhap ma sinh vien: ";getline(cin,maSV);
		cout<<"Nhap ho dem sinh vien: ";getline(cin,hoDem);
		cout<<"Nhap ten sinh vien: ";getline(cin,ten);
		cout<<"Nhap gioi tinh: ";getline(cin,gioiTinh);
		cout<<"Nhap nam sinh: ";cin>>namSinh;
		cout<<"Nhap diem tong ket: ";cin>>diemTK;cin.ignore();
	}
	void xuat(){
		cout<<setw(10)<<maSV<<setw(15)<<hoDem<<setw(10)<<ten<<setw(10)<<gioiTinh<<setw(10)<<namSinh<<setw(10)<<diemTK<<endl;
	}
};
#define MAX 10
struct List{
	int count;
	sinhVien p[MAX];
};
List L;
void creat (List &L){
	L.count=-1;
}
bool empty(List L){
	if (L.count==-1){
		return true;
	}
	return false;
}
bool full(List L){
	if (L.count == MAX -1){
		return true;
	}
	return false;
}
int xoaDau(List &L){
	if(empty(L) == false){
		for(int i=0;i<L.count;i++){
			L.p[i]=L.p[i+1];
		}
		L.count--;
		return 1;
	}
	else{
		cout<<"Khong du dieu kien de xoa"<<endl;
		return 0;
	}
}
int xoaIndex(int k, List &L){
	if(empty(L)== false && k>0 && k<= L.count+1){
		if(k-1==0){
			xoaDau(L);
			return 1;
		}
		else{
			for(int i = k;i<=L.count;i++){
				L.p[i-1]=L.p[i];
			}
			L.count --;
			return 1;
		}
	}
	else{
		cout<<"Khong du dieu kien de xoa"<<endl;
		return 0;
	}
}
pair<int,int> Min(List &L){
	int min = L.p[0].diemTK;
	int check = 0;
	for(int i=0;i<=L.count;i++){
		if(L.p[i].diemTK<min){
			check = 1;
			min = L.p[i].diemTK;
		}
		else if(L.p[i].diemTK==min){
			check++;
		}
	}
	pair <int,int> res = make_pair(min,check);
	return res;
}
pair<int,int> Max(List &L){
	int max = L.p[0].diemTK;
	int check = 0;
	for(int i=0;i<=L.count;i++){
		if(L.p[i].diemTK<max){
			check = 1;
			max = L.p[i].diemTK;
		}
		else if(L.p[i].diemTK==max){
			check++;
		}
	}
	pair <int,int> res = make_pair(max,check);
	return res;
}
pair<vector<sinhVien> ,int> Search(List L){
	string X;
	vector<sinhVien> x; 
	cout<<"Nhap ten sinh vien muon tim: ";
	getline(cin,X);
	int check = 0;
	for(int i = 0;i<=L.count;i++){
		if(L.p[i].ten==X){
			check++;
			x.push_back(L.p[i]);
		}
	}
	if(check == 0){
		cout<<"Khong tim duoc sinh vien co ten "<<X<<endl;
		
	}
	pair<vector<sinhVien>, int> res = make_pair(x,check);
	return res;
}

int chen(int k, List &L){
	if(full(L)==false && k >=1 && k<=L.count+2){
		L.count++;
		for(int i=L.count-1;i>=k;i++){
			L.p[i]=L.p[i-1];
		}
		sinhVien c;
		c.nhap();
		L.p[k-1]=c;
		return 1;
	}
	else{
		cout<<"Khong du dieu kien de chen"<<endl;
	}
}
int thayThe( List &L){
	int k;
	cout<<"Chon vi tri can thay the: ";cin>>k;cin.ignore();
	if(empty(L) == false && k>=1 && k <= L.count+1){
		xoaIndex(k,L);
		chen(k,L);
		return 1;
	}
	else{
		cout<<"Khong the thay the "<<endl;
		return 0;
	}
}
void print(List L){
	cout<<"Danh sach sinh vien: "<<endl;
	for(int i=0;i<=L.count;i++){
		L.p[i].xuat();
	}
	cout<<endl;
}
void sapXep(List &L){
	for(int i =0;i<=L.count-1;i++){
		int m =i;
		for(int j=i+1;j<=L.count;j++){
			if(L.p[m].ten>L.p[j].ten){
				m=j;
			}
		}
		if(m!=i){
			swap(L.p[m],L.p[i]);
		}
	}
}
void NHAP(List &L){
	int k = 1;
	while(true){
		cout<<"Nhap thong tin sinh vien "<<k<<": "<<endl;
		chen(k,L);
		k++;
		string y;
		cout<<"Co nhap tiep hay khong (Y/N): ";getline(cin,y);
		if(y == "N"){
			break;
		}
	}
}
int main(){
	creat(L);
	NHAP(L);
	pair<int,int> res = Min(L);
	print(L);
	cout<<endl<<"Diem tong ket nho nhat la: "<<res.first<<" Xuat hien "<<res.second<<" lan"<<endl;
	xoaDau(L);
	print(L);
	return 0;
}
