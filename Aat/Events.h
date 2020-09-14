#pragma once
namespace Aat
{
	//class EventType
	//{
	//public:
	//	Event* MakeEvent();
	//private:
	//	std::string eventName;
	//	//std::string evnet
	//};

	//class Event
	//{
	//	friend class EventType;
	//public:
	//	Event();
	//private:
	//	const EventType& eventType;
	//	Event(const EventType& eventtype);
	//};
	class Event
	{
	public:
		Event(std::string name);
		Event();

		const std::string& GetEvent();
	private:
		std::string eventName;
	};
}


