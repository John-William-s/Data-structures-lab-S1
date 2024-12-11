#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

void main() {
    int value, i, n, ch, j;
    struct node *newNode, *current, *head = NULL;
    while(1){
        printf("1: Creation\n2: Display\n\n3: insertion at end\n4: deletion at end\n");
        printf("Enter choice");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the number of nodes: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) 
            {
                newNode = (struct node*)malloc(sizeof(struct node));  
                printf("Enter the value: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = NULL;

                if (head == NULL) 
                {
                    head = newNode; 
                    current = newNode;
                } else
                {
                    current->next = newNode; 
                    current = newNode;
                }
            }
            }
        if(ch==2)
        {
            current = head;
            if(head == NULL)
            {
                printf("Stack is empty....");
            }
            else{
                 printf("The linked list is: ");
            while (current != NULL) {
                printf("%d  ", current->data);
                current = current->next;
            }
            printf("\n");
            }
           

        }
        
        if(ch==3)
        {
            newNode = (struct node*)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d",&value);
            newNode->data=value;
            newNode->next=NULL;
            current=head;
            while (current->next != NULL) 
            {
                current = current->next;
            }
            current->next=newNode;

        }
        if(ch==4)
        {
            current=head;
            if(head==NULL)
            {
              printf("stack is empty.....\n");  
            }
            else if(current->next==NULL)
            {
                head=NULL;
            }
           
            else
            {
                while(current->next->next != NULL)
                {
                    current=current->next;
                }
                current->next=NULL;
            }
            
        }
}
}

   