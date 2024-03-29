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

.PHONY: gen

help-specific:
	@echo "make gen            : Automatically generates TrustInSoft Analysis drivers from ARXML"
	@echo "make tis            : Automatically runs analysis drivers generated by 'make gen'"

gen:
	@echo -e "$(FONT_CYAN)tis-autosar-mockup --arxml test.arxml \\"
	@echo -e "   --rte-header AP_Hello_World/Rte_AP_Hello_World.h \\"
	@echo -e "   --output-dir .trustinsoft \\"
	@echo -e "   -- -Irte_runtime -IAP_Hello_World$(FONT_RESET)"
	@tis-autosar-mockup --arxml test.arxml \
	--rte-header AP_Hello_World/Rte_AP_Hello_World.h \
	--output-dir .trustinsoft \
	-- -Irte_runtime -IAP_Hello_World 

run_all:
	@echo -e "$(FONT_CYAN)run_all.sh -c .trustinsoft/generated_config.json$(FONT_RESET)"
	@../tools/run_all.sh -n 8 -c .trustinsoft/generated_config.json

tis: run_all report

report:
	@echo "Compiling report from" `ls $(RESULTS_DIR)/AP*.json | wc -l` "past executed tests"
	@echo -e "$(FONT_CYAN)$(TIS_REPORT) $(RESULTS_DIR)/ --skip-file rte_mocks.c$(FONT_RESET)"
	@$(TIS_REPORT) $(RESULTS_DIR)/ --skip-file rte_mocks.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

clean: clean-generic
	@echo "Cleaning: Removing all automatically generated files except .trustinsoft/permanent_config.json"
	@rm -rf $(CONFIG_DIR)/[^p]* $(RESULTS_DIR)/ $(LOGS_DIR)/ $(SAVE_DIR)/ tis_report.html
