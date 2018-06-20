TEST_BIN=./.tmp_test_bin

default: test clean

test: init_test build_test
	@$(TEST_BIN)/string_builder_test

init_test:
	@mkdir -p $(TEST_BIN)

build_test: string_builder_test

string_builder_test: string_builder.c string_builder_test.c
	@clang string_builder.c string_builder_test.c -g -O0 -o $(TEST_BIN)/$@

clean:
	@rm -rf $(TEST_BIN)
