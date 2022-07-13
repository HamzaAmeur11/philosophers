#include "../philo/philo.h"
#include <stdlib.h>

static int mals = 0;
pthread_mutex_t lock;

void *routine()
{
	long long i = 0;
	while (++i <= 10000)
	{
		pthread_mutex_lock(&lock);
		mals++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main(int ac ,char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	pthread_t t1[size];
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
		pthread_join(*(t1 + i), NULL);
		printf("thread NUM %d sala \n", i);
	}
	pthread_mutex_destroy(&lock);
	printf("i == %d\n", mals);
}