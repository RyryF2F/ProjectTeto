# GNU Make Project makefile by Ryan B. based on Premake
# Run from mingw-64 for raylib

# Defining config var

ifndef config
	config=debug_x64
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug_x64)
  raylib_config = debug_x64
  tetoengine_config = debug_x64
  tetoeditor_config = debug_x64
  tetowargame_config = debug_x64
  
else ifeq ($(config),debug_x86)
  raylib_config = debug_x86
  tetoengine_config = debug_x86
  tetoeditor_config = debug_x86
  tetowargame_config = debug_x86
	
else ifeq ($(config),debug_arm64)
  raylib_config = debug_arm64
  tetoengine_config = debug_arm64
  tetoeditor_config = debug_arm64
  tetowargame_config = debug_arm64
  
else ifeq ($(config),release_x64)
  raylib_config = release_x64
  tetoengine_config = release_x64
  tetoeditor_config = release_x64
  tetowargame_config = release_x64
  
else ifeq ($(config),release_x86)
  raylib_config = release_x86
  tetoengine_config = release_x86
  tetoeditor_config = release_x86
  tetowargame_config = release_x86
  
else ifeq ($(config),release_arm64)
  raylib_config = release_arm64
  tetoengine_config = release_arm64
  tetoeditor_config = release_arm64
  tetowargame_config = release_arm64
  
else
  $(error "invalid configuration $(config)")
endif

# Projects
PROJECTS := raylib TetoEngine TetoEditor TetoWarGame

#def
.PHONY: all clean help $(PROJECTS)
all: $(PROJECTS)

#proj/
raylib:
ifneq (,$(raylib_config))
	@echo "==== Building raylib ($(raylib_config)) ===="
	@${MAKE} --no-print-directory -C build/build_files -f raylib.make config=$(raylib_config)
endif

TetoEngine: raylib
ifneq (,$(tetoengine_config))
	@echo "==== Building TetoEngine ($(tetoengine_config)) ===="
	@${MAKE} --no-print-directory -C build/build_files -f TetoEngine.make config=$(tetoengine_config)
endif

TetoEditor: TetoEngine
ifneq (,$(tetoeditor_config))
	@echo "==== Building TetoEditor ($(tetoeditor_config)) ===="
	@${MAKE} --no-print-directory -C build/build_files -f TetoEditor.make config=$(tetoeditor_config)
endif

TetoWarGame: TetoEngine
ifneq (,$(tetowargame_config))
	@echo "==== Building TetoWarGame ($(tetowargame_config)) ===="
	@${MAKE} --no-print-directory -C build/build_files -f TetoWarGame.make config=$(tetowargame_config)
endif

#def
clean:
	@${MAKE} --no-print-directory -C build/build_files -f TetoWarGame.make clean
	@${MAKE} --no-print-directory -C build/build_files -f TetoEditor.make clean
	@${MAKE} --no-print-directory -C build/build_files -f TetoEngine.make clean
	@${MAKE} --no-print-directory -C build/build_files -f raylib.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug_x64"
	@echo "  debug_x86"
	@echo "  debug_arm64"
	@echo "  release_x64"
	@echo "  release_x86"
	@echo "  release_arm64"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   TetoEngine"
	@echo "   TetoEditor"
	@echo "   TetoWarGame"
	@echo "   raylib"
	@echo ""