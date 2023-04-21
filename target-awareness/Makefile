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
TARGET := target
FILES := $(TARGET).c
COMPILER := gcc
TIS_OPTS_X64 := -tis-config-load trustinsoft/tis-x64.json -tis-report
TIS_OPTS_ARM32 := -tis-config-load trustinsoft/tis-arm32.json -tis-report

.PHONY: all test report

make: all
	@echo "Options: make test | tis-x64 | tis-arm32 | clean"
	@echo "test:      Runs compiled unit test on host (64 bits little endian)"
	@echo "tis-x64:   Runs TIS with x86_64 target (64 bits little endian) configured"
	@echo "tis-arm32: Runs TIS with ARM32 target (32 bits big endian) configured"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis-x64: tis-long-x64 tis-endianness-x64 count_ub report report-x64

tis-arm32: tis-long-arm32 tis-endianness-arm32 count_ub report report-arm32

tis-long-x64:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "1.double-that"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "1.double-that"

tis-long-x64-gui:
	$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "1.double-that" -gui

tis-endianness-x64:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "2.msb"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "2.msb"

tis-endianness-x64-gui:
	@$(TIS_ANALYZER) $(TIS_OPTS_X64) -tis-config-select-by-name "2.msb" -gui

tis-long-arm32:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "1.double-that"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "1.double-that"

tis-long-arm32-gui:
	$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "1.double-that" -gui

tis-endianness-arm32:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "2.msb"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "2.msb"

tis-endianness-arm32-gui:
	@$(TIS_ANALYZER) $(TIS_OPTS_ARM32) -tis-config-select-by-name "2.msb" -gui

count_ub:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_1:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/1.double-that_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_2:
	@echo "==============================================="
	@echo "      " `trustinsoft/count_ub.sh _results/2.msb_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

clean:
	@rm -rf $(TARGET) *.gc* compile_commands.json _results *.log tis_report.html tis_misra_report


report:
	@echo "Compiling report from" `ls _results/*.json | wc -l` "past executed tests"
	@tis-report _results/ --skip-file test_driver.c,utils.c

report-arm32:
	@mv tis_report.html tis_report.arm32.html
	@printf "\nCheck generated analysis report $(FONT_CYAN)tis_report.arm32.html$(FONT_RESET)\n\n"
	
report-x64:
	@mv tis_report.html tis_report.x64.html
	@printf "\nCheck generated analysis report $(FONT_CYAN)tis_report.x64.html$(FONT_RESET)\n\n"

tis-misra:
	tis-misra --title "DEMO" increment.c
	@printf "\nCheck generated analysis report $(FONT_CYAN)tis_misra_report/index.html$(FONT_RESET)\n\n"
