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

TARGET := demo
FILES := $(TARGET).c
OBJS := $(TARGET).o
TIS_OPTS := $(TIS_OPTS_SHORT) -tis-report

.PHONY: cunit tis-l1 tis-l1-gui 

help-specific:
	@echo "make prepare        : Prepares the environment (install cunit binaries and sources)"
	@echo "make cunit          : Runs CUnit functional tests"
	@echo "make tis-l1         : Runs TISA L1 analysis"
	@echo "make tis-l1-gui     : Runs TISA L1 analysis with the GUI"

cunit:
	@echo -e "$(FONT_CYAN)$(COMPILER) $(FILES) -o $(TARGET) -lcunit && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-overflow $(FILES) -o $(TARGET) -lcunit && ./$(TARGET)

tis-l1-1:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1

tis-l1-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select 1 -gui

count-ub: count-ub-generic

clean: clean-generic

tis-l1: tis-l1-1 count-ub report

prepare:
	@echo "Installing cunit"
	sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
	@echo "Retrieving cunit sources"
	sudo apt install subversion
	svn checkout https://svn.code.sf.net/p/cunit/code/trunk cunit
	cp cunit/CUnit/Headers/CUnit.h.in cunit/CUnit/Headers/CUnit.h

report:
	@echo "Compiling report from" `ls $(RESULTS_DIR)/*.json | wc -l` "past executed tests"
	@tis-report $(RESULTS_DIR) --skip-file cunit/TestRun.c,TestRun.c,Automated.c,Basic.c,TestDB.c,CUError.c,Curses.c,Console.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
