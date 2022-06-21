#include <stdio.h>
#include <string.h>

int main()
{
	int key = 4;
	printf("\nKey: ");
	scanf("%d", &key);


	int k[key];
	int i = 0, m = 0;
	int q = (2 * key) - 2;

	while(i < key)
	{
		k[i] = q - m;
		printf("\n%d : k[i]", k[i]);
		m = m + 2;
		i++;
	}

	k[key - 1] = k[0];


	char str[100];
	printf("\nMessage: ");
	scanf("%s", str);

	int len;
	len = strlen(str);
	printf("\nlength: %d", len);

	printf("\nEncrypted value: ");

	int temp;
	int l = 0, j = 0;

	for(i = 0; i < key && i < len; i++)
	{
		temp = i;
		do {
				printf("%c", str[i]);
				i = i + k[l];
		}while(i < len);

		l = l + 1;
		i = temp;
	}
	printf("\n");

	return 0;
}
