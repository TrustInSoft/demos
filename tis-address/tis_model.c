#include <tis_builtin.h>
#define PIN_0 0x2000000
#define PIN_0_LEN 10
char STUB_PIN_0[PIN_0_LEN] __attribute__((tis_address(PIN_0)));

extern int main();

int tis_main()
{
    tis_make_unknown(STUB_PIN_0, sizeof(STUB_PIN_0));
    main();
    return 0;
}