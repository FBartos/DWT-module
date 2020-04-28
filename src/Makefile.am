SUBDIRS = distributions functions

jagsmod_LTLIBRARIES = weightedt.la

weightedt_la_SOURCES = weightedt.cc

weightedt_la_CPPFLAGS = -I$(includedir)/JAGS

weightedt_la_LIBADD = distributions/weightedtdist.la
weightedt_la_LIBADD += functions/weightedtfunc.la

if WINDOWS
weightedt_la_LIBADD += -ljags-$(JAGS_MAJOR) -ljrmath-0 -lboost_system$(BOOST_LIB_SUFFIX)
else
weightedt_la_LIBADD += -ljags -ljrmath -lboost_system$(BOOST_LIB_SUFFIX)
endif

weightedt_la_LDFLAGS = -module -avoid-version
if WINDOWS
weightedt_la_LDFLAGS += -no-undefined
endif
