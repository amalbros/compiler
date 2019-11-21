//operator precendence parsing

#include<stdio.h>
#include<ctype.h>
#include<string.h>
char productions[100][100]={{'E','.','E','+','T','\0'},{'E','.','T','\0'},{'T','.','T','*','F','\0'},{'T','.','F','\0'},{'F','.','i','\0'},{'F','.','(','E',')','\0'}};
int no_of_prod=6;
char leading_e[10]={'+','*','i','(','\0'};
char leading_t[10]={'*','i','(','\0'};
char leading_f[10]={'i','(','\0'};

char trailing_e[10]={'+','*','i',')','\0'};
char trailing_f[10]={'i',')','\0'};
char trailing_t[10]={'*','i',')','\0'};


char leading_list[10][10]={{'+','*','i','(','\0'},{'i','(','\0'},{'*','i','(','\0'}};
char table[6][6];
char trailing_list[10][10]={{'+','*','i',')','\0'},{'i',')','\0'},{'*','i',')','\0'}};

int get_term_pos(char x)
{
    if(x=='+')
        return 0;
    if(x=='*')
        return 1;
    if(x=='i')
        return 2;
    if(x=='(')
        return 3;
    if(x==')')
        return 4;
    if(x=='$')
        return 5;
}

int get_non_term(char x)
{
    if(x=='E')
        return 0;
    if(x=='F')
        return 1;
    if(x=='T')
        return 2;   
}

void make_parsing_table()
{
    for(int i=0;i<no_of_prod;i++)
    {   //for each production
        for(int j=2;j<strlen(productions[i])-1;j++)
        {
            if(!isupper( productions[i][j] ) && !isupper( productions[i][j+1] ) )   //both are terminals
            {
                table[ get_term_pos(productions[i][j]) ][ get_term_pos(productions[i][j+1]) ] = '=';
            }
            if(j<strlen(productions[i])-2 && !isupper(productions[i][j]) && !isupper(productions[i][j+2])&& isupper(productions[i][j+1]) )  // non-terminal b/w 2 terminals
            {
                    table[ get_term_pos(productions[i][j]) ][ get_term_pos(productions[i][j+2]) ] = '=';
            }
            if(!isupper(productions[i][j]) &&  isupper(productions[i][j+1]))    // term-nonterm
            {
                for(int k=0;k<strlen(leading_list[get_non_term(productions[i][j+1])]);k++)
                {
                    table[ get_term_pos(productions[i][j]) ][ get_term_pos(leading_list[ get_non_term(productions[i][j+1]) ][k]) ] = '<';
                }
            }
            if(isupper(productions[i][j]) && !isupper(productions[i][j+1])) //nonterm-term
            {
                for(int k=0;k<strlen(trailing_list[get_non_term(productions[i][j])]);k++)
                {
                    table[ get_term_pos(trailing_list[get_non_term(productions[i][j])][k]) ] [ get_term_pos(productions[i][j+1]) ] = '>';
                }
            }
        }
    }
    for(int k=0;k<strlen(leading_list[0]);k++)  //handling $
    {
        table[get_term_pos('$')][get_term_pos(leading_list[0][k])]='<';
        table[get_term_pos(trailing_list[0][k])][get_term_pos('$')]='>';
    }
    
}

char row[10]={'+','*','i','(',')','$'};

int main()
{
    make_parsing_table();
    printf("\t%c\t%c\t%c\t%c\t%c\t%c\n",'+','*','i','(',')','$');
    for(int i=0;i<6;i++)
    {
        printf("%c\t", row[i]);
        for(int j=0;j<6;j++)
        {
            printf("%c\t",table[i][j]);
        }
        printf("\n");
    }
    char input_string[100];
    char mod_input_string[100];
    printf("Enter input string: ");scanf("%s", input_string);
    mod_input_string[0] = '$';
    for(int i=0,t=1;i<strlen(input_string)-1;)
    {   mod_input_string[t] = input_string[i];  t+=2;i++;
        mod_input_string[t] = input_string[i];  
        mod_input_string[t-1] = table[ get_term_pos(input_string[i-1]) ][ get_term_pos(input_string[i]) ];
        i++;
    }
    printf("%s", mod_input_string);
    
    
    return 0;
}