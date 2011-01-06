
#ifndef _MFnTripleIndexedComponent
#define _MFnTripleIndexedComponent
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
// CLASS:    MFnTripleIndexedComponent
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnTripleIndexedComponent)
// 
//    This function set allows you to create, edit, and query triple indexed
//    components. Triple indexed components store 3 dimensional index
//    values.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MString.h>
#include <maya/MFnComponent.h>

// *****************************************************************************

// DECLARATIONS

class MIntArray;

// *****************************************************************************

// CLASS DECLARATION (MFnTripleIndexedComponent)

/// Triple indexed component function set. (OpenMaya) (OpenMaya.py)
/**
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnTripleIndexedComponent : public MFnComponent 
{

	declareMFn( MFnTripleIndexedComponent, MFnComponent );

public:

	// Create a triple indexed component of the given type.
	// Allowable types are
	//
	//    MFn::klatticeComponent
	//
	///
	MObject		create( MFn::Type compType, MStatus * ReturnStatus = NULL );

	///
    MStatus 	addElement( int sIndex, int tIndex, int uIndex );
	///
    MStatus 	addElements( const MIntArray& sIndexArray, 
							 const MIntArray& tIndexArray,
							 const MIntArray& uIndexArray );

	///
    MStatus		getElement( int index,
							int & sIndex, int & tIndex, int & uIndex ) const;
	///
    MStatus 	getElements( MIntArray& sIndexArray, 
							 MIntArray& tIndexArray,
							 MIntArray& uIndexArray ) const;

	///
	MStatus		setCompleteData( int maxS, int maxT, int maxU );
	///
	MStatus		getCompleteData( int & maxS, int & maxT, int & maxU ) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnTripleIndexedComponent, MFnComponent );
	
END_NO_SCRIPT_SUPPORT:
    
protected:
// No protected members

private:
// No private members
 
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnTripleIndexedComponent */
