/*This test should be incorrect, the checked type inside the if statment is not of boolean*/


function void main()
{
	var int a = 17;
	var int b = 13;
	var int c = a*b/a+b;
	if(c)
	{
		a = b/c*c*a; 
	}
	else {
		b = a*2/b*c;
	}
}
