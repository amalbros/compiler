#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Blank ' '
#define Tab '\t'
#define MAX 100
char expression[MAX], postfix_expr[MAX];
long int stack_postfix[MAX];
char stack_3ac[20];
char null_str[10] = "\0\0\0\0\0\0\0\0\0\0";
char new_exp[10];
int top;
void postfix_push(long int symbol)
{
if(top > MAX)
{
printf("Stack overflow\n");
exit(1);
}
else
{
top=top+1;
stack_postfix[top] = symbol;
}
}
 
long int postfix_pop()
{
if (top == -1 )
{
printf("Stack underflow \n");
exit(2);
}
else
return (stack_postfix[top--]);
}
 
int white_space(char symbol)
{
if( symbol == Blank || symbol == Tab || symbol == '\0')
return 1;
else
return 0;
}

int prec(char symbol )
{
switch(symbol)
{
case '(':
return 0;
case '+':
case '-':
return 1;
case '*':return 2;
case '/':
case '%':
return 3;
case '^':
return 4;
}
} 
 
void expression_to_postfix(char expression[])
{
top = 0;
int i,p=0,type,precedence,len;
char next ;
stack_postfix[top]='#';
len=strlen(expression);
expression[len]='#';
for(i=0; expression[i]!='#';i++)
{
if( !white_space(expression[i]))
{
switch(expression[i])
{
case '(':
postfix_push(expression[i]);
break;
 
case ')':
while((next = postfix_pop()) != '(')
postfix_expr[p++] = next;
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
precedence = prec(expression[i]);
while(stack_postfix[top]!='#' && precedence<= prec(stack_postfix[top]))
postfix_expr[p++] = postfix_pop();
postfix_push(expression[i]);
break;
default: 
postfix_expr[p++] = expression[i];
}
}
}
while(stack_postfix[top]!='#')
postfix_expr[p++] = postfix_pop();
postfix_expr[p] = '\0' ; 
}

   
int check_operator(char ch){
    switch(ch){
        case '+':
        case  '*':
        case '-':
        case '/': return 1;
    }

    return 0;

}
 void push(char ch){
      stack_3ac[top] = ch; 
      top++;
 }

 char pop(){
    
    return stack_3ac[--top];
     
 }
 void print_stack(){
     for(int i=0;i<top;i++){
         printf("%c",stack_3ac[i]);
     }
     printf("\n");
 }
 void Create_3AC(char postfix_expr[]){
    char temp_name = 'p';
    char tmp1,tmp2;
    top = 0;
    int temp_increment = 50; // 0 -> 48
    for(int i=2;i<strlen(postfix_expr);i++){
        if(check_operator(postfix_expr[i]) == 0){
           push(postfix_expr[i]);
        }
        else{
           new_exp[0] = temp_name;
           new_exp[1] = '=';
           tmp1 = pop();
           tmp2 = pop();
           new_exp[2] = tmp2;
           new_exp[3] = postfix_expr[i];
           new_exp[4] = tmp1;
           new_exp[5] = '\0';
           printf("%s\n",new_exp);
           push(temp_name);
           temp_name++;
        }
 
    }
    temp_name--;   
    strcpy(new_exp,null_str);
    new_exp[0]=postfix_expr[0];
    new_exp[1]='=';
    new_exp[2]=temp_name;
    new_exp[3]='\0';
    printf("%s\n",new_exp);
 }
 
void main()
{
long int value;
printf("Enter Expression : ");
scanf("%s",expression);
expression_to_postfix(expression);
printf("PostFix Expression : %s\n",postfix_expr);
Create_3AC(postfix_expr);
}
 

