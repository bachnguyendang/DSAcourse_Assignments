                                        //Đề bài: Find a pair with the given sum array
//Version 1: Brute force, unrefined
// #include<stdio.h>
// int main(){
// 	int size, sum; scanf("%d %d", &size,&sum);
// 	int ar[size];
// 	for(int i = 0; i < size; i++){
// 		scanf("%d", &ar[i]);
// 	} 
// 	int found = 0;
// 	for(int i = 0; i < size; i++){
// 		for(int j = i + 1; j < size; j++){
// 			if(ar[i] + ar[j] == sum){
// 				if(found) printf("or\n");
// 				found++;
// 				printf("Pair found (%d,	 %d)\n", ar[i], ar[j]);
// 				break;
// 			}
// 		}
// 	}
// 	if(!found) printf("Pair not found"); 
// 	return 0;
// } 


// Version 2: Using algorithm
#include <iostream>
using namespace std;
int main() {
	int size, target; cin >> size >> target;
	int ar[size];
	for(int i = 0; i < size; i++){
		cin >> ar[i];
	}
	// Em hiện chỉ biết mỗi thuật toán sắp xếp này thôi :( sau này nếu biết cái khác tối ưu hơn thì em sẽ chỉnh sau 
	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			int temp = ar[i];
			if(ar[i] > ar[j]){
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
	int start = 0, end = size - 1;
	bool found = false;
	while(start < end){
		if(ar[start] + ar[end] == target){
			if(found) cout << "or" << endl;
			found = true;
			cout << "Pair found (" << ar[start] << "," << ar[end] << ")" << endl;
			start ++; end--;
		}
		else if(ar[start] + ar[end] > target) end--;
		else start++;
	}
	if(!found) cout << "Pair not found!";
	return 0;
}


