# trustinsoft/demos
# Copyright (C) 2022-2023 TrustInSoft
# mailto:contact AT trust-in-soft DOT com
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 
SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
GCC_VERSION := $(shell gcc --version | head -n 1 | cut -d ' ' -f 4 | cut -d '.' -f 1)

TIS_ANALYZER := tis-analyzer
TARGET := increment
FILES := test_driver.c utils.c $(TARGET).c
OBJS := test_driver.o utils.o $(TARGET).o
COMPILER := gcc
TIS_OPTS := -tis-config-load demo-tools/tis.json -fun-inout increment_array -inout-verbose 0 -tis-report

.PHONY: all test tis-l1  tis-l1-gui tis-l1-run tis-l1-run-gui tis-l2 tis-l2-gui tis-l2-run tis-l2-run-gui report


all:
	@echo "make test:       Runs tests"
	@echo "make tis:        Runs TISA complete analysis"
	@echo "make tis-l1:     Runs TISA interpreter mode analysis"
	@echo "make tis-l2:     Runs TISA analyzer mode analysis"
	@echo "make clean:      Cleans everything to revert to the beginning of the demo"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)
	@echo ""
	@# With gcc 11 and higher the coverage files have a different name.
	@# Temporarily fixing by changing file name to the expected name
	@if [ $(GCC_VERSION) -ge 11 ]; then \
	mv $(TARGET)-$(TARGET).gcno $(TARGET).gcno; \
	mv $(TARGET)-$(TARGET).gcda $(TARGET).gcda; \
	fi
	gcov $(TARGET).c

cov:
	$(shell if [ -f $(TARGET).gcno ]then; gcov $(TARGET)-$(TARGET).c; else; gcov $(TARGET).c; fi)

tis:
	@echo -e "Running all tests"
	@tis run -f
	@tis report --open

tis-l1:
	@echo -e "Running intepreter tests"
	@tis run -f 1..4
	@tis report --open

tis-l2:
	@echo -e "Running intepreter tests"
	@tis run -f 5
	@tis report --open

clean:
	@echo "Cleaning..."
	@rm -rf $(TARGET) *.gc* compile_commands.json _results *.log tis_report.html tis_misra_report
	@echo "Reverting increment.c to original..."
	@git checkout -q -- increment.c
	
tis-misra:
	tis-misra --title "DEMO" increment.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_misra_report/index.html$(FONT_RESET)\n\n"
