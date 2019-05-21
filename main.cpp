#include <entt/entt.hpp>
#include <cstdint>
#include <iostream>

struct position {
    float x;
    float y;
};

struct velocity {
    float dx;
    float dy;
};


void update(entt::registry &registry)
{
    auto view = registry.view<position, velocity>();

    for (auto entity: view)
    {
        auto &vel = view.get<velocity>(entity);
        vel.dx += .1f;
        vel.dy += .2f;
    }

}

void update(entt::registry &registry, std::uint64_t dt)
{
    registry.view<position, velocity>().each([dt](auto &pos, auto &vel)
                                             {
                                                 pos.x += vel.dx * dt;
                                                 pos.y += vel.dy * dt;
                                             });
}

int main(int argc, char* argv[])
{
    entt::registry registry;
    std::uint64_t dt = 16;

    for (auto i = 0; i < 10; ++i)
    {
        auto entity = registry.create();
        registry.assign<position>(entity, i * 1.f, i * 1.f);
        if (i % 2 == 0)
        {
            registry.assign<velocity>(entity, i * .5f, i * .5f);
        }
    }

    update(registry);
    update(registry, dt);

    registry.view<position>().each([](auto &pos)
                                   {
                                        std::cout << "X: " << pos.x << " Y: " << pos.y << std::endl;
                                   });

    return 0;
}

