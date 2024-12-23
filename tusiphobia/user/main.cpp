#include "pch.h"

#include "il2cpp-init.h"
#include "helpers.h"
#include "hooks.h"
#include <chrono>
#include <thread>
#include <tusiphobia/lib/Il2CppHelper.h>

#ifdef _DEBUG
bool debug = true;
#else
bool debug = false;
#endif

using namespace app;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

HMODULE hModule;
bool running = true;

int run() {

    il2cpp_thread_attach(il2cpp_domain_get());


    il2cppi_new_console();

    /*Il2CppHelper* _helper = new Il2CppHelper();

      while (true) {
          if (GetAsyncKeyState(VK_F1) & 0x8000) {
              const Il2CppImage* _image = _helper->GetImage("Assembly-CSharp.dll");

              _helper->GetMethodInfo(_image, "SetFOV", 1, "NolanBehaviour", "");

          }

          std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }

      delete _helper;*/

    if (strstr(GetCommandLineA(), "--tusiphobia.debug") != nullptr)
        debug = true;

    printf("tusiphobia initializing...\n");
    Hooks::init();

    printf("initialized successfully\n");
    while ((!debug || !GetAsyncKeyState(VK_END) & 1) && running) {
        Sleep(200);
    }

    printf("tusiphobia exiting...");
    Hooks::uninit();

    return 0;
}

void quit(int code) {
    FreeConsole();
    CloseHandle(GetCurrentThread());
    FreeLibraryAndExitThread(hModule, code);
}

void run(void* lpParameter) {
    hModule = (HMODULE)lpParameter;

    init_il2cpp();
    il2cpp_thread_attach(il2cpp_domain_get());

    quit(run());
}

void shutdown() {
    running = false;
}
