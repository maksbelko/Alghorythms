#include "Game.h"
Game* Game::instance_ = nullptr;
Game* Game::getIstance(const std::string value) {
	if (instance_ == nullptr) {
		instance_ = new Game(value);
	}
	return instance_;
}