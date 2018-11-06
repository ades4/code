#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
void jud_killer()
{
	char killer = '0';
	for(killer = 'A';killer <= 'D';killer++)
	{
		if ((killer != 'A') + (killer == 'C') +
			(killer == 'D') + (killer != 'D') == 3)
		{
			printf("Ð×ÊÖÊÇ:%c\n", killer);
			break;
		}
	}
}
int main()
{
	jud_killer();
	system("pause");
	return 0;
}