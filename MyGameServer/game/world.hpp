#ifndef __WORLD_HPP__
#define __WORLD_HPP__

class World
{
public:
	static World& Instance();

	void Update(unsigned int now_second);
private:
	World();
	~World();
	World(const World&) = delete;
	World& operator=(const World&) = delete;
};


#endif