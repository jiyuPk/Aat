#pragma once
#include "Events.h"
//������Ʈ�Ҷ� �̺�Ʈ�� �޾ƿͼ� ���� ������Ʈ�� ó���Ѵ�.

class EventQueue
{
public:
	EventQueue();
	//RValue�� ������ ĳ��ģȭ���� �迭�� �����Ѵ�.
	void AddEvent(Aat::Event&& event);
	//Aat::Event PopEvent();
	void Update();
private:
	static const int sizeOfList = 20;
	int head;
	int tail;
	Aat::Event eventList[sizeOfList];
};

