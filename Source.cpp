#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char date[20];
char uname[20];
char bname[20];
char mno[15];
long int cost;
int n,i;

//function for writting entry of book into file;
void write(){
	FILE *fp;
	char dat[20];
	char unam[20];
	char bnam[20];
	char mn[15];
	long int cost;
	printf("\n Enter the date: ");
	scanf("%s",dat);
	printf("\n Enter the name of coustomer name: ");
	scanf("%s",unam);
	printf("\n Enter the mobile number: ");
	scanf("%s",mn);
	printf("\n Enter the Book name: ");
	scanf("%s",bnam);
	printf("\n Entr the cost of book: ");
	scanf("%ld",&cost);

	fp=fopen("record.txt","a");
	fprintf(fp,"\n%s %s %s %s %ld\n",dat,unam,mn,bnam,cost);
	printf("    \n Record written successfully!!!!");
	fclose(fp);
}
// function to search by date
void display(char da[])
{
	FILE *fp;
	int res=0;
	fp=fopen("record.txt","r");
	while (fscanf(fp,"\n%s %s %s %s %ld\n",date,uname,mno,bname,&cost)!=EOF)
	{
		res=strcmp(date,da);


		if (res==0)
		{
			printf("\n\n coustomer name=%s",uname);
			printf("\n Mobile NO=%s",mno);
			printf("\n Book Name=%s",bname);
			printf("\n Book Cost=%ld",cost);

		}

	}//close of while functon

	fclose(fp);
}//close of display functon
void main(){
	int ch;
	char lm[20];
	do
	{
		printf("\n\t***welcome to the Bookshop***\n");
		printf("\n press <1> to creat entry for book");
		printf("\n press <2> to display on specific date");
		printf("\n press <0> to exit");

		printf("\n\n Enter your choice:");
		scanf("%d",&ch);


		switch (ch)
		{
		case 1:write();
			break;
		case 2:printf("\n Enter the date: ");
			scanf("%s",&lm);
			display(lm);
			break;
		case 0:
			exit(0);
			break;
		default:

			printf("Invalid selecton");
			break;
		}

	} while (true);



}
