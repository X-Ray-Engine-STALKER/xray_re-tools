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
// CLASS:    MCommonRenderSettingsData
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MCommonRenderSettingsData)
//
// MCommonRenderSettingsData is a container class that encapsulates
// the data for common rendering globals. The data is intended to be 
// accessed with method 
//		MRenderUtil::setCommonRenderGlobals(MCommonRenderSettingsData)
//
// ****************************************************************************

#if defined __cplusplus


// ****************************************************************************

// INCLUDED HEADER FILES

#ifndef _MCommonRenderSettingsData
#define _MCommonRenderSettingsData

#include <maya/MTypes.h>
#include <maya/MTime.h>
#include <maya/MString.h>
#include <maya/MObject.h>

// ****************************************************************************

// CLASS DECLARATION (MCommonRenderSettingsData)

/// Data container for common rendering settings (OpenMayaRender) (OpenMayaRender.py)
/**
   This class is a container for common rendering settings
*/
class MRenderUtil;

class OPENMAYARENDER_EXPORT MCommonRenderSettingsData
{
	public:
	friend class MRenderUtil;
	enum MpathType{
			kRelativePath,
			kFullPathImage,
			kFullPathTmp};

	///
	MCommonRenderSettingsData();
	///
	~MCommonRenderSettingsData();

	///
	bool isAnimated() const;

	///
    bool isMovieFormat() const;

	/// Used with getImageName. Sets the pass name for later use.
	void			setPassName		(const MString & pass);
	/// Used with getImageName. Sets the field name for later use.
	void			setFieldName	(const MString & field);
	/// Obtains the image name with the proper subdirectory structure.
	const MString	getImageName(
						MpathType		pathType,
						double			frameNumber,
						const MString &	sceneName,
						const MString &	cameraName,
						const MString &	fileFormat,
						const MObject	layer,
						const bool		createDirectory = true,
						MStatus *		ReturnStatus = NULL) const;

	// The data set

	/// Base name for the rendered image
	MString			name;
	/// File naming scheme. 
	unsigned int 	namingScheme;
	/// Number of padding zeros for the frame number
	unsigned int 	framePadding;
	/// Single string that defines the whole naming convention
	MString			namePattern;

	/// Predefined supported image format
	unsigned int	imageFormat;
	/// Custom image format name
	MString			customImageFormat;

	/// First frame number
	MTime			frameStart;
	/// Last frame number
	MTime			frameEnd;
	/// Frame number step
	float			frameBy;

	/// When false, only the selected objects should be rendered
	bool			renderAll;

	/// When true, overrides the default image format extension
	bool			useCustomExt;
	/// Custom format extension, when useCustomExt is true
	MString			customExt;

	/// When true, images need to be renumbered. This only affects
	/// the image names.
	bool			renumberFrames;
	/// First image number, when renumbering
	float			renumberStart;
	/// Image number step, when renumbering
	float			renumberBy;

	/// Image width in pixels
	unsigned int	width;
	/// Image height in pixels
	unsigned int	height;
	/// Image aspect ratio. This is equal to pixelAspect * width / height
	float			deviceAspectRatio;
	/// Pixel aspect ratio
	float			pixelAspectRatio;
	/// Dot per Inch
	float			dotPerInch;

	/// When on, a default light should be created when no light is
	/// available in the scene.
	bool			enableDefaultLight;

	/// The mel string to be executed before a scene is rendered
	MString			preMel;
	/// The mel string to be executed after a scene is rendered
	MString			postMel;
	/// The mel string to be executed before a render layer is rendered
	MString			preRenderLayerMel;
	/// The mel string to be executed after a render layer is rendered
	MString			postRenderLayerMel;
	/// The mel string to be executed before a frame is rendered
	MString			preRenderMel;
	/// The mel string to be executed after a frame is rendered
	MString			postRenderMel;

	protected:
	static const char* className();

	private:
	
	// Pointer to the TcommonRenderGlobalsData class
	const void*		internalData;
};

#endif
#endif // _MCommonRenderSettingsData
