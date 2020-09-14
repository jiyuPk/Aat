#pragma once
#include "Events.h"
//업데이트할때 이벤트를 받아와서 다음 업데이트때 처리한다.

class EventQueue
{
public:
	EventQueue();
	//RValue로 가져와 캐쉬친화적인 배열에 복사한다.
	void AddEvent(Aat::Event&& event);
	//Aat::Event PopEvent();
	void Update();
private:
	static const int sizeOfList = 20;
	int head;
	int tail;
	Aat::Event eventList[sizeOfList];
};

