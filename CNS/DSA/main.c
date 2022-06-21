#include <stdio.h>
#include <math.h>

int main()
{
	int p, q, h, H, x, k;
	printf("\nEnter p value: ");
	scanf("%d", &p);

	printf("\nEnter q value: ");
    scanf("%d", &q);

	printf("\nEnter h value: ");
    scanf("%d", &h);

	printf("\nEnter H value: ");
    scanf("%d", &H);

	printf("\nEnter x value: ");
    scanf("%d", &x);

	printf("\nEnter k value: ");
    scanf("%d", &k);

	int g, y, r, s, i, u1, u2, v, w;

	g = ((h * (p - 1) / q) % p);

	y = ((int) pow(g, x)) % p;

	r = (((int) pow(g, x)) % p) % q;

	s = ((int) 1 / k * (H + (x * r))) % q;

	for(i = 1; i < q; i++)
	{
		w = i;
		break;
	}

	u1 = (H * w) % q;
	u2 = (r * w) % q;

	v = ((int) (pow(g, u1) * (int) pow(y, u2)) % p) % q;

	printf("\nGloval public key g: %d", g);
	printf("\nUser private key x: %d", x);
	printf("\nUser public key y: %d", y);
	printf("\nValue of (r,s): (%d, %d)", r, s);
	printf("\nw value: %d", w);
	printf("\n u1 value: %d", u1);
	printf("\n u2 value: %d", u2);
	printf("\n Value of v: %d", v);

	if(v == r)
		printf("\n Signature Verified");
	else
		printf("\n Signature not Verified");
	return 0;
}
