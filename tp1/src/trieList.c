#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _list {
  int targetNode;
  unsigned char letter;
  struct _list* next;
}* List;

typedef struct _trie {
  int maxNode;
  int nextNode;
  List* transition;
  bool* finite;
}* Trie;

List createList(int targetNode, unsigned char letter) {
  List list = malloc(sizeof (struct _list));
  list->targetNode = targetNode;
  list->letter = letter;
  list->next = NULL;
}

Trie createTrie(int maxNode) {
  Trie trie = malloc(sizeof (struct _trie));
  trie->maxNode = maxNode;
  trie->nextNode = 0;
  List* transition = calloc(maxNode, sizeof(List));
  trie->transition = transition;
  bool* finite = calloc(maxNode, sizeof (bool));
  trie->finite = finite;
  return trie;
}

*p = transition[node]
while((l = *p) != NULL) {
  p = &(l->next);
}
*p = createList(.....)

int newNode(trie Trie) {
  int n = trie->nextNode;
  trie->nextNode++;
  return n;
}

void freeList(List list) {
  List next;
  while(list != NULL) {
    next = list->next;
    free(list);
    list = next;
  }
}

void addTransition(Trie trie, int node, int targetNode, unsigned char letter) {
  list = trie->transition[node];
  if(list == NULL) {
    trie->transition[node] = createList(targetNode, letter);
  }
  List next;
  while((next = list->next) != NULL) {
    list = next; 
  }
  list->next = createList(targetNode, letter);
}

void freeTrie(Trie trie) {
  List* transition = trie->transition;
  int maxNode = trie->maxNode;
  for(int i = 0; i < maxNode; i++) {
    freeList(transition[i]);
  }
  free(trie->finite);
  free(trie);
}

int follow(Trie trie, int node, unsigned char a) {
  List transition = trie->transition[node];
  while(transition != NULL && transition->letter != a) {
    transition = transition->next;
  }
  if(transition == NULL) {
    return transition->targetNode;
  } else {
    return -1;
  }
}

void appendAt(Trie trie, int node, unsigned char *w) {
  int n = node;
  int i = 0;
  unsigned char a = w[0];
  while(a != '\0') {
    addTransition(n ) 
  }
}

void insertInTrie(Trie trie, unsigned char *w) {
  int n = 0;
  int i = 0;
  unsigned char a = w[0];
  int f;
  while(a != '\0' && n != -1) {
    f = follow(trie, n, a);
    if(f == -1) {
      append(trie, n, &w[i]);
      break;
    }
    n = f;
    i++; 
    a = w[i];
  }
}

bool isInTrie(Trie trie, unsigned char *w) {
  int n = 0;
  int i = 0;
  unsigned char a = w[0];
  while(a != '\0' && n != -1) {
    n = follow(trie, n, a);
    i++; 
    a = w[i];
  }
  return (n != -1);
}

