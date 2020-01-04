function int foo(){
    var int x;
    var int* y;
    var char* x;
    string y[10];
    var char z;
    x = 5;
    y = &x;
    x = 6;
    {
	var int x; /*redacleration in other scope. */
	var int* y;
	var char* x;
	string y[10];
	var char z;
	x = 5;
	y = &x;
	x = 6;
    }
    
    y = "foobar";
    x = &y[5]; /* x points to 'r' */
    z = *(x - 5); /* z is 'f' */
    y = "barfoo"; /* z is still 'f', but x now points to 'o' */
}
