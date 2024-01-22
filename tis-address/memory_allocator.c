#include <stdlib.h>

#define HEAP_BEGIN  0x8000000
#define HEAP_SIZE   0x100
#define MAX_BLOCKS  10

#ifdef __TRUSTINSOFT_ANALYZER__
char tis_pool[HEAP_SIZE] __attribute__((tis_address(HEAP_BEGIN)));
#endif

static int free_heap_start = HEAP_BEGIN;

static struct memblock {
	long long addr;
	int size;
    char isAllocated;
} mem[MAX_BLOCKS];

void * my_alloc(int size)
{
    int i = 0;
    while (i < MAX_BLOCKS && mem[i].isAllocated) i++;
    if (i == MAX_BLOCKS) return NULL;
    
    if (mem[i].size > size)
    {
        // if (free_heap_start + size > HEAP_BEGIN + HEAP_SIZE) return NULL;
        if (free_heap_start > HEAP_BEGIN + HEAP_SIZE) return NULL;
        mem[i].addr = free_heap_start;
        free_heap_start += size;
    }
    mem[i].size = size;
    mem[i].isAllocated = 1;
    return (void*)(mem[i].addr);
}

void my_free(void * ptr)
{
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (mem[i].addr == (long long)ptr)  {
            mem[i].isAllocated = 0;
            return;
        }
    }
}

int main()
{
    char * paragraph1 = my_alloc(100);
    char * paragraph2 = my_alloc(100);
    char * paragraph3 = my_alloc(100);
    if (paragraph1 == NULL || paragraph2 == NULL || paragraph3 == NULL)
        exit(1);
    strcpy(paragraph1, "TrustInSoft, the ultimate static analyzer");
    strcpy(paragraph2, "Exhaustive static analysis to prove software security and safety");
    // Copy a 90 chars string in paragraph 3
    strcpy(paragraph3, "Ensure your software is immune from vulnerabilities and does not crash whatever the input");
    uppercase(paragraph3);
}

char *  uppercase(char *str)
{
    while (*str != '\0') {
        if (*str > 'a' && *str < 'z') {
            *str = *str + 'A' - 'a';
        }
    }
    return str;
}