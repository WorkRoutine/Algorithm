/*
 * Single list base demo
 *
 * (C) 2017.09 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>

/* demo node */
struct demo_node {
    struct demo_node *next;
    int nr;
};

/* 
 * create list 
 * @head: head of list 
 * @nr: number of node 
 */
void demo_list_alloc(struct demo_node *head, int nr)
{
    int i;

    for (i = 0; i < nr; i++) {
        struct demo_node *node;
        struct demo_node *next;

        /* allocate a new demo_node */
        node = (struct demo_node *)malloc(sizeof(struct demo_node));
        if (!node) {
            printf("Failed: no memory to allocate new demo_node!\n");
            return;
        }
        /* Initialize node */
        printf("Please input a number:\n");
        scanf("%d", &node->nr);
        /* Add node into list */
        next = head->next;
        head->next = node;
        node->next = next;
    }
}

/*
 * Release list
 * @head: header of list
 */
void demo_list_free(struct demo_node *head)
{
    while (head->next) {
        struct demo_node *next;
  
        /* point to next node */
        next = head->next;
        head->next = next->next;

        /* release current node */
        free(next);
    }
}

/*
 * initialize header of list
 * @head: header of list
 */
void demo_header_init(struct demo_node *head)
{
    head->next = NULL;
    head->nr   = -1;
}

/*
 * Traversal list
 * @head: header of list
 */
void demo_trav_list(struct demo_node *head)
{
    int i;
    struct demo_node *node = head->next;

    for (i = 0; node; i++, node = node->next)
        printf("[%d] %d\n", i, node->nr);
}

/*
 * main
 */
int main(void)
{
    /* create head of list */
    struct demo_node head;

    /* initialize head */
    demo_header_init(&head);

    /* create a list */
    demo_list_alloc(&head, 6);

    /* Traversal list */
    demo_trav_list(&head);

    /* destroy a list */
    demo_list_free(&head);
    return 0;
}
