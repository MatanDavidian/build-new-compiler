/*This test should be incorrect, the function return type value is not the same type of the variable that the function value assigned to*/


function char f2()
{
	var char x = 'b';
	var bool flag = true;

	if (flag != false)
	{
		return x;
	}

	else {
		return 'd';
	}

	return 'e';
}

function void main()
{
	var int a = 6;
	a = f2();
}
