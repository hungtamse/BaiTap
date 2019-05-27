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
<<<<<<< HEAD
int x1=1,y1;
=======
int k,x1=1,y1,dem=1,count=0,z, x2=0, y2=0, z2=0, t=0;
int temp[20];
char chuoi[4][10];
string change;
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31


//==================================================================
//bai tap 1
void bt1(){
<<<<<<< HEAD
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
=======
	cout << "hay nhap n: " << endl;
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

>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
		for(int i=0; i<dem; i++){
			y1= z/x1;
			temp[i]=y1;
			z=z%x1;
			x1/=10;
			if(temp[i]%2 != 0){
				count+=temp[i];
			}
<<<<<<< HEAD
=======

>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
		}
		cout << "Sum Odd= "<<count;

	}
	else {
<<<<<<< HEAD
		cout << "ERROR!";
=======
		cout << "Khong hop le";
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
	}
}

//=====================================================================
//bt2


void bt2(){
<<<<<<< HEAD
	string change;
	char chuoi[4][10];
	int count1=0, x2=0, y2=0, z2=0, t=0,count=0;
	cout<<"please input the word to convert"<<endl;
=======
	int count1=0;
	cout<<"please type the word to convert"<<endl;
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
	getline(cin,change);
	for(int i=0; i<change.size(); i++){
		if(change[i]==' '){
		count1+=1;
		}
	}
	if(count1==3){
<<<<<<< HEAD
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
=======
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
					chuoi[1][y2]=change[i];
					y2++;

				}
				if(count==2){
					chuoi[2][z2]=change[i];
					z2++;


				}
				if(count==3){
					chuoi[3][t]=change[i];
					t++;


				}
			}
			cout<<"Convert completed: ";
			cout<<chuoi[0];
			cout<<chuoi[2];
			cout<<chuoi[1];
			cout<<chuoi[3];
		}
		else
			cout<<"Error, please type 4 word!";
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31

}

//=======================================================================
//bt 3
void bt3(){
	int q=0;
<<<<<<< HEAD
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
=======
	cout << "Nhap n: " << endl;
		cin>>n;
		if(n>=1 && n<=100){
			int chuoi[n];
			for(int i=1; i<=n; i++){
				cout<<i<<" ";
				chuoi[i]=300;
			}
			cout<<endl;
			cout << "Diem danh: "<<endl;
			for(int j=1; j<=n; j++){
				cin>>x;
				cin.get();
				chuoi[x]=1;

			}
			cout<<"Vang: ";
			for(y=1; y<=n; y++){
				if(chuoi[y]==300){
					cout<< y<<" ";
				}
			}
		}
		else
			cout<<"Khong hop le";
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31

}


void choice(){
	cout<<"1 Sum Odd"<<endl;
<<<<<<< HEAD
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
=======
		cout<<"2 Word Swap"<<endl;
		cout<<"3 Check Student Acttendance"<<endl;
		cin>>u;
		cin.get();
		switch(u){
		case 1:
			bt1();
			if(cin.get()=='\n'){
				cout<<""<<endl;
				cout<<"====================="<<endl;
				choice();
			}
			break;
		case 2:
			bt2();
			if(cin.get()=='\n'){
				cout<<""<<endl;
				cout<<"====================="<<endl;
				choice();
			}
			break;
		case 3:
			bt3();
			if(cin.get()=='\n'){
				cout<<""<<endl;
				cout<<"====================="<<endl;
				choice();
			}
			break;
		default:
			cout<<"Khong hop le";
			if(cin.get()=='\n'){
				cout<<""<<endl;
				cout<<"====================="<<endl;
				choice();
			}
		}
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
}



//===========================================
int main() {
<<<<<<< HEAD
	bool check= true;
	int c=0;
	while(check){
		choice();
		cout<<"Do you want to continue(0 is no, 1 is yes):";
		cin>>c;
		if(c==0)
			check=false;

	}
=======
	choice();
>>>>>>> 0e58c5b8ee84a13db396f4fba54de2da59e86f31
	return 0;
}
