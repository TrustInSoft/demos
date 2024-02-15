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

TARGET := approx
FILES := approx.c
TIS_OPTS := -val-profile analyzer -val -I.

.PHONY: all clean tis tis-gui

help-specific:
	@echo "make tis            : Runs all analyses with default slevel 0"
	@echo "make tis-1          : Runs analysis #1 with slevel 10000"
	@echo "make tis-2          : Runs analysis #2 with slevel 10000"
	@echo "make tis-3s         : Runs analysis #3 with val-split-return full"
	@echo "and more... see makefile"	

build:
	$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui

tis-1:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test1 -slevel 10000 $(FILES)

tis-2:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 $(FILES)

tis-2-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2 -slevel 10000 $(FILES) -gui

tis-2s-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test2split -slevel 10000 $(FILES) -gui

tis-3s:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test3split -slevel 10000 -val-split-return-function approx:full $(FILES)

tis-3s-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test3split -slevel 10000 -val-split-return-function approx:full $(FILES) -gui

tis-4s:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test4split -slevel 10000 $(FILES)

tis-4s-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test4split -slevel 50000 $(FILES) -gui

tis-5s:
	$(TIS_ANALYZER) $(TIS_OPTS) -main test3 -slevel 10000 -val-split-return-function approx:full $(FILES)

tis-6:
	$(TIS_ANALYZER) $(TIS_OPTS) -main testn -slevel 10000 -val-split-return-function approx:full $(FILES)

clean: clean-generic

report: prepare-generic report-generic
