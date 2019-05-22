#include "ResourceManager.h"

static std::map<std::string, Texture2D> _textures;

Texture2D* ResourceManager::LoadTextureFromFile(std::string file, std::string name)
{
	_textures[name] = LoadTexture(file.insert(0, "resources/").c_str());
	return &_textures[name];
}

Texture2D* ResourceManager::GetTexture(std::string name)
{
	if (_textures.find(name) == _textures.end())
		return nullptr;
	return &_textures[name];
}
