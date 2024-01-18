#include <iostream>
#include <Windows.h>

struct vec3 {
    float x, y, z;

    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

class Player {
private:
    int32_t health;
    int32_t armor;
    const char* name;
    vec3 position;
public:
    Player(int _health = 100, int _armor = 0, const char* _name = "Default", vec3 _position = vec3(0.f, 0.f, 0.f)) : health(_health), armor(_armor), name(_name), position(_position) {}

    void PrintPlayer()
    {
        std::cout << "Health: " << health << "\n" << "Armor: " << armor << "\n" << "Name: " << name << "\n" << "Position: " << position.x << ", " << position.y << ", " << position.z << "\n\n";
    }
};

int main()
{
    Player* player = new Player(120, 120, "mate", vec3(1.5f, 2.0f, 3.0f));
    while (true)
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            player->PrintPlayer();
        }
    }
    delete player;
}
