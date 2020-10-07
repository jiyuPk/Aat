#include "pch.h"
#include "InputManager.h"
Aat::InputManager::InputManager()
{
	isInitialized = false;
}

void Aat::InputManager::Initialize(std::filesystem::path path)
{
	inputs = new Inputs(path);

	isInitialized = true;
}

//[[nodiscard]] std::vector<Aat::Input> Aat::InputManager::GetInput()
//{
//	std::vector<Aat::Input> pressedInput;
//	for (auto& inputs : keyMap)
//	{
//		if (inputs.second.IsPressed())
//		{
//			pressedInput.push_back(inputs.second);
//		}
//	}
//	return pressedInput;
//}

void Aat::InputManager::Update()
{
	//GetInput();
}