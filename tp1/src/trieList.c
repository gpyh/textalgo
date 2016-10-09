#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"

struct _list {
  int targetNode;
  unsigned char letter;
  struct _list* next;
};

typedef struct _list* List;

struct _trie {
  int maxNode;
  int nextNode;
  List* transitions;
  bool* finite;
};

Trie createTrie(int maxNode) {
  Trie trie = malloc(sizeof (struct _trie));
  trie->maxNode = maxNode;
  trie->nextNode = 1;
  List* transitions = calloc(maxNode, sizeof(List));
  trie->transitions = transitions;
  bool* finite = calloc(maxNode, sizeof (bool));
  trie->finite = finite;
  return trie;
}

void addTransition(Trie trie, int node, int target, unsigned char a) {
  List transition = malloc(sizeof (struct _list));
  transition->targetNode = target;
  transition->letter = a;
  // Add the transition in the head of the adjacency list
  transition->next = trie->transitions[node];
  trie->transitions[node] = transition;
}

// Finds a transition of label `a` starting from `node`
// If there is such a transition, returns the target node
// Else, returns -1.
int follow(Trie trie, int node, unsigned char a) {
  List transition = trie->transitions[node];
  while(transition != NULL && transition->letter != a) {
    transition = transition->next;
  }
  if(transition != NULL) {
    return transition->targetNode;
  } else {
    return -1;
  }
}

// Creates a path of new nodes starting from `node`
// labelled by `w`.
// Returns the last node if the word is succesfuly appended.
// Returns -1 if the trie is full.
int append(Trie trie, int node, unsigned char* w) {
  int n = node; // current node
  int i = 0;    // current index in w
  int s = trie->maxNode - trie->nextNode; // number of nodes left
  unsigned char a = w[0]; // current letter
  while(a != '\0' && i < s) {
    addTransition(trie, n, n + 1, a);
    n++;
    a = w[i++];
  }
  trie->nextNode = n + 1;
  if (i == s) {
    return -1;
  }
  return n;
}

bool insertTrie(Trie trie, unsigned char *w) {
  int n = 0;   // current node
  int f;       // next node
  int i = 0;   // current index in w
  int end = 0; // last node
  unsigned char a = w[0]; // current letter
  while(a != '\0') {
    f = follow(trie, n, a);
    if(f < 0) {
      end = append(trie, n, &w[i]);
      break;
    }
    n = f;
    a = w[i++];
  }
  if(end < 0) {
    return false;
  }
  trie->finite[end] = true;
  return true;
}

bool isInTrie(Trie trie, unsigned char *w) {
  int n = 0; // current node
  int i = 0; // current index in w
  unsigned char a = w[0]; // current letter
  // Follow a path of label w
  // Stop either when w is read or the path ended
  while(a != '\0' && n >= 0) {
    n = follow(trie, n, a);
    a = w[i++];
  }
  if (n < 0) {
    return false;
  }
  return trie->finite[n];
}

void freeList(List list) {
  List next;
  while(list != NULL) {
    next = list->next;
    free(list);
    list = next;
  }
}

void freeTrie(Trie trie) {
  List* transitions = trie->transitions;
  int maxNode = trie->maxNode;
  for(int i = 0; i < maxNode; i++) {
    freeList(transitions[i]);
  }
  free(trie->finite);
  free(trie);
}

/*
*p = transition[node]
while((l = *p) != NULL) {
  p = &(l->next);
}
*p = createList(.....)
*/
