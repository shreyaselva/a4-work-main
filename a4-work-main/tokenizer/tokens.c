/* TODO: Provide implementations of your tokenize function here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "../vector/vect.h"

//check if character is token
int is_token(char ch) {
  return ch == '(' || ch == ')' || ch == '<' || ch == '>' || ch == ';' || ch == '|';
}
//check if whitespace
int is_whitespace(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

//takes string and returns tokens vector
vect_t *tokenize(const char *input) {
  vect_t *tokens = vect_new();

  char buffer[1024];
  int buf_idx = 0;

  //flag for double quotes
  int double_quotes = 0;

  int i = 0;
  while (input[i] != '\0') {
    char current = input[i];

  if (current == '"') {
    double_quotes = !double_quotes;
    i++;
    continue;
}

  if (double_quotes) {
    buffer[buf_idx++] = current;
    buffer[buf_idx] = '\0';
}

else {
  if (is_whitespace(current)) {
    if (buf_idx > 0) {
    buffer[buf_idx] = '\0';
    vect_add(tokens, buffer);
    buf_idx = 0;
}
}

//move special characters into own tokens
else if (is_token(current)) {
  if (buf_idx > 0) {
    buffer[buf_idx] = '\0';
    vect_add(tokens, buffer);
    buf_idx = 0;
  }
  char tokenized_str[2] = {current, '\0'};
  vect_add(tokens, tokenized_str);
}

else {
  buffer[buf_idx++] = current;
  buffer[buf_idx] = '\0';
  }
}
  i++;
}

if (buf_idx > 0) {
  buffer[buf_idx] = '\0';
  vect_add(tokens, buffer);
 }

 return tokens;
}
