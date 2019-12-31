function int foo() { return 0; }
function int foo_2() { var int a; a = 2; return a; }
function int foo_3() { if (true) { return foo(); } return 0; }
function void foo_4() { var int a; a = 2; }