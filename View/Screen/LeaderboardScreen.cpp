#include "LeaderboardScreen.hpp"

using namespace views;

LeaderboardScreen::LeaderboardScreen(std::string strName) : View(ViewTag::LEADERBOARD_SCREEN, strName)
{
    this->vecTime = {};
    ViewManager::getInstance()->registerView(this);
}

LeaderboardScreen::~LeaderboardScreen() {}

void LeaderboardScreen::initialize()
{
    float fSpacing = 100;

    this->pReturn = new Text(this->strName + " Return", "Return", FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pReturn);
    float fWidth = this->pReturn->getText()->getLocalBounds().width;
    this->pReturn->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 200.f + fSpacing * 2);
    sf::FloatRect CBounds = this->pReturn->getText()->getGlobalBounds();
    Button *pButton = new Button(this->strName + " Return Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);

    Text *pText = new Text(this->strName + " Title", "Leaderboard", FontManager::getInstance()->getFont(FontType::DEFAULT), 64);
    fWidth = pText->getText()->getLocalBounds().width;
    pText->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 21);
    this->attachChild(pText);

    //     this->vecTopTimes.push_back(new GameTimer("Leaderboard Top Score " + std::to_string(i)));

    for (size_t i = 0; i < 5; i++)
    {
        std::vector<Text *> vecTemp;
        float fScale = 40.f;
        Text *pColon = new Text(this->strName + " Time",
                                ":",
                                FontManager::getInstance()->getFont(FontType::DEFAULT),
                                fScale);

        sf::Color CColor = sf::Color::White;
        pColon->getText()->setStyle(sf::Text::Bold);
        pColon->getText()->setOutlineThickness(5.0f);
        pColon->getText()->setOutlineColor(CColor);
        this->attachChild(pColon);

        CColor = sf::Color::Black;
        // CColor.a = 150;
        pColon->getText()->setFillColor(CColor);

        float fX = SCREEN_WIDTH / 2.f;
        float fY = pText->getText()->getPosition().y + pColon->getText()->getGlobalBounds().height + 50.f * (i + 1);
        pColon->setPosition({fX, fY});

        fX = pColon->getGlobalBounds().left - pColon->getGlobalBounds().width;
        fY = pColon->getGlobalBounds().top;
        float fPadding = fScale - (fScale * 0.3f);

        Text *pText = this->copyText(pColon, "0", fScale);
        vecTemp.push_back(pText);
        fX = fX - ((pColon->getText()->getGlobalBounds().width + fPadding) * 2.f);
        fY -= (fScale * 0.3f);
        pText->setPosition({fX, fY});

        pText = this->copyText(pColon, "0", fScale);
        vecTemp.push_back(pText);
        fX = vecTemp[0]->getPosition().x;
        fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
        pText->setPosition({fX, fY});

        pText = this->copyText(pColon, "0", fScale);
        vecTemp.push_back(pText);
        fX = pColon->getPosition().x;
        fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding) - (fScale * 0.2f);
        pText->setPosition({fX, fY});

        pText = this->copyText(pColon, "0", fScale);
        vecTemp.push_back(pText);
        fX = vecTemp[2]->getPosition().x;
        fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
        pText->setPosition({fX, fY});

        this->vecTime.push_back(vecTemp);
    }

    loadScores();

    // for (size_t i = 0; i < this->vecTime.size(); i++)
    // {
    // fWidth = getLocalBounds().width;
    // pText->getText()->setPosition();
    // vecTime.at(i)->setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - fWidth / 2, pText->getText()->getPosition().y + 30.f * (i + 1)));
    // vecTime.at(i)->setEnabled(true);
    // this->attachChild(vecTime.at(i));
    // vecTopTimes.at(i)->initialize();
    // }
}

Text *views::LeaderboardScreen::copyText(Text *pReference, std::string strText, float fScale)
{
    Text *pText = new Text(this->strName + " Text",
                           strText,
                           FontManager::getInstance()->getFont(FontType::DEFAULT),
                           fScale);

    this->attachChild(pText);

    pText->getText()->setStyle(pReference->getText()->getStyle());
    pText->getText()->setOutlineThickness(pReference->getText()->getOutlineThickness());
    pText->getText()->setOutlineColor(pReference->getText()->getOutlineColor());
    pText->getText()->setFillColor(pReference->getText()->getFillColor());

    pText->setPosition(pReference->getPosition());

    return pText;
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
    std::sort(vecScores.begin(), vecScores.end(), std::greater<float>());

    if (vecTime.size() != 5)
    {
        std::cout << "vecTopTimes does not have 5 gameTimers" << std::endl;
        return;
    }

        std::cout << "vecTime size: " << vecTime.size() << std::endl;
        std::cout << "vecScores size: " << vecScores.size() << std::endl;
        for (auto &vec : vecTime)
            std::cout << "vecText size: " << vec.size() << std::endl;

    for (size_t i = 0; i < std::min(5, (int)vecScores.size()); i++)
    {
        std::cout << "reading: " << vecScores.at(i) << std::endl;
        int ms = (int)(vecScores.at(i) * 1000.f);

        int h = ms / (1000 * 60 * 60);
        ms -= h * (1000 * 60 * 60);

        int m = ms / (1000 * 60);
        ms -= m * (1000 * 60);

        int s = ms / 1000;
        ms -= s * 1000;

        std::stringstream CStream;
        CStream << std::setfill('0') << std::setw(2) << m << std::setw(2) << s;
        std::string strTime = CStream.str();
        std::cout << "strTime size:" << strTime.size() << std::endl;

        for (int j = 0; j < strTime.length(); j++)
            vecTime.at(i).at(j)->setText(std::string(1, strTime.at(j)), false);
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