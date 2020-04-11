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
void deposit(int);
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
              transact(i);
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
  deposit(b);
  else
  {
    printf("\n\n\n\t\t\tYou have entered an invalid input,Please enter a valid input");
    transact(b);
  }
 }
 void withdraw(int x)
 {
  int wi;
  char buf[20];
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");

       fread(&w[x+1],sizeof(w[x+1]),1,fp);
       printf("Your current balance is %s",w[x].balance);
       fclose(fp);
       printf("Enter amount would like to withdraw\n");
       scanf("%d",&wi);
       int upbal=atoi(w[x].balance)-wi;
       //w[x].balance=upbal;
       itoa(upbal,buf,10);
       strcpy(w[x].balance,buf);
       fp=fopen("Web_reg.txt","w");
       fwrite(&w,sizeof(w),1,fp);
       fclose(fp);
       balance(x);
       

 }
 void balance(int x)
 {
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");

       fread(&w[x+1],sizeof(w[x+1]),1,fp);
       printf("balance is %s",w[x].balance);
       fclose(fp);
exit(0);

 }
 void deposit(int r)
 {
  int wi2;
  char buf1[20];
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");

       fread(&w[r+1],sizeof(w[r+1]),1,fp);
       printf("Your current balance is %s",w[r].balance);
       printf("Enter amount would like to deposit\n");
       scanf("%d",&wi2);
       fclose(fp);
       int upbal=atoi(w[r].balance)+wi2;
       //w[x].balance=upbal;
       itoa(upbal,buf1,10);
       strcpy(w[r].balance,buf1);
       fp=fopen("Web_reg.txt","w");
       fwrite(&w,sizeof(w),1,fp);
       fclose(fp);
       printf("Deposit is successful\n");
       balance(r);
 }
 void pwchange(int i)
 {
  char tmp[20];
  FILE *fp;
  printf("\n\t\t\tYou have opted for password change\n");
  printf("\t\t\tPlease enter your new password");
  scanf("%s",tmp);
  fp=fopen("Web_reg.text");
  fread(&w[i+1],sizeof(w[i+1]),1,fp);
  strcopy[w[i].pass,tmp];
  fwrite(&w,sizeof(w),1,fp);
  
 }

 void clrscr()
 {
  system("cls");
 }