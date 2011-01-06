
#ifndef _MFnRenderLayer
#define _MFnRenderLayer
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
// CLASS:    MFnRenderLayer
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnRenderLayer)
//
//	This class is a function set for render layer objects.
//	This provides functionality for getting the objects present in the 
//	render layer, checking whether the given object is in the current 
//	layer, etc.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MFnDependencyNode.h>

// *****************************************************************************

// DECLARATIONS

class MDagPath;
class MPlug;
class MObjectArray;
class MObject; 

 #ifdef _WIN32
 #pragma warning(disable: 4522)
 #endif // _WIN32

// *****************************************************************************

// CLASS DECLARATION (MFnRenderLayer)

///  Function set for render layer. (OpenMayaRender) (OpenMayaRender.py)
/**

Provide functionalities for working with render layers.
*/

class MObjectArray;

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYARENDER_EXPORT MFnRenderLayer : public MFnDependencyNode
{
	declareMFn(MFnRenderLayer, MFnDependencyNode); 

public:

	/// 
	bool				inLayer( const MObject &transform, 
								 MStatus *ReturnStatus = NULL ); 
	
	///
	MStatus				layerChildren(MObjectArray &children, bool recurse = false);

	///
	bool				inCurrentRenderLayer( const MDagPath& objectPath, 
											  MStatus *ReturnStatus = NULL );
	///
	MStatus				listMembers( MObjectArray& objectsInLayer ) const;

	///
	bool				isPlugAdjusted( const MPlug& scenePlug, 
										MStatus *ReturnStatus = NULL) const;

	///
	static MObject		findLayerByName( const MString &renderLayer, 
										 MStatus *ReturnStatus = NULL ); 
	
	/// 
	static MObject		defaultRenderLayer( MStatus *ReturnStatus = NULL ); 
	
	///
	static MStatus		listAllRenderLayers( MObjectArray &rl ); 

	///
	static MObject		currentLayer( MStatus *ReturnStatus = NULL ); 

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnRenderLayer, MFnDependencyNode );
	
END_NO_SCRIPT_SUPPORT:

protected:
	// No protected members

private:
	void *renderLayer;
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32
// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnRenderLayer */
