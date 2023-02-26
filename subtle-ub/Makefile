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
TARGET := demo-ub
FILES := test_driver.c increment.c logutils.c
COMPILER := gcc
TIS_OPTS := -val-profile interpreter -val -I.

.PHONY: ut ut-gcc ut-clang ut-gcc-tis clean tis tis_gui

ut:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-gcc:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-clang:
	@echo -e "$(FONT_CYAN)clang -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@clang -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-gcc-long:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DLOG_VERBOSE -DNAME=\"TrustInSoft\" -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DLOG_VERBOSE -DNAME=\"TrustInSoft\" -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)$(FONT_RESET)"
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

clean:
	@rm -rf $(TARGET) compile_commands.json
