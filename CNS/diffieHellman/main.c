#include<stdio.h>
#include<math.h>

int power(int a, int b, int c)
{
	if(b == 1)
		return a;
	else
		return (((int)pow(a, b)) % c);
}

int main()
{
	int P, G, x, a, y, b, ka, kb;

	P = 23; // prime number
	G = 5; // primitive root
	a = 6; // private key of person A
	x = power(G, a, P);

	b = 15;
	y = power(G, b, P);

	ka = power(y, a, P);
	kb = power(x, b, P);

	printf("\nkey A: %d", a);
	printf("\nkey A: %d", b);


	printf("\nSecret key A: %d", ka);
	printf("\nSecret key A: %d", kb);
	return 0;
}
