function int foo(){
    var int x;
    var int* y;
    var char* x;
    string y[10];
    var char x;	/* x redaclared  */
    x = 5;
    y = &x;
    x = 6;
    
    
    y = "foobar";
    x = *(x - 5); 
    y = "barfoo";
}
