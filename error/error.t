function int foo(){
    var bool x; /* no such pointer type */
    /*x = &(1+3);*/
    var char x;
    var int* y;
    var char* x;
    var char y;
    y = &x; /* address of x is of type char* */
    d =  "this is \"invalid\"";
    
    x = &y;
    /* can only take the address of variable or array element, and (&y) is
    an expression */
}