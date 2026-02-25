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

## Tree Traversals

### Pre-order (NLR) — Node → Left → Right

Also called *depth-first traversal*. Used to extract **prefix** notation from expression trees.

```
1. Visit root
2. Pre-order(left subtree)
3. Pre-order(right subtree)
```

### In-order (LNR) — Left → Node → Right

Also called *symmetric traversal*. Used to display binary search trees in sorted order; produces **infix** expressions.

```
1. In-order(left subtree)
2. Visit root
3. In-order(right subtree)
```

### Post-order (LRN) — Left → Right → Node

Used to extract **postfix** notation from expression trees.

```
1. Post-order(left subtree)
2. Post-order(right subtree)
3. Visit root
```

### Level-order (Breadth-first)

Visit all nodes level by level, left to right.

### Reconstructing a Tree from Traversals

You need **in-order plus one other**:
- In-order + Pre-order: first element of pre-order = root; split in-order around root for left/right sub-trees; recurse.
- In-order + Post-order: last element of post-order = root; same splitting logic.

---

## Huffman's Tree

Huffman coding is a **lossless, variable-length** compression algorithm. Frequent characters get shorter codes; rare characters get longer codes.

**Key terms:**
- **External path length** — Sum of path lengths from root to all external (leaf) nodes
- **Internal path length** — Sum of path lengths from root to all internal nodes
- Relationship: Le = Li + 2n (where n = number of internal nodes)
- **Weighted path length** P = Σ(Wi × Li) for each leaf node

**Huffman Algorithm:**
1. Create a leaf node for each character; add to priority queue (lowest frequency = highest priority)
2. While queue has more than 1 node:
   - Remove two lowest-weight nodes
   - Create new internal node with weight = sum of those two
   - Add new node back to queue
3. Remaining node is the Huffman tree root

In the tree, left branches = 0, right branches = 1. A tree with n leaf nodes has n − 1 internal nodes.

---

## Applications of Trees

Trees are used in: file system directories, compiler construction (syntax/expression trees), database design and indexing (B-trees), hash tables/sets/maps, symbol tables, OS kernel scheduling (Red-black trees), and data compression (Huffman coding).

---

# Practice Problem Solutions

## Review Questions

**1. Concept and applications of trees**

A tree is a recursive, hierarchical, non-linear data structure with one root node and sub-trees.
Applications include: file systems, compilers, databases, symbol tables, expression evaluation,
data compression, OS scheduling.

**2. Two ways to represent binary trees**

Linked representation (nodes with left/right pointers) and sequential/array representation.
Linked is generally preferred because it uses memory only for actual nodes, whereas the array
can waste large amounts of memory for sparse or skewed trees (requiring 2ʰ − 1 slots regardless
of actual node count).

**3. All non-similar binary trees with four nodes**

There are **14** structurally distinct (non-similar) binary trees with 4 nodes. They range from
a completely left-skewed chain to a completely right-skewed chain, with various combinations
of left and right children in between.

**4. Expression tree for postfix: A B + C * D –**

Reading postfix left to right, push operands; on operator, pop two and make them children:
- A B + → (+) with left=A, right=B
- (A+B) C * → (*) with left=(A+B), right=C
- (A+B)*C D – → (–) with left=(A+B)*C, right=D

```
        –
       / \
      *   D
     / \
    +   C
   / \
  A   B
```

**5. Short notes**

**(a) Complete Binary Trees** — Every level except possibly the last is completely filled, and
all nodes are as far left as possible. n nodes → height = ⌊log₂(n+1)⌋. Child/parent
relationships: left child = 2K, right child = 2K+1, parent = ⌊K/2⌋.

**(b) Extended Binary Trees** — Each node has either 0 or exactly 2 children. Original nodes =
internal (circles); added nodes replacing empty sub-trees = external (squares). Used in
Huffman coding analysis. Le = Li + 2n.

**(c) Tournament Trees** — Represent elimination tournaments. Leaf nodes = players; internal
nodes = winners at each round. Root = overall winner. Also called selection or winner trees.

**(d) Expression Trees** — Binary trees where operators are internal nodes and operands are
leaves. Pre-order → prefix, In-order → infix, Post-order → postfix expressions.

**(e) Huffman Trees** — Built using a priority queue to create an optimal variable-length
encoding. Frequent characters get shorter bit codes. Minimizes total weighted path length.

**(f) General Trees** — Nodes may have any number of children. Complex algorithms for
traversal/insertion. Often converted to binary trees for easier processing.

**(g) Forests** — Disjoint union of trees. Can be empty. Created by removing a tree's root;
converted back to a tree by adding a new root.

**6. For the tree (A is root; B, C are children of A; D, E children of B; F, G children of C; H, I children of E):**

**(a) Leaf nodes:** D, H, I, F, G

**(b) Non-leaf nodes:** A, B, C, E

**(c) Ancestors of E:** A, B

**(d) Descendants of A:** B, C, D, E, F, G, H, I

**(e) Siblings of C:** B

**(f) Height of tree:** 4 (levels 0 through 3, counting nodes on longest path: A→B→E→H)

**(g) Height of sub-tree rooted at E:** 2 (E→H or E→I)

**(h) Level of node E:** 2

**(i) Traversals:**
- **Pre-order:** A, B, D, E, H, I, C, F, G
- **In-order:** D, B, H, E, I, A, F, C, G
- **Post-order:** D, H, I, E, B, F, G, C, A
- **Level-order:** A, B, C, D, E, F, G, H, I

**7. For the expression tree (root = +; left child = e; right child = –; – has children D and *; * has children / and c; / has children a and b):**

**(a) Infix expression:** (e + (D – ((a / b) * c)))

**(b) Prefix:** + e – D * / a b c

**(c) Postfix:** e D a b / c * – +

**(d) Evaluate with a=30, b=10, c=2, d=30, e=10:**
- a/b = 30/10 = 3
- (a/b)*c = 3*2 = 6
- D – (a/b)*c = 30 – 6 = 24
- e + 24 = 10 + 24 = **34**

**8. Convert prefix –/ab*+bcd to infix, then draw expression tree:**

Parsing prefix –/ab*+bcd:
- – is root
- Left: /ab → (a/b)
- Right: *+bcd → (b+c)*d

Infix: **(a/b) – ((b+c)*d)**

```
        –
       / \
      /   *
     / \ / \
    a  b +  d
        / \
       b   c
```

**9. Complete vs. full binary trees:**

The first tree (63 at root, 29 and 54 as children, 18/23/45 at next level, 9/11 as leaves) is a
**complete binary tree** but NOT a full binary tree because node 54 has only one child.

The second tree (same but with 49 added as right child of 54) is also a **complete binary tree**
and is also NOT a full binary tree because node 29 has only two children while node 45 has one.

**10. Maximum number of levels for a BST with 100 nodes:**

In the worst case (skewed tree), a BST with 100 nodes can have **100 levels**.

**11. Maximum height of a tree with 32 nodes:**

Maximum height = **32** (a completely skewed/linear tree).

**12. Maximum nodes at levels 3, 4, and 12:**

Maximum nodes at level n = 2ⁿ.
- Level 3: 2³ = **8**
- Level 4: 2⁴ = **16**
- Level 12: 2¹² = **4096**

**13. All non-similar binary trees with three nodes — 5 distinct shapes:**

```
Shape 1         Shape 2         Shape 3         Shape 4         Shape 5
(left skew)                   (balanced)                    (right skew)

  o               o               o               o               o
 /               /               / \               \               \
o               o               o   o               o               o
/                \                                  /                 \
o                o                                 o                   o
```

**14. Binary tree from memory representation (ROOT = 3):**

Tracing from ROOT=3:
- Index 3: DATA=1, LEFT=5, RIGHT=8
- Index 5: DATA=2, LEFT=9, RIGHT=14
- Index 8: DATA=3, LEFT=20, RIGHT=11
- Index 9: DATA=4, LEFT=1, RIGHT=12
- Index 14: DATA=5, LEFT=−1, RIGHT=−1 (leaf)
- Index 20: DATA=6, LEFT=2, RIGHT=16
- Index 11: DATA=7, LEFT=−1, RIGHT=18
- Index 1: DATA=8, LEFT=−1, RIGHT=−1 (leaf)
- Index 12: DATA=9, LEFT=−1, RIGHT=−1 (leaf)
- Index 2: DATA=10, LEFT=−1, RIGHT=−1 (leaf)
- Index 16: DATA=11, LEFT=−1, RIGHT=−1 (leaf)
- Index 18: DATA=12, LEFT=−1, RIGHT=−1 (leaf)

```
           1
          / \
         2   3
        / \ / \
       4  5 6  7
      / \   / \  \
     8   9 10 11  12
```

**15. Memory representation of binary tree (nodes 1–12):**

| Index | LEFT | DATA | RIGHT |
|-------|------|------|-------|
| 1     | 2    | 1    | 3     |
| 2     | 4    | 2    | 5     |
| 3     | 6    | 3    | 7     |
| 4     | 8    | 4    | 9     |
| 5     | −1   | 5    | −1    |
| 6     | 10   | 6    | 11    |
| 7     | −1   | 7    | 12    |
| 8     | −1   | 8    | −1    |
| 9     | −1   | 9    | −1    |
| 10    | −1   | 10   | −1    |
| 11    | −1   | 11   | −1    |
| 12    | −1   | 12   | −1    |

ROOT = 1

**16. Weighted path lengths:**

**T₁** (leaves 2,3,11,5 at depth 3; leaves 5,2 at depth 2):
P₁ = 2×3 + 3×3 + 11×3 + 5×3 + 5×2 + 2×2 = 6+9+33+15+10+4 = **77**

**T₂** (leaves 5,7 at depth 2; leaves 3,4 at depth 3; leaf 2 at depth 2):
P₂ = 5×2 + 7×2 + 3×3 + 4×3 + 2×2 = 10+14+9+12+4 = **49**

**T₃** (leaves 3,2 at depth 3; leaf 5 at depth 2; leaf 11 at depth 1):
P₃ = 3×3 + 2×3 + 5×2 + 11×1 = 9+6+10+11 = **36**

**17. Huffman coding from trees T₁, T₂, T₃:**

For each tree, assign 0 to every left branch and 1 to every right branch, then read the path
from root to each leaf node to get its code. Leaves deeper in the tree get longer codes;
leaves higher up get shorter codes. The exact codes depend on the structure of each tree
as drawn in the exercise figures.

---

## Multiple-Choice Answers

| Question | Answer | Reason |
|----------|--------|--------|
| 1 | **(a) 0** | Leaf nodes have no children, so degree = 0 |
| 2 | **(a) 0** | Root node depth is defined as zero |
| 3 | **(d) 2ʰ − 1** | A full binary tree of height h has at most 2ʰ − 1 nodes |
| 4 | **(a) Depth first** | Pre-order = depth-first traversal |
| 5 | **(c) Priority queue** | Huffman uses a min-priority queue |
| 6 | **(b) 2ⁿ** | Level n can have at most 2ⁿ nodes (root is level 0) |

---

## True or False

| Statement | Answer | Explanation |
|-----------|--------|-------------|
| 1. Nodes that branch into child nodes are called parent nodes | **True** | Correct definition |
| 2. The size of a tree equals the total number of nodes | **True** | Correct definition |
| 3. A leaf node does not branch out further | **True** | Leaf nodes have no children |
| 4. A node with no successors is called the root node | **False** | It is called a leaf/terminal node |
| 5. A binary tree of n nodes has exactly n − 1 edges | **True** | Every node except root has one parent edge |
| 6. Every node has a parent | **False** | The root node has no parent |
| 7. The Huffman coding algorithm uses a variable-length code table | **True** | Core principle of Huffman coding |
| 8. Internal path length sums paths from root to external nodes | **False** | That describes external path length; internal sums paths to internal nodes |

---

## Fill in the Blanks

| # | Answer |
|---|--------|
| 1 | **Internal** (parent node is also called an internal node) |
| 2 | **Nodes** |
| 3 | **2ᵏ** |
| 4 | **2** |
| 5 | **Siblings** |
| 6 | Similar **structure** and similar **content** |
| 7 | At least **log₂(n+1)** and at most **n** |
| 8 | Each node has either no children or exactly two children |
| 9 | **Pre-order** |
| 10 | Its **frequency of occurrence** |

