function int foo(){
    var int x;
    var int* l;
    var char* k;
    string y[10];
    var char z;

    x = 5;
   
    y = "foobar";
    k = &y[5]; /* k points to 'r' */
    z = *(k - 5); /* z is 'f' */
    y = "barfoo"; /* z is still 'f', but x now points to 'o' */
    return *l;
}
function void main(){}
