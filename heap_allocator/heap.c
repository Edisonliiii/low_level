#include "include/heap.h"
#include "include/llist.h"

uint offset = 8;

void
init_heap(heap_t* heap, long start)
{
  // 首个节点
  node_t* init_region = (node_t*) start;
  init_region->hole = 1;
  init_region->size = (HEAP_INIT_SIZE) - sizeof(node_t) - sizeof(footer_t);

  create_foot(init_region);

  add_node(heap->bins[get_bin_index(init_region->size)], init_region);
  
  // 为啥非要强转一下 没懂
  heap->start = (void*) start;                   // 起始地址
  heap->end   = (void*) (start + HEAP_INIT_SIZE);// 终止地址
}

void* heap_alloc(heap_t* heap, size_t size)
{
  uint index = get_bin_index(size);
  bin_t* temp = (bin_t*) heap->bins[index];
}

void heap_free(heap_t* heap, void* p);
uint expand(heap_t* heap, size_t sz);
void contract(heap_t* heap, size_t sz);

uint get_bin_index(size_t sz)
{
  uint index = 0;
  sz = sz < 4 ? 4 : sz;
  while (sz >>= 1) ++index;
  index-=2;
  if (index > BIN_MAX_IDX) index = BIN_MAX_IDX; 
  return index;
}

void
create_foot(node_t* head)
{
  footer_t* foot = get_foot(head);
  foot->header = head;
}

footer_t* get_foot(node_t* node)
{
  return (footer_t*) ((char*)node + sizeof(node_t) + node->size);
}

node_t* get_wilderness(heap_t* heap);