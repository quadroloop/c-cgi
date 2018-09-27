/*
Data Structures Case Study:
Title: ATM Banking 
Author:
   Bryce Narciso C. Mercines

 Operations:
 
 > getUsers
     - gets all the user in JSON form.
 > registerUser
     - saves a new user to the user file.
 > deposit
     - deposit to user balance
 > widthdraw
     - widthdraw from user balance    

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <unistd.h>

// data types and variables to be used 

   char *request;
   long m,n;
   int pin,balance;
   char *accountNumber[],*accountName[];
    bool done = true;
    FILE *account;
    char accountsDIR[50] = "./accounts/", accountsOffset[100], *ruser,*rpin,*rname,*action,*tbalance,*tamount,*tmethod,*tdate;

// json response object
int json_res(char message[],int status){
    printf("{status:\"");
    printf("%d",status);
    printf("\",data:\"");
    printf("%s",message);
    printf("\"}");
    return 0;
}



// query splitter
char* SplitString(char* str, char sep)
{
    char* ret = str;
    for(ret = str; *str != '\0'; ++str)
    {
        if (*str == sep)
        {
            *str = '\001';
        }
    }
    return ret;
}


int main(void)
{
   
// set HTTP header
printf("%s%c%c\n",
   "Content-Type:text/json;charset=iso-8859-1",13,10);
  request = getenv("QUERY_STRING");

  // if(request == NULL)
  //      json_res("atm.c:parse error!",400);
  // else if(sscanf(request,"m1=%ld&n=%ld",&m,&n)!=2)
  //      json_res("data must be numeric",400);
  // else
  //      printf("<P>The product of %ld and %ld is %ld.",m,n,m*n);


    // get balance 
    // char *userBalance;
    // sscanf(request,"userBalance=%s",userBalance);
    // printf("%s",userBalance);
  
  

    sscanf(request,"accNum=%s&accName=%s&pin=%d",accountNumber,accountName,pin);

    char* input = _strdup(&accountNumber);
    char *output, *temp;
    done = false;

    output = SplitString(input, '~');

    int cnt = 1;
    for( ; *output != '\0' && !done; )
    {
        for(temp = output; *temp > '\001'; ++temp) ; 
          if (*temp == '\000') done=true;
           *temp = '\000';
            if(cnt==1){ 
                ruser = output;            
             }
              if(cnt==2){ 
                rname = output;            
             }
             if(cnt==3){
                rpin = output;
             }
             if(cnt == 4){
                action = output;
             }
              if(cnt == 5){
                tbalance = output;
             }
              if(cnt == 6){
                tamount = output;
             }
              if(cnt == 7){
                tmethod = output;
             }
              if(cnt == 8){
                tdate = output;
             }
         ++cnt;      
        output = ++temp;
    }

     //  register user
     // check of account already exist
        if(strcmp(action,"register",20) == 0){
            char *userAcc; 
            userAcc = strcat(accountsDIR,ruser);

             if( access(userAcc, F_OK ) != -1 ) {
                    printf("Sorry, account already exists");
                } else {
                    // create account file 
                      account = fopen(userAcc, "w+");
                      fputs(rname,account);
                      fclose(account);
                    // create balance file
                      account = fopen(strcat(userAcc,"_balance"), "w+");
                      fputs("100",account);
                      fclose(account);

                    // create pin file
                      account = fopen(strcat(userAcc,"_pin"), "w+");
                      fputs(rpin,account);
                      fclose(account);
                      printf("Success! account created!");
                }
              }

          



       // user login
        if(strcmp(action,"login",20) == 0){
            char *userAcc1; 
            char str[60];
            FILE *account1;
            FILE *accName1;
            char cpin[60];
            char cbalance[60];

           
           // check if file  account exist
            userAcc1 = strcat(accountsDIR,ruser);
            // get account data ahead
             accName1 = fopen(userAcc1,"r");
                if(accName1 == NULL) {
                 printf("Error accessing account in account in DB");
                  return(-1);
                 }
                 if( fgets (str, 60, accName1)!=NULL ) {
                 }
                 fclose(accName1); 
              // get balance
               accName1 = fopen(strcat(userAcc1,"_balance"),"r");
                if(accName1 == NULL) {
                 printf("Error accessing ac in account in DB");
                  return(-1);
                 }
                 if( fgets (cbalance, 60, accName1)!=NULL ) {
                 }
                 fclose(accName1);   

                 // check if file exist  
              if( access(userAcc1, F_OK ) != -1 ) {
                // authenticate pin
              account1 = fopen(strcat(userAcc1,"_pin"),"r");
               fgets (cpin,60,account1); 
               fclose(account1);
                // check if pin is correct
               if(strcmp(cpin,rpin,20) == 0){
                //status
                printf("Login_success,");
                //name
                printf("%s,",str);
                //account number
                printf("%s,",ruser);
                //balance
                printf("%s",cbalance);

              }else{
                printf("Cannot login, account does not exist!");
              }
            }else{
              printf("Wrong PIN");
            }
        }
      


        //transact the balance (withdraw, deposit)
         if(strcmp(action,"transact",20) == 0){
               char *userAcc2;
               FILE *account3;
               userAcc2 = strcat("./accounts/",ruser); 
           
              // perform transaction and update balance
               account3 = fopen(strcat(userAcc2,"_balance"), "w");
                      // save initial balance
                      // peform balance update
                      fputs(tbalance,account3);
                      fclose(account3);  
                      printf("Success!, completed transaction of amount: ");
                      printf("%s",tbalance);

              // record transaction
               account3 = fopen(strcat(userAcc2,"_records"), "w+");
                      fputs(tmethod,account3);
                      fputs(",",account3);
                      fputs(tbalance,account3);
                      fputs(",",account3);
                      fputs(tamount,account3);
                      fputs(",",account3);
                      fputs(tbalance,account3);
                      fputs(",",account3);
                      fputs(tdate,account3);
                      fputs("\n",account3);  
                      fclose(account3);     

         }

return 1;
 
}
