
#include <stdio.h>

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

void pop()
{
    if(top != -1)
    {
        top--;
    }
}

int main()
{
    char expression[100];
    int balanced = 1;

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    for(int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if(ch == '(')
        {
            if(top == 49)
            {
                balanced = 0;
                break;
            }

            push(ch);
        }
        else if(ch == ')')
        {
            if(top == -1)
            {
                balanced = 0;
                break;
            }
            else
            {
                pop();
            }
        }
    }

    if(balanced == 1 && top == -1)
    {
        printf("The parentheses are balanced\n");
    }
    else
    {
        printf("The parentheses are not balanced\n");
    }

    return 0;
}
