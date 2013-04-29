// This file is part of the REMOTE API
// 
// Copyright 2006-2013 Dr. Marc Andreas Freese. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// The REMOTE API is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The REMOTE API is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// The REMOTE API is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the REMOTE API.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.0.2 on March 14th 2013

#if !defined(EXTAPICUSTOMCONST_INCLUDED_)
#define EXTAPICUSTOMCONST_INCLUDED_

#include "v_repConst.h"

/* Your custom remote API command IDs. Following are just simple examples */
enum {	
		/* from here on, commands are only identified by their code (or ID) */
		simx_customcmd_get_object_count		=simx_cmdnull_custom_start,
		simx_customcmd_my_cmd2,	/* this command is not implemented yet. You can add many more custom command IDs here */

		/* from here on, commands are also identified by additional 4 bytes. For example,
		   the command to retrieve an object type has no meaning if sent alone: an object
		   handle to which the command applies is required. So the command is identified
		   by a command ID (value here below), and an object handle (1 integer=4 bytes) */
		simx_customcmd_get_object_type		=simx_cmd4bytes_custom_start,
		simx_customcmd_set_object_name,
		simx_customcmd_my_cmd5, /* this command is not implemented yet. You can add many more custom command IDs here */

		/* from here on, commands are also identified by additional 8 bytes. For example,
		   the command to retrieve the label of a UI button has no meaning if sent alone:
		   a UI handle and a button ID to which the command applies is required. So the
		   command is identified by a command ID (value here below), a UI handle (1 integer=4 bytes),
		   and a UI button ID (1 integer=4 bytes). So the command ID is accompanied by additional
		   8 bytes */
		simx_customcmd_get_ui_button_label	=simx_cmd8bytes_custom_start, 
		simx_customcmd_my_cmd7, /* this command is not implemented yet. You can add many more custom command IDs here */

		/* from here on, commands are also identified by one additional string. For example,
		   the command to retrieve the handle of a script has no meaning if sent alone:
		   an object name (where the script is attached to) is required. So the command is
		   identified by a command ID (value here below) and an object name (the string) */
		simx_customcmd_get_script_handle	=simx_cmd1string_custom_start,
		simx_customcmd_my_cmd9 /* this command is not implemented yet. You can add many more custom command IDs here */
};


#endif /* !defined(EXTAPICUSTOMCONST_INCLUDED_) */
