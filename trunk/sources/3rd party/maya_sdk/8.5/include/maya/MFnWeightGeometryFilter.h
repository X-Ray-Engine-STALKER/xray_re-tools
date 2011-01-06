
#ifndef _MFnWeightGeometryFilter
#define _MFnWeightGeometryFilter
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
// CLASS:    MFnWeightGeometryFilter
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnWeightGeometryFilter)
//
// MFnWeightGeometryFilter is the function set for weight geometry filters.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnGeometryFilter.h>
#include <maya/MObject.h>
// *****************************************************************************

// DECLARATIONS
class MObject;
class MDagPath;
class MIntArray;
class MFloatArray;
class MObjectArray;
class MSelectionList;
class MString;

// *****************************************************************************

// CLASS DECLARATION (MFnWeightGeometryFilter)

/// Weight geometry filter function set (OpenMayaAnim) (OpenMayaAnim.py)
/**
MFnWeightGeometryFilter is the function set for editing the weights of
clusters, cluster flexors, and user-defined deformers derived from
MPxDeformerNode.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MFnWeightGeometryFilter : public MFnGeometryFilter
{
	declareMFn(MFnWeightGeometryFilter, MFnGeometryFilter);

public:
	///
	MStatus		getWeights(unsigned int index,
						   const MObject &components,
						   MFloatArray &weights) const;
	///
	MStatus		getWeights(const MDagPath &path,
						   const MObject &components,
						   MFloatArray &weights) const;
	///
	MStatus		setWeight(const MDagPath &path,
						  unsigned int index,
						  const MObject &components,
						  float weight,
						  MFloatArray *oldValues = NULL);
	///
	MStatus		setWeight(const MDagPath &path,
						  const MObject &components,
						  float weight,
						  MFloatArray *oldValues = NULL);
	///
	MStatus		setWeight(const MDagPath &path,
						  unsigned int index,
						  const MObject &components,
						  MFloatArray &values);
	///
	MStatus		setWeight(const MDagPath &path,
						  const MObject &components,
						  MFloatArray &values);
	///
	MString		weightPlugStrings(const MSelectionList &list,
									 MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		getWeightPlugStrings(const MSelectionList &list,
									 MStringArray &plugStringArray) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnWeightGeometryFilter, MFnGeometryFilter );

	///     NO SCRIPT SUPPORT
	MStatus		getWeightPlugStrings(const MSelectionList &list,
									 MString &plugStrings) const;
	
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
#endif /* _MFnWeightGeometryFilter */
