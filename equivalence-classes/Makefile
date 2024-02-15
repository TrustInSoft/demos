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

help: help-specific help-generic

include ../tools/common.mk

TARGET := equivalence-classes
OBJS := $(TARGET).o
FILES := $(TARGET).c
TIS_OPTS := $(TIS_OPTS_SHORT)

help-specific:
	@echo "make test           : Runs classic equivalence test scenario"
	@echo "make tis            : Runs the TIS equivalence classes demo in cmd line"
	@echo "make tis-gui        : Runs the equivalence classes demo in GUI"
	@echo "make clean          : Cleanup and reset demo"

prepare:
	@mkdir -p $(CONFIG_DIR) $(LOGS_DIR)

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)


tis-cli: prepare
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) | tee $(LOGS_DIR)/tis.log

tis-gui: prepare
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FONT_RESET)"
	$(TIS_ANALYZER) $(TIS_OPTS) -gui

tis: tis-cli check_assertions

check_assertions:
	@echo "==============================================="
	@echo "      " `../tools/check_assertions.sh count $(LOGS_DIR)/tis.log` failed or unproven assertion\(s\)
	@echo "$(FONT_RED)"`../tools/check_assertions.sh warnings $(LOGS_DIR)/tis.log` "$(FONT_RESET)"
	@echo "==============================================="

clean: clean-generic

report: report-generic
