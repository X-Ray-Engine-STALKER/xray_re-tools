
#ifndef _MFnCamera
#define _MFnCamera
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
// CLASS:    MFnCamera
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnCamera)
//
// Function set for creation, edit, and query of cameras.
// 
// Many of the camera settings only affect the resulting rendered image. 
// E.g. the F/Stop, shutter speed, the film related options, etc.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MPoint.h>
#include <maya/MDGContext.h>

// *****************************************************************************

// DECLARATIONS

//class MPoint;
class MVector;
class MDagPath;
class MFloatMatrix;
class MPointArray;

// *****************************************************************************

// CLASS DECLARATION (MFnCamera)

/// Function set for cameras. (OpenMaya) (OpenMaya.py)
/**

*/
#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnCamera : public MFnDagNode 
{

	declareDagMFn(MFnCamera,MFnDagNode);
public:
	///
	MObject 	create( MStatus * ReturnStatus = NULL );
	///
	MObject 	create( MObject & parent, MStatus * ReturnStatus = NULL );
	///
	MPoint		eyePoint( MSpace::Space space = MSpace::kObject,
					MStatus * ReturnStatus = NULL ) const;
	///
	MVector		viewDirection( MSpace::Space space = MSpace::kObject,
					MStatus * ReturnStatus = NULL ) const;
	///
	MVector		upDirection( MSpace::Space space = MSpace::kObject,
					MStatus * ReturnStatus = NULL ) const;
	///
	MVector		rightDirection( MSpace::Space space = MSpace::kObject,
					MStatus * ReturnStatus = NULL ) const;
	///
	MPoint		centerOfInterestPoint(
					MSpace::Space space = MSpace::kObject,
					MStatus * ReturnStatus = NULL ) const;
	///
    MStatus     set ( const MPoint &	wsEyeLocation,
					  const MVector & 	wsViewDirection,
					  const MVector & 	wsUpDirection,
					  double         	horizFieldOfView,
					  double        	aspectRatio );
	///
    MStatus     setEyePoint( const MPoint &eyeLocation,
					MSpace::Space space = MSpace::kObject );
	///
    MStatus     setCenterOfInterestPoint( const MPoint &centerOfInterest,
					MSpace::Space space = MSpace::kObject );
	///
    bool        hasSamePerspective( const MDagPath &otherCamera,
								MStatus * ReturnStatus = NULL );
	///
    MStatus     copyViewFrom( const MDagPath &otherCamera );
	///
	MStatus		getFilmFrustum( double distance, MPointArray clipPlanes ) const;
	///
	MStatus		getFilmFrustum( double distance,
								double& hSize,
								double& vSize,
								double& hOffset,
								double& vOffset ) const;
	///
	MStatus		getPortFieldOfView( int width, int height,
									double& horizontalFOV,
									double& verticalFOV ) const;
	///
    MStatus		getViewingFrustum( double windowAspect,
								   double& left, double& right,
								   double& bottom, double& top,
								   bool applyOverscan = false,
								   bool applySqueeze = false ) const;
	///
    MStatus		getRenderingFrustum( double windowAspect,
									 double& left, double& right,
									 double& bottom, double& top ) const;
	///
	MFloatMatrix	projectionMatrix( MStatus * ReturnStatus = NULL ) const;
	///
	MFloatMatrix	projectionMatrix( MDGContext& context,
									  MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setHorizontalFilmAperture( double hFilmAperture );
	///
    double		horizontalFilmAperture( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setVerticalFilmAperture( double vFilmAperture );
	///
    double      verticalFilmAperture( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		getFilmApertureLimits( double & min, double & max ) const;
	///
    MStatus		setAspectRatio( double aspectRatio );
	///
    double      aspectRatio( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		getAspectRatioLimits(double & min, double & max) const;
	///
    MStatus		setVerticalLock( bool lockFlag );
	///
    bool        isVerticalLock( MStatus * ReturnStatus = NULL ) const;
	///
	double		horizontalFilmOffset( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setHorizontalFilmOffset( double hOffset );
	///
	double		verticalFilmOffset( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setVerticalFilmOffset( double vOffset );
	///
	enum FilmFit {
        ///
		kFillFilmFit,
        ///
		kHorizontalFilmFit,
        ///
		kVerticalFilmFit,
        ///
		kOverscanFilmFit,
        ///
		kInvalid
    };
	///
	MStatus		setFilmFit( FilmFit filmFit );
	///
	FilmFit		filmFit( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setFilmFitOffset( double filmFitOffset );
	///
	double		filmFitOffset( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setOverscan( double overscan );
	///
	double		overscan( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setHorizontalRollPivot( double horizontalRollPivot ); 
	///
	double		horizontalRollPivot( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus 	setVerticalRollPivot( double verticalRollPivot ); 
	///
	double		verticalRollPivot( MStatus * ReturnStatus = NULL ) const; 
	///
	MStatus 	setFilmRollValue( double filmRollValue );
	///
	double 		filmRollValue( MStatus * ReturnStatus = NULL ) const; 
	///
	enum RollOrder { 
		///
		kRotateTranslate,
		///
		kTranslateRotate
	}; 
	/// 
	MStatus		setFilmRollOrder( RollOrder filmRollOrder ); 
	///
	RollOrder	filmRollOrder( MStatus * ReturnStatus = NULL ) const; 
	///
	MStatus		setPreScale( double sf ); 
	/// 
	double		preScale( MStatus * ReturnStatus = NULL ) const; 
	///
	MStatus		setPostScale( double sf ); 
	/// 
	double		postScale( MStatus * ReturnStatus = NULL ) const; 
	///
	MStatus		setFilmTranslateH( double translate ); 
	///
	double		filmTranslateH( MStatus * ReturnStatus = NULL ) const; 
	/// 
	MStatus		setFilmTranslateV( double translate ); 
	/// 
	double		filmTranslateV( MStatus * ReturnStatus = NULL ) const; 
	///
	MFloatMatrix postProjectionMatrix( MStatus * ReturnStatus = NULL ) const; 
	///
	MFloatMatrix postProjectionMatrix( MDGContext& context, MStatus * ReturnStatus = NULL ) const;
	/// 
	MStatus		setDisplayFilmGate( bool displayFilmGate );
	///
	bool		isDisplayFilmGate( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setHorizontalFieldOfView( double fov );
	///
    double      horizontalFieldOfView( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setVerticalFieldOfView( double fov );
	///
    double      verticalFieldOfView( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setFocalLength( double focalLength );
	///
    double      focalLength( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		getFocalLengthLimits( double & min, double & max ) const;
	///
    MStatus		setLensSqueezeRatio( double lensSqueezeRatio );
	///
    double      lensSqueezeRatio( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setClippingPlanes( bool ClippingPlanes );
	///
    bool        isClippingPlanes( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setNearClippingPlane( double dNear );
	///
    double      nearClippingPlane( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setFarClippingPlane( double dFar );
	///
    double      farClippingPlane( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setNearFarClippingPlanes( double dNear, double dFar );
	///
    MStatus		setDepthOfField( bool depthOfField );
	///
    bool        isDepthOfField( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setFStop( double fStop );
	///
    double      fStop( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setFocusDistance( double distance );
	///
    double		focusDistance( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setNearFocusDistance( double nearFocusDistance );
	///
    double      nearFocusDistance( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setFarFocusDistance( double farFocusDistance );
	///
    double      farFocusDistance( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		computeDepthOfField();
	///
    MStatus		computeDepthOfField( double nearLimit );
	///
    MStatus		setMotionBlur( bool motionBlur );
	///
    bool        isMotionBlur( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setShutterAngle( double shutterAngle );
	///
    double      shutterAngle( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setCenterOfInterest( double dist );
	///
    double      centerOfInterest( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setIsOrtho( bool orthoState );
	///
    MStatus		setIsOrtho( bool orthoState, double useDist );
	///
    bool        isOrtho( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setOrthoWidth( double orthoWidth );
	///
    double      orthoWidth( MStatus * ReturnStatus = NULL ) const;
	///
    MStatus		setCameraScale( double scale );
	///
    double      cameraScale( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus		setTumblePivot( const MPoint& point );
	///
	MPoint		tumblePivot( MStatus * ReturnStatus = NULL ) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareDagMFnConstConstructor( MFnCamera,MFnDagNode );

	/// OBSOLETE & NO SCRIPT SUPPORT
	MStatus		setStereo( bool stereo );
	/// OBSOLETE & NO SCRIPT SUPPORT
	bool    	isStereo( MStatus * ReturnStatus = NULL ) const;
	/// OBSOLETE & NO SCRIPT SUPPORT
	MStatus		setParallelView( bool parallelView );
	/// OBSOLETE & NO SCRIPT SUPPORT
	bool    	isParallelView( MStatus * ReturnStatus = NULL ) const;
	/// OBSOLETE & NO SCRIPT SUPPORT
	MStatus		setEyeOffset( double eyeOffset );
	/// OBSOLETE & NO SCRIPT SUPPORT
	double		eyeOffset( MStatus * ReturnStatus = NULL ) const;

	///	NO SCRIPT SUPPORT
	MStatus		getFilmFrustum( double distance, MPoint clipPlane[4] ) const;
	
END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members

};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnCamera */
