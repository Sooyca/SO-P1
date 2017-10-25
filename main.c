//Bartosz Sójka
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message( void *text);

int main()
{
	pthread_t thread1, thread2;
	const char *message1 = "Message from thread 1";
	const char *message2 = "Message from thread 2";
	int v1, v2;

	v1 = pthread_create(&thread1, NULL, print_message, (void*)message1);
	if(v1)
	{
		fprintf(stderr, "Error in pthread_create() with thread 1 return code: %d\n", v1);
		exit(EXIT_FAILURE);
	}

	v2 = pthread_create(&thread2, NULL, print_message, (void*)message2);
	if(v2)
	{
		fprintf(stderr, "Error in pthread_create() with thread 2 return code: %d\n", v2);
		exit(EXIT_FAILURE);
	}

	v1 = pthread_join(thread1, NULL);

	if(v1)
	{
		fprintf(stderr, "Error in pthread_join() with thread 1 return code: %d\n", v1);
		exit(EXIT_FAILURE);
	}

	v2 = pthread_join(thread2, NULL);

	if(v2)
	{
		fprintf(stderr, "Error in pthread_join() with thread 2 return code: %d\n", v2);
		exit(EXIT_FAILURE);
	}

	printf("Message from parent thread\n");

	pthread_exit(NULL);

	return 0;
}

void *print_message(void *text)
{
	char *message;
	message = (char*) text;
	printf("%s \n", message);
	pthread_exit(NULL);
}
