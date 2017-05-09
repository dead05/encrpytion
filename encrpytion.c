#include<stdio.h>
#include<conio.h>
#include<string.h>

void read_string(char str[]);
void crypt(char str[], int transform_scheme);

void main()
{
	int transform_scheme;
	char str[100];



	printf("\nEnter a string (Not more than 100 chars): ");

	//Read data from the user
	read_string(str);
	printf("\nOriginal String is: %s\n", str);

	//Read transformation scheme from the user
	printf("\nEnter the transaformation scheme (In Integer): ");
	scanf("%d", &transform_scheme);

	//Logic to convert the input string to encrypted form
	crypt(str, transform_scheme);
	printf("\nConverted String is: %s\n", str);
	getch();
}

void read_string(char str[])
{
	int i, temp;

	i = 0;
	while((temp = getchar()) != '\n')
	{
		str[i] = temp;
		i = i+1;
	}
	str[i] = '\0';
}

void crypt(char str[], int transform_scheme)
{
	int i,len;
	len = strlen(str);

	for(i=0; i<len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + transform_scheme;

			if(str[i] > 'Z')
			{
				str[i] = 'A' + ((str[i] - 'Z') - 1);
			}

			if(str[i] < 'A')
			{
				str[i] = 'Z' - (('A' - str[i]) - 1);
			}
		}
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + transform_scheme;

			if(str[i] > 'z')
			{
				str[i] = 'a' + ((str[i] - 'z') - 1);
			}

			if(str[i] < 'a')
			{
				str[i] = 'z' - (('a' - str[i]) - 1);
			}
		}
	}
}
