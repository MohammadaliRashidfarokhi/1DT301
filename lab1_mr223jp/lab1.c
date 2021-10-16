#include <stdio.h>    // include standard input/output
#include <string.h>   // string utilities
#include <math.h>     // math utilities
#include <stdlib.h>   // utilities for managing memory


int main () {
    return 0;
}

// Warmup: Create function "hello" that prints "Hello world!" (without quotation marks).
void hello() {
    
}

// 1. Create function "add" that takes two integers as arguments and returns their sum.
int add(int a, int b) {
  int sum = a+b;
  return sum;
}
// 2. Double the number using ONLY the left shift operator.
int doubler(int a) {
  int leftShift = a<<1;
  return leftShift;
 }

// 3. Check if number is odd using ONLY bitwise operators. Return 1 if odd, otherwise 0.
int isOdd (int a) {
  if(a&1){
    return 1;
    }else{
      return 0;
  }
}

// 4. Return the value of the k'th bit (from the right, 0-indexed).
// example: a=5, k=2
//     decimal 5 has this 8-bit binary representation 
//     0 0 0 0  0 1 0 1
//     7 6 5 4  3 2 1 0  <--- indices
//                ^
// so we return 1, the bit-value at the index 2.
int getKthBit(int a, int k) {
  return (a & ( 1 << k )) >> k;
}

// 5. Set the k'th bit (0-indexed) to 1. Return result.
int setKthBit(int a, int k) {
  int result = (1 << k) | a;
  return result;
}
// 6. Turn off k'th bit (0-indexed). (i.e, the k'th position should be 0 in binary format). Return result.
int turnOffKthBit(int a, int k) {
  int result = a & ~(1 << k);
  return result;
 }

// 7. Given x, compute -x using only { ~, + } operators. Input x will be a positive integer 1 < x < 100 000.
// - "return -x; " is not allowed ;)
// - hint: write down the binary representation of some number x and -x on paper using 4 bits.
// - hint 2: recall that the leftmost bit represents a negative number.
int negate(int x) {
  return (~ x +1) ;
 }

// 8. You're given an integer n where 1<n<10000. Add up all even numbers from the sequence 2,...,n (inclusive both sides).
int addN(int n) {
  int sum =0;
  for(int i=0 ; i<=n; i+=2){
  sum = sum+i;
  }
  return sum; 
 }

/* 9. Fizzbuzz problem. 

    Iterate i from 1...n (inclusive both sides) and 
    add 5 to sum when i is divisible by x,
    add 10 to sum when i is divisible by y, 
    and 15 to sum when i is divisibble by both x and y.
    
    Return final sum.
*/
int fizz(int x, int y, int n) {

  int sum=0;
  for(int i=1;i<=n;i++){
  if(i%x==0)
  sum=sum+5;
  if(i%y==0)
  sum=sum+10;
  }
  return sum;
 }


/* 10. Jeb an Berry

Students (total of 2*n) are waiting in line for Jeb's hotdogs foodtruck. 
Suddenly Berry's Boba truck pulls up across from Jeb's. In order to make it fair,
the students unanimously decided to split up in two groups: 
    (1) the first half of students remains unchanged, 
    (2) the second half of students reverse and queue up at Jeb's truck.

    Example:
        Before: [Jeb's Truck] Andy, Boris, Chad, Drake 
        After : [Jeb's Truck] Andy, Boris, Drake, Chad [Berry's Truck]
    
    You can always assume an even number of students (2n).

    YOUR TASK:
        - You're given an array of chars (each char represents one person) in order.
            example: abcd
        - (1) Create a linked list structure above function declaration
                - it should contain a char and a pointer to the next node.
        - (2) Iterate through the char array (char* input) and 
              recreate the sequence of students with your linked list implementation. 
        - (3) Re-order the students in your linked list according to the aformentioned specification.
        - (4) Iterate through your linked list and append every character to a contiguous char array (char*).
                example: "abdc" 
        - (5) return the char* mentioned in step (4)

    hint: read about structs and malloc.

*/

// ---- YOUR LINKED LIST NODE DECLARATION BELOW ----
/*
References:
Udemy 
https://www.geeksforgeeks.org/linked-list-set-1-introduction/
https://medium.com/better-programming/introduction-to-linked-lists-in-c-80fc426a6a2f
*/
struct node{
char value;
struct node *next;
};

void append(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

// ---- END OF LINKED LIST DECLARATION ----
char* hotdog (char* input,int total_students){
int i;
int count =0;
struct node *t_node =NULL, *h_node = NULL;
struct node *p_node =NULL;

//(2) Iterate through the char array (char* input) and recreate the sequence of students
for(i=0;i<total_students;i++){
  t_node = (struct node*)malloc(sizeof(struct node));
  t_node->value=input[i];
  t_node->next = NULL;
  if(h_node == NULL){
    h_node = t_node;
    p_node = t_node;
    }else{
      p_node->next = t_node;
      p_node = p_node->next;
      }
// printf("%c",input[i]);
count++;
}
//(3) Re-order the students in your linked list according to the aformentioned specification
// printf("\n");
t_node = h_node;
for(i=0;i<total_students/2;i++){
  p_node = t_node;
  t_node = t_node->next;
  }

struct node *th_node= NULL,*t2_node =NULL,*t3;
while(t_node !=NULL){
  t3 = t2_node;
  t2_node = t_node;
  th_node= t2_node;
  t_node = t_node->next;
  t2_node->next = t3;
 }
p_node->next = th_node;

// (4) Iterate through your linked list and append every character to a contiguous char array (char*).
char *output = malloc(sizeof(char));
memset(output, 0, sizeof output);
i=0;
while(h_node!= NULL){
  i++;
  output = realloc(output, i * sizeof(char));
  append(output,h_node->value);
  h_node =h_node->next;
 }

//printf("%s",output); // Final result

//(5) return the char* mentioned in step (4)
return output;
}