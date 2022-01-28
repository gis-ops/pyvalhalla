/* 
 spatialite_ext.h -- Gaia support for SQLite extensions
  
 version 5.0, 2020 August 1

 Author: Sandro Furieri a.furieri@lqt.it

 ------------------------------------------------------------------------------
 
 Version: MPL 1.1/GPL 2.0/LGPL 2.1
 
 The contents of this file are subject to the Mozilla Public License Version
 1.1 (the "License"); you may not use this file except in compliance with
 the License. You may obtain a copy of the License at
 http://www.mozilla.org/MPL/
 
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

The Original Code is the SpatiaLite library

The Initial Developer of the Original Code is Alessandro Furieri
 
Portions created by the Initial Developer are Copyright (C) 2008-2021
the Initial Developer. All Rights Reserved.

Contributor(s):

Alternatively, the contents of this file may be used under the terms of
either the GNU General Public License Version 2 or later (the "GPL"), or
the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
in which case the provisions of the GPL or the LGPL are applicable instead
of those above. If you wish to allow use of your version of this file only
under the terms of either the GPL or the LGPL, and not to allow others to
use your version of this file under the terms of the MPL, indicate your
decision by deleting the provisions above and replace them with the notice
and other provisions required by the GPL or the LGPL. If you do not delete
the provisions above, a recipient may use your version of this file under
the terms of any one of the MPL, the GPL or the LGPL.
 
*/

#include <spatialite_private.h>

SPATIALITE_PRIVATE int virtualshape_extension_init (void *db);
SPATIALITE_PRIVATE int virtualdbf_extension_init (void *db);
SPATIALITE_PRIVATE int virtualtext_extension_init (void *db);
SPATIALITE_PRIVATE int virtualXL_extension_init (void *db);
SPATIALITE_PRIVATE int virtualnetwork_extension_init (void *db);
SPATIALITE_PRIVATE int virtualrouting_extension_init (void *db);
SPATIALITE_PRIVATE int virtualfdo_extension_init (void *db);
SPATIALITE_PRIVATE int virtualbbox_extension_init (void *db,
						   const void *p_cache);
SPATIALITE_PRIVATE int mbrcache_extension_init (void *db);
SPATIALITE_PRIVATE int virtual_spatialindex_extension_init (void *db);
SPATIALITE_PRIVATE int virtual_elementary_extension_init (void *db);
SPATIALITE_PRIVATE int virtual_knn_extension_init (void *db);
SPATIALITE_PRIVATE int virtual_xpath_extension_init (void *db,
						     const void *p_cache);
SPATIALITE_PRIVATE int virtualgpkg_extension_init (void *db);
SPATIALITE_PRIVATE int virtualgeojson_extension_init (void *db);
