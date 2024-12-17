ifndef config
  config=debug_x64
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
INCLUDES += -I../../proj/TetoEditor -I../../include -I../../proj/TetoEngine/include -I../external/raylib-master/src -I../external/raylib-master/src/external -I../external/raylib-master/src/external/glfw/include
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

ifeq ($(config),debug_x64)
TARGETDIR = ../../bin/Debug
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/x64/Debug/TetoEditor
DEFINES += -DDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -Wshadow -g -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -Wshadow -g -std=c++17
LIBS += ../../bin/Debug/TetoEngine.lib ../../bin/Debug/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Debug/raylib.lib ../../bin/Debug/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Debug -L/usr/lib64 -m64

else ifeq ($(config),debug_x86)
TARGETDIR = ../../bin/Debug
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/x86/Debug/TetoEditor
DEFINES += -DDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -Wshadow -g -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -Wshadow -g -std=c++17
LIBS += ../../bin/Debug/TetoEngine.lib ../../bin/Debug/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Debug/raylib.lib ../../bin/Debug/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Debug -L/usr/lib32 -m32

else ifeq ($(config),debug_arm64)
TARGETDIR = ../../bin/Debug
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/ARM64/Debug/TetoEditor
DEFINES += -DDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -Wshadow -g -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -Wshadow -g -std=c++17
LIBS += ../../bin/Debug/TetoEngine.lib ../../bin/Debug/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Debug/raylib.lib ../../bin/Debug/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Debug

else ifeq ($(config),release_x64)
TARGETDIR = ../../bin/Release
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/x64/Release/TetoEditor
DEFINES += -DNDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -Wshadow -O2 -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -Wshadow -O2 -std=c++17
LIBS += ../../bin/Release/TetoEngine.lib ../../bin/Release/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Release/raylib.lib ../../bin/Release/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Release -L/usr/lib64 -m64 -s

else ifeq ($(config),release_x86)
TARGETDIR = ../../bin/Release
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/x86/Release/TetoEditor
DEFINES += -DNDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -Wshadow -O2 -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -Wshadow -O2 -std=c++17
LIBS += ../../bin/Release/TetoEngine.lib ../../bin/Release/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Release/raylib.lib ../../bin/Release/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Release -L/usr/lib32 -m32 -s

else ifeq ($(config),release_arm64)
TARGETDIR = ../../bin/Release
TARGET = $(TARGETDIR)/TetoEditor.exe
OBJDIR = obj/ARM64/Release/TetoEditor
DEFINES += -DNDEBUG -DPLATFORM_DESKTOP -DGRAPHICS_API_OPENGL_43 -D_WIN32
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -Wshadow -O2 -std=c99
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -Wshadow -O2 -std=c++17
LIBS += ../../bin/Release/TetoEngine.lib ../../bin/Release/raylib.lib -lwinmm -lgdi32
LDDEPS += ../../bin/Release/raylib.lib ../../bin/Release/TetoEngine.lib
ALL_LDFLAGS += $(LDFLAGS) -L../../bin/Release -s

endif

#FILE SETS
###################################
OBJECTS :=
GENERATED :=

OBJECTS += $(OBJDIR)/main.o
GENERATED += $(OBJDIR)/main.o

OBJECTS += $(OBJDIR)/PMLEWindow.o
GENERATED += $(OBJDIR)/PMLEWindow.o

OBJECTS += $(OBJDIR)/TexHand.o
GENERATED += $(OBJDIR)/TexHand.o

	# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking TetoEditor
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning TetoEditor
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif

#FILE RULES
###################################
SRC_FOLDER = ../../proj/PostMasterLevelEditor
GLOBAL_INCLUDE += $(SRC_FOLDER)/include

$(OBJDIR)/main.o: $(SRC_FOLDER)/main.cpp
		@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(MAIN_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
	
$(OBJDIR)/PMLEWindow.o: $(SRC_FOLDER)/PMLEWindow.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(MAIN_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
	
$(OBJDIR)/TexHand.o: $(SRC_FOLDER)/texture/TexHand.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(TEX_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
	
	
-include $(OBJECTS:%.o=%.d)

ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif