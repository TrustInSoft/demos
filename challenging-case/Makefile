# trustinsoft/demos
# Copyright (C) 2023 TrustInSoft
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
TIS_REPORT := tis-report

TARGET := indexgen
FILES := test_driver.c indexgen.c
COMPILER := gcc
TIS_OPTS := -tis-config-load .trustinsoft/config.json -tis-report

.PHONY: clean test tis-l1 tis-l2

all:
	@echo "make test:       Runs unit tests"
	@echo "make tis-l1:     Runs TISA L1 analysis"
	@echo "make tis-l2:     Runs TISA L2 analysis"
	@echo "make tis-l1-gui: Runs TISA L1 analysis with the GUI"
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

tis-l1: tis-l1-run count-l1-ub report

tis-l2: tis-l2-run count-l2-ub report

tis-l1-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1

tis-l1-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1 -gui

tis-l2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 2$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 2

clean:
	@rm -rf $(TARGET) *.gc* compile_commands.json _results

count-l1-ub:
	@echo "==============================================="
	@echo "      " `.trustinsoft/count_ub.sh _results/*test*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count-l2-ub:
	@echo "==============================================="
	@echo "      " `.trustinsoft/count_ub.sh _results/*generalized*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

report:
	@echo "Compiling report from" `ls _results/*.json | wc -l` "past executed tests"
	@$(TIS_REPORT) _results/ --skip-file test_driver.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
