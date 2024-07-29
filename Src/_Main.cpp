#include "ModUtils.hpp"
#include "HooksUtils.hpp"
#include "gd.h" 
using namespace cocos2d;
using namespace cocos2d::extension;

// = win 0x30ca60, imac 0x50c670, m1 0x46365c;
static inline bool verifyLevelIntegrity(std::string, int) {
    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) return TRUE;
    MH_Initialize();
    MappedHooks::registerHook(base + 0x30ca60, verifyLevelIntegrity);
    return TRUE;
}
