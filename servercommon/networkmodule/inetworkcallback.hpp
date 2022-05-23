#ifndef __I_NETWORK_CALLBACK_HPP__
#define __I_NETWORK_CALLBACK_HPP__

#include "servercommon/imodule.hpp"

class INetworkCallback
{
public:
	virtual ~INetworkCallback() {}

	void SetCallbackModule(std::shared_ptr<IModule> module_ptr) 
	{
		m_module_ptr = module_ptr;
	}

	/*
	 ��������acceptʱ��ص��ú���
	 @listen_port	���ض˶˿�
	 @fd			�����ӵ�fd
	 @ip			�Զ˵�ַ�����ʮ����
	 @port			�Զ˶˿ں�
	*/
	virtual void OnAccept(unsigned short listen_port, int fd, const char* peer_ip, unsigned short peer_port) = 0;

	/*
	 ���յ�������Ϣʱ�ص��ú���
	 @netid			������Ϣ��Դ��netid
	 @data			��������
	 @length		���ݳ���
	*/
	virtual void OnRecv(int fd, const char* data, int length) = 0;

	/*
	 ��������Ͽ���ʱ��ص��ú���
	 @netid			�Ͽ����������ӵ�netid
	*/
	virtual void OnDisconnect(int fd) = 0;

	/*
	 �������첽ConnectAsyn������غ�ص�
	 @result		���ӽ���Ƿ�ɹ�
	 @handle		ConnectAsynʱ���������handle
	 @netid			���ӳɹ�ʱ��netidʱ�������ӵ������id
	 @ip			����ip
	 @port			����port
	*/
	virtual void OnConnect(bool result, int handle, int fd, unsigned int ip, unsigned short port) = 0;

	hv::EventLoopPtr GetEventLoopPtr() const 
	{ 
		auto module_ptr = m_module_ptr.lock();
		if (module_ptr)
		{
			return module_ptr->GetEventLoop();
		}
		return nullptr; 
	}

protected:
	std::weak_ptr<IModule> m_module_ptr;
};


#endif