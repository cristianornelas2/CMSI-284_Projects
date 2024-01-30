

## Cristian Ornelas

##### https://github.com/lmu-cmsi284-spring2020/oh-say-can-you-c-cristianornelas2

| Category/Feedback | Points |
| --- | ---: |
| **code-point-to-utf8.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 1/1 |
| • _Correct program output?_ All tests pass. | 3/3 |
| • _Correct handling of invalid user input?_ All tests pass. | 1/1 |
| **split-string-at-index.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 4/4 |
| • _Correct program output?_ All tests pass. | 12/12 |
| • _Correct handling of invalid user input?_ All tests pass. | 4/4 |
| **print-max-note-lengths.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 1/1 |
| • _Correct program output?_ All tests pass. | 3/3 |
| • _Correct handling of invalid user input?_ No deduction, but ideally, the program prints out some kind of message when arguments are unexpectedly supplied, to inform the user that these aren’t necessary. | 1/1 |
| **get-note-index.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs.  | 1/1 |
| • _Correct program output?_ All tests pass. | 3/3 |
| • _Correct handling of invalid user input?_ All tests pass. | 1/1 |
| **get-chord-index.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs.  | 1/1 |
| • _Correct program output?_ All tests pass. | 3/3 |
| • _Correct handling of invalid user input?_ All tests pass. | 1/1 |
| **split-note-and-chord.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 6/6 |
| • _Correct program output?_ Implementation makes a hardcoded assumption that the longest possible chord to split will only occupy `MAX_SUBSTRING` characters: this will not apply to the 100% general case, and will in fact cause segmentation faults when the `NOTES` or `CHORD_SUFFIXES` arrays may combine for more than `MAX_SUBSTRING` characters. The approach can work, but a more accurate size estimate must be made (–2). | 16/18 |
| • _Correct handling of invalid user input?_ The program correctly checks arguments and return values to determine the validity of user input—it would have been completely correct if `split_note_and_chord` doesn’t seg-fault due to note or chord suffix strings that are longer than `MAX_SUBSTRING` characters. | 6/6 |
| **print-chord.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 4/4 |
| • _Correct program output?_ All tests pass. | 12/12 |
| • _Correct handling of invalid user input?_ Validity check allows some partially non-numeric strings to get through—`is_non_negative_numeral` would have made this foolproof (–1). | 3/4 |
| **chord.c** | |
| • _Compiles and runs without unexpected errors?_ Program compiles and runs. | 2/2 |
| • _Correct program output?_ Because this is a cumulative program from all previous code, we avoid re-deductions of prior errors and will only count new ones.<br><br>Given that consideration, no new issues were found for _chord.c_. | 6/6 |
| • _Correct handling of invalid user input?_ Because this is a cumulative program from all previous code, we avoid re-deductions of prior errors and will only count new ones.<br><br>Given that consideration, no new issues were found for _chord.c_. | 2/2 |
| **Input/output in functions other than `main`** No stray prints found. |  |
| **Failure to write functions as defined** No divergences from function specifications were seen. |  |
| **Hard-to-maintain or error-prone code** No major error-prone or maintainability issues found. |  |
| **Hard-to-read code** Some files have incorrectly-indented lines; please make sure to make the indentation of your code consistently reflect the program’s structure.<br><br>Add spaces after reserved words like `for` and `if`, so that they don’t look like function calls. |  |
| **Version Control** 8 commits; good commit frequency and granularity; commit messages could have been just a tiny bit more descriptive. Good work! |  |
| **Punctuality** First commit on 4/7 7:05pm; last commit on 4/9 9:42pm. Accommodated due to health issues. |  |
| **Total** | **97/100** |
