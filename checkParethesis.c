/*
  Case Study Problem: 1C
  Data Structures: Palindrome Checker
  Author: Bryce Narciso C. Mercines
  Section: BT-IT 4A
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 



int countChars( char* s, char c )
{
    return *s == '\0'
              ? 0
              : countChars( s + 1, c ) + (*s == c);
}


// A function to check number of parenthesis
void chkPth(char str[])
{
     HANDLE  hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   if(countChars( str, '(' ) !=  countChars( str, ')' )){
      SetConsoleTextAttribute(hConsole, 12);
      printf("%s IS NOT COMPLETE\n", str);   
   }else{
       SetConsoleTextAttribute(hConsole, 10);
      printf("%s IS COMPLETE\n", str);
   }


   
}

// End check
void endTest(){

     HANDLE  hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, 26);
            printf("\n\nParenthesis Checking is Complete!\n");
        SetConsoleTextAttribute(hConsole, 7);      
}
 
// Driver program to test above function
int main() {

HANDLE  hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int lines_allocated = 128;
int max_line_len = 100; 

// read file to stack

// Allocate lines of text 

    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    if (words==NULL){
            fprintf(stderr,"Out of memory (1).\n");
            exit(1);
        }

    FILE *fp = fopen("expressions.txt", "r");
    if (fp == NULL) {
            fprintf(stderr,"Error opening file.\n");
            exit(2);
        }

    int i;
    for (i=0;1;i++) {

          int j;
        // Have we gone over our line allocation?
        if (i >= lines_allocated){

            int new_size;
            // realloacte lines 
            new_size = lines_allocated*2;
            words = (char **)realloc(words,sizeof(char*)*new_size);
            if (words==NULL){
                  fprintf(stderr,"Error: Out of memory.\n");
                  exit(3);
                }
            lines_allocated = new_size;
            }
        // Store spaces for the next line 
        words[i] = malloc(max_line_len);
        if (words[i]==NULL) {
              fprintf(stderr,"Error Out of memory (3).\n");
               exit(4);
            }
        if (fgets(words[i],max_line_len-1,fp)==NULL)
            break;

        // Get rid of `Carraige Return` or `Line Feed` at end of line 
        for (j=strlen(words[i])-1;j>=0 && (words[i][j]=='\n' || words[i][j]=='\r');j--)
            ;
        words[i][j+1]='\0';
        }
    // close file 
    fclose(fp);

    
   // Banner
    SetConsoleTextAttribute(hConsole, 150);
    printf("===================================\n");
    SetConsoleTextAttribute(hConsole, 27);
    printf("[ Expression Parenthesis Checker  ]\n");
    SetConsoleTextAttribute(hConsole, 150);
    printf("===================================\n\n");

    
       int j;
    for(j = 0; j < i; j++)
        chkPth(words[j]);

        

   /* free allocated memory */
    for (;i>=0;i--)
        free(words[i]);
    free(words);

     endTest();
}
