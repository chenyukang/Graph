Graph
=====

this is my solution for this problem:

assume there are many pair relationship for nodes,
say a -> b, means a will relay on b, b -> c means b will relay on c,
so given many pairs of relations and a specific node, 
what is the nodes this node related on ?

for example:
a->b 
b->c
a->d
e->a

relaies_of(a) will output : [b, c, d]
relaies_of(b) will output : [ c ]
relaies_of(e) wiil output : [a, b, c, d]

in my solution , I use bitmap to store the relationships, and so the union operation of two bitmap will be simple.
and the operation of query will be in constant time.

Do you have a better solution ? 