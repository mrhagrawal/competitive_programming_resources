// Recursive function to perform post-order traversal of the tree
void inorder(Node *root)
{
	// if the current node is empty
	if (root == nullptr)
		return;
    
	// Traverse the left subtree
	inorder(root->left);
	// Display the data part of the root (or current node)
    cout << root->data << " ";
	// Traverse the right subtree
	inorder(root->right);

}