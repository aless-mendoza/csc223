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


