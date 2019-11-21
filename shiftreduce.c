#include<stdio.h>
#include<string.h>
int z = 0, i = 0, j = 0, c = 0;  
char a[16], ac[20], stk[15], act[10];
void sr() 
{ 
	strcpy(ac,"Reduce to"); 
	for(z = 0; z < c; z++) 
	{ 
		if(stk[z] == 'i') 
		{ 
			printf("%sE->i", ac); 
			stk[z] = 'E'; 
			stk[z + 1] = '\0'; 
			printf("\n$%s\t%s$\t", stk, a); 
		} 
		if(stk[z] == '('&& stk[z + 1] == 'E' && stk[z + 2] == ')')
		{ 
		    
			printf("%sE->(E)", ac); 
			stk[z] = 'E'; 
			stk[z + 1] = '\0'; 
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a); 
			i = i - 2; 
		} 	
	} 	
	for(z=0; z<c; z++) 
	{ 
		
		if(stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') 
		{ 
			printf("%sE->E*E", ac); 
			stk[z]='E'; 
			stk[z + 1]='\0'; 
			stk[z + 1]='\0'; 
			printf("\n$%s\t%s$\t", stk, a); 
			i = i - 2; 
		} 
		
		
	} 
	for(z = 0; z < c; z++) 
	{ 
		 
		if(stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') 
		{ 
			printf("%sE->E+E", ac); 
			stk[z] = 'E'; 
			stk[z + 1] = '\0'; 
			stk[z + 2] = '\0'; 
			printf("\n$%s\t%s$\t", stk, a); 
			i = i - 2; 
		} 
		
	} 
	return ;
} 
int main() 
{ 
	printf("\nE->E+E\n E->E*E \nE->(E)/id\n");	 
	printf("\nEnter input\n");
	gets(a); 
	c=strlen(a); 
	strcpy(act,"shift"); 
	printf("\nSTACK \t INPUT STRING \t ACTION"); 
	printf("\n$\t%s$\t", a);
	for(i = 0; j < c; i++, j++) 
	{  
		printf("%s", act); 
		stk[i] = a[j];	 
		stk[i + 1] = '\0'; 
		a[j]=' '; 
		printf("\n$%s\t%s$\t", stk, a); 
		sr(); 
	} 
	sr(); 
	if(stk[0] == 'E' && stk[1] == '\0') 
		printf("accept\n"); 
	else  
		printf("reject\n"); 
}

