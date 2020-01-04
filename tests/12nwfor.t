/*This test should be incorrect, the variable type checked in the loop condition is not of type boolean*/

function void t() 
{
	var int a = 0;
	for(a = 12; a; a = a + 1)
	{
		if(a>10*3)
		{
			a = a + 1;
		}
		
	}
}

function void main()
{
	t();
}



