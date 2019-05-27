//============================================================================
// Name        : CheckStudentAttendance.cpp
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
void AddOdd(){
    int temp[20];
    int z, k = 0, CountNum=1, count=0;
    cout << "INPUT N: " << endl;
    cin >> k;
    if(k>=0 && k<=4000000000){
        z=k;
        while(k>=10){
            k/=10;
            CountNum+=1;
        }
        for(int i=1; i<CountNum; i++){
            x1*=10;
        }
        for(int i=0; i<CountNum; i++){
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
//WordSwap


void WordSwap(){
    string StringInput;
    int count1=0,j=0, n=0;
    cout<<"please input the word to convert"<<endl;
    getline(cin,StringInput);
    for(int i=0; i<StringInput.size(); i++){
        if(StringInput[i]==' '){
            count1+=1;
        }
    }
    if(count1>=3){
        char ArrayTemp[count1][10];
        for(int i=0; i<StringInput.size(); i++){
            ArrayTemp[j][n]=StringInput[i];
            n++;
            if(StringInput[i]==' '){
                ArrayTemp[j][n]='\0';
                j++;
                n=0;
            }
        }
        ArrayTemp[j][n]='\0';
        for(int i=0; i<=count1; i++){
            if(i==1){
                cout << ArrayTemp[count1-1] << " ";
            }
            if(i==count1-1){
                cout<<ArrayTemp[1]<<" ";
            }
            else{
                cout<<ArrayTemp[i]<<" ";
            }
        }
    }
    else{
        cout<<"Please input more than 4 word!"<<endl;
    }

}

//=======================================================================
//bt 3
void CheckStudentAttendance(){
    cout << "INPUT N: " << endl;
    cin>>n;
    if(n>=1 && n<=100){
        int ArrayTemp[n];
        for(int i=1; i<=n; i++){
            cout<<i<<" ";
            ArrayTemp[i]=300;
        }
        cout<<endl;
        cout << "CHECK START: "<<endl;
        for(int j=1; j<=n; j++){
            cin>>x;
            cin.get();
            ArrayTemp[x]=1;
        }
        cout<<"Absent: ";
        for(y=1; y<=n; y++){
            if(ArrayTemp[y]==300){
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
    cout<<"3 Check Student Attendance"<<endl;
    cin>>u;
    cin.get();
    switch(u){
        case 1:
            AddOdd();
            cout<<""<<endl;
            cout<<"====================="<<endl;
            break;
        case 2:
            WordSwap();
            cout<<""<<endl;
            cout<<"====================="<<endl;
            break;
        case 3:
            CheckStudentAttendance();
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
        if(c==0){
            check=false;
        }
    }
    return 0;
}
