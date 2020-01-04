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
function int main()
{
	 {
	 	{} /* empty code blocks are okay, although not very useful */
	 }
	 return 0;
}
function int foo2()
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
