#include <iostream>

int sum(int tree[], int index) 
{
	int sum = 0;
	++index;

	while (index > 0) 
	{
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

void update(int tree[], int n, int index, int val) 
{
	++index;
	while (index <= n) 
	{
		tree[index] += val;
		index += index & (-index);
	}
}

int* construct(int arr[], int n) 
{
	int* tree = new int[n + 1];
	for (int i = 0; i < n+1; ++i)
	{
		tree[i] = 0;
	}

	for (int i = 0; i < n; ++i) 
	{
		update(tree, n , i, arr[i]);
	}
	return tree;
}

int main() 
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* tree = construct(arr, sizeof(arr) / sizeof(arr[0]));
}
