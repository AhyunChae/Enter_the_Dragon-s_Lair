#include"stdafx.h"
#include<iostream>
#include"GameManager.h"
#include"SDL.h"
#include"Components.h"
#include"Player.h"
#include"Monster.h"

void InitGame() {
	GameManager::getinstance()->g_flag = true;
}
int main(int arc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("wer", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	GameManager* gm = GameManager::getinstance();
	gm->g_renderer = SDL_CreateRenderer(win, -1, 0);

	gm->InitMap();
	InitGame();
	gm->map->SetTile();
	gm->PathFind(1, 8, 8, 1);
	gm->TestHwakIn();


	objf::CreateObj<Player>("Player");
	objf::CreateObj<Monster>("Monster");

	gm->sm->intro_music();

	while (gm->g_flag) {
		gm->Update();
		gm->Render();
		SDL_Delay(33);
	}

	for (int i = 0; i < gm->objCol.size(); i++) {
		delete(gm->objCol[i]);
	}

	SDL_DestroyWindow(win);


	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}