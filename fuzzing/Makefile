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

help: help-specific help-generic

include ../tools/common.mk

TARGET := calc
FILES := test_driver.c boundary.c
SEEDS := seeds
TIS_OPTS := -val-profile analyzer -val -I.
COMPILER := "/usr/bin/afl-gcc"

MAX_EXECUTIONS := 50000

.PHONY: tis-fuzz afl afl-easy afl-medium afl-hard afl-easy-smart afl-easy-semi-smart afl-medium-smart afl-medium-semi-smart afl-hard-smart afl-hard-semi-smart

help-specific:
	@echo "make afl            : Runs AFL to produce inputs for tis-fuzz"
	@echo "make tis-fuzz       : Runs tis-fuzz"

tis-fuzz:
	mkdir -p work/
	mkdir -p tis-fuzz-results/
# The below is a workaround to generate AST
	chmod a+w work tis-fuzz-results
	rm -f work/real_input.txt
	ln -sr seeds/seed1.txt work/real_input.txt
	$(TIS_ANALYZER) -tis-config-load trustinsoft/tis.json -save tis-fuzz-results/ast.state
	rm work/real_input.txt
# end of workaround
	tis-fuzz --ast tis-fuzz-results/ast.state --tis-config trustinsoft/tis.json -i afl-results/ -o tis-fuzz-results --mkfs work/real_input.txt --no-parallel

afl: afl-easy-semi-smart

afl-easy: afl-easy-smart

afl-medium: afl-medium-semi-smart

afl-hard: afl-hard-semi-smart

afl-easy-smart:
	$(COMPILER) -DEASY $(FILES) -o $(TARGET)-easy-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -E $(MAX_EXECUTIONS) -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-smart @@

afl-medium-smart:
	$(COMPILER) -DMEDIUM $(FILES) -o $(TARGET)-medium-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-smart @@

afl-hard-smart:
	$(COMPILER) -DHARD $(FILES) -o $(TARGET)-hard-smart
	cp $(SEEDS)-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-smart @@

afl-easy-semi-smart:
	$(COMPILER) -DEASY $(FILES) -o $(TARGET)-easy-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -E $(MAX_EXECUTIONS) -i $(SEEDS) -o afl-results -- ./$(TARGET)-easy-semi-smart @@

afl-medium-semi-smart:
	$(COMPILER) -DMEDIUM $(FILES) -o $(TARGET)-medium-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-medium-semi-smart @@

afl-hard-semi-smart:
	$(COMPILER) -DHARD $(FILES) -o $(TARGET)-hard-semi-smart
	cp $(SEEDS)-semi-smart/* $(SEEDS)
	afl-fuzz -i $(SEEDS) -o afl-results -- ./$(TARGET)-hard-semi-smart @@

test-seeds:
	gcc $(FILES) -o $(TARGET)
	./run_test.sh

clean: clean-generic
	@rm -f $(SEEDS)/*smart*
	@rm -rf $(TARGET)* afl-results tis-fuzz-results

report: report-generic
