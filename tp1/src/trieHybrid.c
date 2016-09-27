#include <stdlib.h>
#include <stdbool.h>

typedef struct _list {
  int targetNode;
  unsigned char letter;
  struct _list* next;
}* List;

typedef struct {
  int maxNode;
  int nextNode;
  List* transitionOthers;
  char *finite;
}* Trie;

Trie createTrie(int maxNode) {
  return NULL;
}

void insertInTrie(Trie trie, unsigned char *w) {
  
}

bool isInTrie(Trie tris, unsigned char *w) {
  return false;
}
