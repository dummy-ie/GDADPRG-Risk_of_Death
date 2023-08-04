#include "LeaderboardScreen.hpp"

using namespace views;

LeaderboardScreen::LeaderboardScreen(std::string strName) : View(ViewTag::LEADERBOARD_SCREEN, strName)
{
    this->vecTopTimes = {};
    ViewManager::getInstance()->registerView(this);
}

LeaderboardScreen::~LeaderboardScreen() {}

void LeaderboardScreen::initialize()
{
    float fSpacing = 100;

    this->pReturn = new Text(this->strName + " Return", "Return", FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pReturn);
    float fWidth = this->pReturn->getText()->getLocalBounds().width;
    this->pReturn->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 200 + fSpacing * 2);
    sf::FloatRect CBounds = this->pReturn->getText()->getGlobalBounds();
    Button* pButton = new Button(this->strName + " Return Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);

    Text *pText = new Text(this->strName + " Title", "Leaderboard", FontManager::getInstance()->getFont(FontType::DEFAULT), 64);
    fWidth = pText->getText()->getLocalBounds().width;
    pText->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 21);
    this->attachChild(pText);

    for (size_t i = 1; i <= 5; i++)
        this->vecTopTimes.push_back(new GameTimer("Leaderboard Top Score " + std::to_string(i)));

    for (size_t i = 0; i < this->vecTopTimes.size(); i++)
    {
        // fWidth = getLocalBounds().width;
        // pText->getText()->setPosition();
        vecTopTimes.at(i)->setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - fWidth / 2, pText->getText()->getPosition().y + 30.f * (i + 1)));
        vecTopTimes.at(i)->setEnabled(true);
        this->attachChild(vecTopTimes.at(i));
    }
        

}

void LeaderboardScreen::loadScores()
{
    std::ifstream scores("File/scores.txt"); 

    if (!scores.is_open())
    {
        std::cout << "scores.txt does not exist" << std::endl;
        return;
    }

    std::vector<float> vecScores;
    std::string readScore;
    while (std::getline(scores, readScore))
    {
        vecScores.push_back(std::stof(readScore));
    }

    scores.close();
    std::sort(vecScores.begin(), vecScores.end());
    
    if (vecTopTimes.size() != 5)
    {
        std::cout << "vecTopTimes does not have 5 gameTimers" << std::endl;
        return;
    }
    
    for (size_t i = 0; i < std::min(5, (int)vecScores.size()); i++)
    {
        this->vecTopTimes.at(i)->setTime(vecScores.at(i));        
    }
}

void LeaderboardScreen::onClick(Button *pButton)
{
    if (pButton->getName().find("Return Button") != std::string::npos)
    {
        this->pReturn->setColor(sf::Color::White);
    }
}

void LeaderboardScreen::onHover(Button *pButton)
{
    if (pButton->getName().find("Return Button") != std::string::npos)
        this->pReturn->setColor(sf::Color::Green);
}

void LeaderboardScreen::onRelease(Button *pButton)
{
    if (pButton->getName().find("Return Button") != std::string::npos)
    {
        std::cout << "[LEADERBOARD RETURN]" << std::endl;
        SceneManager::getInstance()->loadScene(SceneTag::GAME_MENU);
    }
}

void LeaderboardScreen::reset(Button *pButton)
{
    if (pButton->getName().find("Return Button") != std::string::npos)
    {
        this->pReturn->setColor(sf::Color::Black);
    }
}