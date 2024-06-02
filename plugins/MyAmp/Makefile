#!/usr/bin/make -f

VST2 ?= true
LV2 ?= true

NAME = MyAmp

FILES_DSP = MyAmp.cpp

include ../../dpf/Makefile.plugins.mk

ifeq ($(VST2), true)
TARGETS += vst
endif

ifeq ($(LV2), true)
ifeq ($(HAVE_DGL), true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif
endif

all: $(TARGETS)
