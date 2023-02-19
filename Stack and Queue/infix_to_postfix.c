#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    if (SIZE - top > 1)
    {
        stack[++top] = ch;
    }
    else
    {
        printf("\nStack Overflow\n");
        exit(1);
    }
}

char pop()
{
    char ch;

    if (top < 0)
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        ch = stack[top--];
        return ch;
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char ch;
    char temp;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    ch = infix_exp[i];
    while (ch != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isdigit(ch) || isalpha(ch))
        {
            postfix_exp[j] = ch;
            j++;
        }
        else if (is_operator(ch) == 1)
        {
            temp = pop();
            while (is_operator(temp) == 1 && precedence(temp) >= precedence(ch))
            {
                postfix_exp[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(ch);
        }
        else if (ch == ')')
        {
            temp = pop();
            while (temp != '(')
            {
                postfix_exp[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;

        ch = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
    }
    postfix_exp[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix);
    printf("Postfix Expression: [ %s ]\n", postfix);

    return 0;
}