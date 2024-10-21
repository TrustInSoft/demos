[kernel] Loading configuration file config.json (analysis #2)
[kernel] Configuration successfully loaded.
[kernel] [1/6] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
[kernel] [2/6] Parsing TIS_KERNEL_SHARE/libc/tis_runtime.c (with preprocessing)
[kernel] [3/6] Parsing TIS_KERNEL_SHARE/__tis_mkfs.c (with preprocessing)
[kernel] [4/6] Parsing TIS_KERNEL_SHARE/mkfs_empty_filesystem.c (with preprocessing)
[kernel] [5/6] Parsing /home/rolland/src/tisdemos/challenging-case/indexgen.c (with preprocessing)
[kernel] [6/6] Parsing /home/rolland/src/tisdemos/challenging-case/test_driver.c (with preprocessing)
[kernel] Successfully parsed 2 files (+4 runtime files)
[value] Analyzing a complete application starting at generalized_analysis
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C
[value] using specification for function tis_interval
/home/rolland/src/tisdemos/challenging-case/test_driver.c:70:[kernel] warning: accessing out of bounds index [-1..99998]. assert 0 ≤ index_0;
                  stack: generalized_analysis
[value] Done for function generalized_analysis
[info] Saved files information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_files.csv'
[info] Saved function information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_functions.csv'
[info] Saved variable information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_variables.csv'
[info] Saved shared variable information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_shared_variables.csv'
[info] Saved type information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_types.csv'
[info] Saved statement information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_statements.csv'
[info] Saved property information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_properties.csv'
[info] Saved decision information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_decisions.csv'
[info] Saved dead block information in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_dead_blocks.csv'
[info] Saved JSON results in '/home/rolland/src/tisdemos/challenging-case/trustinsoft/.tis-current/2.generalized-analysis_results/2.generalized-analysis_results.json'
[time] Performance summary:
  Parsing: 0.660s
  Value Analysis: 0.009s
  
  Total time: 0h00m01s (= 0.669 seconds)
  Max memory used: 136.2MB (= 136216576 bytes)
