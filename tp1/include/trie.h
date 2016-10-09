#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

typedef struct _trie* Trie;

Trie createTrie(int maxNode);
bool insertTrie(Trie trie, unsigned char *w);
bool isInTrie(Trie trie, unsigned char *w);
void freeTrie(Trie trie);

#endif // TRIE_H
