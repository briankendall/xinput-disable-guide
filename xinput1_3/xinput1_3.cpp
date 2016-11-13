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

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved ) {
	mHinst = hinstDLL;
	if ( fdwReason == DLL_PROCESS_ATTACH ) {
		char sysdir[255], path[255];
		GetSystemDirectory( sysdir, 254 );
		sprintf( path, "%s\\xinput1_3.dll", sysdir );
		mHinstDLL = LoadLibrary( path );
		if ( !mHinstDLL )
			return ( FALSE );

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

