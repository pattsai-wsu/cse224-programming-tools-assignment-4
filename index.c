// Patrick Tsai - PA4 Index - Due  11/15/2019 by 8:00am
//
// This program breaks text within text files into phrases
// Then counts the number of occurences of each phrase
// There is a max limit of the first 1000 phrases
// After which the program will still count occurences of each phrase
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// prototype functions
int superGetChar();
void sortLength(int*, char dictionary[1001][202], int count[1001]);
void countPhrase(int*, int count[1001], char dictionary[1001][202]);
void countPhraseMore(int*, int count[1001], char dictionary[1001][202], char tempPhrase[1001][202]);

// start program
int main () {

int count[1001];             // used to count phrases
char dictionary[1001][202];  // where phrases are kept
char tempPhrase[1001][202];  // used for counting phrases over 1000
int c, n=1, j=0, i=1, y;

  // initial call to retreive character input and handle any leading whitespace
  c=superGetChar();
    while ( isspace(c) || c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {
      c=superGetChar();  
    }

  // uses the EOF or ctrl D to signal stop
  while (c != EOF) {         // test if character is EOF
    if (n < 1001) {          // test if dictionary phrase is more than 1000 
      if (j < 201) {         // test if phrase length is more than 200 characters
        if ( c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {  //test if character signals end of phrase
          dictionary[n][j]='\0';    // if end of phrase character, replace with a null terminator
          countPhrase(&n, count, dictionary);  // send phrase to the count function
          n++;  // increment the dictionary phrase count
          c=superGetChar();  // get the next character
            while ( isspace(c) || c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {  // if the character is a space or punctation then skip it
              c=superGetChar();
            }
          j=0;  // if the next character should go into a new phrase, set array character count to zero
        }
        else {               // if the character is not a phrase ending character, then place it in the dictionary array, and get the next character
          dictionary[n][j]=c;    
          j++;
          c=superGetChar();
        }
      }
    else {                    // if the character is greater than the 200th character in the phrase, then do the following
      dictionary[n][j]='\0';  // replace it with a null teminator and get the next character that is not a white space or phrase ending character 
      countPhrase(&n, count, dictionary);  // send phrase to the phrase counter
      n++;                    // increment the dictionary phrase input
      c=superGetChar();
      while ( c != ',' && c != '.' && c != ';' && c !=':' && c != '?' && c != '!' ) {
        c=superGetChar();
      }
      while ( isspace(c) || c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {
          c=superGetChar();   
      }
      j=0;                    // and reet the phrase character count to 0
    }
   }

   else {                    // if the dictionary phrase index is greater than 1000, then this section of code will run 
     if (j < 201) {          // whis will keep phrase length at 200 characters and the functionality is the same as above, however, uses a temp phrase for temporary storage and count
       if ( c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {
         tempPhrase[1][j]='\0';
         countPhraseMore(&n, count, dictionary, tempPhrase);
           y=0;
           while(y<201) {
             tempPhrase[1][y]='\0';
             y++;
           }
         c=superGetChar();
           while ( isspace(c) || c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {
             c=superGetChar();
           }
         j=0;
       }
     tempPhrase[1][j]=c;    
     j++;
     c=superGetChar();
     }
     else {
       tempPhrase[1][j]='\0';
       countPhraseMore(&n, count, dictionary, tempPhrase);
         y=0;
         while(y<201) {
           tempPhrase[1][y]='\0';
           y++;
         }
       c=superGetChar();
         while ( c != ',' && c != '.' && c != ';' && c !=':' && c != '?' && c != '!' ) {
           c=superGetChar();
         }
         while ( isspace(c) || c == ',' || c == '.' || c == ';' || c ==':' || c == '?' || c == '!' ) {
           c=superGetChar();   
         }       
       j=0;
     }
   }
 }

 n=n-1;                              // this is to remove the last phrase in dictionary, which is an empty string in the 1001 index created due to dict incremented above 1000
 sortLength(&n, dictionary, count);  // function to sort entire dictionary  

  while (i <= n) {                   // print loop
    printf("%05d <%s>\n", count[i], dictionary[i]);
    i++;
  }

  printf("\n");

return 0;
}
