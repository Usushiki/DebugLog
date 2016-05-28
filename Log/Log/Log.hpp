//----------------------------------------------------------------//
//					      DebugLog.hpp							�@//		
//																  //
//			About   �o�̓E�B���h�E�ւ̃��O��\��			�@�@�@//
//     	    Last Update  2016/05/26								�@//
//																  //
//																  //
//																�@//
//----------------------------------------------------------------//

//-----------------------------
//���d�C���N���[�h�h�~
//-----------------------------
#pragma once

//-----------------------------
//�w�b�_�t�@�C���̃C���N���[�h
//-----------------------------
#include"LogDefine.hpp"

#include<sstream>


#ifdef GAIA_DEBUG

#include<crtdbg.h>


#endif // DEBUG 


//�}�N����`
#define DebugLogFileLine(...)DebugProcess(Log(__VA_ARGS__,__FILE__,__LINE__) )
#define DebugLog(...)DebugProcess(Log(__VA_ARGS__))


template<typename T, typename... Args>
inline void Log(const T& message, const Args&... args)
{
#ifdef GAIA_DEBUG


	std::wstringstream wss;

	wss << message;		//���b�Z�[�W���X�g���[���ɗ�������
	wss << "  ";

	Log(wss, args...);	//���b�Z�[�W���Ȃ��Ȃ�܂ōċA
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
	wss << L'\n';	//�I�[������ǉ�

	//�\��
	OutputDebugString(wss.str().c_str());
#endif
}
