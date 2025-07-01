#include "lemin.h"

int main(int argc, char **argv)
{
    t_lem_in    *run;
    t_room      *start;
    t_room      *a;
    t_room      *b;
    t_room      *c;
    t_room      *d;
    t_room      *e;
    t_room      *f;
    t_room      *g;
    t_room      *h;
    t_room      *i;

    run = (t_lem_in *)malloc(sizeof(t_lem_in *));
    run->end = NULL;
    run->nb_ants = 1;
    run->nb_rooms = 9;
    run->rooms = NULL;
    run->start = NULL;

    start = (t_room *)malloc(1 * sizeof(t_room));
    a = (t_room *)malloc(1 * sizeof(t_room));
    b = (t_room *)malloc(1 * sizeof(t_room));
    c = (t_room *)malloc(1 * sizeof(t_room));
    d = (t_room *)malloc(1 * sizeof(t_room));
    e = (t_room *)malloc(1 * sizeof(t_room));
    f = (t_room *)malloc(1 * sizeof(t_room));
    g = (t_room *)malloc(1 * sizeof(t_room));
    h = (t_room *)malloc(1 * sizeof(t_room));
    i = (t_room *)malloc(1 * sizeof(t_room));

    run->start = start;
    start->neighbors = (t_room **)malloc((3 + 1) * sizeof(t_room *));
    start->neighbors[0] = a;
    start->neighbors[1] = b;
    start->neighbors[2] = c;
    start->neighbors[3] = NULL;

    a->is_end = 0;
    a->is_start = 1;
    a->is_visited = 0;
    a->name = "a";
    a->neighbors = (t_room **)malloc((2 + 1) * sizeof(t_room *));
    a->neighbors[0] = d;
    a->neighbors[1] = e;
    a->neighbors[2] = NULL;
    a->x = 0;
    a->y = 0;

    b->is_end = 0;
    b->is_start = 1;
    b->is_visited = 0;
    b->name = "d";
    b->neighbors = (t_room **)malloc((1) * sizeof(t_room *));
    b->neighbors[0] = NULL;
    b->x = 0;
    b->y = 0;

    c->is_end = 0;
    c->is_start = 1;
    c->is_visited = 0;
    c->name = "a";
    c->neighbors = (t_room **)malloc((1) * sizeof(t_room *));
    c->neighbors[0] = NULL;
    c->x = 0;
    c->y = 0;

    d->is_end = 0;
    d->is_start = 0;
    d->is_visited = 0;
    d->name = "d";
    d->neighbors = (t_room **)malloc((1 + 1) * sizeof(t_room *));
    d->neighbors[0] = g;
    d->neighbors[1] = NULL;
    d->x = 0;
    d->y = 0;

    e->is_end = 0;
    e->is_start = 0;
    e->is_visited = 0;
    e->name = "d";
    e->neighbors = (t_room **)malloc((2 + 1) * sizeof(t_room *));
    e->neighbors[0] = i;
    e->neighbors[1] = h;
    e->neighbors[2] = NULL;
    e->x = 0;
    e->y = 0;

    f->is_end = 1;
    f->is_start = 0;
    f->is_visited = 0;
    f->name = "d";
    f->neighbors = (t_room **)malloc((1 + 1) * sizeof(t_room *));
    f->neighbors[0] = "end";
    f->neighbors[1] = NULL;
    f->x = 0;
    f->y = 0;

    g->is_end = 0;
    g->is_start = 0;
    g->is_visited = 0;
    g->name = "a";
    g->neighbors = (t_room **)malloc((1) * sizeof(t_room *));
    g->neighbors[0] = NULL;
    g->x = 0;
    g->y = 0;

    h->is_end = 1;
    h->is_start = 0;
    h->is_visited = 0;
    h->name = "d";
    h->neighbors = (t_room **)malloc((1 + 1) * sizeof(t_room *));
    h->neighbors[0] = "end";
    h->neighbors[1] = NULL;
    h->x = 0;
    h->y = 0;

    i->is_end = 0;
    i->is_start = 0;
    i->is_visited = 0;
    i->name = "d";
    i->neighbors = (t_room **)malloc((1 + 1) * sizeof(t_room *));
    i->neighbors[0] = f;
    i->neighbors[1] = NULL;
    i->x = 0;
    i->y = 0;

    t_room  **pointer;
    pointer = ft_pointer_begin(run);
    ft_tree(pointer);
}