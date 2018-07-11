
# =======================config===============================
#INSTALL_DIR=


# ======Don't edit anything by yourself after this line=======
RM=rm -f
CC=clang

TEST_BIN=./.tmp_test_bin
TARGET_O=sb.o
TARGET_A=libsb.a

default: test clean


$(TARGET_A): $(TARGET_O)
	@ar r $(TARGET_A) $(TARGET_O)

$(TARGET_O): sb.c sb.h
	@$(CC) sb.c -c -o $@

test: init_test build_test
	@$(TEST_BIN)/sb_test

test-mem: test
	@valgrind --leak-check=full $(TEST_BIN)/sb_test

init_test:
	@mkdir -p $(TEST_BIN)

build_test: sb_test

sb_test: sb.c sb_test.c
	@$(CC) sb.c sb_test.c -g -O0 -o $(TEST_BIN)/$@

echo:
	@echo "INSTALL_DIR=$(INSTALL_DIR)"

lib:
	@make $(TARGET_A)

clean:
	@rm -rf $(TEST_BIN)
	@$(RM) $(TARGET_O) $(TARGET_A)
	@$(RM) a.out

