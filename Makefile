CXX = /usr/local/bin/g++-13
CC := $(CXX)

TARGET_EXEC := sc_main

SRC_DIRS := $(shell pwd)
BUILD_DIR := $(SRC_DIRS)/obj

FRAMEWORK_SRC_DIR := /Users/ebinouri/Documents/UNi/OpenSourceTools/fault-injection-framework/core/src

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
FRAMEWORK_SRC := $(shell find $(FRAMEWORK_SRC_DIR) -name '*.cpp' -or -name '*.c')


# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
OBJS_DIR := $(subst $(SRC_DIRS),$(BUILD_DIR),$(SRCS))
OBJS := $(addsuffix .o, $(OBJS_DIR))
# OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)


# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d | grep -v "\.")
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
FRAMEWORK_INC_FLAGS := $(addprefix -I,$(FRAMEWORK_SRC))

LDFLAGS := -L /usr/local/systemc-2.3.3/lib -L /usr/local/uvm-systemc-1.0-beta4/lib
LDLIBS := -l systemc -l uvm-systemc
CPPFLAGS :=  -std=c++17 -I /usr/local/systemc-2.3.3/include/ -I /usr/local/uvm-systemc-1.0-beta4/include/ -I $(FRAMEWORK_SRC_DIR)/utils/ -I $(FRAMEWORK_INC_FLAGS)

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS += $(INC_FLAGS)

.PHONY:all
all: clean run


# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: run
run: $(BUILD_DIR)/$(TARGET_EXEC)
	$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
