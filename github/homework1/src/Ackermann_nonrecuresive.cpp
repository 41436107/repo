#include<iostream>
using namespace std;

void push_stack(int* s, int& top, int capacity, int value) {//push函式（推入） 
    s[++top] = value;
}

int pop_stack(int* s, int& top) {//pop函式（彈出） 
    return s[top--];
}


int A_N(int m,int n){
	int capacity =60;// 堆疊的容量
	int top =-1;// -1 代表堆疊是空的
	int* s=new int[capacity];//用來模擬遞迴的呼叫堆疊
	
	push_stack(s,top,capacity,m);// 先把初始的 m 推入堆疊

	while(top>=0){
	
	m= pop_stack(s,top);
	
	if(m==0)// 符合m==0所以n+1 
	{
		n++;
	}
	else if (n==0){// 把 n 設為 1，並把 m-1 推入堆疊等下一輪處理
		n=1;
		push_stack(s,top,capacity,m-1);
	}
	else{// 要先算內層 A(m, n-1)，算完的結果才是外層 A(m-1, ?) 的第二個數
		n--;
		push_stack(s,top,capacity,m-1);
		push_stack(s,top,capacity,m);
	}	
	}
	
	delete[] s;
	return n;
} 

int main(){
	cout<<"非遞迴"<<"\n";
	int m,n;
	cout<<"input m:";
	cin>>m;
	cout<<"input n:";
	cin>>n;
	
	cout<<"function output:"<<A_N(m,n)<<"\n";// 呼叫函式並輸出結果 
	
	system("PAUSE");
	return 0;
	
}
