/*
 * Static sequence ADT.
 *
 *                 Time  Space
 * build:          NA    O(n)
 * length:         O(1)  O(1)
 * get_at:         O(1)  O(1)
 * set_at:         O(1)  O(1)
 * insert_at:      O(n)  O(1)
 * delete_at:      O(n)  O(1)
 * insert_first:   O(n)  O(1)
 * delete_first:   O(n)  O(1)
 * insert_last:    O(n)  O(1)
 * delete_last:    O(1)  O(1)
 * print_sequence: O(n)  O(1)
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "StaticSequence.h"

#define DEFAULT_LENGTH 16

typedef struct sequence {
  int *sequence;
  int length;
} Sequence;

struct sequence *my_sequence = NULL;

// Build a Sequence
void build(void) {
  my_sequence = malloc(sizeof(Sequence));
  if (!my_sequence) {
    printf("ERROR: Couldn't allocate memory for new sequence structure\n");
    return;
  }

  my_sequence->sequence = malloc(sizeof(int) * DEFAULT_LENGTH);
  if (!my_sequence->sequence) {
    printf("ERROR: Couldn't allocate memory for new sequence array\n");
    free(my_sequence);
    return;
  }

  my_sequence->length = 0;
}

// Get length of Sequence
int length(void) {
  return my_sequence->length;
}

// Get value at specified index
int get_at(int idx) {
  return my_sequence->sequence[idx];
}

// Set value at specified index
void set_at(int idx, int value) {
  my_sequence->sequence[idx] = value;
}

// Insert value at specified index
void insert_at(int idx, int value) {
  if (my_sequence->length == DEFAULT_LENGTH) {
    printf("ERROR: Sequence is full. Please delete an item.\n");
    return;
  }

  if (idx >= DEFAULT_LENGTH-1) {
    printf("ERROR: Cannot use 'insert_at' at final Sequence position.\n");
    return;
  }

  for (int i = my_sequence->length-1; i >= idx; i--)
    my_sequence->sequence[i+1] = my_sequence->sequence[i];
  my_sequence->sequence[idx] = value;
  my_sequence->length++;
}

// Delete value at specified index
void delete_at(int idx) {
  my_sequence->length--;
  for (int i = idx; i < my_sequence->length; i++)
    my_sequence->sequence[i] = my_sequence->sequence[i+1];
}

// Insert value at front of Sequence
void insert_first(int value) {
  for (int i = my_sequence->length; i > 0; i--)
    my_sequence->sequence[i] = my_sequence->sequence[i-1];
  my_sequence->sequence[0] = value;
}

// Delete value at front of Sequence
void delete_first(void) {
  for (int i = 0; i < my_sequence->length; i++)
    my_sequence->sequence[i] = my_sequence->sequence[i+1];
  my_sequence->length--;
}

// Insert value at end of Sequence
void insert_last(int value) {
  my_sequence->sequence[my_sequence->length] = value;
  my_sequence->length++;
}

// Delete value at end of Sequence
void delete_last(void) {
  my_sequence->length--;
}

// Print Sequence to screen
void print_sequence(void) {
  if (my_sequence->length == 0) {
    printf("Sequence is empty\n");
    return;
  }

  for (int i = 0; i < my_sequence->length; i++)
    printf("%d ", my_sequence->sequence[i]);
  printf("\n");
}
