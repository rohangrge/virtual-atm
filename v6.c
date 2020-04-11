#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

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
void upbalance(int);
void pwchange(int);
void exprogram(void);
void delay(int);
void otp(void);
int main()
{
clrscr();
printf("\n\n\n\n\n\t\t\t\tWELCOME TO MY ATM");
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
        {  if(c==8)
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
        int e;
        for(e = 0; (e < 100 && w[i].pass[e] != '\0'); e++)
        {
        w[i].pass[e] = w[i].pass[e] + 3;
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
    int f;
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
         for(f = 0; (f< 100 && w[i].pass[f] != '\0'); f++)
        w[i].pass[f] = w[i].pass[f] - 3;
        strcpy(pass,w[i].pass);
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
 }/*printf("\n\n\t\tno such user exists do you want to register?\n\n");
  printf("\t\t\t\tpress 'Y'to register");
  if(getch()=='Y'|| getch()=='y')
	{reg();}
  else{
printf("\n\n\t\t Thank you for using the atm! Hope to see you again");
exit(0);}*/

            int chck;
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress 1 to register yourself or 2 to try login again");
            //if(getch()==13)
           //clrscr();
            scanf("%d",&chck);
            if (chck==1)
            {
              reg();
            }
            if(chck==2)
            {
              login();
            }
            else
            {
              printf("your input is invalid,you will be lead to initial screen again\n");
            main();
          }
      getch();
      fclose(fp);
    }
 void transact(int b)
 {
   //int dela=10101010;
  //void delay(dela);

  clrscr();
  int tran;
  printf("\n\n\n\t\t\t\tYou have chosen to transact");
  printf("\n\n\n\t\t\t\tPlease chose your required transaction\n\n\n\t\t\t\tEnter\n\t\t\t\t1 for Withdrawal\n\t\t\t\t2 for balance query\n\t\t\t\t3 for Deposit\n");
  printf("\t\t\t\t4 for password change\n\t\t\t\t5 for exit and end transactions\n");
  scanf("%d",&tran);
  if(tran==1)
    withdraw(b);
  if(tran==2)
    balance(b);
  if(tran==3)
  deposit(b);
  if(tran==4)
  pwchange(b);
  if(tran==5)
  exprogram();

  else
  {
    printf("\n\n\n\t\t\tYou have entered an invalid input,Please enter a valid input");
    transact(b);
  }
 }
 void withdraw(int x)
 {
  clrscr();
  int wi;
  char buf[20];
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");

       fread(&w[x+1],sizeof(w[x+1]),1,fp);
        printf("\n\n\t\t\t\tWELCOME TO WITHDRAWAL ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^\n");

       printf("\t\t\tYour current balance is %s\n",w[x].balance);
       fclose(fp);
       printf("\t\t\tYou are being led to OTP verification\n");
       delay(2);
       otp();
       printf("\t\t\tEnter amount would like to withdraw\n\t\t\t\t");
       scanf("%d",&wi);
       if(wi>atoi(w[x].balance))
        {
          clrscr();
          printf("\t\t\tThe amount that you have entered is greater than your balance\n");
          printf("\t\t\t\tPlease enter an amount lesser than your balance\n");
          delay(3);
          //clrscr();
          withdraw(x);
        }
        else
        {
               int upbal=atoi(w[x].balance)-wi;
       //w[x].balance=upbal;
       itoa(upbal,buf,10);
       strcpy(w[x].balance,buf);
       fp=fopen("Web_reg.txt","w");
       fwrite(&w,sizeof(w),1,fp);
       fclose(fp);
       upbalance(x);
       printf("\n\t\t\t*****Thank you for banking with us*****");
       exit(0);
     }
       

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
 void upbalance(int x)
 {
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");

       fread(&w[x+1],sizeof(w[x+1]),1,fp);
       printf("\t\t\tYour updated balance is %s",w[x].balance);
       fclose(fp);
//exit(0);
}
 void deposit(int r)
 {
  clrscr();
  int wi2;
  char buf1[20];
  FILE *fp;
  fp=fopen("Web_reg.txt","rb");
  printf("\n\n\t\t\t\tWELCOME TO DEPOSIT ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^\n");


       fread(&w[r+1],sizeof(w[r+1]),1,fp);
       printf("\t\t\tYour current balance is %s\n",w[r].balance);
       printf("\t\t\tEnter amount would like to deposit\n");
       scanf("%d",&wi2);
       fclose(fp);
       int upbal=atoi(w[r].balance)+wi2;
       //w[x].balance=upbal;
       itoa(upbal,buf1,10);
       strcpy(w[r].balance,buf1);
       fp=fopen("Web_reg.txt","w");
       fwrite(&w,sizeof(w),1,fp);
       fclose(fp);
       printf("\t\t\tDeposit is successful\n");
       upbalance(r);
       printf("\n\t\t******Thank you for banking with us******\n");
       exit(0);
 }
 void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
        
} 
  void pwchange(int i)
 {
   clrscr();
     int y=0;
     char a;
  char tmp[20];
  FILE *fp;
  printf("\n\t\t\tYou have opted for password change\n");
  delay(1);
   printf("\t\t\tYou are being led to OTP verification\n");
       delay(2);
       otp();

  printf("\t\t\tPlease enter your new password:");
while((a=getch())!=13)
{
    tmp[y++]=a;
          printf("%c",'*');

}
int g;
        for(g = 0; (g < 100 && tmp[g] != '\0'); g++)
        {
        tmp[g] = tmp[g]+ 3;
        }




  //scanf("%s",tmp);
  fp=fopen("Web_reg.txt","w+");
  fread(&w[i],sizeof(w[i]),5,fp);
 // fp=fopen("We")
  strcpy(w[i].pass,tmp);
  fwrite(&w,sizeof(w),1,fp);
  fclose(fp);
  printf("\n\t\t\tYour password has been succesfulyy changed\n");
  printf("\n\t\t\tYou will be redirected to transact\n");
  int dela=3;
  delay(dela);
  transact(i);
 }
 void exprogram()
 {
   printf("\n\t\t***Your session has ended,Thank you\n");
   exit(0);
 }
 

 void clrscr()
 {
  system("cls");
 }
 void otp()
 {
     clrscr();
     printf("\n\t\t\tWELCOME TO OTP VERIFICATION\n");
     int cnt=1;
     int ot;
    int upper=9999;
     int lower=1000;
    int it; 
    char ap[10];
    int num=0,tr=0;
    for (it = 0; it < cnt; it++) 
    { 
        srand(time(0));
         num = (rand() % 
           (upper - lower + 1)) + lower; 
    }
            tr=num;
           char te[]="Your OTP is ";
           itoa(num,ap,10);
           strcat(te,ap);
        MessageBox(0,te, "OTP Viewer", MB_OK );
    
    printf("\n\t\t\tEnter your OTP received on your phone\n\t\t\t\t");
    scanf("%d",&ot);
    if(ot==tr)
    {
        printf("\n\t\t\tOTP verified successfuly\n");
        return;
    }
    else 
    {

        printf("\t\t\tOTP VERIFICATION FAILED,Please retry\n");
        delay(4);
        otp();     

    }
} 
 