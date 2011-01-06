#ifndef _MString
#define _MString
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
// CLASS:    MString
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MString)
//
//  The MString class implements a string class, and is used to pass
//  all string arguments to Maya API methods.

//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

class MStringArray;

// *****************************************************************************

// CLASS DECLARATION (MString)

/// Manipulate strings. (OpenMaya)
/**
 Methods for handling strings.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MString  
{

public:
	///
				MString();
	///
				MString( const char* charString );
	///
				MString( const wchar_t* charString );
    ///
                MString( const char* charString, int charLength );
    ///
				MString( const wchar_t* charString, int wcharLength );
	///
				MString( const MString& other );
	///
	        	~MString();
	///
	MString&	operator += ( const MString& other );
	///
	MString&	operator += ( const char * other );
	///
	MString&	operator += ( double other );
	///
	MString&	operator += ( int other );
	///
	MString&	operator += ( unsigned int other );
	///
	MString&	operator += ( float other );
	///
	MString&	operator =  ( const MString& other );
	///
	MString&	operator =  ( const char * other );
	///
	MString&	operator =  ( double value );
	///
	bool		operator == ( const MString& other ) const;
	///
	bool		operator == ( const char * other ) const;
	///
	bool		operator != ( const MString& other ) const;
	///
	bool		operator != ( const char * other ) const;
	///
	MString     operator + (const MString& other ) const;
	///
	MString     operator + (const char * other ) const;
	///
	MString     operator + ( double value ) const;
	///
	MStatus		set( const char * charString );
	///
	MStatus		setUTF8( const char *utf8String );
	///
	MStatus		setWChar( const wchar_t * wcharString );
    ///
    MStatus     set( const char * charString, int charLength );
	///
	MStatus		setWChar( const wchar_t * wcharString, int wcharLength );
	///
	MStatus		set( double value );
    ///
	MStatus		set( double value, int precision );
    ///
	const char*		asChar() const;
    ///
	const char*		asChar(int &charLength) const;
    ///
	const char* 	asUTF8() const;
    ///
	const char* 	asUTF8(int &utf8Length) const;
    ///
	const wchar_t*	asWChar() const;
    ///
	const wchar_t*	asWChar(int &numChars) const;
	///
	unsigned int	length() const;
    ///
	unsigned int    numChars() const; 
	///
	void		clear();
	///
	int			index(char) const;
	///
	int			indexW(char) const;
    ///
	int			indexW(wchar_t) const;
	///
	int			indexW(const MString &) const;
    ///
	int			rindex(char) const;
	///
	int			rindexW(char) const;
    ///
	int			rindexW(wchar_t) const;
    ///
	int			rindexW(const MString &) const;

	///
	MStatus		split(char, MStringArray&) const;
    ///
	MStatus		split(wchar_t, MStringArray&) const;
	///
	MString		substring(int start, int end) const;
    ///
	MString		substringW(int start, int end) const;
	///
	MString&	toUpperCase();
	///
	MString&	toLowerCase();
	///
	bool		isShort() const;
	///
	short		asShort() const;
	///
	bool		isInt() const;
	///
	int			asInt() const;
	///
	bool		isUnsigned() const;
	///
	unsigned int	asUnsigned() const;
	///
	bool		isFloat() const;
	///
	float		asFloat() const;
	///
	bool		isDouble() const;
	///
	double		asDouble() const;
	///
	MString		expandEnvironmentVariablesAndTilde( MStatus * ReturnStatus = NULL ) const;
	///
	MStatus     format(const MString &fmt, const MStringArray& args);
	///
	MStatus     format(const MString &fmt,
					   const MString& arg1=MString::argUnused,
					   const MString& arg2=MString::argUnused,
					   const MString& arg3=MString::argUnused,
					   const MString& arg4=MString::argUnused,
					   const MString& arg5=MString::argUnused,
					   const MString& arg6=MString::argUnused,
					   const MString& arg7=MString::argUnused,
					   const MString& arg8=MString::argUnused,
					   const MString& arg9=MString::argUnused,
					   const MString& arg10=MString::argUnused);

BEGIN_NO_SCRIPT_SUPPORT:

	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT std::ostream& operator<<(std::ostream&, const MString& );
	///	NO SCRIPT SUPPORT
	friend OPENMAYA_EXPORT MString operator+(const char *, const MString& );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
	struct {
		const char *stringValue;
		void  *impl;
	} api_data;
	//  Placeholder argument for variable argument list 
	static const MString argUnused; 
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32


// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MString */
