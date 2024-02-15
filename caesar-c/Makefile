
# trustinsoft/demos
# Copyright (C) 2022-2024 TrustInSoft
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

FILES := test_driver.c caesar.c
TIS_OPTS = $(TIS_OPTS_SHORT) -tis-report

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis-l1-gui tis-l2-gui test1 test2 test-int report

help-specific:
	@echo "make test           : Runs unit tests"
	@echo "make tis-l1         : Runs TISA L1 analysis for positive and negative shift"
	@echo "make tis-l2         : Runs TISA L2 analysis generalization of shift"
	@echo "make tis-l2-step2   : Runs TISA L2 analysis generalization of string"
	@echo "make tis-l2-gui     : Runs TISA L2 analysis with the GUI on the generalization of shift"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN)gcov caesar.c $(FONT_RESET)"
	@gcov caesar.c

tis-l1-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.positive-shift" | grep -v '\[info\]'
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.negative-shift" | grep -v '\[info\]'
	@echo "==============================================="
	@echo "      " `../tools/count-ub.sh _results/[12].*-shift_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

tis-l1: tis-l1-run report

tis-l2: tis-l2-run report

tis-l2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -D LEVEL2$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -D LEVEL2 -tis-config-select-by-name "3.generalized-shift" | grep -v '\[info\]'
	@echo "==============================================="
	@echo "      " `../tools/count-ub.sh _results/3.generalized-shift_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

tis-l2-step2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -D LEVEL2 -D LEVEL2_STEP2$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -D LEVEL2 -D LEVEL2_STEP2 -tis-config-select-by-name "4.generalized-string" | grep -v '\[info\]'
	@echo "==============================================="
	@echo "      " `../tools/count-ub.sh _results/4.generalized-string_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

tis-l2-step2: tis-l2-step2-run report

tis-l1-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui # -tis-config-select-by-name main -gui | sed '/stack:.*test_driver.c/q'

tis-l2-gui: tis-l2-run report
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER)  $(TIS_OPTS) -gui -D LEVEL2$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui -D LEVEL2 -tis-config-select-by-name "3.generalized-shift"

tis-l2-step2-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name 4.generalized-string -D LEVEL2=1 -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui -D LEVEL2 -D LEVEL2_STEP2 -tis-config-select-by-name "4.generalized-string" 

report: report-generic

break_build:
	@! cat _results/*_results.json|jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'

clean: clean-generic
	@rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log compile_commands.json
