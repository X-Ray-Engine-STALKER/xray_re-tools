
#ifndef _MFnPartition
#define _MFnPartition
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
// CLASS:    MFnPartition
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPartition)
//
// MFnPartition is the function partition that is used for manipulating
// partitions of objects.  Partitions in Maya are dependency nodes, so it
// is possible for one partition to contain others.
// 
// A partition is a list of dependency nodes and dag nodes.  Partitions
// are useful for keeping track of lists of objects for many purposes such
// as selection or applying common rendering parameters.  Partitions in
// Maya are also dependency nodes, so it is possible for one partition to
// contain others..
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MString.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS
 
class MObjectArray;
class MSelectionList;
class MDagPath;


// *****************************************************************************

// CLASS DECLARATION (MFnPartition)

/// Function Partition for Partitions of Objects. (OpenMaya) (OpenMaya.py)
/**
    Function partition for partitions of objects
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnPartition : public MFnDependencyNode 
{

	declareMFn(MFnPartition, MFnDependencyNode);

public:
	
	///
	enum Restriction { 
		///
		kNone,
		///
		kVerticesOnly,
		///
		kEdgesOnly,
		///
		kFacetsOnly,
		///
		kEditPointsOnly,
		///
		kRenderableOnly
	};

	///
	MObject     create( bool isRenderPartition = false,
						MStatus * ReturnStatus = NULL );
	///
	bool        isRenderPartition( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     addMember( const MObject &set );
	///
	MStatus     removeMember( const MObject &set );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnPartition, MFnDependencyNode );
	
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
#endif /* _MFnPartition */
