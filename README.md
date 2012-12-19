Graph
=====

this is my solution for this problem:

assume there are many pair relationship for nodes,
say a -> b, means a will rely on b, b -> c means b will rely on c,
so given many pairs of such type relationships and a specific node, 
what is the nodes this node will rely on ?

<example>
for example:
a->b 
b->c
a->d
e->a

relies_of(a) will output : [b, c, d]
relies_of(b) will output : [ c ]
relies_of(e) wiil output : [a, b, c, d]

</example>


in my solution , I use bitmap to store the relationships, and so the union operation of two bitmap will be simple.
and the operation of query will be in constant time.

Do you have a better solution ? 