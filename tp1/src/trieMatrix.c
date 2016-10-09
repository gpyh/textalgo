#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"

struct _trie {
  int maxNode;
  int nextNode;
  int** transitions;
  char* finite;
};

Trie createTrie(int maxNode) {
  int** transitions = malloc(maxNode * (sizeof (int*)));
  for(int i = 0; i < maxNode; i++) {
    transitions[i] = calloc(maxNode, sizeof (int));
  }
  Trie trie;
  trie->transitions = transitions;
  return trie;
}

void insertInTrie(Trie trie, unsigned char* w) {
  size_t n = strlen(w);
  for(int i = 0; i++; i < n) {

  }
  
}

bool isInTrie(Trie tris, unsigned char* w) {
  return false;
}

