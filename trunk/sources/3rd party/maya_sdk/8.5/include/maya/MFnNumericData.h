
#ifndef _MFnNumericData
#define _MFnNumericData
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
// CLASS:    MFnNumericData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnNumericData)
//
//  MFnNumericData allows the creation and manipulation of numeric data objects
//  for use in the dependency graph.  Normally, data objects are not required 
//  for the transmission of numeric data.  The graph supports numeric types 
//  directly (see the methods of MDataHandle).
//
//  Numeric data objects are useful if you have an attribute that accepts
//  generic data.  A generic attribute can accept multiple types of data,
//  so you cannot hardwire it to accept a specific type of numeric data.
//  So, generic attributes can only accept numeric data in the form of actual
//  data objects.
//
//  This function set only supports pairs and triples of numeric data.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// CLASS DECLARATION (MFnNumericData)

/// Numeric data function set. (OpenMaya) (OpenMaya.py)
/**
 MFnNumericData allows the manipulation of numeric data for
 dependency node attributes.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnNumericData : public MFnData 
{

	declareMFn(MFnNumericData, MFnData);

public:

	///
	enum Type {
        ///
		kInvalid,
        /// Boolean
		kBoolean,
        /// One byte
		kByte,
        /// One character
		kChar,
        /// One short
		kShort,
		/// Two shorts
		k2Short,
		/// Three shorts
		k3Short,
        /// One long  (actually int since "long" is not platform-consistent)
		kLong,
		/// One int		
		kInt = kLong,
		/// Two longs  (actually 2 ints since "long" is not platform-consistent)
		k2Long,
		/// Two ints
		k2Int = k2Long,
		/// Three longs  (actually 3 ints since "long" is not platform-consistent)
		k3Long,
		/// Three ints
		k3Int = k3Long,
        /// One float
		kFloat,
		/// Two floats
		k2Float,
		/// Three floats
		k3Float,
        /// One double
		kDouble,
		/// Two doubles
		k2Double,
		/// Three doubles
		k3Double,
		/// Four doubles
		k4Double,
        /// An address
        kAddr,
		///
		kLast
    };

	///
	MObject create( Type dataType, MStatus* ReturnStatus = NULL );

	///
	Type numericType( MStatus* ReturnStatus = NULL );

BEGIN_NO_SCRIPT_SUPPORT:
	///     NO SCRIPT SUPPORT
	MStatus getData( short& val1, short& val2 );
	///     NO SCRIPT SUPPORT
	MStatus getData( int& val1, int& val2 );
	///     NO SCRIPT SUPPORT
	MStatus getData( float& val1, float& val2 );
	///     NO SCRIPT SUPPORT
	MStatus getData( double& val1, double& val2 );
	///     NO SCRIPT SUPPORT
	MStatus getData( short& val1, short& val2, short& val3 );
	///     NO SCRIPT SUPPORT
	MStatus getData( int& val1, int& val2, int& val3 );
	///     NO SCRIPT SUPPORT
	MStatus getData( float& val1, float& val2, float& val3 );
	///     NO SCRIPT SUPPORT
	MStatus getData( double& val1, double& val2, double& val3 );
	///     NO SCRIPT SUPPORT
	MStatus getData( double& val1, double& val2, double& val3, double& val4 );

	///     NO SCRIPT SUPPORT
	MStatus setData( short val1, short val2 );
	///     NO SCRIPT SUPPORT
	MStatus setData( int val1, int val2 );
	///     NO SCRIPT SUPPORT
	MStatus setData( float val1, float val2 );
	///     NO SCRIPT SUPPORT
	MStatus setData( double val1, double val2 );
	///     NO SCRIPT SUPPORT
	MStatus setData( short val1, short val2, short val3 );
	///     NO SCRIPT SUPPORT
	MStatus setData( int val1, int val2, int val3 );
	///     NO SCRIPT SUPPORT
	MStatus setData( float val1, float val2, float val3 );
	///     NO SCRIPT SUPPORT
	MStatus setData( double val1, double val2, double val3 );
	///     NO SCRIPT SUPPORT
	MStatus setData( double val1, double val2, double val3, double val4 );

	///     NO SCRIPT SUPPORT
 	declareMFnConstConstructor( MFnNumericData, MFnData );
	
END_NO_SCRIPT_SUPPORT:

	///
	MStatus getData2Short( short& val1, short& val2 );
	///
	MStatus getData2Int( int& val1, int& val2 );
	///
	MStatus getData2Float( float& val1, float& val2 );
	///
	MStatus getData2Double( double& val1, double& val2 );
	///
	MStatus getData3Short( short& val1, short& val2, short& val3 );
	///
	MStatus getData3Int( int& val1, int& val2, int& val3 );
	///
	MStatus getData3Float( float& val1, float& val2, float& val3 );
	///
	MStatus getData3Double( double& val1, double& val2, double& val3 );
	///
	MStatus getData4Double( double& val1, double& val2, double& val3, double& val4 );

	///
	MStatus setData2Short( short val1, short val2 );
	///
	MStatus setData2Int( int val1, int val2 );
	///
	MStatus setData2Float( float val1, float val2 );
	///
	MStatus setData2Double( double val1, double val2 );
	///
	MStatus setData3Short( short val1, short val2, short val3 );
	///
	MStatus setData3Int( int val1, int val2, int val3 );
	///
	MStatus setData3Float( float val1, float val2, float val3 );
	///
	MStatus setData3Double( double val1, double val2, double val3 );
	///
	MStatus setData4Double( double val1, double val2, double val3, double val4 );


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
#endif /* _MFnNumericData */
