/*This test should be correct, the type of the array index should be an int*/

function void main()
{
	string str1[100] = "TestingIndexType";
	var int k = 1;
	var bool t = true;

	while(t)
	{
		k = k * 2;
		str1[k] = 'n';
		if(k<6*2)
		{
			t = false;
		}
	}
}











