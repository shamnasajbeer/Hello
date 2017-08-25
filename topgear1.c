#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int age;
    char name[20];
    struct node* next;
}node_t;

node_t *head = NULL; 

void insert(void){
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Unable to allocate memory\n");
        exit(-1);
    }
    printf("Enter name and age to be inserted\n");  
    scanf("%s %d",(temp->name),&(temp->age));
    temp->next = NULL;
    if(head ==  NULL){
        head = temp;
        printf("Node added at front\n");
    }
    else{
        node_t *current = head;
        node_t *prev = NULL;
        while(current != NULL){
            if((head->age) > (temp->age)){
                temp->next = head;
                head=temp;
                return;
            }
            else if(current->age == temp->age){
                prev=current->next;
                current->next = temp;
                temp->next = prev;
                return;
            }
            else if((current->age) > (temp->age)){
                prev->next = temp;
                temp->next = current;                  
                return;
            }
            prev = current;
            current = current->next;    
        }
        prev->next = temp;    

        printf("Node added at end\n");
    }
    return ;
}

void removeN(void){
    int value=0,count=1;
    printf("Enter N :\n");
    scanf("%d",&value);
    node_t *current=head;
    node_t *prev=NULL;
    node_t *temp=NULL;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    while(current != NULL){
        if(value == count){
            prev->next = current->next;
            temp = current;
            free (temp);
            temp=NULL;
            break;   
        }
        prev = current;
        current = current->next;
        count++;
    }
    return;
}

void printN(void){
    int value=0,count=1;
    printf("Enter N :\n");
    scanf("%d",&value);
    node_t *current=head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    while(current != NULL){
        if(value == count){
            printf("%s  %d \n--> ",current->name,current->age);
            break;   
        }
        current = current->next;
        count++;
    }
}

void printlist(void){
    node_t* current = head;
    if(head == NULL){
        printf("List is empty\n");
        return ;
    }
    printf("Linked list elements are : \n head-->");
    while(current != NULL){
        printf("%s  %d \n--> ",current->name,current->age);
        current = current->next;
    }     
    printf(" NULL\n");
    return ;  
}

int main(void) {

    int choice = 1,opt = 0;
    while(choice){

        printf("1.Insert node\n");
        printf("2.Remove Nth node\n");
        printf("3.Print Nth node\n");
        printf("4.Print List\n");

        scanf("%d",&opt);
        switch(opt){
            case 1:
                insert();
                break;
            case 2:
                removeN();
                break;
            case 3:
                printN();
                break;
            case 4:
                printlist();
                break;
            default :
                printf("You entered wrong choice\n");
                break;

        }
        printf("Do you want continue , Press 0 or 1 \n");
        scanf("%d",&choice);
    }
    return 0;
}        


