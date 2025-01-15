#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
}*root = NULL, *temp,*newnode,*current;

int val; 

struct node *createnode(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left= NULL;
    newnode->right= NULL;
    return newnode; 
}

struct node *insert(struct node *root,int val)
{
    if(root==NULL)
    {
        temp=createnode(val);
        root=temp;
        return root;
    }
    else
    {
        if(val > root->data)
            root->right = insert(root->right,val);
        
        if (val < root->data)
            root->left = insert(root->left,val);
    }
    return root;
}

void insertion()
{
    printf("Enter the data: ");
    scanf("%d",&val);

    root = insert(root,val);
}

struct node *min(struct node *root)
{
    while(root->left==NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root,int val)
{
    if(val>root->data)
        root->right=delete(root->right,val);

    else if(val<root->data)
        root->left = delete(root->left,val);
    
    else
    {
        if(root->right==NULL)
            return root->left;
        
        else if(root->left==NULL)
            return root->right;
        
        else
        {
            temp= min(root->right);
            root->data = temp->data;       
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}

void deletion()
{
    printf("Enter the element you wish to delete: ");
    scanf("%d",&val);

    root = delete(root,val);

}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}
void display()
{
    inorder(root);
}

void main()
{
    int ch;
    while(1)
    {
        printf("Enter the choice: ");
        scanf("%d",&ch);
        if(ch==1)
        insertion();

        if (ch==2)
        display();

        if(ch==3)
            deletion();
    }
}