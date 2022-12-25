#ifndef LOGUTILS_H
#define LOGUTILS_H
void log_addresses(const int data[], const char *name);
void log_array(const int array[], int length);

void log_info(const char *msg, const int array[], int len, const char *name, int with_addr);
#endif
