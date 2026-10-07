#include<iostream>
using namespace std;

int A(int m,int n){// 定義函式 
	if (m==0){// 符合m==0所以n+1 
	
	 return n+1;	
	}
	else if (n==0){// 符合n==0所以A(m-1,n=1) 
	 return A(m-1,1);	
	}
	else{            
	 return A(m-1,A(m,n-1));// 要先算內層 A(m, n-1)，算完的結果才是外層 A(m-1, ?) 的第二個數
	} 
}
int main(){	
	cout<<"遞迴"<<"\n";
	int m,n;
	cout<<"input m:";
	cin>>m;
	cout<<"input n:";
	cin>>n;
	cout <<"function output:"<<A(m,n)<<"\n";// 呼叫函式並輸出結果 
	
	system("PAUSE");
	return 0;
}



