#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <Xinput.h>
#include "xinput1_3.h"

#define XINPUT_GAMEPAD_GUIDE 0x400


HINSTANCE mHinst, mHinstDLL;
FARPROC mProcs[12];

LPCSTR mImportNames[] = {
	(LPCSTR )100, (LPCSTR )101, (LPCSTR )102, (LPCSTR )103, 
	"DllMain", "XInputEnable", "XInputGetBatteryInformation", "XInputGetCapabilities", 
	"XInputGetDSoundAudioDeviceGuids", "XInputGetKeystroke", "XInputGetState", "XInputSetState", 
};

static CHAR *                      //   return error message
getLastErrorText(                  // converts "Lasr Error" code into text
	CHAR *pBuf,                        //   message buffer
	ULONG bufSize)                     //   buffer size
{
	DWORD retSize;
	LPTSTR pTemp = NULL;

	if (bufSize < 16) {
		if (bufSize > 0) {
			pBuf[0] = '\0';
		}
		return(pBuf);
	}
	retSize = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_ARGUMENT_ARRAY,
		NULL,
		GetLastError(),
		LANG_NEUTRAL,
		(LPTSTR)&pTemp,
		0,
		NULL);
	if (!retSize || pTemp == NULL) {
		pBuf[0] = '\0';
	}
	else {
		pTemp[strlen(pTemp) - 2] = '\0'; //remove cr and newline character
		sprintf(pBuf, "%0.*s (0x%x)", bufSize - 16, pTemp, GetLastError());
		LocalFree((HLOCAL)pTemp);
	}
	return(pBuf);
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved ) {
	mHinst = hinstDLL;
	if ( fdwReason == DLL_PROCESS_ATTACH ) {
		OutputDebugString("Modified XInput1_3.dll: loading!");
		char sysdir[255], path[255];
		GetSystemDirectory( sysdir, 254 );
		sprintf( path, "%s\\xinput1_3.dll", sysdir );
		mHinstDLL = LoadLibrary( path );
		if (!mHinstDLL) {
			char buffer[500];
			OutputDebugString("Modified XInput1_3.dll: LoadLibrary failed");
			OutputDebugString(getLastErrorText(buffer, sizeof(buffer)));
			return (FALSE);
		}

		for ( int i = 0; i < 12; i++ )
			mProcs[ i ] = GetProcAddress( mHinstDLL, mImportNames[ i ] );
	} else if ( fdwReason == DLL_PROCESS_DETACH ) {
		FreeLibrary( mHinstDLL );
	}
	return ( TRUE );
}

DWORD WINAPI ordinal100(DWORD index, XINPUT_STATE *state) {
	typedef DWORD (__stdcall *RealGetStateType)(DWORD, XINPUT_STATE *);
	RealGetStateType realGetState = (RealGetStateType)mProcs[0];
	DWORD result = realGetState(index, state);

	if (result == 0) {
		state->Gamepad.wButtons &= (~XINPUT_GAMEPAD_GUIDE);
	}

	return result;
}

//  ?? 
int WINAPI ordinal101() {
	return callordinal101();
}

//  ?? 
int WINAPI ordinal102() {
	return callordinal102();
}

//  ?? 
int WINAPI ordinal103() {
	return callordinal103();
}

// DllMain
int WINAPI _DllMain() {
	return call_DllMain();
}

// XInputEnable
int WINAPI _XInputEnable() {
	return call_XInputEnable();
}

// XInputGetBatteryInformation
int WINAPI _XInputGetBatteryInformation() {
	return call_XInputGetBatteryInformation();
}

// XInputGetCapabilities
int WINAPI _XInputGetCapabilities() {
	return call_XInputGetCapabilities();
}

// XInputGetDSoundAudioDeviceGuids
int WINAPI _XInputGetDSoundAudioDeviceGuids() {
	return call_XInputGetDSoundAudioDeviceGuids();
}

// XInputGetKeystroke
int WINAPI _XInputGetKeystroke() {
	return call_XInputGetKeystroke();
}

// XInputGetState
int WINAPI _XInputGetState() {
	return call_XInputGetState();
}

// XInputSetState
int WINAPI _XInputSetState() {
	return call_XInputSetState();
}

