#include"stdafx.h"
#include "SoundManager.h"
#include <iostream>

//bgm 볼륨조절
#define VOLUME 30
//효과음 볼륨조절
#define SE_VOLUME 50

SoundManager::SoundManager() {
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cout << "Mix_OpenAudio " << Mix_GetError() << std::endl;
		exit(1);
	}
	intro_bgm = Mix_LoadMUS("./resource/intro.mp3");
	if (intro_bgm == 0) {
		std::cout << "Mix_LoadMUS(\"intro.mp3\"): " << Mix_GetError() << std::endl;
	}
	stage_bgm = Mix_LoadMUS("./resource/stage.mp3");
	if (stage_bgm == 0) {
		std::cout << "Mix_LoadMUS(\"stage.mp3\"): " << Mix_GetError() << std::endl;
	}
	ending_bgm = Mix_LoadMUS("./resource/ending.mp3");
	if (ending_bgm == 0) {
		std::cout << "Mix_LoadMUS(\"ending.mp3\"): " << Mix_GetError() << std::endl;
	}
	gameover_bgm = Mix_LoadMUS("./resource/gameover.mp3");
	if (gameover_bgm == 0) {
		std::cout << "Mix_LoadMUS(\"gameover.mp3\"): " << Mix_GetError() << std::endl;
	}
	Mix_VolumeMusic(VOLUME);
	btn_click_se = Mix_LoadWAV("./resource/button_click.mp3");
	btn_hold_se = Mix_LoadWAV("./resource/button_hold.mp3");
	move_se = Mix_LoadWAV("./resource/move.mp3");
	player_atk_se = Mix_LoadWAV("./resource/player_attack.wav");
	player_dmg_se = Mix_LoadWAV("./resource/player_damaged.wav");
	monster_atk_se = Mix_LoadWAV("./resource/monster_attack.wav");
	monster_dmg_se = Mix_LoadWAV("./resource/monster_damaged.wav");
	Mix_VolumeChunk(btn_click_se, SE_VOLUME);
	Mix_VolumeChunk(btn_hold_se, SE_VOLUME);
	Mix_VolumeChunk(move_se, SE_VOLUME);
	Mix_VolumeChunk(player_atk_se, SE_VOLUME);
	Mix_VolumeChunk(player_dmg_se, SE_VOLUME);
	Mix_VolumeChunk(monster_atk_se, SE_VOLUME);
	Mix_VolumeChunk(monster_dmg_se, SE_VOLUME);
}

SoundManager::~SoundManager() {
	Mix_FreeMusic(intro_bgm);
	Mix_FreeMusic(stage_bgm);
	Mix_FreeMusic(ending_bgm);
	Mix_FreeChunk(move_se);
	Mix_FreeChunk(btn_click_se);
	Mix_FreeChunk(btn_hold_se);
	Mix_FreeChunk(player_atk_se);
	Mix_FreeChunk(player_dmg_se);
	Mix_FreeChunk(monster_atk_se);
	Mix_FreeChunk(monster_dmg_se);
	Mix_CloseAudio();
}
//인트로 화면 bgm 재생
void SoundManager::intro_music()
{
	if (Mix_PlayingMusic()) {
		Mix_HaltMusic();
	}
	Mix_PlayMusic(intro_bgm, -1);
}
//게임 내 bgm 재생
void SoundManager::stage_music()
{
	if (Mix_PlayingMusic()) {
		Mix_HaltMusic();
	}
	Mix_PlayMusic(stage_bgm, -1);
}
//엔딩 화면 bgm 재생
void SoundManager::ending_music()
{
	if (Mix_PlayingMusic()) {
		Mix_HaltMusic();
	}
	Mix_PlayMusic(ending_bgm, -1);
}
//게임오버 화면 bgm 재생
void SoundManager::gameover_music()
{
	if (Mix_PlayingMusic()) {
		Mix_HaltMusic();
	}
	Mix_PlayMusic(gameover_bgm, -1);
}
//버튼 클릭 효과음 재생
void SoundManager::btn_click_sound()
{
	Mix_PlayChannel(-1, btn_click_se, 0);
}
//버튼 홀드 효과음 재생
void SoundManager::btn_hold_sound()
{
	Mix_PlayChannel(-1, btn_hold_se, 0);
}
//움직일 때 발소리 재생
void SoundManager::move_sound()
{
	Mix_PlayChannel(-1, move_se, 0);
}
//플레이어가 공격 시 효과음 재생
void SoundManager::player_atk_sound()
{
	Mix_PlayChannel(-1, player_atk_se, 0);
}
//플레이어가 피격 시 효과음 재생
void SoundManager::player_dmg_sound()
{
	Mix_PlayChannel(-1, player_dmg_se, 0);
}
//몬스터가 공격 시 효과음 재생
void SoundManager::monster_atk_sound()
{
	Mix_PlayChannel(-1, monster_atk_se, 0);
}
//몬스터가 피격 시 효과음 재생
void SoundManager::monster_dmg_sound()
{
	Mix_PlayChannel(-1, monster_dmg_se, 0);
}