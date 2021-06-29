#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>

// here we will check to see if it is a space char such as a space tab or end of line
int space_char (char c){
  if((c == '\t' || c == ' ') && c != '\0'){
    return 1;
  }
  else
  return 0;
}

//here we will check to see if it is a non space character such as a anything other than a tab,space, or end of line
int non_space_char(char c){
  if(c != '\t' && c != ' ' && c != '\0')
    return 1;
  else
    return 0;
}

//here we will check to see where the start of the word is
char* word_start(char *str){

  //iterate through the string as long as there is a space character
    while(*str){
      if(non_space_char(*str)){
	return str;
      }
      str++;
  }
    //if found return string
  return NULL;
}

// here we will check to see if there is a word terminator 
char *word_terminator(char *word){
  // iterate through checking if it is a non space character
  while(*word){
    if(non_space_char(*word)){
      return word;
    }
    word++;
  }
  // if it is a space character then return 
  return NULL;
}

int count_words(char *str){
  int count = 0;
  //you could use word start to figure out the count words because there could be multiple spaces
  while(*str){
    if(space_char(*str)){
      count++;
    }
    str++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  int i;
  // here is where we malloc the size of memory that we need to make the copy
  char *copy_of_string = malloc (sizeof(char) * (len+1));

  for(int i = 0; i < len; i++){
    copy_of_string[i] = inStr[i];
  }
  //this is to set to null
  copy_of_string[i] ='\0';
  
  return copy_of_string;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
 
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str){
  int i= 0;
  int totalWords = count_words(str);
  // here is where we wmalloc the size that we need so that we could tokenize
  char **pointer = malloc(sizeof(char*) * (totalWords +1));

  for(int i = 0; i < totalWords; i++){
    int length = word_terminator(str) - word_start(str);
    pointer[i] = copy_str(str,length);

    str = word_terminator(str);
    str = word_start(str);
  }
  pointer[i] = 0;
  return pointer;
}

int word_count;
/* Prints all tokens. */
void print_tokens(char **tokens){
  int i;
  for(int i = 0; tokens[i] != NULL; i++){
      printf("%s\n", tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i;
  //free all the words that are in tokens
  for(int i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  // free the memory for tokens
  free(tokens);
}
