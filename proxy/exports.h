#pragma once

extern "C" FARPROC OriginalFuncs_dwmapi[99];
extern "C" FARPROC OriginalFuncs_psapi[27];
extern "C" FARPROC OriginalFuncs_version[17];
extern "C" FARPROC OriginalFuncs_winhttp[65];
extern "C" FARPROC OriginalFuncs_winmm[181];

namespace Exports {
	inline constexpr std::array<const char*, 5> compatibleModules = { "dwmapi.dll", "psapi.dll", "version.dll", "winhttp.dll", "winmm.dll"};
	
	constexpr std::array<const char*, 181> winmmExportNames = {
		"CloseDriver",
		"DefDriverProc",
		"DriverCallback",
		"DrvGetModuleHandle",
		"GetDriverModuleHandle",
		"OpenDriver",
		"PlaySound",
		"PlaySoundA",
		"PlaySoundW",
		"SendDriverMessage",
		"WOWAppExit",
		"auxGetDevCapsA",
		"auxGetDevCapsW",
		"auxGetNumDevs",
		"auxGetVolume",
		"auxOutMessage",
		"auxSetVolume",
		"joyConfigChanged",
		"joyGetDevCapsA",
		"joyGetDevCapsW",
		"joyGetNumDevs",
		"joyGetPos",
		"joyGetPosEx",
		"joyGetThreshold",
		"joyReleaseCapture",
		"joySetCapture",
		"joySetThreshold",
		"mciDriverNotify",
		"mciDriverYield",
		"mciExecute",
		"mciFreeCommandResource",
		"mciGetCreatorTask",
		"mciGetDeviceIDA",
		"mciGetDeviceIDFromElementIDA",
		"mciGetDeviceIDFromElementIDW",
		"mciGetDeviceIDW",
		"mciGetDriverData",
		"mciGetErrorStringA",
		"mciGetErrorStringW",
		"mciGetYieldProc",
		"mciLoadCommandResource",
		"mciSendCommandA",
		"mciSendCommandW",
		"mciSendStringA",
		"mciSendStringW",
		"mciSetDriverData",
		"mciSetYieldProc",
		"midiConnect",
		"midiDisconnect",
		"midiInAddBuffer",
		"midiInClose",
		"midiInGetDevCapsA",
		"midiInGetDevCapsW",
		"midiInGetErrorTextA",
		"midiInGetErrorTextW",
		"midiInGetID",
		"midiInGetNumDevs",
		"midiInMessage",
		"midiInOpen",
		"midiInPrepareHeader",
		"midiInReset",
		"midiInStart",
		"midiInStop",
		"midiInUnprepareHeader",
		"midiOutCacheDrumPatches",
		"midiOutCachePatches",
		"midiOutClose",
		"midiOutGetDevCapsA",
		"midiOutGetDevCapsW",
		"midiOutGetErrorTextA",
		"midiOutGetErrorTextW",
		"midiOutGetID",
		"midiOutGetNumDevs",
		"midiOutGetVolume",
		"midiOutLongMsg",
		"midiOutMessage",
		"midiOutOpen",
		"midiOutPrepareHeader",
		"midiOutReset",
		"midiOutSetVolume",
		"midiOutShortMsg",
		"midiOutUnprepareHeader",
		"midiStreamClose",
		"midiStreamOpen",
		"midiStreamOut",
		"midiStreamPause",
		"midiStreamPosition",
		"midiStreamProperty",
		"midiStreamRestart",
		"midiStreamStop",
		"mixerClose",
		"mixerGetControlDetailsA",
		"mixerGetControlDetailsW",
		"mixerGetDevCapsA",
		"mixerGetDevCapsW",
		"mixerGetID",
		"mixerGetLineControlsA",
		"mixerGetLineControlsW",
		"mixerGetLineInfoA",
		"mixerGetLineInfoW",
		"mixerGetNumDevs",
		"mixerMessage",
		"mixerOpen",
		"mixerSetControlDetails",
		"mmDrvInstall",
		"mmGetCurrentTask",
		"mmTaskBlock",
		"mmTaskCreate",
		"mmTaskSignal",
		"mmTaskYield",
		"mmioAdvance",
		"mmioAscend",
		"mmioClose",
		"mmioCreateChunk",
		"mmioDescend",
		"mmioFlush",
		"mmioGetInfo",
		"mmioInstallIOProcA",
		"mmioInstallIOProcW",
		"mmioOpenA",
		"mmioOpenW",
		"mmioRead",
		"mmioRenameA",
		"mmioRenameW",
		"mmioSeek",
		"mmioSendMessage",
		"mmioSetBuffer",
		"mmioSetInfo",
		"mmioStringToFOURCCA",
		"mmioStringToFOURCCW",
		"mmioWrite",
		"mmsystemGetVersion",
		"sndPlaySoundA",
		"sndPlaySoundW",
		"timeBeginPeriod",
		"timeEndPeriod",
		"timeGetDevCaps",
		"timeGetSystemTime",
		"timeGetTime",
		"timeKillEvent",
		"timeSetEvent",
		"waveInAddBuffer",
		"waveInClose",
		"waveInGetDevCapsA",
		"waveInGetDevCapsW",
		"waveInGetErrorTextA",
		"waveInGetErrorTextW",
		"waveInGetID",
		"waveInGetNumDevs",
		"waveInGetPosition",
		"waveInMessage",
		"waveInOpen",
		"waveInPrepareHeader",
		"waveInReset",
		"waveInStart",
		"waveInStop",
		"waveInUnprepareHeader",
		"waveOutBreakLoop",
		"waveOutClose",
		"waveOutGetDevCapsA",
		"waveOutGetDevCapsW",
		"waveOutGetErrorTextA",
		"waveOutGetErrorTextW",
		"waveOutGetID",
		"waveOutGetNumDevs",
		"waveOutGetPitch",
		"waveOutGetPlaybackRate",
		"waveOutGetPosition",
		"waveOutGetVolume",
		"waveOutMessage",
		"waveOutOpen",
		"waveOutPause",
		"waveOutPrepareHeader",
		"waveOutReset",
		"waveOutRestart",
		"waveOutSetPitch",
		"waveOutSetPlaybackRate",
		"waveOutSetVolume",
		"waveOutUnprepareHeader",
		"waveOutWrite",
		"ExportByOrdinal2"
	};

	constexpr std::array<const char*, 65> winhttpExportNames = {
		"Private1",
		"SvchostPushServiceGlobals",
		"WinHttpAddRequestHeaders",
		"WinHttpAutoProxySvcMain",
		"WinHttpCheckPlatform",
		"WinHttpCloseHandle",
		"WinHttpConnect",
		"WinHttpConnectionDeletePolicyEntries",
		"WinHttpConnectionDeleteProxyInfo",
		"WinHttpConnectionFreeNameList",
		"WinHttpConnectionFreeProxyInfo",
		"WinHttpConnectionFreeProxyList",
		"WinHttpConnectionGetNameList",
		"WinHttpConnectionGetProxyInfo",
		"WinHttpConnectionGetProxyList",
		"WinHttpConnectionSetPolicyEntries",
		"WinHttpConnectionSetProxyInfo",
		"WinHttpConnectionUpdateIfIndexTable",
		"WinHttpCrackUrl",
		"WinHttpCreateProxyResolver",
		"WinHttpCreateUrl",
		"WinHttpDetectAutoProxyConfigUrl",
		"WinHttpFreeProxyResult",
		"WinHttpFreeProxyResultEx",
		"WinHttpFreeProxySettings",
		"WinHttpGetDefaultProxyConfiguration",
		"WinHttpGetIEProxyConfigForCurrentUser",
		"WinHttpGetProxyForUrl",
		"WinHttpGetProxyForUrlEx",
		"WinHttpGetProxyForUrlEx2",
		"WinHttpGetProxyForUrlHvsi",
		"WinHttpGetProxyResult",
		"WinHttpGetProxyResultEx",
		"WinHttpGetProxySettingsVersion",
		"WinHttpGetTunnelSocket",
		"WinHttpOpen",
		"WinHttpOpenRequest",
		"WinHttpPacJsWorkerMain",
		"WinHttpProbeConnectivity",
		"WinHttpQueryAuthSchemes",
		"WinHttpQueryDataAvailable",
		"WinHttpQueryHeaders",
		"WinHttpQueryOption",
		"WinHttpReadData",
		"WinHttpReadProxySettings",
		"WinHttpReadProxySettingsHvsi",
		"WinHttpReceiveResponse",
		"WinHttpResetAutoProxy",
		"WinHttpSaveProxyCredentials",
		"WinHttpSendRequest",
		"WinHttpSetCredentials",
		"WinHttpSetDefaultProxyConfiguration",
		"WinHttpSetOption",
		"WinHttpSetStatusCallback",
		"WinHttpSetTimeouts",
		"WinHttpTimeFromSystemTime",
		"WinHttpTimeToSystemTime",
		"WinHttpWebSocketClose",
		"WinHttpWebSocketCompleteUpgrade",
		"WinHttpWebSocketQueryCloseStatus",
		"WinHttpWebSocketReceive",
		"WinHttpWebSocketSend",
		"WinHttpWebSocketShutdown",
		"WinHttpWriteData",
		"WinHttpWriteProxySettings"
	};

	constexpr std::array<const char*, 17> versionExportNames = {
		"GetFileVersionInfoA",
		"GetFileVersionInfoByHandle",
		"GetFileVersionInfoExA",
		"GetFileVersionInfoExW",
		"GetFileVersionInfoSizeA",
		"GetFileVersionInfoSizeExA",
		"GetFileVersionInfoSizeExW",
		"GetFileVersionInfoSizeW",
		"GetFileVersionInfoW",
		"VerFindFileA",
		"VerFindFileW",
		"VerInstallFileA",
		"VerInstallFileW",
		"VerLanguageNameA",
		"VerLanguageNameW",
		"VerQueryValueA",
		"VerQueryValueW"
	};

	constexpr std::array<const char*, 27> psapiExportNames = {
		"EmptyWorkingSet",
		"EnumDeviceDrivers",
		"EnumPageFilesA",
		"EnumPageFilesW",
		"EnumProcessModules",
		"EnumProcessModulesEx",
		"EnumProcesses",
		"GetDeviceDriverBaseNameA",
		"GetDeviceDriverBaseNameW",
		"GetDeviceDriverFileNameA",
		"GetDeviceDriverFileNameW",
		"GetMappedFileNameA",
		"GetMappedFileNameW",
		"GetModuleBaseNameA",
		"GetModuleBaseNameW",
		"GetModuleFileNameExA",
		"GetModuleFileNameExW",
		"GetModuleInformation",
		"GetPerformanceInfo",
		"GetProcessImageFileNameA",
		"GetProcessImageFileNameW",
		"GetProcessMemoryInfo",
		"GetWsChanges",
		"GetWsChangesEx",
		"InitializeProcessForWsWatch",
		"QueryWorkingSet",
		"QueryWorkingSetEx"
	};

	constexpr std::array<const char*, 99> dwmapiExportNames = {
		"DwmpDxGetWindowSharedSurface",
		"DwmpDxUpdateWindowSharedSurface",
		"DwmEnableComposition",
		"dwmapiExportByOrdinal0",
		"dwmapiExportByOrdinal1",
		"dwmapiExportByOrdinal2",
		"dwmapiExportByOrdinal3",
		"dwmapiExportByOrdinal4",
		"dwmapiExportByOrdinal5",
		"dwmapiExportByOrdinal6",
		"dwmapiExportByOrdinal7",
		"DllCanUnloadNow",
		"dwmapiExportByOrdinal8",
		"dwmapiExportByOrdinal9",
		"dwmapiExportByOrdinal10",
		"DllGetClassObject",
		"DwmAttachMilContent",
		"DwmDefWindowProc",
		"DwmDetachMilContent",
		"DwmEnableBlurBehindWindow",
		"DwmEnableMMCSS",
		"DwmExtendFrameIntoClientArea",
		"DwmFlush",
		"DwmGetColorizationColor",
		"dwmapiExportByOrdinal11",
		"DwmGetCompositionTimingInfo",
		"DwmGetGraphicsStreamClient",
		"DwmpGetColorizationParameters",
		"DwmpDxgiIsThreadDesktopComposited",
		"DwmGetGraphicsStreamTransformHint",
		"DwmGetTransportAttributes",
		"DwmpSetColorizationParameters",
		"dwmapiExportByOrdinal12",
		"DwmGetUnmetTabRequirements",
		"DwmGetWindowAttribute",
		"DwmpRenderFlick",
		"DwmpAllocateSecurityDescriptor",
		"DwmpFreeSecurityDescriptor",
		"dwmapiExportByOrdinal13",
		"dwmapiExportByOrdinal14",
		"dwmapiExportByOrdinal15",
		"dwmapiExportByOrdinal16",
		"dwmapiExportByOrdinal17",
		"DwmpEnableDDASupport",
		"dwmapiExportByOrdinal18",
		"dwmapiExportByOrdinal19",
		"dwmapiExportByOrdinal20",
		"dwmapiExportByOrdinal21",
		"dwmapiExportByOrdinal22",
		"DwmInvalidateIconicBitmaps",
		"dwmapiExportByOrdinal23",
		"dwmapiExportByOrdinal24",
		"dwmapiExportByOrdinal25",
		"dwmapiExportByOrdinal26",
		"dwmapiExportByOrdinal27",
		"dwmapiExportByOrdinal28",
		"DwmTetherTextContact",
		"dwmapiExportByOrdinal29",
		"dwmapiExportByOrdinal30",
		"dwmapiExportByOrdinal31",
		"dwmapiExportByOrdinal32",
		"dwmapiExportByOrdinal33",
		"dwmapiExportByOrdinal34",
		"dwmapiExportByOrdinal35",
		"dwmapiExportByOrdinal36",
		"dwmapiExportByOrdinal37",
		"dwmapiExportByOrdinal38",
		"dwmapiExportByOrdinal39",
		"dwmapiExportByOrdinal40",
		"dwmapiExportByOrdinal41",
		"dwmapiExportByOrdinal42",
		"dwmapiExportByOrdinal43",
		"dwmapiExportByOrdinal44",
		"dwmapiExportByOrdinal45",
		"dwmapiExportByOrdinal46",
		"dwmapiExportByOrdinal47",
		"dwmapiExportByOrdinal48",
		"dwmapiExportByOrdinal49",
		"dwmapiExportByOrdinal50",
		"dwmapiExportByOrdinal51",
		"dwmapiExportByOrdinal52",
		"dwmapiExportByOrdinal53",
		"dwmapiExportByOrdinal54",
		"DwmpUpdateProxyWindowForCapture",
		"DwmIsCompositionEnabled",
		"DwmModifyPreviousDxFrameDuration",
		"DwmQueryThumbnailSourceSize",
		"DwmRegisterThumbnail",
		"DwmRenderGesture",
		"DwmSetDxFrameDuration",
		"DwmSetIconicLivePreviewBitmap",
		"DwmSetIconicThumbnail",
		"DwmSetPresentParameters",
		"DwmSetWindowAttribute",
		"DwmShowContact",
		"DwmTetherContact",
		"DwmTransitionOwnedWindow",
		"DwmUnregisterThumbnail",
		"DwmUpdateThumbnailProperties"
	};

	void load(HMODULE originalModule, const char* const* exportNames, FARPROC* originalFunctions, size_t arraySize);

	inline void load_dwmapi(const HMODULE originalModule) { load(originalModule, dwmapiExportNames.data(), OriginalFuncs_dwmapi, dwmapiExportNames.size()); }
	inline void load_psapi(const HMODULE originalModule) { load(originalModule, psapiExportNames.data(), OriginalFuncs_psapi, psapiExportNames.size()); }
	inline void load_version(const HMODULE originalModule) { load(originalModule, versionExportNames.data(), OriginalFuncs_version, versionExportNames.size()); }
	inline void load_winhttp(const HMODULE originalModule) { load(originalModule, winhttpExportNames.data(), OriginalFuncs_winhttp, winhttpExportNames.size()); }
	inline void load_winmm(const HMODULE originalModule) { load(originalModule, winmmExportNames.data(), OriginalFuncs_winmm, winmmExportNames.size()); }

	inline constexpr std::array<decltype(&load_psapi), 5> loadFunctions = { load_dwmapi, load_psapi, load_version, load_winhttp, load_winmm };

	constexpr void load(const size_t index, const HMODULE originalModule) { loadFunctions[index](originalModule); }

	bool isModuleCompatible(const std::string& moduleName, size_t* index);
}
