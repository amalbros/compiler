#include<stdio.h>
#include<string.h>
char expressions[10][10];
int n_exp;
void func(){
    for(int i=0;i<n_exp;i++){
        if(strlen(expressions[i]) == 3){
            printf("mov ax,[address_%c]\n",expressions[i][2]);
            printf("mov [address_%c],ax\n",expressions[i][0]);
            break;
        }
        
        printf("mov ax,[address_%c]\n",expressions[i][2]);
        if( expressions[i][3] == '+'){
                printf("add ax,[address_%c]\n",expressions[i][4]);
                }
        else if( expressions[i][3] == '-'){
                printf("sub ax,[address_%c]\n",expressions[i][4]);
        }
        else if( expressions[i][3] == '*' ){
                printf("mov bx,[address_%c]\n",expressions[i][4]);
                printf("mul bx\n");
        }

        else if( expressions[i][3] == '/' ){
                printf("mov bx,[address_%c]\n",expressions[i][4]);
                printf("div bx\n");
        }

        printf("mov [address_%c],ax\n\n",expressions[i][0]);


    }
}
void main(){
    printf("Enter no of expressions:-\n");
    scanf("%d",&n_exp);

    printf("Enter  expressions:-\n");
    for(int i=0;i<n_exp;i++){
        scanf("%s",expressions[i]);
    }

    func();

    printf("\n");




}
