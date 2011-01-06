#ifndef _MFnPlugin
#define _MFnPlugin
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
// CLASS:    MFnPlugin
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPlugin)
//
//  This class is used in the initializePlugin and uninitializePlugin functions
//  in a Maya plugin in order to register new services with Maya.  The
//  constructor for this class is passed the MObject provided by Maya as an
//  argument to initializePlugin and uninitializePlugin.  Subsequent calls are
//  made to the various "register" methods from inside initializePlugin, and to
//  the various "deregister" methods from inside uninitializePlugin.
//
//  A plug-in's uninitializePlugin function is not called automatically when Maya
//  exits.  Meaning any code which deallocates resources or a similar task will
//  be called when the plug-in is explicitly unloaded but not when Maya exits.
//  In order to work-around this problem and execute the code when Maya exits use
//  the MSceneMessage class's addCallback method with a message of "kMayaExiting".
//  This will register a callback function that will be executed when the
//  "kMayaExiting" message occurs.  Use this message and the addCallback method
//  to deallocate any resources when exiting.
//
//  A side effect of including MFnPlugin.h is to embed an API version string
//  into the .o file produced.  If it is necessary to include MFnPlugin.h
//  into more than one file that comprises a plugin, the preprocessor macro
//  MNoVersionString should be defined in all but one of those files
//  prior to the inclusion of MFnPlugin.h.  If this is not done, the linker
//  will produce warnings about multiple definitions of the variable
//  MApiVersion as the .so file is being produced.  These warning are
//  harmless and can be ignored.  Normally, this will not arise as only the
//  file that contains the initializePlugin and uninitializePlugin
//  routines should need to include MFnPlugin.h. Plugin developers on the 
//  Window's API developers will have to define MNoPluginEntry to suppress the
//  the creation of multiple definitions of DllMain. 
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MApiVersion.h>
#include <maya/MPxNode.h>
#include <maya/MPxData.h>

#if !defined(MNoPluginEntry)
#ifdef NT_PLUGIN
#include <maya/MTypes.h>
HINSTANCE MhInstPlugin;

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	MhInstPlugin = hInstance;
	return 1;
}
#endif // NT_PLUGIN
#endif // MNoPluginEntry

// *****************************************************************************

// DECLARATIONS
#define	PLUGIN_COMPANY "Autodesk"
struct _object;
typedef struct _object PyObject;

class MString;
class MFileObject;
class MTypeId;

class MPxMaterialInformation;
class MPxBakeEngine;
///
typedef MPxMaterialInformation* (*MMaterialInfoFactoryFnPtr) (MObject& object);
typedef MPxBakeEngine*	        (*MBakeEngineCreatorFnPtr)();
// *****************************************************************************

// CLASS DECLARATION (MFnPlugin)

/// Register and deregister plug-in services with Maya. (OpenMaya) (OpenMayaMPx.py)
/**
  Register plug-in supplied, commands, dependency nodes, etc. with Maya
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnPlugin : public MFnBase 
{
public:
	///
					MFnPlugin();
	///
					MFnPlugin( MObject& object,
							   const char* vendor = "Unknown",
							   const char* version = "Unknown",
							   const char* requiredApiVersion = "Any",
							   MStatus* ReturnStatus = 0L );
	///
	virtual			~MFnPlugin();
	///
	virtual			MFn::Type type() const; 

	///
	MString			vendor( MStatus* ReturnStatus=NULL ) const;
	///
	MString			version( MStatus* ReturnStatus=NULL ) const;
	///
	MString			apiVersion( MStatus* ReturnStatus=NULL ) const;
	///
	MString			name( MStatus* ReturnStatus=NULL ) const;
	///
	MString			loadPath( MStatus* ReturnStatus=NULL ) const;
	///
	MStatus			setName( const MString& newName,
							 bool allowRename = true );

	///
	MStatus			setVersion( const MString& newVersion );

	///
	MStatus			registerCommand(const MString& commandName,
									MCreatorFunction creatorFunction,
									MCreateSyntaxFunction 
									    createSyntaxFunction = NULL);
	///
	MStatus			deregisterCommand(	const MString& commandName );
	///
	MStatus 		registerControlCommand(const MString& commandName,
										   MCreatorFunction creatorFunction
										   );
	///
	MStatus			deregisterControlCommand(const MString& commandName);
	///
	MStatus 		registerModelEditorCommand(const MString& commandName,
								   		MCreatorFunction creatorFunction,
								   		MCreatorFunction paneCreatorFunction);
	///
	MStatus			deregisterModelEditorCommand(const MString& commandName);
	///
    MStatus         registerContextCommand( const MString& commandName,
											MCreatorFunction creatorFunction);

	///
    MStatus         registerContextCommand( const MString& commandName,
											MCreatorFunction creatorFunction,
											const MString& toolCmdName,
											MCreatorFunction toolCmdCreator,
											MCreateSyntaxFunction
												toolCmdSyntax = NULL
											);

	///
    MStatus         deregisterContextCommand( const MString& commandName );
	///
    MStatus         deregisterContextCommand( const MString& commandName,
											  const MString& toolCmdName );
	///
	MStatus			registerNode(	const MString& typeName,
									const MTypeId& typeId,
									MCreatorFunction creatorFunction,
									MInitializeFunction initFunction,
									MPxNode::Type type = MPxNode::kDependNode,
									const MString* classification = NULL); 
	///
	MStatus			deregisterNode(	const MTypeId& typeId );
	///
	MStatus			registerShape(	const MString& typeName,
									const MTypeId& typeId,
									MCreatorFunction creatorFunction,
									MInitializeFunction initFunction,
									MCreatorFunction uiCreatorFunction,
									const MString* classification = NULL); 
	///
	MStatus			registerTransform(	const MString& typeName,
										const MTypeId& typeId,
										MCreatorFunction creatorFunction,
										MInitializeFunction initFunction,
										MCreatorFunction xformCreatorFunction,
										const MTypeId& xformId,
										const MString* classification = NULL);
	///
	MStatus			registerData(	const MString& typeName,
									const MTypeId& typeId,
									MCreatorFunction creatorFunction,
									MPxData::Type type = MPxData::kData );
	///
	MStatus			deregisterData(	const MTypeId& typeId );
	///
	MStatus         registerDevice( const MString& deviceName,
									MCreatorFunction creatorFunction );
	///
	MStatus         deregisterDevice( const MString& deviceName );
	///
	MStatus			registerFileTranslator( const MString& translatorName,
										char* pixmapName,
										MCreatorFunction creatorFunction,
										char* optionsScriptName = NULL,
										char* defaultOptionsString = NULL,
										bool requiresFullMel = false );
	///
	MStatus			deregisterFileTranslator( const MString& translatorName );
	///
	MStatus			registerIkSolver( const MString& ikSolverName,
										MCreatorFunction creatorFunction );
	///
	MStatus			deregisterIkSolver( const MString& ikSolverName );
	///
	MStatus			registerUIStrings(MInitializeFunction registerMStringResources,
									  const MString &pluginStringsProc);

	MStatus			registerUI(PyObject * creationProc,
							   PyObject * deletionProc,
							   PyObject * creationBatchProc = NULL,
							   PyObject * deletionBatchProc = NULL);
	///
	MStatus			registerDragAndDropBehavior( const MString& behaviorName,
												 MCreatorFunction creatorFunction);

	///
	MStatus         deregisterDragAndDropBehavior( const MString& behaviorName );

	///
	MStatus			registerImageFile( const MString& imageFormatName,
									   MCreatorFunction creatorFunction,
									const MStringArray& imageFileExtensions); 
	///
	MStatus			deregisterImageFile( const MString& imageFormatName);

	///
	static MObject  findPlugin( const MString& pluginName );

	///
	static bool		isNodeRegistered(	const MString& typeName);

	///
	MTypeId			matrixTypeIdFromXformId(const MTypeId& xformTypeId, MStatus* ReturnStatus=NULL);

	///
	MStringArray	addMenuItem(
							const MString& menuItemName,
							const MString& parentName, 
							const MString& commandName, 
							const MString& commandParams,
							bool needOptionBox = false,
							const MString *optBoxFunction = NULL,
							MStatus *retStatus = NULL
							);
	///
	MStatus			removeMenuItem(MStringArray& menuItemNames);
	///
	MStatus			registerMaterialInfo(const MString& type, MMaterialInfoFactoryFnPtr fnPtr );
	///
	MStatus			unregisterMaterialInfo(const MString &typeName);
	///
	MStatus			registerBakeEngine(const MString &typeName, MBakeEngineCreatorFnPtr fnPtr );
	///
	MStatus			unregisterBakeEngine(const MString &typeName);

	///				
	static void			setRegisteringCallableScript();
	///
	static bool			registeringCallableScript();

BEGIN_NO_SCRIPT_SUPPORT:
	///     NO SCRIPT SUPPORT
	MStatus			registerUI(const MString & creationProc,
							   const MString & deletionProc,
							   const MString & creationBatchProc = "",
							   const MString & deletionBatchProc = "");
END_NO_SCRIPT_SUPPORT:

protected:
	virtual const char* className() const;

private:
					MFnPlugin( const MObject& object,
							   const char* vendor = "Unknown",
							   const char* version = "Unknown",
							   const char* requiredApiVersion = "Any",
							   MStatus* ReturnStatus = 0L );
	MFnPlugin&		operator=( const MFnPlugin & ) const;
	MFnPlugin&		operator=( const MFnPlugin & );
	MFnPlugin*		operator& () const;
	MFnPlugin*		operator& ();
};
#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnPlugin */
