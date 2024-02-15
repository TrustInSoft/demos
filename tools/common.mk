
CONFIG_DIR := .trustinsoft
CONFIG_FILE := $(CONFIG_DIR)/config.json
TIS_OPTS_SHORT := -tis-config-load $(CONFIG_FILE)
TIS_ANALYZER := tis-analyzer
TIS_REPORT := tis-report
TIS_MISRA := tis-misra

# Don't change the below
RESULTS_DIR := $(CONFIG_DIR)/results
LOGS_DIR := $(CONFIG_DIR)/logs
SAVE_DIR := $(CONFIG_DIR)/save

SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_BLACK := `tput setaf 0`
FONT_RED := `tput setaf 1`
FONT_GREEN := `tput setaf 2`
FONT_YELLOW := `tput setaf 3`
FONT_BLUE := `tput setaf 4`
FONT_MAGENTA := `tput setaf 5`
FONT_CYAN := `tput setaf 6`
FONT_WHITE := `tput setaf 7`
FONT_RESET := `tput sgr0`
FONT_UNDERLINE := `tput sgr 0 1`

GCC_VERSION := $(shell gcc --version | head -n 1 | cut -d ' ' -f 4 | cut -d '.' -f 1)

.PHONY: tis gui tis-l1 tis-l2 test help-generic help-specific clean count_ub count_ub_2

help-generic:
	@echo "-- Generic options -------------------------------------"
	@echo "make misra     : Runs tis-misra to generate MISRA report"
	@echo "make report    : Runs tis-report to generate tis_report.html from past executed analyses"
	@echo "make clean     : Cleans everything and reverts to initial demo state"

tis-misra:
	@echo $(FONT_CYAN)$(TIS_MISRA) --title "DEMO" .$(FONT_RESET)
	@$(TIS_MISRA) --title "DEMO" .
	@printf "\nCheck generated test report $(FONT_CYAN)tis_misra_report/index.html$(FONT_RESET)\n\n"

misra: tis-misra

report:
	@echo "Compiling report from" `ls $(RESULTS_DIR)/*.json | wc -l` "past executed tests"
	@$(TIS_REPORT) $(RESULTS_DIR)/ --skip-file test_driver.c,utils.c,$(CONFIG_DIR)/tis_model.c
	@printf "\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"
