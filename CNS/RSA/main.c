#include<stdio.h>
#include<math.h>
int gcd(int a, int h)
{
	int temp;
	while(1)
	{
		temp = a % h;
		if(temp == 0)
			return h;
		a = h;
		h = temp;
	}
}

int main()
{
	double p = 3;
	double q = 5;
	double n = p * q;
	double totient = (p - 1) * (q - 1);
	double e = 2;
	double count;
	double d;
	double plainText = 8;

	while(e < totient)
	{
		count = gcd(e, totient);
		if(count == 1)
			break;
		else
			e++;
	}
	double k = 2;
	d = (1 + (k * totient)) / e;
	double cipherVal = pow(plainText, e);
	double plainVal = pow(cipherVal, d);
	cipherVal = fmod(cipherVal, n);
	plainVal = fmod(plainVal, n);


	printf("\n Message data = %lf", plainText);
	printf("\n e = %lf", e);
	printf("\n d = %lf", d);
	printf("\n Encrypted data = %lf", cipherVal);
	printf("\n Original data = %lf\n", plainVal);

	return 0;
}
