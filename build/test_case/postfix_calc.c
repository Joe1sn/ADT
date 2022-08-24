#include <stdio.h>
#include <ADT/stack.h>
int main()
{
    char postfix[postfix_size];
    printf("please input the postfix expression:\n");
    gets(postfix);
    if(!is_legal(postfix))
    {
        printf("abnormal: have invalid character in postfix\n");
        return ERROR;
    }
    //two decimal places
    printf("%s = %.2f\n",postfix,calculating(postfix));
    return 0;
}