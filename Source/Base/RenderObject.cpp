/*=========================================================================

  OpenGC - The Open Source Glass Cockpit Project
  Please see our web site at http://www.opengc.org

  Albatross UAV Project - http://www.albatross-uav.org

  Copyright (c) 2001-2003 Damion Shelton
  All rights reserved. Contributions by Hugo Vincent.
  See Copyright.txt or http://www.opengc.org/Copyright.htm for details.

  This software is distributed WITHOUT ANY WARRANTY; without even 
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
  PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "RenderObject.h"
#include "Debug.h"

namespace OpenGC
{

RenderObject::RenderObject()
{
	// Initialize with safe default parameters

	m_UnitsPerPixel = 1.0;

	m_PhysicalPosition.x = 0;
	m_PhysicalPosition.y = 0;

	m_PhysicalSize.x = 0;
	m_PhysicalSize.y = 0;

	m_Scale.x = 1.0;
	m_Scale.y = 1.0;
}

RenderObject::~RenderObject()
{

}

void RenderObject::SetScale(double xScale, double yScale)
{
	// Set gauge scaling factors
	// Must be a double greater than 0

	if(xScale > 0)
		m_Scale.x = xScale;

	if(yScale > 0)
		m_Scale.y = yScale;
}

void RenderObject::SetPosition(double xPos, double yPos)
{
	m_PhysicalPosition.x = xPos;
	m_PhysicalPosition.y = yPos;
}

void RenderObject::SetUnitsPerPixel(double unitsPerPixel)
{
	m_UnitsPerPixel = unitsPerPixel;
}

// Called by framework when a mouse click occurs
void RenderObject::HandleMouseButton(int button, int state, int x, int y)
{
	if(this->ClickTest(button, state, x, y))
	{
		// Convert the click to an x/y position in render object physical coordinates
		double physX, physY;
		physX = (((double)x - (double)m_PixelPosition.x)/(double)m_PixelSize.x)*m_PhysicalSize.x;
		physY = (((double)y - (double)m_PixelPosition.y)/(double)m_PixelSize.y)*m_PhysicalSize.y;

		if(state==0)
			this->OnMouseDown(button, physX, physY);
		else
			this->OnMouseUp(button, physX, physY);
	}
}

// Called when a mouse "down" event occurs
void RenderObject::OnMouseDown(int button, double physicalX, double physicalY)
{
	// The default version of this doesn't do anything
	// Overload to provide specific functionality
	LogPrintf("RenderObject: mouse down called\n");
}

// Called when a mouse "up" event occurs
void RenderObject::OnMouseUp(int button, double physicalX, double physicalY)
{
	// The default version of this doesn't do anything
	// Overload to provide specific functionality
}

// Called when keyboard event occurs
void RenderObject::OnKeyboard(int keycode, int modifiers)
{
	// The default version of this doesn't do anything
	// Overload to provide specific functionality
}

} // end namespace OpenGC
