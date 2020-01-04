/* long
comment long
comment */

function bool foo1(int a, b, y; char c)
{
	var real s;
	var int* k=null,m;
	var int g,l;
	var string p;
	var bool res = true;
	var char* f,i;
	g = foo2(); /* call before declaration */
	s = 4.5;
	c=*f;
	i = f-7;
	c = c;

	{
		var char x = 'd', b;
		var int y;
		b = '&';
		a = (y * 7)/a-y;
		res = (b == c) && (y > a);
	}
    return res ;
}


function void fee1(int i, j, k, x)
{
    function bool fee2(int l, m, n)
    {
		var bool x, j; /* declarations */
		var char* k;
		*k = '@'; /* statements */
		i = l + l;
		if ((*k == '*') || (false != false) && (l + m < i))
		{
			x = l < m;
		}
		return x;
	}
	var bool ghgh; /* declarations */
	{
		var char x;
		var bool k = true;
		k = foo1(5,i, 34,x);
    }
    x = k;
}



function int foo2()
{
    string s1[100]="aba", s2[3], s3[20]="4";
    var int i, j=0, cnt;
	string a[30], b[100] = s3;
	var char c;
	var int ds =i;
	c = 'e';
	a[19] = 'f';
	a[4+2] = 'g';
	b = a;
	b[3] = c;
	a = "test"; /* basically equivalent to a[0] = 't'; a[1] = 'e'; a[2] =
	's'; a[3] = 't'; a[4] = '\0'; */
	i = |b|; /* this assigns 100 to variable i, since the length
	operator returns the size of the character array */
    cnt = 1;
    for(i=0; i<|s1|; i=i+1){
		do{
			if (s1[i] == s2[j])
			cnt = cnt*2;
			j=j+1;
		}while(false && true);
		j=i*2;
    }
    return cnt;
}


function int foo4()
{
	do{
		var int j;
		j=j+1;
	}while(true);
    {   
		var int x,k;
		var int* y;
		x = 5;
		y = &x;
		x = 6;
		if (&x == y && *y == x)
			*y = 9;
		{
			var char* x;
			string y[10];
			var char z;
			y = "foobar";
			x = &y[5*3+5*k];         
			z = *(x + 5);       
			y = "barfoo"; 
		}
    }
    return 0;
}



function void main()
{
    var int a;
    a = foo2();
}

function int foo10()
{
	function int foo20()
	{
	    
	}
	function int foo30()
	{
	
	}
	function int foo40()
	{
		function int foo41()
		{
			var char i;
		}
		function bool foo42()
		{
			var int i, j, k,x;
		}
		function void foo43()
		{
			var int i, j, k,x,l,m;
			var bool df;
			if (fee1(i, j, k, x) == foo43())
			{
				df = l < m;
			}
		}

	}

}
