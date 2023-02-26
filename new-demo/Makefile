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

TIS_ANALYZER := tis-analyzer
TARGET := increment
FILES := test_driver.c utils.c $(TARGET).c
COMPILER := gcc
TIS_OPTS := -tis-config-load trustinsoft/tis.json -tis-report

.PHONY: all test tis-l1  tis-l1-gui tis-l1-run tis-l1-run-gui tis-l2 tis-l2-gui tis-l2-run tis-l2-run-gui report


all:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)
	@echo ""
	@echo -e "$(FONT_CYAN)gcov $(TARGET).c $(FONT_RESET)"
	@gcov $(TARGET).c

tis-l1-1:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.1.small-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.1.small-array"

tis-l1-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.1.small-array" -gui

tis-l1-2:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.2.large-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.2.large-array"

tis-l1-3:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.3.zero-length-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.3.zero-length-array"

tis-l1-4:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.4.null-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.4.null-array"

count_ub:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/1.*-array_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_2:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/2.*-array_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

tis-l2-1:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-small-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-small-array"

tis-l2-2:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.2.generalized-large-array"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.2.generalized-large-array"

tis-l2-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-small-array" -gui

clean:
	@rm -rf $(TARGET) *.gc* compile_commands.json _results *.log tis_report.html

#tis-l1: tis-l1-1 tis-l1-2 count_ub report
tis-l1: tis-l1-2 tis-l1-3 tis-l1-4 tis-l1-1 count_ub report

tis-l2: tis-l2-1 tis-l2-2 count_ub_2 report

report:
	@echo "Compiling report from" `ls _results/*.json | wc -l` "past executed tests"
	@tis-report _results/ --skip-file test_driver.c,utils.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
