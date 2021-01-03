#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create_node(int data);
Node* insert(Node *head, int);
void display(Node *head);
Node* insert_any_pos(Node *,int, int);

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

    printf("\nEnter the position from 0 - %d:",size);
    scanf("%d",&position);
    if(position > 0 || position > size){
        printf("Enter valid position.");
        return 0;
    }
    printf("Enter the data: ");
    scanf("%d",&data);

    head = insert_any_pos(head, data, position);
    printf("Data inserted.\n");
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

Node* insert_any_pos(Node *head, int data, int position){
    Node *new_node = create_node(data);
    Node *temp = head;
    if(head == NULL){
        head = new_node;
        return head;
    }
    else{
        if(position == 0){
            //printf("Position: %d\n",position);
            //printf("New node: data=[%d] next=[%d]\n",new_node->data, new_node->next);
            new_node -> next = temp;
            //printf("Temp node: data=[%d] next=[%d]\n",temp->data, temp);
            //printf("New node: data=[%d] next=[%d]\n",new_node->data, new_node->next);
            return new_node;
        }
        else{
            int i=0;

            for(i=1; i<position; i++){
                if(temp->next != NULL){
                    temp = temp->next;
                }
                else{
                    temp->next = new_node;
                    return head;
                }
            }
            Node *next_node = temp->next;
            temp->next = new_node;
            new_node -> next = next_node;

            return head;
        }
    }
}