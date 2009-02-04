# Builds: OpenGC libraries and application (top level)
# Project: OpenGC for Albatross
# Author: Hugo Vincent
# Date: 22 March 2006

import os

# Utility Functions:


CacheDir('/home/hugo/.sconscache') # Enable build object cache

# Configuration options
conf = {
	"debug": False,
	"compiler": 'g++',
	"inc_path": [
		'#Source/Base',
		'#Source/Gauges',
		'#Source/Navigation',
		'#Source/DataSources',
		'#Source/Application',
		'/usr/include/freetype2', 
		'/usr/include/FTGL',
		'/Users/hugo/Projects/MacOSX/Fltk/include'
	],
	"cflags": '-O2 -Wall -Wformat',
	"linkflags": '-Wl,-O2',
	"libpath": ['#Build', '/usr/X11R6/lib'],
	"linklibs": [
		'opengc_base',
		'opengc_nav',
		'opengc_gauges',
		'opengc_datasource',
		'GL', 'ftgl', 'fltk', 'fltk_gl', # Core dependencies
		'plibnet', 'plibul', # Needed for FGDataSource
		'opengc_base' # don't know why this needs to be included twice, but hey
	]
}

# Nothing to actually build here, just recurse into the various source directories
SConscript(['Source/Base/SConscript',
			'Source/Gauges/SConscript',
			'Source/Navigation/SConscript',
			'Source/DataSources/SConscript',
			'Source/Application/SConscript'],
			exports='conf')

