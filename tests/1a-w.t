function int foo()
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
function void main()
{
	 {
	 	{} /* empty code blocks are okay, although not very useful */
	 }
}
