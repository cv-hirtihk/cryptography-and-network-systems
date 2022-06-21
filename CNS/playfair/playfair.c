#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// to convert the given value to lower case
void toLowerCase(char str[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(str[i] > 64 && str[i] < 91)
			str[i] += 32;
	}
}


// to remove spaces
int removeSpaces(char* arr, int size)
{
	int i, count = 0;
	for(i = 0; i < size; i++)
	{
		if(arr[i] != ' ')
		{
			arr[count++] = arr[i];
		}
	}
	arr[count] = '\0';

	return count;
}


// to make the plain text length to be even
int prepare(char str[], int size)
{
	if(size % 2 != 0)
	{
		// here x is added in order to make the text's size even
		str[size++] = 'z';
		// \0 -> escape sequence
		str[size] = '\0';
	}
	return size;
}

void generateKeyTable(char key[], int size, char keyT[5][5])
{
	int i, j, k, flag = 0, *dicty;

	dicty = (int*) calloc(26, sizeof(int));

	for(int i = 0; i < size; i++)
	{
		if(key[i] != 'j')
		{
			dicty[key[i] - 97] = 2;
		}
	}

	dicty['j' - 97] = 1;

	i = 0; j = 0;

	for(k = 0; k < size; k++)
	{
		if(dicty[key[k] - 97] == 2)
		{
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if(j == 5)
			{
				i++;
				j = 0;
			}
		}
	}

	for(k = 0; k < 26; k++)
    {
		if(dicty[k] == 0)
		{
			keyT[i][j] = (char)(k + 97);
			j++;
			if(j == 5)
			{
				i++;
				j = 0;
			}
		}
	}
}


void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if(a == 'j')
		a = 'i';

	else if(b == 'j')
		b = 'i';

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(keyT[i][j] == a)
			{
				arr[0] = i;
				arr[1] = j;
			}
			else if(keyT[i][j] == b)
			{
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}


int mod5(int a){ return (a % 5);}

void encrypt(char str[], char keyT[5][5], int size)
{
	int i, a[4];

	for(i = 0; i < size; i += 2)
	{
		search(keyT, str[i], str[i + 1], a);

		if(a[0] == a[2])
		{
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}

		else if(a[1] == a[3])
		{
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}

		else
		{
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

void encryptByPlayFair(char str[], char key[])
{
	char ps, ks;
	char keyT[5][5];

	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	ps = strlen(str);
	toLowerCase(str, ps);
    ps = removeSpaces(str, ps);
    //printf("\nspaces removed: %s", key);
//    toLowerCase(str, ps);

	// to make the size even
	ps = prepare(str, ps);

	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}

int main()
{

	char str[30], key[30];

	printf("\nKey: ");
	fgets(key, 30, stdin);

	printf("\nPlain text: ");
	fgets(str, 30, stdin);

	encryptByPlayFair(str, key);

	printf("\nCipher text: %s", str);

	return 0;
}
