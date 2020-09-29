#include "pch.h"
#include "Input.h"

//bool Aat::Input::IsPressed()
//{
//	//variant에서 타입비교 찾기
//	if (type == InputType::Keyboard)
//	{
//		return sf::Keyboard::isKeyPressed(std::get<sf::Keyboard::Key>(input));
//	}
//	if (type == InputType::MouseClick)
//	{
//		return sf::Mouse::isButtonPressed(std::get<sf::Mouse::Button>(input));
//	}
//	return 0;
//}

Aat::Inputs::Inputs(std::filesystem::path path)
{
	LoadKeyMap(path);
}

void Aat::Inputs::LoadKeyMap(std::filesystem::path path)
{
	std::ifstream file(path);
	if (!file)
		std::cerr << "can't open file" << std::endl;

	//sf::Keyboard::Key key = ;
	std::string name;
	int type;
	//while(file >> )
	file.close();
}

void Aat::Inputs::SaveKeyMap(std::filesystem::path path)
{
	std::ofstream file(path);
	if(!file)
		std::cerr << "can't open file" << std::endl;

	file.close();
}
