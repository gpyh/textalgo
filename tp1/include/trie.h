#ifndef TRIE_H
#define TRIE_H

Trie createTrie(int maxNode);
void insertTrie(Trie trie, unsigned char *w);
int isInTrie(Trie trie, unsigned char *w);

#endif // TRIE_H
