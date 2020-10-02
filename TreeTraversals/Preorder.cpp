// Recursive function to perform post-order traversal of the tree
void preorder(Node *root)
{
	// if the current node is empty
	if (root == nullptr)
		return;
    // Display the data part of the root (or current node)
    cout << root->data << " ";
	// Traverse the left subtree
	preorder(root->left);
	// Traverse the right subtree
	preorder(root->right);

}