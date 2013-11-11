//-----------------------------------------------------------------------------
#ifndef expatHelperH
#define expatHelperH expatHelperH
//-----------------------------------------------------------------------------
#include <memory.h>
#include <stdio.h>
#include <Toolkits/expat/include/ExpatImpl.h>

//-----------------------------------------------------------------------------
template<class _Ty>
bool ParseXMLFromFile( CExpatImpl<_Ty>& parser, FILE* fp, const int bytesToProcessPerFileAccess = 256 )
//-----------------------------------------------------------------------------
{
	// Loop while there is data and processing so far went good
	bool boSuccess = true;
	while( !feof( fp ) && boSuccess )
	{
		char* pszBuffer = (char*)parser.GetBuffer( bytesToProcessPerFileAccess );
		if( !pszBuffer )
		{
			boSuccess = false;
		}
		else
		{
			const size_t nLength = fread( pszBuffer, 1, bytesToProcessPerFileAccess, fp );
			boSuccess = parser.ParseBuffer( static_cast<int>(nLength), nLength == 0 );
		}
	}
	return boSuccess;
}

//-----------------------------------------------------------------------------
template<class _Ty>
bool ParseXMLFromBuffer( CExpatImpl<_Ty>& parser, const char* pBuf, const size_t bufSize )
//-----------------------------------------------------------------------------
{
	char* pszBuffer = static_cast<char*>(parser.GetBuffer( static_cast<int>(bufSize) + 1 ));
	if( !pszBuffer )
	{
		return false;
	}

	memcpy( pszBuffer, pBuf, bufSize );
	pszBuffer[bufSize] = '\0'; // make this a well terminated string!
	return parser.ParseBuffer( static_cast<int>(bufSize), true );
}

#endif // expatHelperH
