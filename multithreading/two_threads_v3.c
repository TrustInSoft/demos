#include <pthread.h>

static pthread_mutex_t m1;
static int x=0;

static void *mythread(void *arg)
{
    pthread_mutex_lock(&m1);
    if (x<3) x++;
    pthread_mutex_unlock(&m1);
    return arg;
}

int main(void)
{
    pthread_t th;

    pthread_mutex_init(&m1, NULL);

    pthread_create(&th, NULL, mythread, NULL); // start mythread
    
    pthread_mutex_lock(&m1);
    if (x<3) x++;
    pthread_mutex_unlock(&m1);
    
    return 0;
}
