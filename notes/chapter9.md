# Chapter 9: Trees

## Summary

This chapter introduces trees as non-linear, hierarchical data structures. It covers general trees, binary trees and their variants, memory representations, traversal algorithms, Huffman coding, and applications.

---

## Key Concepts & Definitions

**Tree** — A recursive structure of one or more nodes where one node is the *root* and all remaining nodes form sub-trees.

**Root node** — The topmost node; has no parent. If ROOT = NULL, tree is empty.

**Leaf node (terminal node)** — A node with no children; degree = 0.

**Path** — A sequence of consecutive edges connecting nodes.

**Ancestor** — Any predecessor node on the path from root to a given node.

**Descendant** — Any successor node on any path from a given node down to a leaf.

**Level number** — Root is at level 0; each child's level = parent's level + 1.

**Degree** — Number of children a node has.

**In-degree / Out-degree** — Number of edges arriving at / leaving a node.

**Height of a tree** — Total nodes on the longest path from root to deepest node. A root-only tree has height 1.

**Depth of a node** — Length of path from root to that node. Root depth = 0.

**Siblings** — Nodes at the same level sharing the same parent.

---

## Types of Trees

**General Trees** — Nodes may have any number of children. Complex to work with algorithmically, so often converted to binary trees.

**Forests** — A disjoint union of trees. Can be empty (it's a set). Converting a forest to a tree: add a single root. Converting a tree to a forest: delete the root.

**Binary Trees** — Each node has at most 2 children (left and right). Key properties:
- n nodes → exactly n − 1 edges
- Height h → at least h nodes, at most 2ʰ − 1 nodes
- n nodes → height is at least log₂(n+1), at most n

**Complete Binary Tree** — Every level except possibly the last is fully filled; nodes appear as far left as possible. For node at position K: left child = 2K, right child = 2K+1, parent = ⌊K/2⌋. Height = ⌊log₂(n+1)⌋.

**Extended Binary Tree (2-tree)** — Every node has either 0 or exactly 2 children. Empty sub-trees of the original tree become new external nodes (squares); original nodes become internal nodes (circles). Relationship: Le = Li + 2n.

**Binary Search Tree** — Ordered binary tree (covered in next chapter).

**Expression Trees** — Binary trees representing algebraic expressions. Operators are internal nodes; operands are leaf nodes.

**Tournament Trees (Selection Trees)** — External nodes = players, internal nodes = winners of matches at each round. Also called winner trees.

---

## Memory Representations

**Linked Representation** — Each node has three fields:

```c
struct node {
    struct node *left;
    int data;
    struct node *right;
};
```

NULL pointers (X) represent empty sub-trees. ROOT pointer points to root; ROOT = NULL means empty tree.

**Sequential (Array) Representation** — Uses array TREE[]. Root at TREE[1]. Node at index K has children at 2K and 2K+1. Maximum array size = 2ʰ − 1. Empty nodes stored as NULL. Simple but memory-inefficient for sparse trees.

---

## Converting a General Tree to a Binary Tree

Three rules:
- **Rule 1:** Root of binary tree = Root of general tree
- **Rule 2:** Left child of node N in binary tree = Leftmost child of N in general tree
- **Rule 3:** Right child of node N in binary tree = Right sibling of N in general tree

---


