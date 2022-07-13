#include "../philo.h"

void *routine()
{
	printf("tst Threads\n");
	sleep(3);
	printf("7na khdamin da9a wahda\n");
	sleep(2);
	printf("atktb li lfoo9 tani\n");
	return (NULL);
}

void *routine2()
{
	printf("tst Threads\n");
	sleep(5);
	printf("7na khdamin da9a wahda\n");
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	t1, t2;
	//pthread_t : a variable when store some information about the thread

	//whin i creat a thread it execute a fct "ex : routine"
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	//parametre of pthread_create : function is used to create a new thread, with attributes specified by attr,

	//cmnd to know what the max of threads in a process.
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return(3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
}