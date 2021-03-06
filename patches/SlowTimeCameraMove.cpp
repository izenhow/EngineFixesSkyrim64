#include "../skse64_common/Relocation.h"
#include "../skse64_common/SafeWrite.h"

namespace SlowTimeCameraMove
{
	// 40 53 48 83 EC 50 F3 0F 10 51 ? 48 8B D9 +0x2B, +0x92, +0x1F9
	RelocAddr<uintptr_t> CameraMove_Timer1(0x00850A7F); // +0x4
	RelocAddr<uintptr_t> CameraMove_Timer2(0x00850AE6); // +0x4
	RelocAddr<uintptr_t> CameraMove_Timer3(0x00850C4D); // +0x4
	// F3 0F 59 1D ? ? ? ? F3 0F 10 05 ? ? ? ?
	RelocAddr<uintptr_t> CameraMove_Timer4(0x00850FEA); // +0x4
	// E8 ? ? ? ? 48 8D 4B 4C -> +0x13
	RelocAddr<uintptr_t> CameraMove_Timer5(0x008510B7); // +0x4

	bool Patch()
	{
		_MESSAGE("- slow time camera movement -");
		_MESSAGE("patching camera movement to use frame timer that ignores slow time");
		// patch (+0x4)
		SafeWrite8(CameraMove_Timer1.GetUIntPtr(), 0xC9);
		SafeWrite8(CameraMove_Timer2.GetUIntPtr(), 0x62);
		SafeWrite8(CameraMove_Timer3.GetUIntPtr(), 0xFB);
		SafeWrite8(CameraMove_Timer4.GetUIntPtr(), 0x5E);
		SafeWrite8(CameraMove_Timer5.GetUIntPtr(), 0x91);
		_MESSAGE("success");

		return true;
	}
}