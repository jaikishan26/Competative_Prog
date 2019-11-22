int largestBST(node* current, int size, int max, int min, bool is)
{
	if(current == NULL)
	{
		is = true;
		return 0;
	}
	max = INT_MIN;
	//int mi = INT_MAX;
	int ls = 0, rs = 0;
	bool left, right;
	bool temp;
	left = false;
	right = false;
	//int s = INT_MIN;
	ls = largestBST(current->left, size, max, min, temp );
	if(temp == true &&  current->data > max)
	left = true;
	
	int mi = min;
	min = INT_MAX;
	
	rs = largestBST(current->right, size, max, min, temp );
	if(temp==true && current->data<min)
	right = true;
	
	if(mi < min)
	{
		min = mi;
	}
	if(current->data<min)
	{
		min = current->data;
	}
	if(current->data>max)
	{
		max = current->data;
	}
	if(left && right)
	{
		if(ls+rs+1>size);
		size= ls+rs+1;
		return ls+rs+1;
	}
	else
	{
		temp = false;
		return 0;
	}
}
