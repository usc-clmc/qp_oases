TOP = $(realpath $(dir $(lastword $(MAKEFILE_LIST))))
BINDIR = ${TOP}/bin
include ${TOP}/make_linux.mk
