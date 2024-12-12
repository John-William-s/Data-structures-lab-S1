#include <stdio.h>
#include <stdbool.h>
int queue[10], front = -1, rear = -1, num, op, max, value;
bool flag = true;
void insert();
int delete();
void display();
void main()
{
    printf("\nEnter the size of the queue:");
    scanf("%d", &max);
    while (flag)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nChoose your Operation:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            value = delete ();
            if (value == -1)
            {
                printf("\nQueue is empty");
            }
            else
            {
                printf("\nDeleted element is %d", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("\nEnter a valid operation");
            break;
        }
    }
}
void insert()
{
    if (rear == max - 1)
    {
        printf("\n Queue is full!");
    }
    else
    {
        rear++;
        printf("\nEnter element to be inserted:");
        scanf("%d", &num);
        queue[rear] = num;
        printf("\nInserted new element");
    }
}
int delete()
{
    if (front == -1 && rear == -1)
    {
        return -1;
    }
    else
    {
        front++;
        num = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        return num;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty!");
    }
    else
    {
        printf("\n Queue elements are\n");
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}