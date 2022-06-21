#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int key, option, i;
	char message[128], supp;

	printf("\n Key: ");
	scanf("%d", &key);
	scanf("%c", &supp);

	printf("\n Enter message: ");
	scanf("%s", message);
	scanf("%c", &supp);

	printf("\nChoose the operation to be performed.\n\t1. Encryption\n\t2. Decryption\n");
	scanf("%d", &option);
	scanf("%c", &supp);

	switch(option)
	{
		case 1:	printf("\nPerforming Encrytion on the message: %s, using the key %d", message, key);
				for(i = 0; i < strlen(message); i++)
				{
					message[i] = message[i] + key;
				}
				printf("\n Encrypted value: %s\n", message);
				break;

		case 2:	printf("\nPerforming Decryption on the message: %s, using the key %d", message, key);
				for(i = 0; i < strlen(message); i++)
                {
                    message[i] = message[i] - key;
                }
                printf("\n Decrypted value: %s\n", message);
                break;

		default:	printf("\nSelect a valid option\n");
					break;
	}
	return 0;
}
