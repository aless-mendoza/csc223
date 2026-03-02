# Chapter 10: Efficient Binary Trees

## 10.1 Binary Search Trees (BST)
A Binary Search Tree (BST), also known as an **ordered binary tree**, is a variant of binary trees where nodes are arranged in a specific order.

### Key Properties
*   **Left Sub-tree:** All nodes in the left sub-tree have a value less than the root node.
*   **Right Sub-tree:** All nodes in the right sub-tree have a value greater than or equal to the root node (depending on implementation).
*   **Recursive Nature:** The same rule applies to every sub-tree within the tree.
*   **Duplicates:** A BST may or may not contain duplicate values, depending on how it is implemented.

### Efficiency and Complexity
*   **Average Running Time (Search):** $O(\log_2 n)$. At every step, the algorithm eliminates half of the remaining tree.
*   **Worst-Case Running Time:** $O(n)$. This occurs when the tree is "skewed" (a linear chain of nodes).
*   **Advantages:** 
    *   More efficient searching than linked lists ($O(n)$).
    *   Faster insertion/deletion than sorted arrays (where shifting elements is expensive).

---
## 10.2 Operations on Binary Search Trees

### 10.2.1 Searching for a Node
Searching begins at the root node.
1.  Check if the tree is empty. If so, the value is not found.
2.  If `VAL == root.data`, the node is found.
3.  If `VAL < root.data`, recursively call the search on the **left** child.
4.  If `VAL > root.data`, recursively call the search on the **right** child.

### 10.2.2 Inserting a New Node
The insert function adds a node at the correct position to maintain BST properties.
*   It follows the same logic as the search function to find the appropriate leaf location.
*   **Average Case:** $O(\log n)$
*   **Worst Case:** $O(n)$ (proportional to the height of the tree).
### 10.2.3 Deleting a Node
Deletion is handled in three specific cases:
*   **Case 1: Node has no children (Leaf Node):** Simply remove the node.
*   **Case 2: Node has one child:** Replace the node with its child (link the parent of the deleted node to the child of the deleted node).
*   **Case 3: Node has two children:** 
    1.  Find the **in-order predecessor** (largest value in the left sub-tree) OR the **in-order successor** (smallest value in the right sub-tree).
    2.  Replace the value of the node to be deleted with the value of the predecessor/successor.
    3.  Delete the predecessor/successor node (which will now fall into Case 1 or Case 2).

### 10.2.4 Determining Height
To find the height, calculate the height of the left and right sub-trees recursively.
*   `Height = 1 + max(Height of Left Sub-tree, Height of Right Sub-tree)`

### 10.2.5 Determining Node Counts
*   **Total Nodes:** `totalNodes(left) + totalNodes(right) + 1`
*   **Internal Nodes:** Count nodes that have at least one child.
*   **External Nodes (Leaf Nodes):** Count nodes with no children. If a tree has only one node (root), that node is considered the external node.

### 10.2.6 Mirror Image
A mirror image is obtained by interchanging the left and right sub-trees at every node recursively.

### 10.2.7 Deleting an Entire Tree
To remove a tree from memory, follow a post-order style deletion:
1.  Delete the left sub-tree.
2.  Delete the right sub-tree.
3.  Free the current node.

### 10.2.8 Smallest and Largest Nodes
*   **Smallest Node:** Follow the `left` pointers from the root until you reach a node where `LEFT == NULL`.
*   **Largest Node:** Follow the `right` pointers from the root until you reach a node where `RIGHT == NULL`.

---

## Algorithms (Pseudocode)

### Search (Recursive)
```c
SearchElement(TREE, VAL)
Step 1: IF TREE->DATA = VAL OR TREE = NULL
            Return TREE
        ELSE
            IF VAL < TREE->DATA
                Return SearchElement(TREE->LEFT, VAL)
            ELSE
                Return SearchElement(TREE->RIGHT, VAL)
        [END OF IF]
Step 2: END


