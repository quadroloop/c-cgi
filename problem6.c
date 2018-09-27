/*
  Exercise Problem: 6
  Data Structures: Sequence Algorithm
  Author/s: 
  Mercines, Bryce Narciso C.
  Mariano, Miles Nomel G.
  Nacis, Bejamin N.
  Padilla, Charles Harold S.
  De Guzman, John Raphael L.

  Section: BT-IT 4A
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 
#include <limits.h> 
#include <conio.h>

  
// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  


// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 



int getStack(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 



//========================================================================

// problem number
int pnum(int num){
	 HANDLE  hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(hConsole, 31);
            printf("\n\n");
            printf("%d",num);
            printf(".)\n\n");
        SetConsoleTextAttribute(hConsole, 7);     
}


//display sequence 
int sout(int sq[]) {
     for(int i = 0; i < 10; i++) {
        printf("%d",sq[i]);
        printf(",");

  } 
}

// global sequence
int sequence[10] = {2,4,6,8,10,12,14,16,18,20};


// 1.) insert-Before(S,p,x)
// Insert x berfore p in the sequence
int insertBefore(int S[], int p, int x){
	pnum(1);
    printf("Original Sequence: ");
    sout(sequence);
    printf("\n");
    printf("Insert element at Before position: ");
    printf("%d",p);
    printf("\n");
    printf("element to insert: ");
    printf("%d",x);
    printf("\n");
    printf("Result Sequence: ");
    for(int i = 0; i < 10; i++){
       if(i != p){
          printf("%d",S[i]);
          printf(",");
       }else{
          printf("%d",S[i]);
          printf(",");
          printf("%d",x);
          printf(",");
         
       }         
    }
   return 1;
}

    

// 2.) insert-After(S,p,x)
// Insert x after p in the sequence
int insertAfter(int S1[], int p1,int x1){
    pnum(2);
    printf("Original Sequence: ");
    sout(sequence);
    printf("\n");
    printf("Insert element Atfer position: ");
    printf("%d",p1);
    printf("\n");
    printf("element to insert: ");
    printf("%d",x1);
    printf("\n");
    printf("Result Sequence: ");
    for(int i = 0; i < 10; i++){
       if(i != p1){
          printf("%d",S1[i]);
          printf(",");
       }else{
          printf("%d",S1[i]);
          printf(",");
          printf("%d",x1);
          printf(",");
         
       }         
    } 
    return 1;
}


// 3.) Remove(S,p)
// Remove the element at position p
int Remove(int S2[], int p2){
	pnum(3);
    printf("Original Sequence: ");
    sout(sequence);
    printf("\n");
    printf("Remove element at position: ");
    printf("%d",p2);
    printf("\n");
    printf("Result Sequence: ");
    for(int i = 0; i < 10; i++){
       if(i != p2){
          printf("%d",S2[i]);
          printf(",");
       }  
    } 
    return 1;
}

// 4.) Replace(S,p,x)
// Replace with element at position p with x
int Replace(int S3[],int p3,int x3){
	pnum(4);
    int i = 0;
    printf("Original Sequence: ");
    sout(sequence);
    printf("\n");
    // algorithm
    sequence[p3] = x3;
    // algorithm end
    printf("Replacing Element at position: ");
    printf("%d",p3);
    printf("\n"); 
    printf("With: ");
    printf("%d",x3);
    printf("\n"); 
    printf("Result Sequence: ");
    sout(sequence);

    return 1;
}

// 5.) First(S),Last(S)
// return the first and last element of the sequence, respectively
int firstLast(int S4[]){
	pnum(5);
   int fe;
   int le;
   size_t ms = sizeof(S4)/sizeof(S4[0]);
      fe = S4[0];
      le = S$[ms];
    printf("Sequence: ");
    sout(sequence);
    printf("\n");
    printf("First Element: ");
    printf("%d",fe);
    printf("\n");   
    printf("Last Element: ");
    printf("%d",le);
    printf("\n");   
    return 1;
}

// 6.) Prev(S,p), Next(S,p)
// Return the preceding element to p in the sequence
int PrevNext(int S5[], int p4){
	pnum(6);
    int i=0;
    int xn;
    int prevxn;
    int res;
    while((i<10) && (S5[i] != S5)) i++;
    xn = (i<10) ? (i) : (-1);
    prevxn = xn-1;
    res = S5[prevxn];
    printf("Sequence: ");
    sout(S5);
    printf("\n");
    printf("Target Element: ");
    printf("%d",S5);
    printf("\n");
    printf("Element Before Target: ");
    printf("%d",res);
    return res;
}

// 7.) Elem-At-Rank(S,r)
// return the element at rank r in the sequence
int elemAtRank(int S6[], int r5){
	pnum(7);
    int rank = sequence[S6-1];
    printf("Sequence: ");
    sout(S6);
    printf("\n");
    printf("Value of Element at rank ");
    printf("%d",r5);
    printf("\n");
    printf("%d",rank);
    return rank;
}

// 8.) Replace-At-Rank(S,r,x)
// replace the element at rank in the sequence
int replaceAtRank(int S7[], int r6, int x6){
	pnum(8);
    sequence[r6-1] = x6;
    printf("Original Sequence: ");
    sout(S7);
    printf("\n");
    printf("Replace of Element at rank ");
    printf("%d",r6);
    printf("\n");
    printf("With: ");
    printf("%d",x6);
    printf("\n");
    printf("Result Sequence: ");
    sout(S7);
    return 1;
}

// 9.) Insert-At-Rank(S,r,X)
// insert the element x at rank r increasing the rank of all the other elements
int insertAtRank(int S8[], int r7, int x7){
	pnum(9);
    int rank = r7-1;
    printf("Original Sequence: ");
    sout(S8);
    printf("\n");
    printf("Insert element at rank:");
    printf("%d",r7);
    printf("\n");
    printf("element to insert: ");
    printf("%d",x7);
    printf("\n");
    printf("Result Sequence: ");
    for(int i = 0; i < 10; i++){
       if(i != rank){
          printf("%d",S8[i]);
          printf(",");
       }else{
          printf("%d",x7);
          printf(",");
          printf("%d",S8[i]);
          printf(",");
       }         
    }
  
    return 1;
}

// 10.) Remove-At-Rank(S,r)
// remove the element of rank r in the sequence decreasing the rank of all the other elements
int removeatRank(int S9[], int r8){
	pnum(10);
     int rank = r8-1;
    printf("Original Sequence: ");
    sout(S9);
    printf("\n");
    printf("Remove Element at Rank: ");
    printf("%d",r8);
    printf("\n");
    printf("Result Sequence: ");
    for(int i = 0; i < 10; i++){
       if(i != rank){
          printf("%d",S9[i]);
          printf(",");
       }      
    }
  
    return 1;
}

// 11.) Size(S)
// return the size of the sequence
int sizeSeq(int S10[]){
	pnum(11);
    size_t n = sizeof(S10)/sizeof(S10[0]);
    printf("Sequence: ");
    sout(S10);
    printf("\n");
    printf("Sequence size: ");
    printf("%d",n);
    return 1;
}

// 12.) At-Rank(S,r)
// return the position of element at rank r 
int atRank(int S11[], int r10){
    int rank = r10-1; 
    pnum(12);
    printf("Sequence: ");
    sout(S11);
    printf("\n");
    printf("Position of Element at rank ");
    printf("%d",r10);
    printf("\n");
    printf("%d",rank);
    return rank;
}

// 13.) Rank-Of(S,p)
// return the rank of the element at position p
int rankOf(int S12[], int p11){
	pnum(13);
    int i = 0 ,rank, pos;
    while((i<10) && (S12[i] != p11)) i++;
    pos = (i<10) ? (i) : (-1);
    rank = pos+1;
    printf("Sequence: ");
    sout(S12);
    printf("\n");
    printf("Rank of Element at position ");
    printf("%d",p11);
    printf("\n");
    printf("%d",rank);
    return rank;
}

int main() {
     HANDLE  hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
     SetConsoleTextAttribute(hConsole, 31);
    printf("\nProblem 6: Exercise Algorithm for Sequences\n\n");

 // run functions

  // 1.)  
	insertBefore(sequence,2,3);
  // 2.)
  insertAfter(sequence,3,4);
  // 3.)
  Remove(sequence,8);
  // 4.)
  Replace(sequence,4,5);
  // 5.)
  firstLast(sequence);
  //6.)
  PrevNext(sequence,0);
  // 7.)
  elemAtRank(sequence,4);
  // 8.)
  replaceAtRank(sequence,3,200);
  // 9.)
  insertAtRank(sequence,1,302);
  // 10.)
  removeatRank(sequence,4);
  // 11.)
  sizeSeq(sequence);
  //12.)
  atRank(sequence,6);
  //13.)
  rankOf(sequence,2);



 printf("\n\nDone!\n");

}