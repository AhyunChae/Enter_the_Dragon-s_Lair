#include"stdafx.h"
#include"Components.h"
#include"SDL.h"

void Component::setOwner(Object* own) {
	m_Owner = own;
}
void InputComponent::HandleEvent() {
	
}

void SpriteComponent::InitSprite(const char* file) {
	SDL_Surface* tmp;
	tmp = IMG_Load(file);
	if (textr != 0) {
		SDL_DestroyTexture(textr);
		textr = 0;
	}
	textr = SDL_CreateTextureFromSurface(GameManager::getinstance()->g_renderer, tmp);
	SDL_FreeSurface(tmp);
}

void transform::SetPos(int x, int y) {
	this->x = x;
	this->y = y;
}
void transform::SetSize(int w, int h) {
	this->w = w;
	this->h = h;
}
SDL_Rect transform::GetRect() {
	return { this->x * 100,this->y * 100,this->w,this->h };
}


void SpriteComponent::SetSpriteRect(int x, int y, int w, int h) {
	sr.x = x;
	sr.y = y;
	sr.w = w;
	sr.h = h;
}
void SpriteComponent::Render() {
	SDL_Rect tmp;
	GameManager* gm = GameManager::getinstance();
	transform* t_tr = m_Owner->GetComponent<transform>("transform");
	tmp = { t_tr->x*100 - gm->p_x*100 + 1280/2 - (t_tr->w / 2),
			t_tr->y*100 - gm->p_y*100 + 720/2 - (t_tr->h / 2),
			t_tr->w,t_tr->h };
	SDL_RenderCopy(gm->g_renderer, textr, &sr, &tmp);
}