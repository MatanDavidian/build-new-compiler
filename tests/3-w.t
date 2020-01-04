function int foo() { return 0; }
function int foo_2() { var int a; a = 2; return a; }
function int foo_3() {
	function int foo_2() { var int a; a = 2; return a; }/*function with same name in other scope*/
 	if (true) { return foo(); } 
	return foo_2(); 
}
function void main() { var int a; a = 2; }
