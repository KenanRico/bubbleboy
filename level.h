#include <SDL2/SDL.h>
#include "tilelayer.h"
#include "tileset.h"
#include "imagelayer.h"
#include <string>
#include <vector>


#ifndef LEVEL_H
#define LEVEL_H
class Level{
	private:
		std::string lv_dir;
		std::string lv_file;
		std::vector<TileLayer*> lv_layers;
		std::vector<ImageLayer*> lv_imagelayers;
		std::vector<TileSet*> lv_tilesets;
		int lv_mapH;
		int lv_mapW;
		int lv_tileH;
		int lv_tileW;
		bool lv_complete;
		SDL_Renderer* mainRendererPointer;
		mutable SDL_Texture* texture;
		SDL_Window* mainWindowPointer;
		SDL_Rect* lv_srcRect;
		SDL_Rect* lv_dstRect;
	public:
		Level() = delete;
		~Level();
		Level(const Level&) = delete;
		Level& operator=(const Level&) = delete;
	public:
		Level(const char*, const char*, SDL_Renderer*, SDL_Window*);
	private:
		void initLevel(); //Parse lv_name and insert TileLayer objects and TileSet objects
		void destroyLevel(); //Free layer and tileset objects
	private:
		void drawBackground() const;
		int** overallTileLayer() const;
		bool setTextureFromTileID(int) const;
	public:
		void updateLevel() const;
		void renderLevel() const;
		bool isComplete() const;
};
#endif
