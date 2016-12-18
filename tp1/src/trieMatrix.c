#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
<<<<<<< HEAD
=======
#include <limits.h>
>>>>>>> 8c6ca95e61bd8cc0bf3bf06928d31f4f8ac3c463
#include "trie.h"

struct _trie {
  int maxNode;
  int nextNode;
  int** transitions; // matrix of nodes ; rows are nodes ; columns are letters
  char* finite;
};

Trie createTrie(int maxNode) {
  int** transitions = malloc(maxNode * (sizeof (int*)));
  for(int i = 0; i < maxNode; i++) {
    // Initialized at 0, although it's the root's number
    // It's not a problem, because no transition should point to the root
    transitions[i] = calloc(UCHAR_MAX + 1, sizeof (int));
  }
  Trie trie = malloc(sizeof (struct _trie));
  trie->transitions = transitions;
  return trie;
}

static inline
void addTransition(Trie trie, int node, int target, unsigned char a) {
  trie->transitions[node][a] = target;
}

static inline
int follow(Trie trie, int node, unsigned char a) {
  return trie->transitions[node][a];
}

int append(Trie trie, int node, unsigned char* w) {
  int n = node;
  int i = 0;
  int s = trie->maxNode - trie->nextNode;
  unsigned char a = w[0];
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

bool insertTrie(Trie trie, unsigned char* w) {
  int n = 0;   // current node
  int f;       // next node
  int i = 0;   // current index in w
  int end = 0; // last node
  unsigned char a = w[0];
  while(a != '\0') {
    f = follow(trie, n, a);
    if(f == 0) {
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

bool isInTrie(Trie trie, unsigned char* w) {
  int n = 0;
  int i = 0;
  unsigned char a = w[0];
  if(a == '\0') {
    return trie->finite[0];
  }
  do {
    n = follow(trie, n, a);
    a = w[i++];
  } while(a != '\0' && n > 0);
  if (n == 0) {
    return false;
  }
  return trie->finite[n];
}

void freeTrie(Trie trie) {
  int** transitions = trie->transitions;
  int maxNode = trie->maxNode;
  for(int i = 0; i < maxNode; i++) {
    free(transitions[i]);
  }
  free(transitions);
  free(trie);
}

