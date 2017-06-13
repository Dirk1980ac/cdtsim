EXTRA_DIST = cdtsim.spec.in

noinst_SCRIPTS = cdtsim.spec

CLEANFILES = cdtsim.spec

cdtsim.spec: cdtsim.spec.in
	$(AM_V_GEN)sed \
		-e 's,@PACKAGE_VERSION\@,$(PACKAGE_VERSION),g' \
		$< > $@