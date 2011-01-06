
#ifndef _MFnKeyframeDeltaMove
#define _MFnKeyframeDeltaMove
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
//
// *****************************************************************************
//
// CLASS:    MFnKeyframeDeltaMove
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnKeyframeDeltaMove)
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnKeyframeDelta.h>

// *****************************************************************************

// DECLARATIONS
class MTime;

// *****************************************************************************

// CLASS DECLARATION (MFnKeyframeDeltaMove)

/// Function set for change in keyframe value or time. (OpenMayaAnim) (OpenMayaAnim.py) 
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnKeyframeDeltaMove : public MFnKeyframeDelta 
{

	declareMFn(MFnKeyframeDeltaMove, MFnKeyframeDelta);

public:

	/// 
	MTime		previousTime( MStatus * ReturnStatus = NULL ) const;
	///
	MTime		currentTime( MStatus * ReturnStatus = NULL ) const;
	///
	double		previousValue( MStatus * ReturnStatus = NULL ) const; 
	///
	double		currentValue( MStatus * ReturnStatus = NULL ) const;	

	///
	unsigned int	previousIndex( MStatus * ReturnStatus = NULL ) const;
	///
	virtual unsigned int keyIndex( MStatus * ReturnStatus = NULL ) const; 

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnKeyframeDeltaMove, MFnKeyframeDelta );
	
END_NO_SCRIPT_SUPPORT:

protected:
	// No protected.

private:
	// No private. 
};

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnKeyframeDeltaMove */
