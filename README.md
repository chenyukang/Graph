Graph
=====


this is my solution for this problem:

assume there are many pair relationship for node,
say a -> b, means a will relay on b, b -> c means b will relay on c,
so given many pairs of relations and a node, 
what is the nodes this node related on ?

for example:
a->b 
b->c
a->d

relaies_of(a) will output : [b , c , d]
relaies_of(b) will output : [ c ]

in my solution , I use bitmap to store the relationships, and also union two bitmap will be simple.


