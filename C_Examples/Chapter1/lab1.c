#include <stdio.h>

#include <stdlib.h>

#include <string.h>


/* return true if char is a whitespace

   false if otherwise
*/

int space(char c){
  if (c == ' ' || c == '\n' || c == '\t' || c == '\0'){
    return 1;
  }else{
    return 0;
  }
}
  
  /* return false if char is a whitespace 
     true if otherwise
  */

  int non_space(char c){
    if(c == ' ' || c == '\n' || c == '\t' || c == '\0'){
      return 0;
    }else{
      return 1;
    }
  }
/* Returns a pointer to the first character of the next

   space-separated word. Return zero pointer if str doesn't

   contain any words.*/

char *word_start(char *str){
  for(int i=0;*(str+i)!='\0';i++){
    if(non_space(*(str+1))){
      return str+1;
    }
  }
}
 



/* Returns a pointer to the first space character of the zero

   terminated string*/

char *end_word(char *str){
  char *start = word_start(str);
  for(int i=0; *(start+i)!='\0'; i++){
    if(space(*(start+i+1))){
      return start+i;
    }
  }
}
 
    

// counts the number of words or tokens

int count_tokens(char* str){
  int counter = 0;
  for(int i=0; *(str+i)!='\0' ;i++){
    if(non_space(*(str+i))){
      if(space(*(str+i+1))){
	counter++;
      }
    }
  }
  return counter;
}
  

/* Returns a freshly allocated new zero terminated

   string containing <len> chars from <inStr> 

 */

char *copy_str(char *inStr, short len){
  char *copy = (char *)malloc(len);
  for(int i=0; i<len ; i++){
    *(copy+i) = *(inStr+i);
  }
  *(copy+len) = '\n';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     tokens[3] = 0

*/
 
char** tokenize(char *str){
  char words = count_tokens(str)+1;
  char **arr = (char **)malloc(sizeof(char *) * (words+1));
  int i=0;
  arr[i] = strtok(str, " ");
  for(i=1; i < words ;i++){
    arr[i] = strtok(NULL, " ");
  }
  arr[i++] = '\0';
  return arr;

}

/* Prints all tokens */

void print_all_tokens(char **tokens){
  for(int i=0;*(tokens+i)!='\0';i++){
    printf("%s\n", *(tokens+i));
  }
}


int main() {
  char string[] = "This is a test for tokenize";

  print_all_tokens(tokenize(string));

  return 0;
}
