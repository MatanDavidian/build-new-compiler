/*This test should be incorrect, the variable type checked in the loop condition is not of type boolean*/


function void t() 
{
	var real rn = 16.3;
	var int p = 8;
	while(rn)
	{
		
		if(rn > p * 3)
		{
			p = p / 2;
		}
	}
		
}

function void main()
{
	t();
}
