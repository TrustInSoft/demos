# trustinsoft/demos
# Copyright (C) 2024 TrustInSoft
# mailto:contact AT trust-in-soft DOT com
# 

TIS_ANALYZER := tis-analyzer
SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`
TIS_OPTS_SHORT := -val -slevel 10
TIS_OPTS := $(TIS_OPTS_SHORT) 

.PHONY: all tis clean

all:
	@echo "make tis:        Runs TISA L2 analysis with dataflow analysis"
	@echo "make clean:      Cleans everything to revert to the beginning of the demo"

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS_SHORT) vm.c -gui $(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) vm.c -gui

clean:
	@echo "Cleaning..."
	rm -rf *.gc* *~
