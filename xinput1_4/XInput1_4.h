#ifndef __XInput1_4_h__
#define __XInput1_4_h__

	#define naked __declspec(naked)
	#define inline __forceinline


	extern FARPROC mProcs[];
	inline naked int callordinal100() { __asm { jmp dword ptr [ mProcs + 0 * 4 ] } }
	inline naked int callordinal101() { __asm { jmp dword ptr [ mProcs + 1 * 4 ] } }
	inline naked int callordinal102() { __asm { jmp dword ptr [ mProcs + 2 * 4 ] } }
	inline naked int callordinal103() { __asm { jmp dword ptr [ mProcs + 3 * 4 ] } }
	inline naked int callordinal104() { __asm { jmp dword ptr [ mProcs + 4 * 4 ] } }
	inline naked int callordinal108() { __asm { jmp dword ptr [ mProcs + 5 * 4 ] } }
	inline naked int call_DllMain() { __asm { jmp dword ptr [ mProcs + 6 * 4 ] } }
	inline naked int call_XInputEnable() { __asm { jmp dword ptr [ mProcs + 7 * 4 ] } }
	inline naked int call_XInputGetAudioDeviceIds() { __asm { jmp dword ptr [ mProcs + 8 * 4 ] } }
	inline naked int call_XInputGetBatteryInformation() { __asm { jmp dword ptr [ mProcs + 9 * 4 ] } }
	inline naked int call_XInputGetCapabilities() { __asm { jmp dword ptr [ mProcs + 10 * 4 ] } }
	inline naked int call_XInputGetKeystroke() { __asm { jmp dword ptr [ mProcs + 11 * 4 ] } }
	inline naked int call_XInputGetState() { __asm { jmp dword ptr [ mProcs + 12 * 4 ] } }
	inline naked int call_XInputSetState() { __asm { jmp dword ptr [ mProcs + 13 * 4 ] } }

#endif // __XInput1_4_h__
