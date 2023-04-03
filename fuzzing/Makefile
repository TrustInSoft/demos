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

clean:
	@rm -f $(SEEDS)/*aided*
	@rm -rf $(TARGET)* *.gc* compile_commands.json afl-results

afl: afl-medium

afl-easy:
	/usr/bin/afl-gcc -DEASY $(FILES) -o $(TARGET)-easy
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy @@

afl-medium:
	/usr/bin/afl-gcc -DMEDIUM $(FILES) -o $(TARGET)-medium
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium @@

afl-hard:
	/usr/bin/afl-gcc -DHARD $(FILES) -o $(TARGET)-hard
	cp $(SEEDS)-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard @@

afl-easy-aided:
	/usr/bin/afl-gcc -DEASY $(FILES) -o $(TARGET)-easy-aided
	cp $(SEEDS)-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-aided @@

afl-medium-aided:
	/usr/bin/afl-gcc -DMEDIUM $(FILES) -o $(TARGET)-medium-aided
	cp $(SEEDS)-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-aided @@

afl-hard-aided:
	/usr/bin/afl-gcc -DHARD $(FILES) -o $(TARGET)-hard-aided
	cp $(SEEDS)-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-aided @@

afl-easy-semi-aided:
	/usr/bin/afl-gcc -DEASY $(FILES) -o $(TARGET)-easy-semi-aided
	cp $(SEEDS)-semi-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-semi-aided @@

afl-medium-semi-aided:
	/usr/bin/afl-gcc -DMEDIUM $(FILES) -o $(TARGET)-medium-semi-aided
	cp $(SEEDS)-semi-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-semi-aided @@

afl-hard-semi-aided:
	/usr/bin/afl-gcc -DHARD $(FILES) -o $(TARGET)-hard-semi-aided
	cp $(SEEDS)-semi-aided/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-semi-aided @@

test-seeds:
	gcc $(FILES) -o $(TARGET)
	./run_test.sh
