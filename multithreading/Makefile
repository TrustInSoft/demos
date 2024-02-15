
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

TARGET := two_threads
FILES := $(TARGET).c
COMPILER := gcc

.PHONY: all tis clean

help-specific:
	@echo "make tis-v1         : Run multithread analysis on code v1"
	@echo "make tis-v2         : Run multithread analysis on code v2"
	@echo "make tis-v3         : Run multithread analysis on code v3"

tis-v1 :
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads.c$(FONT_RESET)"
	@$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads.c | sed -E \
	   -e "s/(Iteration [0-9]+)/$(FONT_CYAN)\1$(FONT_RESET)/g" \
	   -E -e "s/(.*)(unprotected).*/\1$(FONT_RED)\2$(FONT_RESET)/g" \
		-E -e "s/.*(data races|read by|write by).*/$(FONT_YELLOW)\0$(FONT_RESET)/g"

tis-v2 :
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads_v2.c$(FONT_RESET)"
	@$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads_v2.c | sed -E \
	   -e "s/(Iteration [0-9]+)/$(FONT_CYAN)\1$(FONT_RESET)/g" \
	   -E -e "s/(.*)(unprotected).*/\1$(FONT_RED)\2$(FONT_RESET)/g" \
		-E -e "s/.*(data races|read by|write by).*/$(FONT_YELLOW)\0$(FONT_RESET)/g"

tis-v3 :
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads_v3.c$(FONT_RESET)"
	@$(TIS_ANALYZER) -val -mthread -slevel 1000 two_threads_v3.c | sed -E \
	   -e "s/(Iteration [0-9]+)/$(FONT_CYAN)\1$(FONT_RESET)/g" \
	   -E -e "s/(.*)(unprotected).*/\1$(FONT_RED)\2$(FONT_RESET)/g" \
		-E -e "s/.*(data races|read by|write by).*/$(FONT_YELLOW)\0$(FONT_RESET)/g"

clean: clean-generic
	@rm -rf *~ output.txt $(TARGET)

report: report-generic
