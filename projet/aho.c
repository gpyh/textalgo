#include <stdlib.h>


struct _AC {
  Trie t; // La structure
  size_t* sup; // Tableau de suppléance (états, indexé sur les états)
  List* output; // Tableau de sortie (listes de mots, indexé sur les états)
  unsigned char** words; // Mots à chercher
  size_t* indexes; // Index dand words correspondant à chaque état
  size_t n; // Nombre de mots à chercher
};

typedef struct _AC *AC;

// MAX = maximum unsigned char
// UNDEF = maximum size_t
// trans fonction(trie, état de départ, lettre) qui renvoit état
// d'arrivée ou UNDEF
AC preAC(const unsigned char** words, size_t n) {
  // TODO implémenter la file ou la remplacer
  // Allouer une trie
  // La mettre dans AC
  // f = file vide  
  size_t p, s, r;
  for(unsigned char a = 1; a < MAX; a++) {
    if((p = trans(trie, 0, a)) == UNDEF) {
      continue;
    }
    enfiler(f, p);
    sup[p] = 0;
  }
  while(f non vide) {
    r = defiler(f);
    for(unsigned char a = 1; a < MAX; a++) {
      if((p = trans(trie, r, a)) == UNDEF) {
        continue;
      }
      enfiler(f, p);
      s = sup[r];
      while(trans(trie, s, a) == UNDEF) {
        s = sup[s];
      }
      sup[p] = trans(trie, s, a);
      append(output[p], output(sup[p]));
    }
  }
}


void searchAC(int* occ, size_t n) {
}


