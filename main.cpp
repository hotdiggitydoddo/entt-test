#include <entt/entt.hpp>
#include <raylib.h>

#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>

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

	for (auto entity : view)
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
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);


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


	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		update(registry);
		update(registry, dt);
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		auto view = registry.view<position>();
		for (auto entity : view)
		{
			auto &pos = view.get(entity);

			std::stringstream ss;
			ss << "X: " << pos.x << " Y: " << pos.y << std::endl;
			DrawText(ss.str().c_str(), 190, 100 + (entity * 30), 20, LIGHTGRAY);
		}
	
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

