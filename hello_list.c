#include<stdio.h>
#include<stdlib.h>

typedef struct list_element {
    int a;
    int b;
    double c;
    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* create_list_element(int a, int b, double c)
{
    list_element* pstr = malloc(sizeof(list_element));
    pstr->a = a;
    pstr->b = b;
    pstr->c = c;
    pstr->next = NULL;
    pstr->prev = NULL;
    return pstr;
}

void insert_into_list(list_element* a, list_element* b)
{
    list_element* c = a->next;
    a->next = b;
    b->prev = a;
    b->next = c;
    if(c != NULL)
        c->prev = b;
}

void print_list(list_element* a)
{
    list_element* el;
    el = a;
    while(el != NULL) {
        printf("value = %d\n", el->a);
        el = el->next;
    }
}

list_element* get_by_number(list_element* a, int number)
{
    // Fill me
}

void delete_from_list(list_element* a)
{
    // Fill me
}

int main()
{
    list_element* r = create_list_element(42, -1, 3.14);
    int i;
    list_element* ri;
    for(i = 0; i < 10; i++) {
        ri = create_list_element(i, -i, 3.14);
        insert_into_list(r, ri);
    }

    print_list(r);

    list_element* to_delete = get_by_number(r, 5);
    delete_from_list(to_delete);

    print_list(r);

    return 0;
}
