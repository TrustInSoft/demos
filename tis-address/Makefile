# trustinsoft/demos
# Copyright (C) 2024 TrustInSoft
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

TIS_OPTS := $(TIS_OPTS_SHORT) -tis-report

help-specific:
	@echo "make tis            : Runs the 2 TISA memory mapping examples without tis_address"
	@echo "make tis-address    : Runs the 2 TISA memory mapping examples with tis_address directive"
	@echo "make tis-init       : Runs the TISA 'init' memory mapping example with the GUI"
	@echo "make tis-reg        : Runs the TISA 'get_registers' memory mapping example with the GUI"

tis-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "1.init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.init"
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "2.get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.get_registers"

tis: tis-run report count-ub

tis-address-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "1.init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.init" -DWITH_TIS_ADDRESS
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "2.get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.get_registers" -DWITH_TIS_ADDRESS

tis-address: tis-address-run report count-ub

tis-init:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "init" -gui

tis-reg:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "get_registers" -DWITH_TIS_ADDRESS -gui

count-ub: count-ub-generic
