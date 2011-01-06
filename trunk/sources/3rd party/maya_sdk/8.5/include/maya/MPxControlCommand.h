#ifndef _MPxControlCommand
#define _MPxControlCommand
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MPxControlCommand
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxControlCommand)
//
//  This is the command class used for creating proxy UI control.
//
//  The following proxy classes can currently be constructed:
//		Table widget (using MPxUITableControl).
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MSyntax.h>
#include <maya/MArgParser.h>

// *****************************************************************************

// DECLARATIONS

class MStringArray;
class MIntArray;
class MPxUIControl;

// *****************************************************************************

// CLASS DECLARATION (MPxControlCommand)

/// Base class for control creation commands (OpenMayaUI) (OpenMayaMPx.py)
/**
  The base class for control creation commands.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxControlCommand
{
public:
	///
							MPxControlCommand	();
	///
	virtual					~MPxControlCommand	();

	///
	virtual MPxUIControl *	makeControl			() = 0; 
	
	/// 
	virtual MStatus			doEditFlags			();
	///
	virtual MStatus			doQueryFlags		();
	///
	virtual MStatus			appendSyntax		();
	///
	virtual bool			skipFlagForCreate	(const MString &longFlag);
	///
	void					clearResult			();
	///
	MStatus					setResult			(bool result);
	///
	MStatus					setResult			(int result);
	///
	MStatus					setResult			(double result);
	///
	MStatus					setResult			(const MString &result);
	///
	MStatus					setResult			(const MStringArray &result);
	///
	MStatus					setResult			(const MIntArray &result);

	// SCRIPT USE ONLY
	MPxUIControl *_control( MStatus *ReturnStatus = NULL )
		{ return control( ReturnStatus ); }
	MSyntax	_syntax(MStatus *ReturnStatus = NULL) const 
		{ return syntax( ReturnStatus ); }
	MArgParser _parser(MStatus *ReturnStatus = NULL) const 
		{ return parser( ReturnStatus ); }
	//

protected:
	///	USE _control() IN SCRIPT
	MPxUIControl *control( MStatus *ReturnStatus = NULL );
	///	USE _syntax() IN SCRIPT
	MSyntax syntax(MStatus *ReturnStatus = NULL) const;
	///	USE _parser() IN SCRIPT
	MArgParser parser(MStatus *ReturnStatus = NULL) const;

private:
	const char *className() const;
	void setData(void *ptr);

   	void *instance; 

	friend class MPxUIControl; 
	friend class MPxUITableControl;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxControlCommand */
