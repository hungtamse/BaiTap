//============================================================================
// Name        : bt3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,x,y,u;
int x1=1,y1;


//==================================================================
//bai tap 1
void bt1(){
    int temp[20];
    int z, k = 0, dem=1, count=0;
    cout << "INPUT N: " << endl;
    cin >> k;
    if(k>=0 && k<=40000000000){
    	z=k;
    	while(k>=10){
    		k/=10;
    		dem+=1;
		}
    	for(int i=1; i<dem; i++){
			x1*=10;
		}
		for(int i=0; i<dem; i++){
			y1= z/x1;
			temp[i]=y1;
			z=z%x1;
			x1/=10;
			if(temp[i]%2 != 0){
				count+=temp[i];
			}
		}
		cout << "Sum Odd= "<<count;

	}
	else {
		cout << "ERROR!";
	}
}

//=====================================================================
//bt2


void bt2(){
	string change;
	char chuoi[4][10];
	int count1=0, x2=0, y2=0, z2=0, t=0,count=0;
	cout<<"please input the word to convert"<<endl;
	getline(cin,change);
	for(int i=0; i<change.size(); i++){
		if(change[i]==' '){
		count1+=1;
		}
	}
	if(count1==3){
		cout <<"Not Convert: "<<change<<endl;
		for(int i=0; i<change.size(); i++){
			if(change[i]==' '){
				count+=1;
			}
			if(count==0){
				chuoi[0][x2]=change[i];
				x2++;
			}
			if(count==1){
				chuoi[0][x2]='\0';
				chuoi[1][y2]=change[i];
				y2++;
			}
			if(count==2){
				chuoi[1][y2]='\0';
				chuoi[2][z2]=change[i];
				z2++;
			}
			if(count==3){
				chuoi[2][z2]='\0';
				chuoi[3][t]=change[i];
				t++;
			}
		}
		chuoi[3][t]='\0';
		cout<<"Convert completed: ";
		cout<<chuoi[0];
		cout<<chuoi[2];
		cout<<chuoi[1];
		cout<<chuoi[3];
	}
	else
		cout<<"Error, please input 4 word!";

}

//=======================================================================
//bt 3
void bt3(){
	int q=0;
	cout << "INPUT N: " << endl;
	cin>>n;
	if(n>=1 && n<=100){
		int chuoi[n];
		for(int i=1; i<=n; i++){
			cout<<i<<" ";
			chuoi[i]=300;
		}
		cout<<endl;
		cout << "CHECK START: "<<endl;
		for(int j=1; j<=n; j++){
			cin>>x;
			cin.get();
			chuoi[x]=1;
		}
		cout<<"Absent: ";
		for(y=1; y<=n; y++){
			if(chuoi[y]==300){
				cout<< y<<" ";
			}
		}
	}
	else
		cout<<"ERROR!";

}


void choice(){
	cout<<"1 Sum Odd"<<endl;
	cout<<"2 Word Swap"<<endl;
	cout<<"3 Check Student Acttendance"<<endl;
	cin>>u;
	cin.get();
	switch(u){
		case 1:
			bt1();
			cout<<""<<endl;
			cout<<"====================="<<endl;
			break;
		case 2:
			bt2();
			cout<<""<<endl;
			cout<<"====================="<<endl;
			break;
		case 3:
			bt3();
			cout<<""<<endl;
			cout<<"====================="<<endl;
			break;
		default:
			cout<<"ERROR!";
			cout<<""<<endl;
			cout<<"====================="<<endl;
	}
}



//===========================================
int main() {
	bool check= true;
	int c=0;
	while(check){
		choice();
		cout<<"Do you want to continue(0 is no, 1 is yes):";
		cin>>c;
		if(c==0)
			check=false;

	}
	return 0;
}
