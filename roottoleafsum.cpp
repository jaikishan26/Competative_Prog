vector<int> res;
bool roottoleafsum(node* root, int sum)
{
	if(root==NULL)
	return false;
	if(root->left==NULL && root->right==NULL)
	{
		if(root->data==sum)
		{
			res.push_back(root->data);
			return true;
		}
		else
		return false;
	}
	if(roottoleafsum(root->left, sum-root->data))
	{
		res.push_back(root->data);
		return true;
	}
	if(roottoleafsum(root->right, sum-root->data))
	{
		res.push_back(root->data);
		return true;
	}
	return false;
}
