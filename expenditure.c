#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>

void menu();

void received_amt();
void expenditure();
void balance();
void monthly_bill();

typedef struct
{
    float amt;
    char date[10];
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
        printf(" 0.Exit\n 1.Received Amount\n 2.Expenditure\n 3.Balance\n 4.Monthly Expense\n Enter your Choice : ");
        scanf("%c",&choice);
        switch(choice)
        {
            case '0':
                exit(0);
                break;
            case '1':
                received_amt();
                break;
            case '2':
                expenditure();
                break;
            case '3':
                balance();
                break;
            case '4':
                monthly_bill();
                break;
            default:
                printf("Invalid choice!\nPress any key to continue");
                break;
        }
        getch();
    }
}

void received_amt()
{
    FILE *fl;
    system("cls");
    printf("*****Received Amount*****\n");
    printf("Enter new Record(Y/N): ");
    while(toupper(getche())=='Y')
    {
        system("cls");
        fl=fopen("received_amount.txt","ab");
        printf("Enter the Date:");
        scanf("%s",str.date);
        printf("Enter the received amount:");
        scanf("%f",&str.amt);
        fwrite(&str,sizeof(str),1, fl);
        fclose(fl);
        printf("Enter new Record(Y/N): ");
    }
    menu();
}

void expenditure()
{
    FILE *fl;
    system("cls");
    printf("*****Expenditure*****\n");
    printf("Enter new Record(Y/N): ");
    while(toupper(getche())=='Y')
    {
        system("cls");
        fl=fopen("expense.txt","ab");
        printf("Enter the Date:");
        scanf("%s",str.date);
        printf("Enter the amount:");
        scanf("%f",&str.amt);
        fwrite(&str,sizeof(str),1, fl);
        fclose(fl);
        printf("Enter new Record(Y/N): ");
    }
    menu();
}

void balance()
{
    system("cls");

    //Display for Received Amount
    float sum_received_amount=0;
    printf("*************BALANCE*************\n\n");
    printf("Date\t\t| Received Amount\n");
    printf("----------------|----------------\n");
    FILE *fl;
    fl=fopen("received_amount.txt","rb");
    rewind(fl);
    fflush(fl);
    while(fread(&str,sizeof(str),1,fl))
    {
        printf("%s\t",str.date);
        printf("|");
        printf(" %.3f\n",str.amt);
        sum_received_amount+=str.amt;
    }
    fclose(fl);

    //Display for expenditure
    float sum_expenditure=0;
    printf("\n\n\nDate\t\t| Expenditure\n");
    printf("----------------|----------------\n");
    fl=fopen("expense.txt","rb");
    rewind(fl);
    fflush(fl);
    while(fread(&str,sizeof(str),1,fl))
    {
        printf("%s\t",str.date);
        printf("|");
        printf(" %.3f\n",str.amt);
        sum_expenditure+=str.amt;
    }
    fclose(fl);

    //Display of total amount
    float bill;
    bill=sum_received_amount-sum_expenditure;
    printf("\n\nTotal Amount : %.3f",bill);
}

void monthly_bill()
{
    system("cls");

    int mon;
    int year;
    printf("Enter the month(1-12) : ");
    scanf("%d",&mon);
    printf("Enter the year : ");
    scanf("%d",&year);
    //Display of Monthly bill
    int a,i;
    a=strlen(str.date);
    for(i=0;i<=a;i++)
    {
        if(str.date[i]== '.' || str.date[i]== '/')
            {
                if(str.date[i+1]==mon || ((str.date[i+1]*10)+(str.date[i+2])==mon ))
                {
                    if(str.date[i+1]==year || ((str.date[i+1]*10)+(str.date[i+2])==year))
                    {
                        // Received Amount
                        float sum_received_amount=0;
                        FILE *fl;
                        fl=fopen("received_amount.txt","rb");
                        rewind(fl);
                        fflush(fl);
                        while(fread(&str,sizeof(str),1,fl))
                        {
                            printf("%s\t",str.date);
                            printf("|");
                            printf(" %.3f\n",str.amt);
                            sum_received_amount+=str.amt;
                        }
                        fclose(fl);

                        //Display for expenditure
                        float sum_expenditure=0;
                        printf("\n\n\nDate\t\t| Expenditure\n");
                        printf("----------------|----------------\n");
                        fl=fopen("expense.txt","rb");
                        rewind(fl);
                        fflush(fl);
                        while(fread(&str,sizeof(str),1,fl))
                        {
                            printf("%s\t",str.date);
                            printf("|");
                            printf(" %.3f\n",str.amt);
                            sum_expenditure+=str.amt;
                        }
                        fclose(fl);

                        //Display of total amount
                        float bill;
                        bill=sum_received_amount-sum_expenditure;
                        printf("\n\nTotal Amount : %.3f",bill);
                    }
                }
            }
    }
}
