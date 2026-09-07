CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
CC ?= cc
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic
JAVAC ?= javac
JAVA ?= java
PYTHON ?= python3

BUILD_DIR := build
CPP_SOURCES := $(wildcard cpp/*.cpp)
C_SOURCES := $(wildcard c/*.c)
JAVA_SOURCES := $(wildcard java/*.java)
CPP_BINARIES := $(patsubst cpp/%.cpp,$(BUILD_DIR)/cpp/%,$(CPP_SOURCES))
C_BINARIES := $(patsubst c/%.c,$(BUILD_DIR)/c/%,$(C_SOURCES))
JAVA_CLASSES := $(patsubst java/%.java,$(BUILD_DIR)/java/%.class,$(JAVA_SOURCES))

.PHONY: all cpp c java list run help clean

all: cpp c java

cpp: $(CPP_BINARIES)

c: $(C_BINARIES)

java: $(JAVA_CLASSES)

$(BUILD_DIR)/cpp/%: cpp/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/c/%: c/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/java/%.class: java/%.java
	@mkdir -p $(@D)
	$(JAVAC) -d $(BUILD_DIR)/java $<

list:
	@printf '%s\n' 'Available exercises:'
	@for file in $(CPP_SOURCES) $(C_SOURCES) $(JAVA_SOURCES) $(wildcard python/*.py); do printf '  %s\n' "$$file"; done

run:
	@if [ -z "$(FILE)" ]; then \
		printf '%s\n' 'Usage: make run FILE=cpp/staircase_dp.cpp'; \
		exit 1; \
	fi; \
	case "$(FILE)" in \
		cpp/*.cpp|c/*.c) \
			$(MAKE) --no-print-directory "$(BUILD_DIR)/$(basename $(FILE))" && \
			exec "./$(BUILD_DIR)/$(basename $(FILE))" ;; \
		java/*.java) \
			$(MAKE) --no-print-directory "$(BUILD_DIR)/java/$(notdir $(basename $(FILE))).class" && \
			exec $(JAVA) -cp "$(BUILD_DIR)/java" "$(notdir $(basename $(FILE)))" ;; \
		python/*.py) \
			exec $(PYTHON) "$(FILE)" ;; \
		*) \
			printf 'Unsupported file: %s\n' "$(FILE)"; \
			exit 1 ;; \
	esac

help:
	@printf '%s\n' \
		'make              Compile all C, C++, and Java exercises' \
		'make list         List runnable exercises' \
		'make run FILE=... Compile (when needed) and run one exercise' \
		'make clean        Remove everything generated in build/'

clean:
	$(RM) -r $(BUILD_DIR)
