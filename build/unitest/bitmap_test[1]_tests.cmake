add_test( test_bitmap.test_bitmap /Users/niuyuean/miniob/build/bin/bitmap_test [==[--gtest_filter=test_bitmap.test_bitmap]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_bitmap.test_bitmap PROPERTIES WORKING_DIRECTORY /Users/niuyuean/miniob/build/unitest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( bitmap_test_TESTS test_bitmap.test_bitmap)
