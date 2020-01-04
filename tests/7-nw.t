function int foo(int a,b,c)
{
	 var int x;
	 {
	 	var int y;
	 	x = 1;
	 	y = 2;
	 {
	 	x = 2;
	 }
	 	y = 3;
	 }
	 return 0;
}
function int foo2()
{
	var int a,b,c,d,e;
	a= foo(a,b,c,d);
	 {
	 	{} /* empty code blocks are okay, although not very useful */
	 }
	 return 0;
}
function void main()
{
}
