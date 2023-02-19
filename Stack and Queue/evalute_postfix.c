#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{

    if (MAX - top > 1)
    {
        stack[++top] = val;
    }
    else
    {
        printf("\nStack Overflow\n");
        exit(1);
    }
}

int pop()
{
    int val;
    if (top < 0)
    {
        printf("stack under flow");
    }
    else
    {
        val = stack[top--];
        return val;
    }
}

int EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            A = pop();
            B = pop();
            switch (ch)
            {
            case '^':
                val = pow(B, A);
                break;
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            push(val);
        }
    }
    int ans = pop();
    return ans;
}

int main()
{
    char postfix[MAX];
    printf("\nEnter Postfix expression : ");
    gets(postfix);
    int res = EvalPostfix(postfix);
    printf("After Evaluation of postfix = %d\n", res);
}