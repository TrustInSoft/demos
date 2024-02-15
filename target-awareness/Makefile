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

help: help-specific help-generic

include ../tools/common.mk

TARGET := target
FILES := $(TARGET).c
TIS_OPTS_X64 := -tis-config-load trustinsoft/tis-x64.json -tis-report
TIS_OPTS_ARM32 := -tis-config-load trustinsoft/tis-arm32.json -tis-report

.PHONY: all test report

help-specific:
	@echo "make test           : Runs compiled unit test on host (64 bits little endian)"
	@echo "make tis-x64        : Runs TIS with x86_64 target (64 bits little endian) configured"
	@echo "meak tis-arm32      : Runs TIS with ARM32 target (32 bits big endian) configured"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis-x64: tis-long-x64 tis-endianness-x64 count-ub report report-x64

tis-arm32: tis-long-arm32 tis-endianness-arm32 count-ub report report-arm32

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

count-ub:
	@echo "==============================================="
	@echo "      " `trustinsoft/count-ub.sh _results/*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count-ub-1:
	@echo "==============================================="
	@echo "      " `trustinsoft/count-ub.sh _results/1.double-that_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count-ub-2:
	@echo "==============================================="
	@echo "      " `trustinsoft/count-ub.sh _results/2.msb_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

clean: clean-generic

report: report-generic

report-arm32:
	@mv tis_report.html tis_report.arm32.html
	@printf "\nCheck generated analysis report $(FONT_CYAN)tis_report.arm32.html$(FONT_RESET)\n\n"
	
report-x64:
	@mv tis_report.html tis_report.x64.html
	@printf "\nCheck generated analysis report $(FONT_CYAN)tis_report.x64.html$(FONT_RESET)\n\n"
