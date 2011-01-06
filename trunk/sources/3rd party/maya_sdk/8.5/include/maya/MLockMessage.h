#ifndef _MLockMessage
#define _MLockMessage
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
// CLASS:    MLockMessage
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MLockMessage)
//
//	This class is used to register callbacks for conditional node and
//	plug locking. These callbacks allow you to intercept events that
//	involve the internal testing of the lock flag on a node or
//	plug. If the node, or plug, is locked the assigned API callback
//	routine, if attached to the node, will be invoked, and, at this
//	time, you have the option to override the lock. This allows the
//	API programmer the ability to ignore a lock and allow a lock event
//	to occur. This allows the API programmer to adjust the level of
//	granularity on the locking mechanism. There are three levels of
//	locking callbacks.
//
//		\begin{itemize}
//		\item {\bf DAG Level Events}
//		\item {\bf All Other Node Level Events}
//      \item {\bf Plug Level Events} 
//		\end{itemize}
//
// To remove a callback use MMessage::removeCallback.  All callbacks
// that are registered by a plug-in must be removed by that plug-in
// when it is unloaded. Failure to do so will result in a fatal error.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#include <maya/MMessage.h>

// *****************************************************************************

// DECLARATIONS

class MPlug;
class MObject;
class MDGModifier;
class MDagPath; 

// *****************************************************************************

// CLASS DECLARATION (MLockMessage)

/// Node/plug locking messages. (OpenMaya) (OpenMaya.py)
/**
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MLockMessage : public MMessage
{ 
public:
	/// Plug related locking events 
	enum LockPlugEvent { 
		/// An invalid plug event received. 
		kInvalidPlug = 0,
		/// User is trying to lock the plug. 
		kPlugLockAttr,
		/// User is trying to unlock the plug. 
		kPlugUnlockAttr,			
		/// Plug lock query on plug value change.
		kPlugAttrValChange,			
		/// Plug lock query on a remove attribute event. 
		kPlugRemoveAttr,
		/// Plug lock query on a rename attribute event. 
		kPlugRenameAttr,
		/// Plug lock query on a connect to a locked attribute.
		kPlugConnect, 
		/// Plug lock query on a disconnect from a locked source attribute.
		kPlugDisconnect, 
		/// Used for internal bounds checking. 
		kLastPlug
	}; 

	/// DAG related locking events 
	enum LockDAGEvent { 
		/// Invalid DAG event received. 
		kInvalidDAG = 0,
		/// Lock query on group action. 	
		kGroup,
		/// Lock query on ungroup action. 
		kUnGroup,
   		/// Lock query on reparent action. 
		kReparent,
		/// Lock query on a child add action. 
		kChildReorder,
		/// Lock query on an instance event.
		kCreateNodeInstance,
    	/// Lock query on node whose children will be instanced.  
		kCreateChildInstance,
		/// Lock query on node whose parent will be instanced. 
		kCreateParentInstance,
		/// Used for internal bounds checking. 
		kLastDAG
	}; 
	
	/// Miscellaneous lock event types
	enum LockEvent { 
		/// Invalid node lock event received.  
		kInvalid = 0,
		/// Lock query on a rename event. 
		kRename,
		/// Lock query on a delete event. 
		kDelete,
		/// Lock query on a lock event. 
		kLockNode,
		/// Lock query on an unlock event. 
		kUnlockNode,
		/// Lock query on an add attribute event. 
		kAddAttr,
		/// Lock query on an remove attribute event. 
		kRemoveAttr,
		/// Lock query on an rename attribute event. 
		kRenameAttr,
		/// Lock query on an unlock attribute event. 
		kUnlockAttr, 
		/// Lock query on a lock attribute event. 
		kLockAttr,
		/// Used for internal bounds checking.  
		kLast
	}; 

	// Function pointer typedefs
	typedef void (*MLockEventFunction)( MObject &node,MObject &aux,void* clientData, MLockMessage::LockEvent eventType,bool &decision );
	typedef void (*MLockDagEventFunction)( MDagPath &dagPath,MDagPath &otherPath,void* clientData, MLockMessage::LockDAGEvent eventType,bool &decision );
	typedef void (*MLockPlugEventFunction)( MPlug &plug,MPlug &otherPlug,void * clientData, MLockMessage::LockPlugEvent eventType,bool &decision );

public:
	///
	static MCallbackId  setNodeLockQueryCallback( 
								MObject& node, 
								MLockMessage::MLockEventFunction func, 
								void *clientData = NULL, 
								MStatus *status = NULL );  
	///
	static MCallbackId  setNodeLockDAGQueryCallback( 
								MDagPath& path, 
								MLockMessage::MLockDagEventFunction func, 
								void *clientData = NULL, 
								MStatus *status = NULL ); 
	/// 
	static MCallbackId  setPlugLockQueryCallback( 
								MPlug& plug, 
								MLockMessage::MLockPlugEventFunction func, 
								void *clientData = NULL, 
								MStatus *status = NULL ); 
	///
	static MCallbackId  setPlugLockQueryCallback( 
								MObject& node, 
								MLockMessage::MLockPlugEventFunction func, 
								void *clientData = NULL, 
								MStatus *status = NULL ); 

protected: 
	// No protected. 

private: 
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************

#endif /* __cplusplus */
#endif /* _MLockMessage */
