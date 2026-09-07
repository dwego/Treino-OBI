CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

BUILD_DIR := build
CPP_SOURCES := $(wildcard cpp/*.cpp)
CPP_BINARIES := $(patsubst cpp/%.cpp,$(BUILD_DIR)/cpp/%,$(CPP_SOURCES))
POSITIONAL_FILE := $(word 2,$(MAKECMDGOALS))
RUN_FILE := $(if $(strip $(FILE)),$(strip $(FILE)),$(POSITIONAL_FILE))

.PHONY: all cpp list run help clean

all: cpp

cpp: $(CPP_BINARIES)

$(BUILD_DIR)/cpp/%: cpp/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

list:
	@printf '%s\n' 'Available exercises:'
	@for file in $(CPP_SOURCES); do printf '  %s\n' "$$file"; done

ifneq ($(POSITIONAL_FILE),)
.PHONY: $(POSITIONAL_FILE)
$(POSITIONAL_FILE):
	@:
endif

run:
	@if [ -z "$(RUN_FILE)" ]; then \
		printf '%s\n' 'Usage: make run cpp/staircase_dp.cpp'; \
		exit 1; \
	fi; \
	case "$(RUN_FILE)" in \
		cpp/*.cpp) \
			$(MAKE) --no-print-directory "$(BUILD_DIR)/$(basename $(RUN_FILE))" && \
			exec "./$(BUILD_DIR)/$(basename $(RUN_FILE))" ;; \
		*) \
			printf 'Only cpp/*.cpp files are supported: %s\n' "$(RUN_FILE)"; \
			exit 1 ;; \
	esac

help:
	@printf '%s\n' \
		'make                  Compile all C++ exercises' \
		'make list             List runnable C++ exercises' \
		'make run cpp/file.cpp Compile (when needed) and run one exercise' \
		'make clean            Remove everything generated in build/'

clean:
	$(RM) -r $(BUILD_DIR)
