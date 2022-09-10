#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The function below is what takes the character that has been inputed as the command and changes it into an intiger that the program will understand as the command to be used.

int value (char *string1)
	{
	int x = 2;
	char string2 [10];
	while(string2[x] != '\0')
		{
		string2[x-2] = string1[x];
		x = x + 1;
	    }
	string2[x-2]='\0';
	return(atoi(string2));
	}

int main(int argc, char *argv[])
{

//declaration of variables//
FILE *fptr;

char promt [15];
char ch;
int count=0, i;
int ltd=25;	
int tab=8;
int startat=-1;
int endat=32767;
	
if(argc == 1)
{
printf("No filename entered \n");
exit(0);
}
	
//Opening the file for reading//
fptr = fopen (argv[argc-1], "r");
if (fptr==NULL)

{
//exit the program when file is not found
printf("Cannot open file\n");
exit(0);
}
//this is the statement that will identify the arguements that are being used
	 for(i=1;i<(argc-i);i++)
		{
		//this code is what will identify the 'n' argument
		 if(argv[i][1]=='l')
				{
				//this is what grabs the number value from the argument and changes the lines that are displayed
				 ltd=value(argv[i]);
			    }
			//This is what determines the character that should be used for the Tab command
		if(argv[i][1]=='t')
			{
				tab=value(argv[i]);
			}
			//This is used to allow the user to choose how many lines should be skipped before the program starts to display the file on screen.
		if(argv[i][1]=='b')
			{
				startat=value(argv[i]);
			}
		if(argv[i][1]=='h')
			{
			printf("welcome to the More program, created by Harry Caldwell!/n");
			printf("Commands:/n -t: This command allows you add extra tabs to the text./n -n:");
			}
		if(argv[i][1]=='e')
			{
				endat=value(argv[i]);
			}
		}	
//main loop that reads the file until the end of file (EOF) Marker
ch = fgetc (fptr);
while (ch !=EOF)

{
if (ch == 10) 
		{
		//This module is for counting the number of lines that has been displayed on the screen
		count = count+1;
			//This function counts the lines that have been counted by the program, and is changed by the ltd variable that can be changed by the user when inputing a command.
		if (count%ltd == 0 && count!=0 && count > startat )
			{
			printf ("\n-more-");
			promt[0]=getc(stdin);
			}
		}
		//This module is used to add tabs to the text that is being displayed by the program.
		if (count > startat)
		{
		if (ch != '\t')
			{
	  		printf("%c",ch);
    		}
		else
			{
			for(i=0;i<tab;i++)
				{
			    printf(" ");
				}
			}
         } 
		ch = fgetc (fptr);  
}
	
//close the file after the end of file//
fclose (fptr);
printf("\nNumber of lines : %d \n" , count);
return 0;
}