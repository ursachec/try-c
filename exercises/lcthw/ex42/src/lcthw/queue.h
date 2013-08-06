#ifndef lcthw_Queue_h
#define lcthw_Queue_h

#include <lcthw/list.h>

typedef struct List Queue;

#define Queue_create List_create
#define Queue_destroy List_destroy

#define Queue_send List_unshift
#define Queue_recv List_pop
#define Queue_peek List_last
#define Queue_count List_count

#define QUEUE_FOREACH(L,V) LIST_FOREACH(L,last,prev,V)

#endif
