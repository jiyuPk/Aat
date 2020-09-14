#include "pch.h"
#include "EventQueue.h"

EventQueue::EventQueue()
{
	head = 0;
	tail = 0;
}

void EventQueue::AddEvent(Aat::Event&& event)
{
	if ((tail + 1) % sizeOfList != head)
	{
		eventList[tail] = event;
		tail = (tail + 1) % sizeOfList;
	}
	else
		throw("queue is too short");
}

void EventQueue::Update()
{
	if (head == tail)
		return;
}
