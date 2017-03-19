#include "StdAfx.h"
#include "LoadLibraryConfig.h"

// 是否允许加载指定的DLL库 [添加 2017.03.18 李欢]
BOOL IsAllowLoadLibraryByConfig( LPCTSTR lpszLibrary )
{
	if (NULL == lpszLibrary || _tcslen(lpszLibrary) < 1)
		return FALSE;

	// 合成配置文件路径
	CString strAppPath;
	::GetModuleFileName(NULL, strAppPath.GetBuffer(MAX_PATH), MAX_PATH);
	strAppPath.ReleaseBuffer();
	int nPos = strAppPath.ReverseFind(_T('\\'));
	if (nPos != -1)
		strAppPath = strAppPath.Left(nPos);
	strAppPath = strAppPath + _T("\\LoadLibraryConfig.ini");

	// 默认返回1，即文件不存在或key不存在
	const int nState = ::GetPrivateProfileInt(_T("State"), lpszLibrary, 1, strAppPath);
#ifdef _DEBUG
	_tprintf(_T("%s\\[%s] %s=%d\n"), strAppPath, _T("State"), lpszLibrary, nState);
#endif // _DEBUG

	if (nState != 0)
		return TRUE;

	return FALSE;
}
