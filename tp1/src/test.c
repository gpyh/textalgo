#include <stdlib.h>
#include <stdio.h>
#include "trie.h"

int main(int argc, char* argv[]) {
  if(argc > 1) {
    fprintf(stderr, "Usage: %s", argv[0]);
  }
  Trie trie = createTrie(5000);
  insertTrie(trie, (unsigned char*) "hello world!");
  if(isInTrie(trie, (unsigned char*) "hello world!")) {
    printf("It worked!\n");
  } else {
    printf("It didn't work...\n");
  }
  return EXIT_SUCCESS;
}
