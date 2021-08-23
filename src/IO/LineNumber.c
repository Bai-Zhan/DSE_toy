#include<stdio.h>
#include<stdlib.h>

int line_number(char *name)
{
	FILE*input_hadron=fopen(name,"r");
	if(input_hadron==NULL)
	{
		printf("no such file %s\n",name);
		return -1;
	}
	char c;
	int num_hadron=0;
	c=fgetc(input_hadron);
	while(c!=EOF)
	{
		if(c=='\n')num_hadron++;  //calculate line number of the file
		c=fgetc(input_hadron);
	}
	fclose(input_hadron);
	return num_hadron;
}
	








