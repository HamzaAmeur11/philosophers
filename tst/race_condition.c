#include "../philo/philo.h"

static int mals = 0;
pthread_mutex_t lock;

void *routine()
{
	long long i = 0;
	while (++i <= 100000)
	{
		pthread_mutex_lock(&lock);
		mals++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&lock);
	printf("i == %d\n", mals);
}