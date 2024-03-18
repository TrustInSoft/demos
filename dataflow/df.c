
enum period {PEAK,OFFPEAK,NBPERIOD } current_period;

unsigned total;
unsigned total_during_period[NBPERIOD];

unsigned previous_t;

void update_totals(unsigned t, unsigned instant_pow) {
  unsigned duration = t - previous_t;
  unsigned energy = instant_pow * duration;
  total = total + energy;
  switch (current_period) {
  case PEAK:
    // do_peak_things();
    break;
  case OFFPEAK:
    // do_offpeak_things();
    break;
  }
  total_during_period[current_period] = total_during_period[current_period] + energy;
  previous_t = t;
}

// analysis driver
#include <tis_builtin.h>
int main(void) {
  // set up the inputs:
  tis_make_unknown( & previous_t, sizeof previous_t);
  current_period = tis_interval(0, NBPERIOD - 1);
  unsigned t;
  tis_make_unknown( & t, sizeof t);
  unsigned instant_pow;
  tis_make_unknown( & instant_pow, sizeof instant_pow);

  // call the target function
  update_totals(t, instant_pow);
}
