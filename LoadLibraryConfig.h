#pragma once
// ���Ƿ��������ָ����DLL��������
// ����: � 2017.03.18
// ���ù���:
// 1�������ļ����ƣ�"LoadLibraryConfig.ini"
// 2: �����ļ�·����ִ�г����Ŀ¼��
// 3: ��ʽ:
//     [State]
//     $DllName1$.dll=1 // �������
//     $DllName2$.dll=0 // ���������



// �Ƿ��������ָ����DLL�� [���� 2017.03.18 �]
BOOL IsAllowLoadLibraryByConfig(LPCTSTR lpszLibrary);

// �������ü���DLL
// ��װ LoadLibrary
inline HMODULE LoadLibraryByConfig(LPCTSTR lpLibFileName)
{
	return IsAllowLoadLibraryByConfig(lpLibFileName)? ::LoadLibrary(lpLibFileName) : NULL;
}

// ��װ LoadLibraryEx
inline HMODULE LoadLibraryExByConfig( LPCTSTR lpLibFileName,HANDLE hFile, DWORD dwFlags)
{
	return IsAllowLoadLibraryByConfig(lpLibFileName)? ::LoadLibraryEx(lpLibFileName, hFile, dwFlags) : NULL;
}