/********************************************************************************* 
* Harman Gidha, hgidha 
* ListTest.c 
*********************************************************************************/ 

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    List L = newList();
    freeList(&L);
    assert(L == NULL);

    List l = newList();
    assert(length(l) == 0);
    assert(index(l) == -1);
    
    append(l, 1);
    append(l, 2);
    append(l, 3);
    assert(front(l) == 1);
    assert(back(l) == 3);

    moveFront(l);
    assert(get(l) == 1);

    List a = newList();
    append(a, 1);
    append(a, 2);
    append(a, 3);
    assert(equals(l, a));

    List b = newList();
    clear(a);
    assert(equals(a, b));

    set(l, 0);
    assert(get(l) == 0);

    moveBack(l);
    assert(get(l) == 3);
    movePrev(l);
    assert(get(l) == 2);

    moveNext(l);
    assert(get(l) == 3);

    prepend(l, -1);
    moveFront(l);
    assert(get(l) == -1);

    insertBefore(l, -2);
    moveFront(l);
    assert(get(l) == -2);

    insertAfter(l, -15);
    moveNext(l);
    assert(get(l) == -15); //l: -2, -15, -1, 0, 2, 3
    printList(stdout, l);
    printf("\n");

    deleteFront(l);
    moveFront(l);
    assert(get(l) == -15);
    deleteBack(l);
    moveBack(l);
    assert(get(l) == 2); //l: -15, -1, 0, 2
    printList(stdout, l);
    printf("\n");

    delete(l);
    moveBack(l);
    assert(get(l) == 0); //l: -15, -1, 0

    printList(stdout, l); //should be -15, -1, 0
    printf("\n");

    List c = copyList(l);
    assert(equals(l, c));
    
    freeList(&l);
    freeList(&a);
    freeList(&b);
    freeList(&c);
}