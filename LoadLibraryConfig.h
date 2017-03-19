#pragma once
// 对是否允许加载指定的DLL进行配置
// 创建: 李欢 2017.03.18
// 配置规则:
// 1：配置文件名称："LoadLibraryConfig.ini"
// 2: 配置文件路径：执行程序根目录下
// 3: 格式:
//     [State]
//     $DllName1$.dll=1 // 允许加载
//     $DllName2$.dll=0 // 不允许加载



// 是否允许加载指定的DLL库 [创建 2017.03.18 李欢]
BOOL IsAllowLoadLibraryByConfig(LPCTSTR lpszLibrary);

// 根据配置加载DLL
// 包装 LoadLibrary
inline HMODULE LoadLibraryByConfig(LPCTSTR lpLibFileName)
{
	return IsAllowLoadLibraryByConfig(lpLibFileName)? ::LoadLibrary(lpLibFileName) : NULL;
}

// 包装 LoadLibraryEx
inline HMODULE LoadLibraryExByConfig( LPCTSTR lpLibFileName,HANDLE hFile, DWORD dwFlags)
{
	return IsAllowLoadLibraryByConfig(lpLibFileName)? ::LoadLibraryEx(lpLibFileName, hFile, dwFlags) : NULL;
}