SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_MAGENTA := `tput setaf 5`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer++
FILES := test_driver.cpp caesar.cpp
TIS_OPTS := -tis-config-load tis.json -tis-report -cxx-std=c++17
COMPILER := g++
CPPFLAGS := -std=c++17

.PHONY: test cov clean tis_l1 tis_l2 tis_l1_report tis_l2_report tis_l1_gui tis_l2_gui test1 test2 test-int report count_ub count_ub_2

all:
	@echo "make test:          Runs unit tests"
	@echo "make tis-l1:        Runs TISA L1 analysis for positive and negative shift"
	@echo "make tis-l2:        Runs TISA L2 analysis generalization of shift"
	@echo "make tis-l2-step2:  Runs TISA L2 analysis generalization of string"
	@echo "make tis-l2-gui:    Runs TISA L2 analysis with the GUI on the generalization of shift"
	@echo "make clean:         Cleans everything to revert to the beginning of the demo"

test:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar$(FONT_RESET)"
	@$(COMPILER) -I. -fprofile-arcs -ftest-coverage $(FILES) -o caesar && ./caesar
	@echo ""
	@echo -e "$(FONT_CYAN)gcov caesar.cpp $(FONT_RESET)"
	@gcov caesar.cpp | tac | sed "/File 'caesar.cpp'/q" | tac

tis-l1: tis-l1-run count_ub report

tis-l2: tis-l2-run count_ub_2 report

tis-l2-step2: tis-l2-step2-run count_ub_2_step2 report

tis-l2-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TIS_OPTS) -tis-report -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-shift" -D LEVEL2=1 -gui

tis-l2-step2-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) -D LEVEL2=1  $(TIS_OPTS) -tis-report -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.2.generalized-string" -D LEVEL2=1 -gui

tis-l1-run:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.1.positive-shift"
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.2.negative-shift"

tis-l1-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "1.1.positive-shift" -gui | sed '/stack:.*test_driver.cpp/q'

tis-l2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -D LEVEL2=1$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.1.generalized-shift" -D LEVEL2=1

tis-l2-step2-run:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name generalized-string -D LEVEL2=1$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "2.2.generalized-string" -D LEVEL2=1 -D LEVEL2_STEP2=1

report:
	@printf "Compiling report from past executed tests:\n"
	@ls _results/*.json | sed 's/_results\.json//'
	@tis-report _results/ --skip-file test_driver.cpp
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

break-build:
	@! cat _results/*_results.json|jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'

clean:
	@rm -rf a.out a.out.dSYM caesar caesar.dSYM *.gcov *.gcda *.gcno _results tis_report.html

count_ub:
	@echo "==============================================="
	@echo "      " `./count_ub.sh _results/1.*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_2:
	@echo "==============================================="
	@echo "      " `./count_ub.sh _results/2.1*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="

count_ub_2_step2:
	@echo "==============================================="
	@echo "      " `./count_ub.sh _results/2.2*_results.json` UNDEFINED BEHAVIORS FOUND
	@echo "==============================================="
