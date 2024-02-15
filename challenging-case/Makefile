# trustinsoft/demos
# Copyright (C) 2023-2024 TrustInSoft
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

help: help-specific help-gen

include ../tools/common.mk



TIS_ANALYZER := tis-analyzer
TIS_REPORT := tis-report

TARGET := indexgen
FILES := test_driver.c indexgen.c
COMPILER := gcc
TIS_OPTS := -tis-config-load .trustinsoft/config.json -tis-report

.PHONY: clean test tis-l1 tis-l2

help-specific:
	@echo "make test           : Runs unit tests"
	@echo "make tis-l1         : Runs TISA L1 analysis"
	@echo "make tis-l2         : Runs TISA L2 analysis"
	@echo "make tis-l1-gui     : Runs TISA L1 analysis with the GUI"

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

tis-l1: tis-l1-run count-ub-1 report

tis-l2: tis-l2-run count-ub-2 report

tis-l1-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1

tis-l1-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1 -gui

tis-l2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 2$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 2

count-ub-1: count-ub-1-generic

count-ub-2: count-ub-2-generic

report: report-generic

clean: clean-generic
