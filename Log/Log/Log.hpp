//----------------------------------------------------------------//
//					      DebugLog.hpp							　//		
//																  //
//			About   出力ウィンドウへのログを表示			　　　//
//     	    Last Update  2016/05/26								　//
//																  //
//																  //
//																　//
//----------------------------------------------------------------//

//-----------------------------
//多重インクルード防止
//-----------------------------
#pragma once

//-----------------------------
//ヘッダファイルのインクルード
//-----------------------------
#include"LogDefine.hpp"

#include<sstream>


#ifdef GAIA_DEBUG

#include<crtdbg.h>


#endif // DEBUG 


//マクロ定義
#define DebugLogFileLine(...)DebugProcess(Log(__VA_ARGS__,__FILE__,__LINE__) )
#define DebugLog(...)DebugProcess(Log(__VA_ARGS__))


template<typename T, typename... Args>
inline void Log(const T& message, const Args&... args)
{
#ifdef GAIA_DEBUG


	std::wstringstream wss;

	wss << message;		//メッセージをストリームに流し込む
	wss << "  ";

	Log(wss, args...);	//メッセージがなくなるまで再帰
#endif
}



template<typename T, typename... Args>
inline void Log(std::wstringstream& wss, const T& message, const Args&... args)
{
#ifdef GAIA_DEBUG

	wss << message;		
	wss << "  ";
	
	Log(wss, args...);

#endif
}



inline void Log(std::wstringstream& wss)
{
#ifdef GAIA_DEBUG
	wss << "  ";
	wss << L'\n';	//終端文字を追加

	//表示
	OutputDebugString(wss.str().c_str());
#endif
}
