#ifndef GAME_H
#define GAME_H
#include <string>
class Game
{
public:

	Game(Game&) = delete;
	void operator=(const Game&) = delete;
	static Game* getIstance(const std::string);
	std::string const Name() const { return name_;} 
	~Game() {
		if (instance_ != nullptr) {
			delete instance_;
		}
	}
private:
	Game(const std::string value) : name_(value)
	{
	}

	static Game* instance_;
	std::string name_;
};
#endif // !GAME_H



