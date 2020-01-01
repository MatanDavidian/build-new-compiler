function void main(){

	var char a = 'h';
	string b[6] = "abcdef";
	var real c = 94.95;
	var int d = 77;
	var bool e= true;

	var char* ap;
	var real* cp;
	var int* dp;

	ap = &a;
	dp = &d;
	ap = &b[1];

	if (*ap == *a){
		e=false;
	}

	
	
}
