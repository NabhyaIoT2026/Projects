#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>

void menu();

void details();
void issued();
void rent();

typedef struct
{
    char date[10];
    char name[10];
}rec_amt;
rec_amt str;

void main()
{
    menu();
}

void menu()
{
    while(1)
    {   char choice;
        system("cls");
        printf(" 0.Exit\n 1.Details\n 2.To Check issued or not\n 3.Total RENT \n Enter your Choice : ");
        scanf("%c",&choice);
        switch(choice)
        {
            case '0':
                exit(0);
                break;
            case '1':
                details();
                break;
            case '2':
                issued();
                break;
            case '3':
                rent();
                break;
            default:
                printf("Invalid choice!\nPress any key to continue");
                break;
        }
        getch();
    }
}

void details()
{
    FILE *fl;
    system("cls");
    printf("*****DETAILS*****\n");
    printf("Enter new Record(Y/N): ");
    while(toupper(getche())=='Y')
    {
        system("cls");
        fl=fopen("details.txt","ab");
        printf("Enter Name of book:");
        scanf("%s",str.name);
        printf("Enter the Date:");
        scanf("%s",str.date);
        fwrite(&str,sizeof(str),1, fl);
        fclose(fl);
        printf("Enter new Record(Y/N): ");
    }
    menu();
}

void issued()
{
    system("cls");
    int i,a,flag=0;
    char b[10];
    a=strlen(b);
    printf("*****Checking*****\n");
    printf("Enter the name of the book:");
    scanf("%s",b);
    for(i=0;i<a;i++)
    {
        if(strcmp(b,str.name))
        {
            flag++;
        }
    }
    if(flag==0)
        printf("ISSUED");
    else
        printf("NOT ISSUED");
}

void rent()
{
    system("cls");
    float amt=0;
    int a,i;
    printf("RENT PER DAY IS RS 10:\n");
    printf("The Book is %s rented on %s\n",str.name,str.date);
    printf("Enter the number of days the book rented:");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        amt+=10;
    }
    printf("Total Rent is %f.",amt);
}
