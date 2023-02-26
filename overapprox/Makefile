# tis-examples
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
TARGET := approx
FILES := approx.c
COMPILER := gcc
TIS_OPTS := -val-profile analyzer -val -I.

.PHONY: all clean tis tis-gui

all:
	$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-1:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test1 -slevel 10000 $(FILES)

tis-2:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 $(FILES)

tis-2-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 $(FILES) -gui

tis-3:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 -val-split-return-function approx:full $(FILES)

tis-3-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 -val-split-return-function approx:full $(FILES) -gui

tis-4:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test3 -slevel 10000 $(FILES)

tis-5:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test3 -slevel 10000 -val-split-return-function approx:full $(FILES)

tis-6:
	$(TIS_ANALYZER) $(TIS_OPTS) -main testn -slevel 10000 -val-split-return-function approx:full $(FILES)

clean:
	@rm -rf $(TARGET) compile_commands.json
