#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int superGetChar() {     // this function pulls individual characters from input
  int in, up, result;    // turns them to uppercase and makes all white space types a single space
  in=getchar();          // pulls character
  while (in == '(' || in == ')' || in == '\'' || in == '"' || in == '-') {
   in=getchar();         // checks if it is an ignorable character
  }                      // if it is, then pulls next character
  up=toupper(in);        // turns the character to an uppercase
  if (isspace(up)) {     // checks for space
    up=' ';              // turns to a single space
  }
return up;               // returns character
}


