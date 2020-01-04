/*Test if the function return value type is of the same type as the function signature type - should be correct*/

function int foo()
{
	var int a = 10;
	if(a == 10) 
	{
		a = a + 1;
	}
	return a;
}

function void main() 
{
	foo();
}
