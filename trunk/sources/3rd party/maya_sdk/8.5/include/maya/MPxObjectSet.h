#ifndef _MPxObjectSet
#define _MPxObjectSet
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
// CLASS:    MPxObjectSet
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxObjectSet)
// 
//  MPxObjectSet is the parent class of all user defined object sets.
//  User defined sets are dependency nodes.
//
//  This class can be used to implement new kinds of sets within maya that
//  can have selectable/manipulatable components and behave in a similar
//  manner to the objectSet node included in maya.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MPxNode.h>


// *****************************************************************************

// CLASS DECLARATION (MPxObjectSet)

/// Parent class of all user defined object sets. (OpenMaya) (OpenMayaMPx.py)
/**
	Create user defined sets.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxObjectSet : public MPxNode  
{
public:

	///
	MPxObjectSet();
	///
	virtual ~MPxObjectSet();
    ///               
	virtual MPxNode::Type type() const;
	///
	virtual bool canBeDeleted( bool isSrcNode );

	//
    // Inherited attributes
	//

	/// Connections to this attribute specify the dagNodes or
	/// parts (components) of the same that are members of this set.
	static MObject dagSetMembers;

	/// References to dependNode attributes which defines set membership.
	static MObject DNSetMembers;

	/// The index of a user defined color in which the dag object component
	/// members should appear. A value of -1 disables use of the color.
	/// Values outside the range [-1,7] may give unpredictable results.
	static MObject memberWireframeColor;

	/// A text string to annotate the set.
	static MObject annotation;

	/// This attribute is obsolete and should no longer be used
	static MObject isLayer;

	/// Is set membership restricted to objects with vertices?
	/// This attribute should not be explicitly changed by the user.
	static MObject verticesOnlySet;

	/// Is set membership restricted to objects with edges?
	/// This attribute should not be explicitly changed by the user.
	static MObject edgesOnlySet;

	/// Is set membership restricted to objects with facets?
	/// This attribute should not be explicitly changed by the user.
	static MObject facetsOnlySet;

	/// Is set membership restricted to objects with edit points?
	/// This attribute should not be explicitly changed by the user.
	static MObject editPointsOnlySet;

	/// Is set membership restricted to renderable objects only?
	/// This attribute should not be explicitly changed by the user.
	static MObject renderableOnlySet;

	/// References to the partition nodes this set is a member of.
	static MObject partition;

	/// When parts (components) of dagNodes are in the set, connections
	/// are made to this attribute to hold references to groupId nodes,
	/// with the id uniquely identifying the group in the dagNode.
	static MObject groupNodes;

	/// References to nodes that operate upon this set, such as deformers.
	static MObject usedByNodes;

private:
	static void				initialSetup();
	static const char*	    className();

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxObjectSet */
