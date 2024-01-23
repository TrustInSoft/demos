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

CONFIG_DIR := .trustinsoft
CONFIG_FILE := $(CONFIG_DIR)/config.json
TIS_ANALYZER := tis-analyzer
TIS_REPORT := tis-report

# Don't change the below
RESULTS_DIR := $(CONFIG_DIR)/results
LOGS_DIR := $(CONFIG_DIR)/logs
SAVE_DIR := $(CONFIG_DIR)/save

SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

CONFIG_FILE := .trustinsoft/config.json
TIS_OPTS_SHORT := -tis-config-load $(CONFIG_FILE) 
TIS_OPTS := $(TIS_OPTS_SHORT) -tis-report-directory $(RESULTS_DIR) -tis-report

.PHONY: all tis

all:
	@echo "make tis:        Runs the 2 TISA memory mapping examples without tis_address"
	@echo "make tis-address:Runs the 2 TISA memory mapping examples with tis_address directive"
	@echo "make tis-init:   Runs the TISA 'init' memory mapping example with the GUI"
	@echo "make tis-reg:    Runs the TISA 'get_registers' memory mapping example with the GUI"
	@echo "make clean:      Cleans everything to revert to the beginning of the demo"

tis-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "init"
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "get_registers"

tis: tis-run report

tis-address-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "init" -DWITH_TIS_ADDRESS
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "get_registers" -DWITH_TIS_ADDRESS

tis-address: tis-address-run report

tis-init:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "init"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "init" -gui

tis-reg:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) -tis-config-select-by-name "get_registers"$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "get_registers" -DWITH_TIS_ADDRESS -gui

count_ub:
	@echo "==============================================="
	@echo "      " `../tools/count_ub.sh $(RESULTS_DIR)/*.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

clean:
	@echo "Cleaning..."
	rm -rf $(RESULTS_DIR)/ $(LOGS_DIR)/ $(SAVE_DIR)/ tis_report.html tis_misra_report

report:
	@echo "Compiling report from" `ls $(RESULTS_DIR)/*.json | wc -l` "past executed tests"
	@$(TIS_REPORT) $(RESULTS_DIR)/ --skip-file test_driver.c,utils.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
