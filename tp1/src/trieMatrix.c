#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int maxNode;
  int nextNode;
  int** transition;
  char* finite;
}* Trie;

Trie createTrie(int maxNode) {
  int** transition = malloc(maxNode * (sizeof (int*)));
  for(int i = 0; i++; i < maxNode) {
    transition[i] = calloc(maxNode, sizeof (int));
  }
  Trie trie;
  trie->transition = transition;
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

