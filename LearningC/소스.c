#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "17017"

int timer(int wait_time)
{
	time_t start;
	
	printf("\n엔터를 누르면 시작합니다");
	getchar();
	start = time(NULL);
	while (1)
	{
		if (time(NULL) == start + wait_time)
		{
			break;
		}
	}
	printf("\n대기가 완료되었습니다\n");

	return 1;
}

int doorLock()
{
	char input_password[10] = "17017";
	int chance = 5;
	int wait_time = 10;
	while (1) {
		printf("비밀번호를 입력하세요\n>>");
		gets(input_password);

		if (strcmp(input_password, PASSWORD) != 0)
		{
			if (chance == 0)
			{
				printf("5번 실패하여 doorLock을 잠금니다...%d초 기다리세요", wait_time);
				if (timer(wait_time) == 1)
				{
					chance = 5;
				}
				wait_time += 10;
			}
			else 
			{
				printf("틀린 비밀번호 입니다. 다시 입력해주세요.");
				chance--;
			}
			continue;
		}
		else
		{
			printf("접속이 완료되었습니다.");
			break;
		}
	}
}
int main()
{
	doorLock();
	printf("아들 ~ 이제오니?\n");
	return  0;
}