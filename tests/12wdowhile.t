/*This test should be correct, the variable type checked in the loop condition is of type boolean*/


function void t() 
{
	var bool t = true;
	var int c = 10;
	var int d = 100;
	do 
	{
		d = d - 10;
		if(c > d)
		{
			t = false;
		}
	} while(t);
			
}

function void main()
{
	t();
}
