#include<stdio.h>

void push(int *, int, int *);
void pop(int *, int *);
void display(int *, int *);

void maximum_in_stack(int *, int *);
void minimum_in_stack(int *, int *);

int main(){
    int stack_arr[50];
    int top = -1;
    int choice;
    int data;
    while(1){
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. Maximum\n");
        printf("5. Minimum\n");
        printf("0: EXIT\n");
        printf("Enter your option: ");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                push(stack_arr, data, &top);
                break;
            case 2:
                pop(stack_arr, &top);
                break;
            case 3:
                display(stack_arr, &top);
                break;
            case 4:
                maximum_in_stack(stack_arr, &top);
                break;
            case 5:
                minimum_in_stack(stack_arr, &top);
                break;
            default:
                display(stack_arr, &top);
        }
    }
}

void push(int *arr, int data, int *top){
    if(*top < (50 - 1)){
        *top += 1;
        arr[*top] = data;
    }
    else{
        printf("Stack is full.\n");
    }
}

void pop(int *arr, int *top){
    if(*top != -1){
        *top -=1;
    }
    else{
        printf("Stack is empty.\n");
    }
}

void display(int *arr, int *top){
    if(*top != -1){
        int size = *top;
        int i=0;
        for(i=0; i<=size; i++){
            printf("[%d] ",arr[i]);
        }
        printf("\n");
    }
    else{
        printf("Stack is empty.\n");
    }
}

void maximum_in_stack(int *arr, int *top){
    int max = '\0';
    int size = *top;
    int i=0;
    if(*top != -1){
        for(i=0; i<=size; i++){
            if(max == '\0'){
                max = arr[i];
            }
            else{
                if(max < arr[i]){
                    max = arr[i];
                }
            }
        }
        printf("Max: %d\n",max);
    }
    else{
        printf("Stack is empty.\n");
    }
}

void minimum_in_stack(int *arr, int *top){
    int min = '\0';
    int size = *top;
    int i = 0;
    if(*top != -1){
        for(i=0; i<=size; i++){
            if(min == '\0'){
                min = arr[i];
            }
            else{
                if(min > arr[i]){
                    min = arr[i];
                }
            }
        }
        printf("Min: %d\n",min);
    }
    else{
        printf("Stack is empty.\n");
    }
}

