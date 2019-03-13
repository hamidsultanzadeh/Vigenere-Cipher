#include<iostream>
using namespace std;
char dekod(int x){
	char a[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int r[26];
	
	for(int i=0 ; i<26 ; i++){
		r[i]=i;
		
		if(x==r[i]) return a[i];
	}
	
	return '-';
}

int kod(char c){
	//          01234567890123456789012345
	char a[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int r[26];
	
	for(int i=0 ; i<26 ; i++){
		r[i]=i;
		
		if(c==a[i]) return r[i];
	}
	
	return -1;
}

int main(){
	string cumle,acar;
	
	cin>>cumle;
	cin>>acar;
	
	int sifre[cumle.length()];
	
	int index=0;
	
	for(int i=0 ; i<cumle.length() ; i++){
		int cumle_kod = kod(cumle[i]);
		int acar_kod = kod(acar[index]);
		
		/*
		OUTPUT
		cout<<cumle_kod<<" ";
		cout<<acar_kod<<endl;
		*/
		sifre[i]=(cumle_kod+acar_kod)%26;
		
		index++;
		if(index==acar.length()) index=0;
	
	}
	
	for(int i=0 ; i<cumle.length() ; i++){
		char c=dekod(sifre[i]);
		cout<<c;
	}
	
	
	return 0;
}
