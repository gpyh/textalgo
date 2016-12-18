#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct _list {
  struct _list* next;
  size_t index; // Index de l'occurence du motif
} list_t;

list_t* insert(list_t* list, size_t index) {
  list_t* head = malloc(sizeof (list_t));
  head->next = list;
  head->index = index;
  return head;
}

void freeList(list_t* list) {
  list_t* next;
  while(list != NULL) {
    next = list->next;
    free(list);
    list = next;
  }
}

list_t* searchNaive(char* x, size_t m, char* y, size_t n) {
  list_t* list = NULL;
  size_t i;
  size_t j;
  for(j = 0; j < n - m; j++) {
    for(i = 0; i < m; i++) {
      if(x[i] != y[j+i]) {
        break;
      }
    }
    if(i == m) {
      list = insert(list, j);
    }
  }
  return list;
}

list_t* searchNaiveFastLoop(char* x, size_t m, char* y, size_t n) {
  (void)(n); // Unused
  list_t* list = NULL;
  size_t i;
  char* sy;
  for(sy = y; *sy != '\0'; sy++) {
    for(i = 0; i < m; i++) {
      if(x[i] != *(sy + i)) {
        break;
      }
    }
    if(i == m) {
      list = insert(list, y - sy);
    }
  }
  return list;
}

/* void searchNaiveFastLoopSentinel(char* x, size_t m, char* y, size_t n) { */
  
/* } */

list_t* searchNaiveStrncmp(char* x, size_t m, char* y, size_t n) {
  list_t* list = NULL;
  size_t j;
  for(j = 0; j < n - m; j++) {
    if(strncmp(y + j, x, n)) {
      list = insert(list, j);
    }
  }
  return list;
}

list_t* searchNaiveStrncmpFastLoop(char* x, size_t m, char* y, size_t n) {
  (void)(n); // Unused
  list_t* list = NULL;
  char* sy;
  for(sy = y; *sy != '\0'; sy++) {
    if(strncmp(sy, x, m)) {
      list = insert(list, y - sy);
    }
  }
  return list;
}

/* void searchNaiveStrncmpFastLoopSentinel(char* x, size_t m, char* y, size_t n) { */
  
/* } */

ssize_t* goodPrefix(char* x, size_t m) {
  ssize_t* table = malloc(m * (sizeof (ssize_t)));
  table[0] = -1;
  ssize_t i = 0;
  size_t j;
  for(j = 1; j < m; j++) {
    table[j] = i;
    while(i >= 0 && x[i] != x[j]) {
      i = table[i];
    }
    i++;
  }
  table[m] = i;
  return table;
}

ssize_t* bestPrefix(char* x, size_t m) {
  ssize_t* table = malloc(m * (sizeof (ssize_t)));
  table[0] = -1;
  ssize_t i = 0;
  size_t j;
  for(j = 1; j < m; j++) {
    if(x[i] == x[j]) {
      table[j] = table[i];
    } else {
      table[j] = i;
      do {
        i = table[i];
      } while(i >= 0 && x[i] != x[j]);
    }
    i++;
  }
  table[m] = i;
  return table;
}

list_t* searchMorrisPratt(char* x, size_t m, char* y, size_t n) {
  list_t* list = NULL; 
  ssize_t* goodPrefixTable = goodPrefix(x, m);
  ssize_t i = 0;
  size_t j;
  for(j = 0; j < n; j++) {
    while(i >= 0 && x[i] != y[j]) {
      i = goodPrefixTable[i];
    }
    i++;
    if((size_t) i == m) {
      list = insert(list, j);
      i = goodPrefixTable[i];
    }
  }
  return list;
}

list_t* searchKnuthMorrisPratt(char* x, size_t m, char* y, size_t n) {
  list_t* list = NULL; 
  ssize_t* bestPrefixTable = bestPrefix(x, m);
  ssize_t i = 0;
  size_t j;
  for(j = 0; j < n; j++) {
    while(i >= 0 && x[i] != y[j]) {
      i = bestPrefixTable[i];
    }
    i++;
    if((size_t) i == m) {
      list = insert(list, j);
      i = bestPrefixTable[i];
    }
  }
  return list;
}

list_t* searchHorspool(char* x, size_t m, char* y, size_t n) {
  list_t* list = NULL;
  size_t d[UCHAR_MAX + 1];
  size_t k;
  for(k = 0; k < UCHAR_MAX + 1; k++) {
    d[k] = m;
  }
  for(k = 0; k < m - 1; k++) {
    d[((unsigned char*) x)[k]] = m - k - 1;
  }
  const unsigned char* p = (unsigned char*) y;
  while(p < ) {
    if(strncmp(x, y, m) == 0) {
      // TODO
    }
    p += d[p[m - 1]];
  }
}






