#pragma once
#include "Input.h"
namespace Aat
{
	class InputManager
	{
	public:
		InputManager();
		void Initialize(std::filesystem::path path);

		//std::vector<Input> GetInput();
		//std::vector<Input> GetInput(InputType filter);

		void Update();
	private:
		bool isInitialized;
		Inputs* inputs;
	};
}
