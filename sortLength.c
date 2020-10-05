#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void sortLength(int *n, char dictionary[1001][202], int count[1001]) {
  int h, i=0, t=*n, tempCount;
  char tempDict[202];
//  printf("<%d>\n", t);
 while (i < *n) {         // uses a bubble sort to sort length
  h=1;                   // therefore it must increment through the entire dictionary n squared times
  while( h < t ) {       // each round it pushes the largest length phrase to the bottom
    if (strlen(dictionary[h])>strlen(dictionary[h+1])) {
      strcpy(tempDict,  dictionary[h]);        // if the length of phrase is larger than the next phrase in the list
      strcpy(dictionary[h], dictionary[h+1]);  // then the function will copy the first phrase to a temp
      strcpy(dictionary[h+1], tempDict);       // then copy the second phrase to the first phrase index
                                               // and then copy the temp -or first phrase- to the index plus one holder 
      tempCount=count[h];                      // the same happens to the count, in order to keep the relationship between count and phrases
      count[h]=count[h+1];
      count[h+1]=tempCount;
   }
  h++;
  }
 t=t-1;
 i++;
 }

return;
}
