#include <stdio.h>
#include <stdbool.h>
int stack[20], tos = -1, max, op;
bool flag = true;
void push();
int pop();
void display();
int peek();
int count();
void main()
{
    int stackcount, value;
    printf("\nEnter the size of the stack:");
    scanf("%d", &max);
    while (flag)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Count\n6.Exit\nChoose your Operation:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            push();
            break;
        case 2:
            value = pop();
            if (value == -1)
            {
                printf("\nStack is empty(Underflow)");
            }
            else
            {
                printf("\nPopped element is %d", value);
            }
            break;
        case 3:
            value = peek();
            if (value == -1)
            {
                printf("\nStack is empty");
            }
            else
            {
                printf("\nTop Element of stack is %d", value);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            stackcount = count();
            printf("\nNumber of stack elements=%d", stackcount);
            break;
        case 6:
            flag = false;
            break;
        default:
            printf("\nEnter a valid operation");
            break;
        }
    }
}
void push()
{
    int num;
    if (tos == max - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("\nEnter the number:");
        scanf("%d", &num);
        tos++;
        stack[tos] = num;
        printf("\nElement Pushed");
    }
}
int pop()
{
    int num;
    if (tos == -1)
    {
        return -1;
    }
    else
    {
        num = stack[tos];
        tos--;
        return num;
    }
}
int peek()
{
    int num;
    if (tos == -1)
    {
        return -1;
    }
    else
    {
        return stack[tos];
    }
}
void display()
{
    if (tos == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nStack Elements are\n");
        for (int i = 0; i <= tos; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}
int count()
{
    return (tos + 1);
}