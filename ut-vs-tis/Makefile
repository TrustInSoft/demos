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

TARGET := demo-ub
FILES := test_driver.c increment.c logutils.c
TIS_OPTS = -val-profile interpreter -val -main test_increment_array -I.

help-specific:
	@echo "make ut             : Runs unit test with code compiled with gcc"
	@echo "make ut-debug       : Runs unit test with code compiled with gcc and extra logging"
	@echo "make ut-long-name   : Runs unit test with code compiled with gcc and longer name variable"
	@echo "make ut-clang       : Runs unit test with code compiled with clang"
	@echo "make tis            : Runs TIS L1 analysis in CLI mode"
	@echo "make tis-gui        : Runs TIS L1 analysis in GUI mode"

ut:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-debug:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DDEBUG -I. $(FILES) -o $(TARGET).gcc && ./$(TARGET).gcc$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DDEBUG -I. $(FILES) -o $(TARGET).gcc && ./$(TARGET).gcc

ut-clang:
	@echo -e "$(FONT_CYAN)clang -DDEBUG -I. $(FILES) -o $(TARGET).clang && ./$(TARGET).clang$(FONT_RESET)"
	@clang -Wno-unused-value -DDEBUG -I. $(FILES) -o $(TARGET).clang && ./$(TARGET).clang

ut-long-name:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DDEBUG -DLONG_NAME -I. $(FILES) -o $(TARGET).longname && ./$(TARGET).longname$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DDEBUG -DLONG_NAME -I. $(FILES) -o $(TARGET).longname && ./$(TARGET).longname

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)$(FONT_RESET)"
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

clean: clean-generic
