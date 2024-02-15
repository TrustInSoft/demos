# trustinsoft/demos
# Copyright (C) 2022-2024 TrustInSoft
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

help: help-specific help-generic

include ../tools/common.mk

TARGET := demo-ub
FILES := test_driver.c increment.c logutils.c
TIS_OPTS := $(TIS_OPTS_SHORT) -val-profile interpreter -val -I. -tis-report

.PHONY: ut ut-gcc ut-clang ut-gcc-tis clean tis tis_gui

help-specific:
	@echo "make gcc            : Run code and tests compiled with gcc"
	@echo "make gcc-verbose    : Run code and tests compiled with gcc and verbose logs"
	@echo "make clang          : Run code and tests compiled with clang and verbose logs"
	@echo "make gcc-long       : Run code and tests compiled with gcc and a longer string"
	@echo "make tis            : Run code with TrustInSoft Analyzer L1"

gcc:
	@echo -e "$(FONT_CYAN)gcc -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@gcc -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

gcc-verbose:
	@echo -e "$(FONT_CYAN)gcc -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@gcc -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

clang:
	@echo -e "$(FONT_CYAN)clang -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@clang -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

gcc-long:
	@echo -e "$(FONT_CYAN)gcc -DLOG_VERBOSE -DNAME=\"TrustInSoft\" -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@gcc -Wno-unused-value -DLOG_VERBOSE -DNAME=\"TrustInSoft\" -I. $(FILES) -o $(TARGET) && ./$(TARGET)

run-tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS)

tis: run-tis count-ub

count-ub: count-ub-generic

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

report: report-generic

clean: clean-generic
