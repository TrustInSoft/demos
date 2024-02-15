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

help: help-specific help-gen

include ../tools/common.mk

FILES := test_driver.c boundary.c
TIS_OPTS := -val-profile analyzer -val -I.

help-specific:
	@echo "make tis            : Runs TISA in CLI mode"
	@echo "make tis-gui        : Runs TISA in GUI modde"

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui

clean: clean-generic 