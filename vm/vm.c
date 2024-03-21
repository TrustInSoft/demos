#include <tis_builtin.h>
#define ARRAY_SIZE 10000
unsigned char mem[ARRAY_SIZE] =  
    {80, 7, 5, 5, 3, 5, 3, 5, 4, 11, 2};
#define NEXT \
if (pos<ARRAY_SIZE-1) ++pos; break
int main() {
  unsigned int A=0, B=0, pos=0;
  tis_make_unknown(mem, ARRAY_SIZE);
  while (1) {
    switch (mem[pos] & 7) {
    // add
    case 0: A+=mem[pos]>>3; NEXT;
    // subtract
    case 1: A-=mem[pos]>>3; NEXT;
            // load
    case 2: A=mem[B]; NEXT;    
    // store
    case 3: if (B<ARRAY_SIZE) mem[B]=A; NEXT;      
    // exit
    case 4: return A;
    // load and add
    case 5: if (B<ARRAY_SIZE) A=A+mem[B]; NEXT;    
    // goto A
    case 6: if (A<ARRAY_SIZE) pos=A; break;   
    // swap A and B
    case 7: {int tmp=B; B=A; A=tmp;} NEXT;
}}}
