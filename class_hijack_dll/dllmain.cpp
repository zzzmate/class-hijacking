#include <Windows.h>
#include <iostream>

struct vec3 {
    float x, y, z;

    vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};
typedef void(__thiscall* classBaseT)(void* pThis, int _health, int _armor, const char* _name, vec3 _position); // the whole class
classBaseT classBaseHk;

typedef void(__thiscall* funcBaseT)(void* pThis); // inside of the class the print function (PrintPlayer)
funcBaseT funcBaseHk;

class newPlayer { // remade class
public:
    int health; // v18 = *(_DWORD *)v35;
    int armor; // v21 = *((_DWORD *)v35 + 1);
    const char* name; // v24 = (char *)*((_DWORD *)v35 + 2);
    vec3 position; // x = (char *)*((_DWORD *)v35 + 3); | y = (char *)*((_DWORD *)v35 + 4); | z = (char *)*((_DWORD *)v35 + 5);
    //newPlayer(int _health, int _armor, const char* _name, vec3 _position) : health(_health), armor(_armor), name(_name), position(_position) {};
};


DWORD WINAPI MainThread(LPARAM param)
{
    while (true)
    {
        uintptr_t modBase = (uintptr_t)(GetModuleHandle(NULL));

        classBaseHk = (classBaseT)(modBase + 0x11F20);
        funcBaseHk = (funcBaseT)(modBase + 0x12480);

        newPlayer createdPlayer;
        classBaseHk(&createdPlayer, 69420, 42069, "zzzmate", vec3(69.0f, 420.f, 0.f));

        if (GetAsyncKeyState(VK_END) & 1) break;
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            funcBaseHk(&createdPlayer);
        }
    }

    FreeLibraryAndExitThread((HMODULE)param, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

