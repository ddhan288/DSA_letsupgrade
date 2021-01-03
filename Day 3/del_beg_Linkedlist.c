#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create_node(int data);
Node* insert(Node *head, int);
void display(Node *head);
Node* delete_beg(Node *);

int main(){
    int size;
    Node *head=NULL;
    int data;
    int i;
    int position;
    printf("Enter the size of the Linkde list: ");
    scanf("%d",&size);
    for(i=0; i<size; i++){
        printf("Enter the number: ");
        scanf("%d",&data);
        head = insert(head, data);
    }
    display(head);
    
    printf("\nElement has been deleted from the beginning.\n");
    head = delete_beg(head);
    display(head);
}

Node* create_node(int data){
    Node *new_node = NULL;
    new_node = (Node *)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

Node* insert(Node *head, int data){
    Node *new_node = create_node(data);
    if(head == NULL){
        head = new_node;
        return head;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display(Node *head){
    Node *temp = head;
    if(temp != NULL){
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    else{
        printf("List is empty.");
    }
}

Node* delete_beg(Node *head){
    head = head->next;
    return head;
}