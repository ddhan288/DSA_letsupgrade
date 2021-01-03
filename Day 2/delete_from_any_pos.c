#include<stdio.h>
#include<stdlib.h>

void removeElement(int *, int);
void displayArr(int *, int);

int main(){
    int *arr = NULL;
    int size = 0;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int i = 0;
    
    // Allocate the memory
    arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL){
        printf("Unable to allocate the size.");
        return 0;
    }

    // Enter numbers in the array
    for(i=0; i<size; i++){
        printf("Enter the number at index %d: ",i);
        scanf("%d",&*(arr+i));
    }

    i=0;
    // Display the array
    for(int i=0; i<size; i++){
        printf("%d \t [%d]\n",i,arr[i]); 
    }
    
    removeElement(arr, size);
    displayArr(arr, size);


    getchar();
    return 0;
}

void removeElement(int *arr, int size){
    int index;
    //int size = sizeof(arr);
    printf("Size of array: %d\n",size);
    printf("Enter the index you wish to delete: ");
    scanf("%d",&index);

    // Checking for edge case ie: index is > or < size of the array
    if(index< 0 || index > size){
        printf("Please enter the correct index");
        //return 0;
    }
    
    int i;
    int temp;

   for(i=index; i<size -1; i++){
                
       if(i+1 < size){                       
            //*(arr + i) = *(arr + i + 1);
            arr[i]= arr[i+1];
        }
    }
    free(arr + (size-1));

}

void displayArr(int *arr, int size){
    //int size = sizeof(arr);
    //printf("Size of array: %d\n",size);
    printf("After deletion.\n");
    int i;
    for(i = 0; i<size-1; i++){
        printf("%d \t [%d] \n",i,arr[i]);
    }
}