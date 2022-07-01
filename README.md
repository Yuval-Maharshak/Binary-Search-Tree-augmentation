# Binary-Search-Tree-augmentation
***
## General Info

This project produces an easy way to augment binary search trees using additional information.
We use the next general theorem: 
> Let f be a field augmenting a binary tree with n nodes. if you can determine f[x] using local info on the sub-tree coming from x (aka f[x] is determined by f of x's
> children or grandchildren or any constant number of children ) then f can be maintained in the insertion and deletion of a node without harming its time complexity.

For example we can add a field size[x] which holds the size of the sub-tree of x without harming the time complexity of insertion and deletion since we can determing
size[x] using size[left[x]] and size[right[x]] using the formula:
> size[x] = size[left[x]] + size[right[x]] + 1

This project uses the theorem so you can easily create an extension of Binary Search Tree in C language without too much work on your side.

## How to use
