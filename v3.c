#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct web
{
char name[30],pass[30];
char balance[30];
}w[99];
int n;
void login(void);
void reg(void);
void transact(int);
void withdraw(int);
void balance(int);
void deposit(void);
void clrscr(void);
int main()
{
clrscr();
printf("\n\n\n\n\n\t\t\t\tWELCOME TO MY WEBSITE");
printf("\n\t\t\t\t=====================");
printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
if(getch()==13)
//clrscr();
//XY:
//{
printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&n);
//}
switch(n)
  {
    case 1: clrscr();
        login();
        break;
    case 2:// clrscr();
        reg();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getch()==13)
       { clrscr();
         main();
      }
  }
  return 0;
}
void reg()
  {
    clrscr();
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("Web_reg.txt","a+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");

      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
  int i=0;
        while(!feof(fp))
        { 
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREADY EXISTS");
            printf("\n\n\tIf you want to login,Please press enter,to try registering again press any other key");
            if(getch()==13)
              login();
            //clrscr();
            else
            reg();
      i++;
            }
  }
        strcpy(w[i].name,checker);
          

      printf("\n\n\t\t\t\t ENTER PASSWORD: ");
      while((c=getch())!=13)
        {
          if(c==8)
          {
            printf("\b\b");
            fflush(stdin);
          }
          else
          {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
        //w[i].balance=0;
        }
        int in;
        printf("\n\t\t\tWould you like to deposit some amount into your account");
        printf("\n\t\t\tEnter 1 to deposit else the default balance will be 0\n\t\t\t");
        scanf("%d",&in);
        if(in==1)
        {
          printf("\n\t\t\tEnter the amount for initial deposit\n\t\t\t");
          scanf("%s",w[i].balance);
        }  
        else
        { 
        strcpy(w[i].balance,"0");
      }
      fwrite(&w[i],sizeof(w[i]),2,fp);
      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        clrscr();
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1: //clrscr();
                    login();
                    break;
              case 2: clrscr();
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING ON THE SYSTEM,HOPE TO SEE YOU SOON");
                    exit(0);
                    break;
          }
        
        
      }
    getch();
  }
  void login()
    {
      clrscr();
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("Web_reg.txt","rb");
      printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
      printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");

        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
  int i=0;
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass); 
        if(checku!=0)
          { i++;
     continue;}
            
          else if(checku==0&&checkp==0)
          {
            clrscr();
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
            printf("\n\n\n\t\t\t\tPress enter to start transacting");
            fclose(fp);
            if(getch()==13)
              transact(2i-1);
            else
            {
              clrscr();
              printf("\n\n\n\t\t\tYou have not chosen to transact,you session will be closed");
            break;
            }
          }
        else if(checku==0&&checkp!=0)
          {
            clrscr();
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
      
         }
  
      getch();
      fclose(fp);
    }
 void transact(int b)
 {
  clrscr();
  int tran;
  printf("\n\n\n\t\t\t\tYou have chosen to transact");
  printf("\n\n\n\t\t\t\tPlease chose your required transaction\n\n\n\t\t\t\tEnter\n\t\t\t\t1 for Withdrawal\n\t\t\t\t2 for balance query\n\t\t\t\t3 for Deposit");
  scanf("%d",&tran);
  if(tran==1)
    withdraw(b);
  if(tran==2)
    balance(b);
  if(tran==3)
  deposit();
  else
  {
    printf("\n\n\n\t\t\tYou have entered an invalid input,Please enter a valid input");
    transact(b);
  }
 }
 void withdraw(int x)
 {
  int wi;
  int i,j;
  char buf[20];
  FILE *fp;
       fp=fopen("Web_reg.txt","r");
       for(i=0;i<10;i++)
       {
       fread(&w[x+i],sizeof(w[x+i]),1,fp);
     }
       fclose(fp);
       fp=fopen("Web_reg.txt","w");
       printf("Your current balance is %s",w[x].balance);
       printf("Enter amount would like to withdraw\n");
       scanf("%d",&wi);
       int upbal=atoi(w[x].balance)-wi;
       //w[x].balance=upbal;
       itoa(upbal,buf,10);
       strcpy(w[x].balance,buf);
       //fwrite(&w[x+1],sizeof(w[x+1]),1,fp); 
       for(j=0;j<10;j++)
       {
       fprintf(fp,"%s",w[j]);
       balance(x);
       fclose(fp);
     }

 }
 void balance(int x)
 {
  FILE *fp;
  char red[300];
  fp=fopen("Web_reg.txt","rb");

       fgets(red,x*90,fp);
       printf("balance is");
  for (int i =(x-1)*90+30;i<x*90;i++)
  {printf("%c",red[i]);} 
       fclose(fp);
exit(0);

 }
 void deposit()
 {
 }
 void clrscr()
 {
  system("cls");
 }