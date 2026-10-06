#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int before[n], after[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &before[i]);
    }
    after[0] = before [0];
    for(int i = 1; i < n; i++){
        after[i] = before[i];
        for(int j = i; j >= 0; j--){
            if(after[j] < after[j - 1]){
                int temp = after[j];
                after[j] = after[j - 1];
                after[j - 1] = temp;
            }
            else break;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", after[i]);
    }
    return 0;
}