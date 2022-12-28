SHELL := /bin/bash

TIS_ANALYZER := tis-analyzer
TARGET := boundary-test
FILES := test_driver.c boundary.c
COMPILER := gcc
TIS_OPTS := -val-profile analyzer -val -I.

.PHONY: ut clean tis tis_gui

ut:
	$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)
	gcov boundary.c

tis:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui

clean:
	@rm -rf $(TARGET) *.gc* compile_commands.json
