#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// this uses the same functionality as countPhrase, however since it is comparing phrases after the first 1000
// it does not have to set the phrase count to 1 if the phrase doesn't already exist
// and it only has to account for the phrases already in dictionary

void countPhraseMore(int *n, int count[1001], char dictionary[1001][202], char tempPhrase[1001][202]) {
  int h=1, t=*n;
    while (h < t) {             // while loop that compares the last phrase -tempPhrase- with all the phrases in dictionary starting with 1 and incrementing through 1000
      if (strcmp(tempPhrase[1], dictionary[h]) != 0){
        h++;
      }
      else {
        break;
      }
    }

    if (strcmp(tempPhrase[1], dictionary[h]) == 0) {
      count[h]=count[h]+1;
    }
return;
}
