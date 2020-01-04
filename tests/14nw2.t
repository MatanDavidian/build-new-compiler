/*This test should be incorrect, the operator [] is used only on string(char array) type*/

function int f1(int b)
{
	var int arr1 = 3;
	arr1[b+1] = 't';
	return b-2;
}

function void main()
{
	var int v1 = 1;
	var int v2 = f1(v1);
}
