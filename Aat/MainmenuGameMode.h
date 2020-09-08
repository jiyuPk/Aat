#pragma once
#include "GameMode.h"
#include "Button.h"

class MainmenuGameMode :
    public GameMode
{
public:
    MainmenuGameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler, sf::Font* font);
    virtual void Update(const Game& game_ref) override;
    virtual void Render() override;
private:


    std::map<std::string, std::unique_ptr<Button>> buttons;

    void MakeButtons(sf::Font* font);
    void UpdateButtons(const Game& game_ref);
    void RenderButtons();

};

