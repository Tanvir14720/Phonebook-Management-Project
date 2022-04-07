#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void insert_record();
void display_record();
void search_record();
void update_record();
void del_record();

struct node
{
    int serial;
    char name[100];
    char father_name[100];
    char mother_name[100];
    int number;
};
struct node s;
void main()
{
    int n;
    system("cls");
    while(n!=8)
    {
        system("cls");

        printf("\t****************************************************\n");
        printf("\t\tWELCOME TO PHONE BOOK\n");
        printf("\t******************************************************\n\n\n");

        printf("\t***AVAILABLE FUNCTION LISTIES*****\n");
        printf("\t\t1:insert student record\n");
        printf("\t\t2:display student record\n");
        printf("\t\t3:search student record\n");
        printf("\t\t4.delete student record\n");
        printf("\t\t5.update student record\n");
        printf("\t\t6.Submitby\n");
        printf("\t\t7:Submitto\n");
        printf("\t\t8:exit\n\n");

        printf("\t\tEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            insert_record();
            break;
        case 2:
            system("cls");
            display_record();
            break;
        case 3:
            search_record();

            break;
        case 4:
            system("cls");
            del_record();
            break;
        case 5:
            system("cls");
            update_record();
            break;
        case 6:
            system("cls");
            submittedBy();
            break;
        case 7:
            system("cls");
            submittedTo();
            break;
        case 8:
            system("cls");
            exit(1);
            break;

        default:
            printf("\n\tWrong choice Entered");

        }
        printf("\n\tPress any key: ");
        getch();

    }

}
void insert_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("project.txt","ab+");
    if(fp==NULL)
    {
        printf("\n\nError:Cannot Open the file!!!");
        return;
    }
    printf("\t***previous stored data*****");
    display_record();
    printf("\t*****Enter New Student Data***\n\n");
    printf("\n\tEnter the serial : ");
    scanf("%d",&s.serial);
    fflush(stdin);
    printf("\n\tEnter your name : ");
    gets(s.name);
    printf("\n\tEnter your father name : ");
    gets(s.father_name);
    printf("\n\tEnter your mother name : ");
    gets(s.mother_name);
    printf("\n\tEnter your phone number : ");
    scanf("%d",&s.number);
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\n\tRecord inserted sucessfully\n");
    }
    fclose(fp);
    printf("\n\t\tUpdate record \n");

}
void display_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("project.txt","rb");

    if(fp==NULL)
    {
        printf("\n\tError : cannot open the file\n");
        return;
    }
    printf("\n\n\t ***phone book details********\n ");
    printf("\ID number:\tName:\tFather name:\tMother name:\tphone number:\n");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("\t%d \t%s \t\t%s \t\t%s \t%d\n",s.serial,s.name,s.father_name,s.mother_name,s.number);
    }
    fclose(fp);
}
void search_record()
{
    system("cls");
    int n,flag =0;
    FILE *fp;

    fp = fopen("project.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: cant open the file");
        return;
    }
    printf("\n\tEnter your search number: ");
    scanf("%d",&n);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.number==n)
        {
            flag=1;
            printf("\n\n\tSucessfull and details\n\n");
            printf("\nserial number\tName\tFather name\tMother name\tphone number\n");
            printf("\t%d \t%s \t\t%s \t\t%s \t%d\n",s.serial,s.name,s.father_name,s.mother_name,s.number);
        }
    }
    if(flag==0)
    {
        printf("\n\tNo such record\n");
    }
    fclose(fp);
}
void del_record()
{
    system("cls");
    char name[100];
    unsigned flag = 0;
    FILE *fp,*ft;
    fp = fopen("project.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: cant open the file");
        return;
    }
    printf("\n\t***previous stored data***");
    display_record();
    printf("\n\tEnter your name which you want to delete :");
    scanf("%s",name);
    ft = fopen("project1.txt","ab+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmp(name,s.name)!=0)
        {
            printf("\n\n\tRecord deleted Sucessfully\n");
            fwrite(&s,sizeof(s),1,ft);

        }
        else
            flag = 1;
    }
    if(flag==0)
    {
        printf("\n\nNo such record found\n");
    }
    fclose(fp);
    fclose(ft);
    remove("project.txt");
    rename("project1.txt","project.txt");
    printf("\n\t\nUpdated recored \n");
    display_record();

}
void update_record()
{
    system("cls");
    int number,flag = 0;
    FILE *fp;
    fp = fopen("project.txt","rb+");
    if(fp==NULL)
    {

    }
    printf("\n\tEnter the number which you want update record\n ");
    scanf("%d",&number);
    printf("\n\t\t***previously stored record of given number****\n");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.number==number)
        {
            flag = 1;
            printf("\nserial number\tName\tFather name\tMother name\tphone number\n");
            printf("\t%d \t%s \t\t%s \t\t%s \t%d\n",s.serial,s.name,s.father_name,s.mother_name,s.number);
            printf("\n\t***Now Enter the New record***\n");
            printf("\n\tEnter the updated serial : ");
            scanf("%d",&s.serial);
            fflush(stdin);
            printf("\n\tEnter updated  your name : ");
            gets(s.name);
            printf("\n\tEnter updated your father name : ");
            gets(s.father_name);
            printf("\n\tEnter updated your mother name : ");
            gets(s.mother_name);
            printf("\n\tEnter updated your phone number : ");
            scanf("%d",&s.number);
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            printf("\n\tUpdate successfully check the display\n");

        }
    }
    fclose(fp);
    if(flag==0)

        printf("\n\tError : something went wrong");

    fclose(fp);
}
void submittedBy()
{
    system("cls");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =          Name                        ID             =");
    printf("\n\t\t\t        =*****************************************************=");
    printf("\n\t\t\t        =    1. Md. Sujon                  Id: 212-15-14720   =");
    printf("\n\t\t\t        =    2. Md. Mashrur Tanvir Nasif   ID: 212-15-14720   =");
    printf("\n\t\t\t        =    3. Md. Istiyak Hossain Khan   ID: 212-15-14709   =");
    printf("\n\t\t\t        =    4. Zubayer Al Kadir           ID: 212-15-14730   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}
void submittedTo()
{

    system("cls");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =      Moushumi Zaman Bonny         =");
    printf("\n\t\t\t        =***********************************=");
    printf("\n\t\t\t        =      Associate Professor          =");
    printf("\n\t\t\t        =         Dept. of CSE              =");
    printf("\n\t\t\t        = Daffodil International University =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

}

