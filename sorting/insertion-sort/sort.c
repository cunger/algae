#include "../../linkedlist/linkedlist.h"
#include <stddef.h>

void sort(linkedlist* sequence) {
  /*
  Iterate over all nodes, starting at index 1.
  */
  int index;
  for (index = 1; ; index++) {
    node* this_node = get(index, *sequence);

    /*
    As soon as we hit the end of the input sequence, stop.
    */
    if (this_node == NULL) return;

    /*
    Subsequence before this node is already sorted. So find the position
    in the subsequence where this node needs to be inserted.
    */
    int new_index = 0;
    node* n = *sequence;
    while (n != NULL && n->data < this_node->data) {
      n = n->next;
      new_index++;
    }

    /*
    Move element from current index to new index.
    */
    move(index, new_index, sequence);
  }
}