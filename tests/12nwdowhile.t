/*This test should be incorrect, the variable type checked in the loop condition is not of type boolean*/


function void t() 
{
	var int p2 = 34;
	do 
	{
		p2 = p2 - 1;
		if(p2<10)
			p2 = p2 - 3;
	} while(p2);
			
}

function void main()
{
	t();
}
