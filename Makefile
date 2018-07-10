
# =======================config===============================
#INSTALL_DIR=


# ======Don't edit anything by yourself after this line=======
RM=rm -f
CC=clang

TEST_BIN=./.tmp_test_bin
TARGET_O=string_builder.o
TARGET_A=libsb.a

default: test clean


$(TARGET_A): $(TARGET_O)
	@ar r $(TARGET_A) $(TARGET_O)

$(TARGET_O): string_builder.c string_builder.h
	@$(CC) string_builder.c -c -o $@

test: init_test build_test
	@$(TEST_BIN)/string_builder_test

test-mem: test
	@valgrind --leak-check=full $(TEST_BIN)/string_builder_test

init_test:
	@mkdir -p $(TEST_BIN)

build_test: string_builder_test

string_builder_test: string_builder.c string_builder_test.c
	@$(CC) string_builder.c string_builder_test.c -g -O0 -o $(TEST_BIN)/$@

echo:
	@echo "INSTALL_DIR=$(INSTALL_DIR)"

lib:
	@make $(TARGET_A)

clean:
	@rm -rf $(TEST_BIN)
	@$(RM) $(TARGET_O) $(TARGET_A)
	@$(RM) a.out

