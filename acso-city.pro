includedir = acso-city/headers/
srcdir = acso-city/sources/
bindir = acso-city/binaries/
objdir = acso-city/objects/

QMAKE_CXXFLAGS += -I$${includedir}
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic

SOURCES = $${srcdir}cidade.cpp \
        $${srcdir}data.cpp \
        $${srcdir}pessoa.cpp \
        $${srcdir}homem.cpp \
        $${srcdir}mulher.cpp \
        $${srcdir}saude.cpp \
        $${srcdir}main.cpp

HEADERS = $${includedir}cidade.hpp \
        $${includedir}data.hpp \
        $${includedir}pessoa.hpp \
        $${includedir}homem.hpp \
        $${includedir}mulher.hpp \
        $${includedir}saude.hpp 

TARGET = $${bindir}desafio

OBJECTS_DIR = $${objdir}

CONFIG += c++11