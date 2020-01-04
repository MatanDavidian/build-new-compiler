/*This test should be correct, the operator [] is used only on string(char array) type*/

function int f1(int b)
{
	string str2[50] = "OperatorTest";
	str2[b/2] = 'N';
	return 1;
}

function void main()
{
	var int v1 = 5;
	var int v2 = f1(v1);
}
