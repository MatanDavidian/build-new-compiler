/*This test should be correct, the variable type checked in the loop condition is of type boolean*/


function void t() 
{
	var bool p = true;
	var int a = 7;
	var int b = 8;
	while(p)
	{
		if(a<b)
		{
			p = false;
		}
	}
		
}

function void main()
{
	t();
}
