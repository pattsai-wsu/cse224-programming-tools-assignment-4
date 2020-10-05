COMPILEFLAGS=
CCOMP=gcc

index: index.o superGetChar.o countPhrase.o countPhraseMore.o sortLength.o 
	$(CCOMP) $(COMPILEFLAGS) -o index index.o superGetChar.o countPhrase.o countPhraseMore.o sortLength.o
index.o: index.c
	$(CCOMP) $(COMPILEFLAGS) -c index.c
superGetChar.o: superGetChar.c
	$(CCOMP)$(COMPILEFLAGS) -c superGetChar.c
countPhrase.o: countPhrase.c
	$(CCOMP) $(COMPILEFLAGS) -c countPhrase.c
countPhraseMore.o: countPhraseMore.c
	$(CCOMP)$(COMPILEFLAGS) -c countPhraseMore.c
sortLength.o: sortLength.c
	$(CCOMP) $(COMPILEFLAGS) -c sortLength.c
clean:
	rm index.o superGetChar.o countPhrase.o countPhraseMore.o sortLength.o index
