#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void countPhrase(int *n, int count[1001], char dictionary[1001][202]) {
  int h=1, t=*n;

    while (h < t) {      // pointer to n -number of  dictionary entries- equal to t, while h -incrementing index- is less than t run this code
      if (strcmp(dictionary[t], dictionary[h]) != 0){   // take the last phrase entered and compare it to the first phrase in dictionary
        h++;                                            // if the phrases are not equivalent, then increment
      }
      else {
        break;                                          // if the phrases are equivolent, then break the while loop
      }
    }

    if (strcmp(dictionary[t], dictionary[h]) == 0 && t != h) {  // if the phrase are equivolent and the indexes do not equal each other
      count[h]=count[h]+1;                                      // then add one to the current count
      *n=t-1;                                                   // and decrement the dictionary phrase index by one, to essentially pop the last phrase
      }
      else {
        count[t]=1;                                             // if there are no equivolent phrases set the count for the last phrase in to 1
      }

return;
}
