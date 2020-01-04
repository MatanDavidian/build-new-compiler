/*This test should be incorrect, the operator [] is used only on string(char array) type*/

function int f1(int b)
{
	var bool p = true;
	p[2]='s';
	return 1;
}

function void main()
{
	var int v1 = 5;
	var int v2 = f1(v1);
}
