#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "17017"

int timer(int wait_time)
{
	time_t start;
	
	printf("\n���͸� ������ �����մϴ�");
	getchar();
	start = time(NULL);
	while (1)
	{
		if (time(NULL) == start + wait_time)
		{
			break;
		}
	}
	printf("\n��Ⱑ �Ϸ�Ǿ����ϴ�\n");

	return 1;
}

int doorLock()
{
	char input_password[10] = "17017";
	int chance = 5;
	int wait_time = 10;
	while (1) {
		printf("��й�ȣ�� �Է��ϼ���\n>>");
		gets(input_password);

		if (strcmp(input_password, PASSWORD) != 0)
		{
			if (chance == 0)
			{
				printf("5�� �����Ͽ� doorLock�� ��ݴϴ�...%d�� ��ٸ�����", wait_time);
				if (timer(wait_time) == 1)
				{
					chance = 5;
				}
				wait_time += 10;
			}
			else 
			{
				printf("Ʋ�� ��й�ȣ �Դϴ�. �ٽ� �Է����ּ���.");
				chance--;
			}
			continue;
		}
		else
		{
			printf("������ �Ϸ�Ǿ����ϴ�.");
			break;
		}
	}
}
int main()
{
	doorLock();
	printf("�Ƶ� ~ ��������?\n");
	return  0;
}