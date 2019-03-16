#include<iostream>
using namespace std;
		//	012345678901234567890123456
char a[28]="#ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char kodChar(int x){
	
	int r[28]={0};
	
	for(int i=1 ; i<28 ; i++){
		r[i]=i;
		
		if(x==r[i]) return a[i];
	}
	
	return '-';
}

int kodInt(char c){
	
	int r[28]={0};
	
	for(int i=1 ; i<28 ; i++){
		r[i]=i;
		
		if(c==a[i]) return r[i];
	}
	
	return -1;
}

int main(){
	
	string cumle,acar;
	
	cin>>cumle;
	cin>>acar;
	
	int sifre[cumle.length()],de_sifre[cumle.length()];
	
	int index=0;
	
	for(int i=0 ; i<cumle.length() ; i++){
		int cumle_kod = kodInt(cumle[i]);
		int acar_kod = kodInt(acar[index]);
		
		
		//OUTPUT
		//cout<<cumle_kod<<" ";
		//cout<<acar_kod<<endl;
		
		int temp=(cumle_kod+acar_kod)%26;
		
		sifre[i]=(temp==0 ? temp+=26 : temp );
		
		index++;
		if(index==acar.length()) index=0;
	
	}
	
	//OUTPUT CODE
	cout<<endl<<"Sifrelenmish metn : ";
	for(int i=0 ; i<cumle.length() ; i++){
		char c=kodChar(sifre[i]);
		cout<<c;
	}
	
	cout<<endl;
	
	index=0;
	
	char ch;
	cout<<endl<<"Deshifre olunsun ? (h/y) : ";
	cin>>ch;
	
	if(ch=='h'){
		cout<<endl<<"Desifrelenmish metn : ";
		
		for(int i=0 ; i<cumle.length() ; i++){
			int cumle_dekod = sifre[i];
			int acar_dekod = kodInt(acar[index]);
			
			//cout<<cumle_dekod<<" "<<acar_dekod<<endl;
			
			int res=(cumle_dekod-acar_dekod)%26;
			
			de_sifre[i]=(res<0 ? res+26 : res);
			index++;
			
			if(index==acar.length()) index=0;
		}
		
		for(int i=0 ; i<cumle.length() ; i++){
			char c = kodChar(de_sifre[i]);
			cout<<c;
		}
	}
	else if(ch=='y') cout<<"Proqram sonlandi..";
	
	
	
	
	return 0;
}
