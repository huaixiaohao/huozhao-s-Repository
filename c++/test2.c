#include <stdio.h>
#include <stdlib.h>

int main()
{
	int getnum;
	printf("输入一个整数 ： ");
	scanf("%d", &getnum);

	if (getnum % 2 == 0 && getnum % 3 == 0)
	{
		printf("number = %d\n", getnum);
	}
	else
	{
		printf("该数不能被2, 3 整除\n");
	}

	system("pause");
	return 0;
}