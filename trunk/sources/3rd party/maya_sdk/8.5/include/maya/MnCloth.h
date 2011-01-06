#ifndef _MnCloth
#define _MnCloth
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
// CLASS:    MnCloth
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MnCloth)
//
//	This class wraps the internal Maya representation of N Cloth suitable
//  for use with the Nucleus solver.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>


// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MnCloth)
/// (OpenMayaFX) (OpenMayaFX.py)
/**
	Class for wrapping N cloth objects
*/

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class TnCloth;
class MFloatPointArray;

class OPENMAYAFX_EXPORT MnCloth
{

public:
 	///
					MnCloth(); 	 	
	///
    virtual			~MnCloth();

    ///
    MStatus         createNCloth();    
    ///
    MStatus         setTopology(const int numFaces, int * numVertsPerFace, int * faces, const int numEdges, int * edges );
    ///
    MStatus         setPositions(const MFloatPointArray & positions,bool startFrame = true);
    ///
    MStatus         setVelocities(const MFloatPointArray & velocities);

	///
    MStatus         setBendRestAngleFromPositions(const MFloatPointArray & positions);

	///
    MStatus         setLinksRestLengthFromPositions(const MFloatPointArray & positions);

    ///
    MStatus         setInputMeshAttractPositions(const MFloatPointArray & positions);

    ///
    MStatus         setInputMeshAttractDamping(float damping);

    ///
    MStatus         setInputMeshAttractAndRigidStrength(float * inputAttractArray,float *  rigidArray,float *  deformArray);    

	///
    MStatus         setComputeRestLength ( const bool b );

	///
    MStatus         setComputeRestAngles ( const bool b );

    ///
    MStatus         setThickness(float radius);
    ///
    MStatus         setThickness(float * radius);
    ///
    MStatus         setInverseMass(float invMass);
    ///
    MStatus         setInverseMass(float * invMass);
    ///
    MStatus         setBounce(float bounce);
    ///
    MStatus         setBounce(float * bounce);
    ///
    MStatus         setFriction(float friction);
    ///
    MStatus         setFriction(float * friction);
    ///
    MStatus         setDamping(float damping);
    ///
    MStatus         setDamping(float * damping);
    ///
    MStatus         setSelfCollisionFlags(const bool vertToVert, const bool vertToEdge = false, 
                                      const bool vertToFace = false, const bool edgeToEdge = false, 
                                      const bool edgeToFace = false);

    ///
    MStatus         setCollisionFlags(const bool vertToVert,
                                      const bool edgeToEdge = false, 
                                      const bool faceToFace= false);
    ///
    MStatus         setDisableGravity ( const bool b );

    ///
    MStatus         setMaxIterations(const int it);                     

    ///
    MStatus         setMaxSelfCollisionIterations(const int it);

    ///
    MStatus         setSelfCollisionSoftness(float softness);

	///
    MStatus         setSelfTrappedCheck(bool on);

	///
    MStatus         setSelfCrossoverPush(float val);
	
    ///
    MStatus         setDragAndLift(float drag,float lift);    

    ///
    MStatus         setTangentialDrag(float tangentialDrag);

    ///
    MStatus         setStartPressure(float startPressure);

    ///
    MStatus         setSealHoles(bool seal);

    ///
    MStatus         setPressure(float pressure);

    ///
    MStatus         setTrackVolume(bool track);

    ///
    MStatus         setIncompressibility(float v);

    ///
    MStatus         setPressureDamping(float damp);

    ///
    MStatus         setPumpRate(float pump);

    ///
    MStatus         setAirTightness(float airTightness);

    ///
    MStatus         setAddCrossLinks(float addCrossLinks);

    ///
    MStatus         setBendAngleDropoff(float dropoff);    

    ///
    MStatus         setShearResistance(float resistance);    

    ///
    MStatus         setStretchAndCompressionResistance(float stretchResist,float compressionResist);

	///
    MStatus         setStretchAndCompressionResistance(float * stretchResist,float * compressionResist);

    ///
    MStatus         setBendAngleScale(float scale);

    ///
    MStatus         setRestitutionAngle(float angle);

    ///
    MStatus         setRestitutionTension(float tension);

    ///
    MStatus         setSelfCollideWidth(float width);
    
    ///
    MStatus         setBendResistance(float strength);    
    
    ///
    MStatus         getNumVertices(unsigned int & numVerts) const;
    ///
    MStatus         getPositions(MFloatPointArray & positions) const;        
    ///
    MStatus         getVelocities(MFloatPointArray & velocities) const;    
    

protected:
// No protected members

private:
	MnCloth( TnCloth * );
    void  setNCloth(TnCloth * nObj,bool own);
    TnCloth * getNCloth() { return fNObject; };
    friend class MFnNObjectData;
	TnCloth * fNObject;	
	bool   fOwn;	
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MnCloth */
