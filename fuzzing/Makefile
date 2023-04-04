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
TARGET := calc
FILES := test_driver.c boundary.c
SEEDS := seeds
TIS_OPTS := -val-profile analyzer -val -I.
CC := "/usr/bin/afl-gcc"

.PHONY: ut clean tis tis_gui

ut:
	@echo -e "$(FONT_CYAN)$(CC) -I. $(FILES) -o $(TARGET)$(FONT_RESET)"
	@$(CC) $(FILES) -o $(TARGET)

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui

tis-fuzz:
	tis-fuzz --tis-config trustinsoft/tis.json -i afl-results -o tis-fuzz-results --mkfs work/real_input.txt

clean:
	@rm -f $(SEEDS)/*smart*
	@rm -rf $(TARGET)* *.gc* compile_commands.json afl-results tis-fuzz-results

afl: afl-easy-semi-smart

afl-easy: afl-easy-smart

afl-medium: afl-medium-semi-smart

afl-hard: afl-hard-semi-smart

afl-easy-smart:
	/usr/bin/afl-gcc -DEASY $(FILES) -o $(TARGET)-easy-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-smart @@

afl-medium-smart:
	/usr/bin/afl-gcc -DMEDIUM $(FILES) -o $(TARGET)-medium-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-smart @@

afl-hard-smart:
	/usr/bin/afl-gcc -DHARD $(FILES) -o $(TARGET)-hard-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-smart @@

afl-easy-semi-smart:
	/usr/bin/afl-gcc -DEASY $(FILES) -o $(TARGET)-easy-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-semi-smart @@

afl-medium-semi-smart:
	/usr/bin/afl-gcc -DMEDIUM $(FILES) -o $(TARGET)-medium-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-semi-smart @@

afl-hard-semi-smart:
	/usr/bin/afl-gcc -DHARD $(FILES) -o $(TARGET)-hard-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-semi-smart @@

test-seeds:
	gcc $(FILES) -o $(TARGET)
	./run_test.sh
