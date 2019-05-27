/*
 * BT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: lhungtam
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>
using namespace std;

int CountSpace(char *str){
    int i, count=0;
    for(i=0; i<strlen(str); i++){
        if(str[i] == ' '){
            count++;
        }
    }
    return count;
}

void WordSwap(char *str){
    char temp[CountSpace(str)][10];
    int i, j=0, n=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]==' '){
            temp[j][n]='\0';
            j++;
            n=0;
        }
        else{
            temp[j][n]=str[i];
            n++;
        }
    }
    temp[j][n]='\0';

    for(i=0; i<=CountSpace(str); i++){
        if(i==1){
            cout << temp[CountSpace(str)-1] << " ";
        }
        else{
            if(i==CountSpace(str)-1){
                cout << temp[1] << " ";
            }
            else{
                if(i==CountSpace(str)){
                    cout << temp[i];
                }
                else{
                    cout << temp[i] << " ";
                }
            }
        }
    }
}

list<int> FindAbsence(int arr[], int size){
    list<int> sv;
    int i, j=1, count=0;
    bool check=false;
    for(j=1; j<=size; j++){//value of array
        check=false;
        for(i=0; i<size; i++){
            if(j==arr[i]){
                check=true;
                break;
            }
        }
        if(check==false){
            sv.push_back(j);
        }
    }
    return sv;
}

int main(){
    int select, n, result=0, temp, size;
    int arr[100];
    char* str;
    list<int> myList;
    str=(char*)malloc(sizeof(char)*256);
    cout << "Select 1 ==> Sum Odd" << "\n" << "Select 2 ==> Word Swap" << "\n"
            << "Select 3 ==> Check Student Attendance" << endl;
    cin >> select;
    cin.get();
    switch(select){
        case 1:
            cin >> n;
            while(n>=0 && n<=4000000000){
                if(n==0){
                    break;
                }
                temp = n%10;
                n /= 10;
                if(temp%2 != 0){
                    result += temp;
                }
            }
            cout << result << endl;
            break;
        case 2:
            cin.getline(str, 255);
            WordSwap(str);
            break;
        case 3:
            cin >> size;
            if(size < 1 || size > 100){
                return -1;
            }
            for(int i=0; i<size; i++){
                cin >> temp;
                if(temp > size || temp < 1){
                    return -1;
                }
                else{
                    arr[i]=temp;
                }
            }
            myList=FindAbsence(arr, size);
            while(!myList.empty()){
                cout << myList.front() << " ";
                myList.pop_front();
            }
            break;
        default:
            cout << "Value input false" << endl;
    }
    return 0;
}

