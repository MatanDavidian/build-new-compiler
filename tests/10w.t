/*This test should be correct, the function return type is the same type as the variable type*/

function int f1()
{
	var int a = 9;
	var int b = 7;
	if(a>b)
	{
		return b+5;
	}
	else {
		return a*6;
	}

	return 0;
}

function void main()
{
	var int c = 0;
	c = f1();
}
	
