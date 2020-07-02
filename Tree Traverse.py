#I'll assume a nodes value is obtained by node.val
#and its children via node.left and node.right

def binary_tree_even_sum(root):
    #if root is null, return 0
    if root is None:
        return 0
    #get the sum of left subtree
    l = binary_tree_even_sum(root.left)
    #and the sum of right subtree
    r = binary_tree_even_sum(root.right)
    #if current node has even value, add it too
    if root.val % 2 == 0:
        return root.val + l + r
    #otherwise just return left and right subtree's summation
    else:
        return l + r