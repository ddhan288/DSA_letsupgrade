#include<stdio.h>

int rotLeft(int *,int);
void displayElements(int *);
int main(){
    int arr[5];
    int i, times;
    for(i=0; i<5; i++){
        printf("Enter the %d element: ",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("Enter the number of times to rotate: ");
    scanf("%d",&times);
    rotLeft(arr, times);
    printf("\nFinal\n");
    displayElements(arr);
}

int rotLeft(int *arr, int times){
    int i;
    int first;
    int temp;
    int size = 5;
    int rt = 0;
    while(rt < times){
        for(i=0; i<size; i++){
            if(i==0){
                first = arr[i];
                arr[i] = arr[i+1];
            }
            else if(i==(size-1)){
                arr[i] = first;
            }
            else{
                temp = arr[i];
                arr[i] = arr[i+1];
            }

        }
        displayElements(arr);
        printf("\n");
        rt++;
    }
}

void displayElements(int *arr){
    int i;
    for(i=0; i<5; i++){
        printf("[%d]",arr[i]);
    }
}