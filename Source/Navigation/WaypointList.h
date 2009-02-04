/*=========================================================================

  OpenGC - The Open Source Glass Cockpit Project
  Please see our web site at http://www.opengc.org

  Albatross UAV Project - http://www.albatross-uav.org

  Copyright (c) 2006 Hugo Vincent
  All rights reserved.
  See Copyright.txt or http://www.opengc.org/Copyright.htm for details.

  This software is distributed WITHOUT ANY WARRANTY; without even 
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
  PURPOSE.  See the above copyright notice for more information.

  =========================================================================*/

#ifndef WaypointList_h
#define WaypointList_h

#include "GeographicObjectList.h"

namespace OpenGC
{

class WaypointList : public GeographicObjectList
{
public:
	WaypointList();
	virtual ~WaypointList();

	// Read a file contain waypoints, returns true if successful, else false
	bool LoadData(const string& fileName);
};

} // end namespace OpenGC

#endif

