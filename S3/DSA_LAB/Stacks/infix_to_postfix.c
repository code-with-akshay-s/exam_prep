
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[50], postfix[50];
    char stack[50];
    int evalStack[50];

    int i, j = 0, top = -1;

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Infix to postfix conversion
    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(isspace(ch))
            continue;

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            stack[++top] = ch;
        }
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }

            if(top != -1)
                top--;
        }
        else if(ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '^')
        {
            while(top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(ch) ||
                  (precedence(stack[top]) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    while(top != -1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    // Postfix evaluation
    int evalTop = -1;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if(isdigit(ch))
        {
            evalStack[++evalTop] = ch - '0';
        }
        else
        {
            int b = evalStack[evalTop--];
            int a = evalStack[evalTop--];
            int result = 0;

            switch(ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if(b == 0)
                    {
                        printf("Division by zero is not allowed\n");
                        return 1;
                    }
                    result = a / b;
                    break;

                case '^':
                    result = (int)pow(a, b);
                    break;
            }

            evalStack[++evalTop] = result;
        }
    }

    if(evalTop == 0)
    {
        printf("Final evaluated result: %d\n", evalStack[evalTop]);
    }
    else
    {
        printf("Invalid expression\n");
    }

    return 0;
}