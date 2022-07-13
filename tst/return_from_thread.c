#include "../philo/philo.h"
#include <stdlib.h>

pthread_mutex_t lock;

void *routine()
{
	char *str = (char *)malloc(10);
	str = (char *)"HAmza\n";
	return ((void *)str);
}

int main(int ac ,char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	pthread_t t1[size];
	char *ret;
	pthread_mutex_init(&lock, NULL);
	int i = -1;
	while (++i < size)
	{
		printf("thread NUM %d started\n", i);
		pthread_create(t1 + i, NULL, &routine, NULL);
	}
	i = -1;
	while (++i < size)
	{
		pthread_join(*(t1 + i), (void **)&ret);
		printf("thread NUM %d sala \n", i);
	}
	pthread_mutex_destroy(&lock);
	printf("i == %s\n", ret);
}