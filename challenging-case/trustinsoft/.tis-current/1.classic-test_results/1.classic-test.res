[kernel] Loading configuration file config.json (analysis #1)
[kernel] Configuration successfully loaded.
[kernel] [1/6] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
[kernel] [2/6] Parsing TIS_KERNEL_SHARE/libc/tis_runtime.c (with preprocessing)
[kernel] [3/6] Parsing TIS_KERNEL_SHARE/__tis_mkfs.c (with preprocessing)
[kernel] [4/6] Parsing TIS_KERNEL_SHARE/mkfs_empty_filesystem.c (with preprocessing)
[kernel] [5/6] Parsing /home/rolland/src/tisdemos/challenging-case/indexgen.c (with preprocessing)
[kernel] [6/6] Parsing /home/rolland/src/tisdemos/challenging-case/test_driver.c (with preprocessing)
[kernel] Successfully parsed 2 files (+4 runtime files)
[value] Analyzing a complete application starting at test1
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
/home/rolland/src/tisdemos/challenging-case/test_driver.c:47:[kernel] warning: accessing out of bounds index {-1}. assert 0 ≤ index_0;
                  stack: test1
[value] Stopping at nth alarm
[from] Non-terminating function test1 (no dependencies)
[value] user error: Degeneration occurred:
                    results are not correct for lines of code that can be reached from the degeneration point.
[info] Saved files information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_files.csv'
[info] Saved function information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_functions.csv'
[info] Saved variable information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_variables.csv'
[info] Saved shared variable information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_shared_variables.csv'
[info] Saved type information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_types.csv'
[info] Saved statement information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_statements.csv'
[info] Saved property information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_properties.csv'
[info] Saved decision information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_decisions.csv'
[info] Saved dead block information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_dead_blocks.csv'
[info] Saved JSON results in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/1.classic-test_results/1.classic-test_results.json'
[time] Performance summary:
  Parsing: 0.978s
  Value Analysis: 2.744s
  
  Total time: 0h00m03s (= 3.722 seconds)
  Max memory used: 236.8MB (= 236879872 bytes)
