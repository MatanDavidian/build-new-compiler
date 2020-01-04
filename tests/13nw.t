/*This test should be incorrect, the type of the array index should is not of type int*/

function void main()
{
	string str2[100] = "TestingIndexTypeV2";
	var real t1 = 1.4;
	var bool p = true;
	while(p)
	{
		str2[t1] = '0';
		t1 = t1+2*t1;
		if(t1 > 35.5)
		{
			p = false;
		}
	}
}











