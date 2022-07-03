#ifndef __WORLD_HPP__
#define __WORLD_HPP__

class World
{
public:
	static World& Instance();

	void OnServerStart();
	void Update(unsigned int now_second);
	void OnRecv(int fd, const char* data, int length);
	void StopServer(const char* reason = nullptr);
private:
	World();
	~World();
	World(const World&) = delete;
	World& operator=(const World&) = delete;
	void ConnectToRedis();
	void StartAsyncTaskThread();
};


#endif