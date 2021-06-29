#include <stdio.h>
#include "tokenizer.h"

int main(){
  int max_str = 1000;

  char input_string[max_str];
  puts("Welcome!");

  puts("Please enter the string that you would like tokenized: ");
  fgets(input_string, max_str, stdin);

  print_tokens(input_string);
}
