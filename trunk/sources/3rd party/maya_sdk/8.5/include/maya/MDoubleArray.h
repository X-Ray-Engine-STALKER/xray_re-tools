#ifndef _MDoubleArray
#define _MDoubleArray
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
// CLASS:    MDoubleArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MDoubleArray)
//
//  This class implements an array of doubles.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently between plugins
//  and internal maya data structures.
//
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

// CLASS DECLARATION (MDoubleArray)

/// Array of doubles data type. (OpenMaya) (OpenMaya.py)
/**
  Implement an array of doubles data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MDoubleArray  
{
public:
 	///
					MDoubleArray();
 	///
					MDoubleArray( const MDoubleArray& other );
 	///
					MDoubleArray( const double src[], unsigned int count );
 	///
					MDoubleArray( const float src[], unsigned int count );
	///
					MDoubleArray( unsigned int initialSize, 
								  double initialValue = 0 );
	///
					~MDoubleArray();
 	///
 	MDoubleArray &  operator=( const MDoubleArray & other );
	///
	MStatus			set( double element, unsigned int index );
	///
	MStatus			set( float element, unsigned int index );
 	///
	MStatus			setLength( unsigned int length );
	///
 	unsigned int        length() const;
 	///
 	MStatus         remove( unsigned int index );
 	///
 	MStatus         insert( double element, unsigned int index );
 	///
 	MStatus         append( double element );
 	///
 	MStatus         copy( const MDoubleArray& source );
 	///
 	MStatus		 	clear();
	///
	MStatus			get( double[] ) const;
	///
	MStatus			get( float[] ) const;
	///
	void			setSizeIncrement ( unsigned int newIncrement );
	///
	unsigned int		sizeIncrement () const;

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
 	double &	 	operator[]( unsigned int index );
	/// NO SCRIPT SUPPORT
	double			operator[]( unsigned int index ) const;

	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT std::ostream &operator<<(std::ostream &os, 
											   const MDoubleArray &array);

END_NO_SCRIPT_SUPPORT:

#if defined(SWIG)
	swigTPythonObjectConverter(double);
	swigExtendAPIArray(MDoubleArray,double);
#endif

protected:
// No protected members

private:
	MDoubleArray( void* );
 	void * arr;
	const double* debugPeekValue;
	bool   own;
	static const char* className();
	void			syncDebugPeekValue();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MDoubleArray */
