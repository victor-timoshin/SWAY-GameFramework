DEPENDENCIES_DIR = Dependencies/
SOURCE_DIR = Src/
BUILD_DIR = Build/
OUTPUT_DIR = $(BUILD_DIR)Bin/

VS_INC_VC = /I"$(VS_INSTALL_DIR)\VC\include" /I"$(VS_INSTALL_DIR)\VC\PlatformSDK\include"
VS_LIB_VC = /LIBPATH:"$(VS_INSTALL_DIR)\VC\PlatformSDK\Lib" /LIBPATH:"$(VS_INSTALL_DIR)\VC\lib"

ADD_COMPILER_OPTS = /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_VC80_UPGRADE=0x0700" /D "_WINDLL" /D "_ATL_MIN_CRT" /D "_MBCS" /Gm /EHsc /RTC1 /MTd /GR- /Fo"$(OUTPUT_DIR)\\" /Fd"$(OUTPUT_DIR)\vc80.pdb" /W3 /nologo /c /Wp64 /ZI /TP /errorReport:prompt
ADD_LINKER_OPTS = /INCREMENTAL /NOLOGO /DLL /DEBUG /PDB:"$(OUTPUT_DIR)\mydll.pdb" /SUBSYSTEM:WINDOWS /IMPLIB:"$(OUTPUT_DIR)\mydll.lib" /MACHINE:X86 /ERRORREPORT:PROMPT

#Указываем компилятор для сборки.
#CC = g++

#Передаем флаги компилятору.
#CFLAGS = -c -Wall

LDFLAGS =

clean:
	rm -rf $(BUILD_DIR)
