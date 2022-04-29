#include<stdio.h>
#include<conio.h>
struct library
{
int bno;
char bname[50];
char bath[20] ;
int bedit;
}lb;
FILE *p,*t;
void add();
void disp();
void edit();
void del();

void main()
{
int x;
do
{
clrscr();
printf("\n..............LIBRARY MANAGEMENT SYSTEM.............\n\n\n");
printf("\n\n1.Add a Book to the Stock.");
printf("\n\n2.Display Books available.");
printf("\n\n3.Edit or Update details of Book.");
printf("\n\n4.Delete a book from the stock.");
printf("\n\n5.Exit from Database.");
printf("\n\n\nEnter option,What you wanna do:");
scanf("%d",&x);
switch(x)
{
case 1:
add();
break;

case 2:
disp();
break;

case 3:
edit();
break;

case 4:
del();
break;

case 5:
printf("\n\t\t\tExiting from application.....Bye");
break;

default:
printf("\n\t\tWrong choice...");
break;
}
getch();
}
while(x!=5);
}

void add()
{
clrscr();
p = fopen("lib.bin","a");
printf("\nAdding new data");
printf("\nEnter No.:");
scanf("%d",&lb.bno);
fflush(stdin);
printf("\nEnter Name of BOOK:");
gets(lb.bname);
printf("\nEnter Name of Author:");
scanf("%s",&lb.bath);
printf("\nEnter Edition of BOOK:");
scanf("%d",&lb.bedit);
fwrite(&lb,sizeof(lb),1,p);
printf("\n\t\tRecord added to file...");
fclose(p);
}


void disp()
{
clrscr();
printf("\n\tDisplaying data\n");
p = fopen("lib.bin","r");
printf("\nBook NO.\t\t   Name\t\t      Author\t\tEdition\n");
while(fread(&lb,sizeof(lb),1,p))
{
printf("\n%d\t\t   %s\t\t   \t%s\t\t%d",lb.bno,lb.bname,lb.bath,lb.bedit);
}
fclose(p);
}


void edit()
{
int no,y;
clrscr();
printf("Enter the number of the book you want to update =");
scanf("%d",&no);
p=fopen("lib.bin","r");
if (p==NULL)
{
printf("\n Can not open file or file does not exist.");
exit(0);
}
t=fopen("empty.bin","w");
while (fread(&lb,sizeof(lb),1,p))
if(no!=lb.bno)
{
fwrite(&lb,sizeof(lb),1,t);
}
else
{
printf("\nWhat editions you want to make? =");
printf("\n1.Book Name");
printf("\n2.Author Name");
printf("\n3.Edition");
printf("\n4.All details.");
printf("\nEnter your option= ");
scanf("%d",&y);
switch(y)
{
case 1:
printf("Enter Updated name=");
scanf("%s",&lb.bname);
fwrite(&lb,sizeof(lb),1,t);
printf("Data update successfully");
break;

case 2:
printf("Enter Updated Author Name.=");
scanf("%s",&lb.bath);
fwrite(&lb,sizeof(lb),1,t);
printf("Data update successfully");
break;

case 3:
printf("Enter Updated Edition=");
scanf("%d",&lb.bedit);
fwrite(&lb,sizeof(lb),1,t);
printf("Data update successfully");
break;

case 4:
printf("Enter Updated Name=");
scanf("%s",&lb.bname);
printf("Enter Updated Author Name=");
scanf("%s",&lb.bath);
printf("Enter Updated Edition=");
scanf("%d",&lb.bedit);
fwrite(&lb,sizeof(lb),1,t);
printf("Data update successfully");
break;

default:
printf("Wrong Option.....");
break;
}
}
fclose(p);
fclose(t);
remove("lib.bin");
rename("empty.bin","lib.bin");
}


 void del()
{
int no;
clrscr();
printf("Enter the number of the book you want to delete =");
scanf("%d",&no);
p=fopen("lib.bin","r");
if (p==NULL)
{
printf("\n Can not open file or file does not exist.");
exit(0);
}
t=fopen("empty.bin","w");
while (fread(&lb,sizeof(lb),1,p))
if(no!=lb.bno)
{
fwrite(&lb,sizeof(lb),1,t);
}
fclose(p);
fclose(t);
remove("lib.bin");
rename("empty.bin","lib.bin");
printf("Record of student deleted successfully");
}

