#define HEAP_BEGIN  0x8000000
#define HEAP_SIZE   0x1000

#ifdef SOLUTION_1
char tis_pool __attribute__((tis_address(HEAP_BEGIN))) = 0xff;
#endif

struct memblock {
	long long addr;
	int size;
    char isAllocd;
} mem[100];

void* my_alloc(int size)
{
    mem[0].addr = HEAP_BEGIN;
    mem[0].size = size;
    mem[0].isAllocd = 1;
    return (void*)(mem[0].addr);
}

int main()
{
    char * ptr = my_alloc(1);
    if(ptr != 0)
        *ptr = 'a';
}