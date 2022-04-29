#include "include/llist.h"

void
add_node(bin_t* bin, node_t* node)
{
  node->next = NULL;
  node->prev = NULL;

  node_t* temp = bin->head;
  // empty linked list
  if (bin->head == NULL) {
    bin->head = node;
    return;
  }

  node_t* current = bin->head;
  node_t* previous = NULL;

  while (current!=NULL && current->size<=node->size)
  {
    previous = current;
    current = current->next;
  }

  if (current == NULL)        // end of linked list
  {
    previous->next = node;
    node->prev = previous;
  }
  else                        // middle of list
  {
    if (previous != NULL)
    {
      previous->next = node;
      node->next = current;
      node->prev = previous;
      current->prev = node;
    }
    else                      // head is the only element
    {
      node->next = bin->head;
      bin->head->prev = node;
      bin->head = node;
    }
  }
}

void
remove_node(bin_t* bin, node_t* node)
{
  if (bin->head == NULL) return;
  if (bin->head == node)
  {
    bin->head = bin->head->next;
    return;
  }

  node_t* temp = bin->head->next;
  while(temp != NULL)
  {
    if (temp == node){
      if (temp->next == NULL)
      {
        temp->prev->next = NULL;
      }
      else
      {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      }
      // no need to delete the head here
      return;
    }
    temp = temp->next;
  }
}

node_t*
get_best_fit(bin* bin, size_t size)
{
  if (bin->head == NULL) return NULL;
  node_t* temp = bin->head;

  while(temp!=NULL)
  {
    if (temp->size>=size)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;            // no fit
}

node_t*
get_last_node(bin_t* bin)
{
  node_t* temp = bin->head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  return temp;
}

node_t* next(node_t* current);
node_t* prev(node_t* current);