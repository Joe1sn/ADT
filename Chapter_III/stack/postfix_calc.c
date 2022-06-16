#include "stack.h"
#include <ADT/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max_item 20
#define postfix_size 200

//redefine date type
// typedef double element_type;

//filter the character but `0~9 +-*/.^`
status is_legal(char *postfix)
{
    for (int i = 0; i < strlen(postfix); i++)
    {
        char c = postfix[i];
        if( !((c>='0'&&c<='9') || c=='.' || c=='+' || c=='-'|| 
                         c=='*'|| c=='/'|| c=='^'))
            return ERROR;
        return OK;
    }
}

//`cur_pos`: get the current element then plus one.
//abnormal return -1, is number return 0, is operator return 1
status get_item(char *postfix, int *cur_pos, char *item)
{
    int i = 0, k=*cur_pos;
    status flag;
    if(postfix[k]=='.') //the first number can not be .
        flag = ABNORMAL;
    else if(postfix[k]>='0' && postfix[k]<='9') //curren is number, next must be operator or number
    {
        while ( (postfix[k]>='0' && postfix[k]<='9') || postfix[k]=='.')
            item[i++] = postfix[k++];
        item[i] = '\0';
        flag = ISNUM;
    }
    else    //is operator
    {
        item[0] = postfix[k++];
        item[1] = '\0';
        flag = ISOP;
    }
    while(postfix[k]==' ')//get the basic element
        k++;
    *cur_pos = k;
    return flag;
}

void do_calc(stack *s, char op)
{
    double rvalue,lvalue;
    if(!top(s,&rvalue)) //pop right value
        exit(0);

    pop(s);

    if(!top(s,&lvalue)) //pop left value
        exit(0);
    pop(s);
    switch (op)
    {
    case '+':
        push(s,lvalue+rvalue);
        break;
    case '-':
        push(s,lvalue-rvalue);
        break;
    case '*':
        push(s,lvalue*rvalue);
        break;
    case '/':
        if(fabs(rvalue)==0){
            printf("can't divid 0\n");
            exit(0);
        }
        push(s,lvalue/rvalue);
        break;
    case '^':
        push(s,pow(lvalue,rvalue));
        break;
    default:
        break;
    }
    
}

element_type calculating(char *postfix)
{
    stack *s = (stack *)malloc(sizeof(stack));
    char item[max_item];    //store operator
    element_type data;
    status flag = ABNORMAL;
    int cur_pos = 0;

    while (postfix[cur_pos]==' ')   //filter space
        cur_pos++;

    create(s,max_item); //creating stack
    while (cur_pos < strlen(postfix)) //start scanning
    {
        flag = get_item(postfix, &cur_pos, item);
        if(flag == ABNORMAL)
        {
            printf("abnormal: invalid element!\n");
            exit(0);
        }
        else if (flag == ISOP)
        {
            switch (item[0])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                do_calc(s,item[0]);
                break;
            }
        }
        else //is number
        {
            data = atof(item);//return string to float
            push(s,data);
        }   
    }
    if(s->top == 0) //only got one element in stack
        top(s, &data);
    else{
        printf("abnoraml: have redundant operator!");
        exit(0);
    }
    destroy(s);
    return data;
}

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