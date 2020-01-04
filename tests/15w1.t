/*This test should be incorrect, the variable type that is left to '=' is not the same type as the variable right to '='*/ 

function void main() 
{
	var int a = 4;
	var int b = 7;
	var int c = a + b;
	var real d = 2.2;
	var real e = 3.1;
	var real f = e;
	var bool c1 = true;
	var bool c2 = c1;
	string str1[10] = "Testing..";
	str1[2] = 'T';	
}
