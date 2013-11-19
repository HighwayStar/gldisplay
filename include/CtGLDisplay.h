//###########################################################################
// This file is part of gldisplay, a submodule of LImA project the
// Library for Image Acquisition
//
// Copyright (C) : 2009-2011
// European Synchrotron Radiation Facility
// BP 220, Grenoble 38043
// FRANCE
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//###########################################################################
#ifndef __CTGLDISPLAY_H__
#define __CTGLDISPLAY_H__

#include "GLDisplay.h"
#include "CtControl.h"

namespace lima
{

class CtGLDisplay
{
 public:
	CtGLDisplay(CtControl *ct_control); 
	virtual ~CtGLDisplay();

	virtual void setRefreshTime(double refresh_time);
	virtual void getRefreshTime(double& refresh_time);

	virtual void createWindow() = 0;
	virtual bool isClosed() = 0;
	virtual void closeWindow() = 0;
	virtual void refresh() = 0;

 protected:
	CtControl *m_ct_control;
	double m_refresh_time;
};


class CtSPSGLDisplay : public CtGLDisplay
{
 public:
	CtSPSGLDisplay(CtControl *ct_control, 
		       int argc = 0, char **argv = NULL);
	virtual ~CtSPSGLDisplay();

	void setSpecArray(std::string spec_name, std::string array_name);
	void getSpecArray(std::string& spec_name, std::string& array_name);

	virtual void createWindow();
	virtual bool isClosed();
	virtual void closeWindow();
	virtual void refresh();

 private:
	static void processlibForkCleanup(void *data);

	SPSGLDisplay *m_sps_gl_display;
};

} // namespace lima

#endif // __CTGLDISPLAY_H__
