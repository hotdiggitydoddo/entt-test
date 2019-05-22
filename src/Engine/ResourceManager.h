#pragma once

#include <raylib.h>

#include <string>
#include <map>

class ResourceManager
{
public:
	static Texture2D* GetTexture(std::string name);
	static Texture2D* LoadTextureFromFile(std::string file, std::string name);

private:
	ResourceManager() { };
};
