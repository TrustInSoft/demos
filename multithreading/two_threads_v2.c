/*
trustinsoft/demos
Copyright (C) 2022-2023 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <pthread.h>

static int x = 0;

static pthread_mutex_t m1;

static void *mythread(void *arg)
{
    // Concurrent access to variable x, concurrent with main thread
    if (x < 3)
        x++;
    return arg;
}

int main(void)
{
    pthread_t th;

    pthread_mutex_init(&m1, NULL);
    pthread_mutex_lock(&m1); // prevents mythread from working

    pthread_create(&th, NULL, mythread, NULL);
    // Concurrent access to variable x, concurrent with thread "mythread"
    if (x < 3)
        x++;
    pthread_mutex_unlock(&m1);
    // now mythread can work

    return 0;
}
