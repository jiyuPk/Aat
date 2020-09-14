#include "pch.h"
#include "Events.h"
//
//Aat::Event::Event(const EventType& eventtype)
//	:eventType(eventType)
//{
//
//}
//
//Aat::Event* Aat::EventType::MakeEvent()
//{
//	return new Event(*this);
//}

Aat::Event::Event(std::string name)
	:eventName(name)
{
}

Aat::Event::Event()
{
}

const std::string& Aat::Event::GetEvent()
{
	return eventName;
}
