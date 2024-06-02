#!/usr/bin/make -f

PLUGIN=MyAmp

include dpf/Makefile.base.mk

all: dgl plugins gen

dgl:
ifeq ($(HAVE_OPENGL), true)
	$(MAKE) all -C dpf/dgl HAVE_OPENGL
endif

plugins: dgl
	$(MAKE) all -C plugins/$(PLUGIN)

ifneq ($(CROSS_COMPILING), true)
gen: plugins dpf/utils/lv2-ttl-generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh
ifeq ($(MACOS), true)
	@$(CURDIR)/dpf/utils/generate-vst-bundles.sh
endif

clean:
	$(MAKE) clean -C dpf/dgl
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(MAKE) clean -C plugins/$(PLUGIN)
	rm -rf bin build

.PHONY: plugins