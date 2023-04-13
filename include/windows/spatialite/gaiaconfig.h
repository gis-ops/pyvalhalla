/* ./src/headers/spatialite/gaiaconfig.h.  Generated from gaiaconfig.h.in by configure.  */
/* ./src/headers/spatialite/gaiaconfig.h.in - manually maintained */

/* Should be defined in order to enable GCP support. */
#define ENABLE_GCP 1

/* Should be defined in order to enable GeoPackage support. */
#define ENABLE_GEOPACKAGE 1

/* Should be defined in order to enable LIBXML2 support. */
#define ENABLE_LIBXML2 1

/* Should be defined in order to enable MiniZIP support. */
#define ENABLE_MINIZIP 1

/* Should be defined in order to enable RTTOPO support. */
#define ENABLE_RTTOPO 1

/* Should be defined in order to enable GEOS_370 support. */
#define GEOS_370 1

/* Should be defined in order to enable GEOS_ADVANCED support. */
#define GEOS_ADVANCED 1

/* Should be defined in order to fully disable GEOS non-thread-safe API. */
/* #undef GEOS_ONLY_REENTRANT */

/* Should be defined in order to enable GEOS_REENTRANT (fully thread-safe). */
#define GEOS_REENTRANT 1

/* Should be defined in order to disable EPSG full support. */
/* #undef OMIT_EPSG */

/* Should be defined in order to disable FREEXL support. */
/* #undef OMIT_FREEXL */

/* Should be defined in order to disable GEOCALLBACKS support. */
#define OMIT_GEOCALLBACKS 1

/* Should be defined in order to disable GEOS support. */
/* #undef OMIT_GEOS */

/* Should be defined in order to disable ICONV support. */
/* #undef OMIT_ICONV */

/* Should be defined in order to disable KNN support. */
/* #undef OMIT_KNN */

/* Should be defined in order to disable MATHSQL support. */
/* #undef OMIT_MATHSQL */

/* Should be defined in order to disable PROJ.4 support. */
/* #undef OMIT_PROJ */

/* Should be defined in order to enable PROJ.6 support. */
#define PROJ_NEW 1

/* Should contain a text-string describing the intended target CPU */
#define SPATIALITE_TARGET_CPU "x86_64-redhat-linux"

/* the Version of this package */
#define SPATIALITE_VERSION "5.0.1"
