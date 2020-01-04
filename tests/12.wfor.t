/*This test should be correct, the variable type checked in the loop condition is of type boolean*/

function void t() 
{
	var bool p = true; 
	var int a = 0;
	for(a = 10; p; a = a + 1)
	{
		if(a>10*3)
		{
			p = false;
		}
	}
}

function void main()
{
	t();
}



