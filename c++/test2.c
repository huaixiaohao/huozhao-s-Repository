#include <stdio.h>
#include <stdlib.h>

int main()
{
	int getnum;
	printf("����һ������ �� ");
	scanf("%d", &getnum);

	if (getnum % 2 == 0 && getnum % 3 == 0)
	{
		printf("number = %d\n", getnum);
	}
	else
	{
		printf("�������ܱ�2, 3 ����\n");
	}

	system("pause");
	return 0;
}