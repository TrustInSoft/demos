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
GCC_VERSION := $(shell g++ --version | head -n 1 | cut -d ' ' -f 4 | cut -d '.' -f 1)

TIS_ANALYZER := tis-analyzer
TARGET := increment
FILES := test_driver.cpp $(TARGET).cpp
OBJS := test_driver.o $(TARGET).o
COMPILER := g++
TIS_OPTS := -cxx-std c++17 -tis-config-load trustinsoft/tis.json -tis-report

.PHONY: all test tis-l1  tis-l1-gui tis-l1-run tis-l1-run-gui tis-l2 tis-l2-gui tis-l2-run tis-l2-run-gui report


all:
	@echo "make test:       Runs unit tests"
	@echo "make tis-l1:     Runs TISA L1 analysis"
	@echo "make tis-l2:     Runs TISA L2 analysis"
	@echo "make tis-l1-gui: Runs TISA L1 analysis with the GUI"
	@echo "make tis-l2-gui: Runs TISA L2 analysis with the GUI"
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
	gcov $(TARGET).cpp

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

tis-l1-all:
	trustinsoft/run_all.sh -n 4 -a "3 2 4 5"

count_ub:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/1.*-array_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_2:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/2.*-array_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

tis-l2-cli:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-small-array"$(FONT_RESET)"
	@trustinsoft/run_all.sh -n 1 -a 6

tis-l2-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.generalized-array" -gui

clean: clean-results clean-cache

clean-results:
	@echo "Cleaning results..."
	@rm -rf $(TARGET) *.gc* compile_commands.json _results/*.csv _results/*.json *.log trustinsoft/*.log tis_report.html tis_misra_report
	@echo "Reverting increment.hpp to original..."
	@git checkout -q -- increment.hpp

clean-cache:
	@echo "Cleaning analysis cache..."
	@rm -rf $(TARGET) _results/*.save

tis-l1: tis-l1-all count_ub report

tis-l2: tis-l2-cli count_ub_2 report

report:
	@echo "Compiling report from" `ls _results/*.json | wc -l` "past executed tests"
# @tis-report _results/ --skip-file test_driver.cpp _ZN18IncrementableArrayIiE8toStringEv
	@tis-report _results/ --skip-file test_driver.cpp
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
	@wslview tis_report.html

tis-misra:
	tis-misra --title "DEMO" increment.hpp
	@printf "\nCheck generated test report $(FONT_CYAN)tis_misra_report/index.html$(FONT_RESET)\n\n"
	@wslview tis_misra_report/index.html