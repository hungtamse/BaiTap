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

int countspace(char *str){
	int i, count=0;
	for(i=0; i<strlen(str); i++){
		if(str[i] == ' ')
			count++;
	}
	return count;
}

void WordSwap(char *str){
	char temp[countspace(str)][10];
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

	for(i=0; i<=countspace(str); i++){
		if(i==1)
			cout << temp[countspace(str)-1] << " ";
		else
			if(i==countspace(str)-1)
				cout << temp[1] << " ";
			else
				if(i==countspace(str))
					cout << temp[i];
				else
					cout << temp[i] << " ";
	}
}

list<int> findAbsence(int arr[], int size){
	list<int> sv;
	int i, j=1, count=0;
	bool check=false;
	for(j=1; j<=size; j++){//value of array
		check=false;
		for(i=0; i<size; i++)
			if(j==arr[i]){
				check=true;
				break;
			}
		if(check==false){
			sv.push_back(j);
		}
	}
	return sv;
}

int main(){
	int select;
	cout << "Chon 1 ==> Bai tap 1" << "\n" << "Chon 2 ==> Bai tap 2" << "\n"
			<< "Chon 3 ==> Bai tap 3" << endl;
	cin >> select;
	cin.get();
	switch(select){
	case 1:{
		int n, result=0, temp;
		cin >> n;
		while(n>=0 && n<=4000000000){
			if(n==0)
				break;
			temp = n%10;
			n /= 10;
			if(temp%2 != 0)
				result += temp;
		}
		cout << result << endl;
	}
		break;
	case 2:{
		char* str;
		str=(char*)malloc(sizeof(char)*256);
		cin.getline(str, 255);
		WordSwap(str);
	}
		break;
	case 3:{
		int i, size, temp, arr[100];
		cin >> size;
		if(size < 1 || size > 100)
			return -1;
		for(i=0; i<size; i++){
			cin >> temp;
			if(temp > size || temp < 1)
				return -1;
			else
				arr[i]=temp;
		}
		list<int> myList=findAbsence(arr, size);
		while(!myList.empty()){
			cout << myList.front() << " ";
			myList.pop_front();
		}
	}
		break;
	default:
		cout << "Nhap sai gia tri" << endl;
	}
	return 0;
}
