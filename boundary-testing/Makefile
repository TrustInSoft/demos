# tis-examples
# Copyright (C) 2022 TrustInSoft
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

TIS_ANALYZER := tis-analyzer
TARGET := boundary-test
FILES := test_driver.c boundary.c
COMPILER := gcc
TIS_OPTS := -val-profile analyzer -val -I.

.PHONY: ut clean tis tis_gui

ut:
	$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o $(TARGET) && ./$(TARGET)
	gcov boundary.c

tis:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui

clean:
	@rm -rf $(TARGET) *.gc* compile_commands.json
