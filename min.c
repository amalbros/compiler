
#include<stdio.h>

	

int main()
{
	int no_of_states, no_alphabets, no_final;	
	printf("Enter no. of  states :");scanf("%d", &no_of_states);
	printf("Enter no. of alphabets:");scanf(" %d", &no_alphabets);
	printf("Enter no.of final states :");scanf(" %d", &no_final);

	int final_states[no_final];
	for(int k=0;k<no_final;k++)
	{	printf("Enter final state:");scanf(" %d", &final_states[k]);}

	int trans_table[no_of_states][no_alphabets];
	int check_table[no_of_states][no_of_states];
	
	for(int i=0;i<no_of_states;i++)
	for(int j=0;j<no_of_states;j++)
	{	
		if(j<i){	check_table[i][j]=0;}	//unmarked
		if(j>=i){	check_table[i][j]=-1;}	//invalid
	}
	

	for(int i=0;i<no_of_states;i++)
	for(int j=0;j<no_alphabets;j++)
	{	printf("transition: %d (%d) next state: ",i,j );
		scanf("%d",&trans_table[i][j]);
	}

	for(int i=0;i<no_of_states;i++)
	{
		for(int j=0;j<no_of_states;j++)
		{	printf("%d ",check_table[i][j]);}
		printf("\n");
	}

	for(int i=0;i<no_of_states;i++)
	{
		for(int j=0;j<no_alphabets;j++)
		{	printf("%d ",trans_table[i][j]);}
		printf("\n");
	}
			
	for(int i=0;i<no_of_states;i++)
	for(int j=0;j<no_of_states;j++)
	{	if(check_table[i][j]==-1)
			continue;
		int i_final=0, j_final=0;
		for(int k=0;k<no_final;k++)
		{	if(final_states[k]==i){	i_final=1;}
			if(final_states[k]==j){	j_final=1;}
		}
		if((i_final==1 && j_final==0) || (i_final==0 && j_final==1))
		{	check_table[i][j]=-1;}	//marked
	}

	int no_markings_flag=0;
	while(no_markings_flag==0)
	{	no_markings_flag=1;
		for(int i=0;i<no_of_states;i++)
		for(int j=0;j<no_of_states;j++)
		{	if(check_table[i][j]==-1)
				continue;
			for(int k=0;k<no_alphabets;k++)
			{
				if(check_table[ trans_table[i][k] ][ trans_table[j][k] ] == 1)
				{	check_table[i][j]=1;no_markings_flag==0;}
			}
		}
	}
	printf("\nFinal matrix\n");
	for(int i=0;i<no_of_states;i++)
	{
		for(int j=0;j<no_of_states;j++)
		{	printf("%d ",check_table[i][j]);}
		printf("\n");
	}		


	int minimised_states[10][10] = {{-1}}, a=0,b=0;
	for(int i=0;i<no_of_states;i++)
	{
		for(int j=0;j<no_of_states;j++)
		{	if(check_table[i][j]==-1)
				continue;
			if(check_table[i][j]==0)
			{	
				minimised_states[a][0]=i;//union funtionsdafahfakjflqeyt
				minimised_states[a][1]=j;
			}
		}
		a++;
	}
		
		
	for(int i=0;i<10;i++){
	for(int j=0;j<10;j++)
	{	printf(" %d ", minimised_states[i][j]);}
	printf("\n");
	}


		
	
	
	return 0;
}
