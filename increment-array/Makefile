SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
TARGET := demo-ub
FILES := test_driver.c increment.c logutils.c
COMPILER := gcc
TIS_OPTS := -val-profile interpreter -val -I.

.PHONY: ut ut-LOG_VERBOSE ut-clang ut-long-name clean tis tis_gui

ut:
	@echo -e "$(FONT_CYAN)$(COMPILER) -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-debug:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-clang:
	@echo -e "$(FONT_CYAN)clang -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@clang -Wno-unused-value -DLOG_VERBOSE -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-long-name:
	@echo -e "$(FONT_CYAN)$(COMPILER) -DLOG_VERBOSE -DLONG_NAME -I. $(FILES) -o $(TARGET) && ./$(TARGET)$(FONT_RESET)"
	@$(COMPILER) -Wno-unused-value -DLOG_VERBOSE -DLONG_NAME -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)$(FONT_RESET)"
	$(TIS_ANALYZER) $(TIS_OPTS) $(FILES)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) $(FILES) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui

clean:
	@rm -rf $(TARGET)
