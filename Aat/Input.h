#pragma once
namespace Aat
{
	enum class InputType
	{
		Keyboard,
		MouseClick,
		MouseWheel
	};

	class Inputs
	{
	public:
		Inputs(std::filesystem::path path);
	private:
		std::vector<std::variant<sf::Keyboard::Key, sf::Mouse::Button>> input;
		std::vector<std::string> name;
		std::vector<InputType> type;

		void LoadKeyMap(std::filesystem::path path);
		void SaveKeyMap(std::filesystem::path path);
	};
}
