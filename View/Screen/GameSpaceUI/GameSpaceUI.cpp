#include "GameSpaceUI.hpp"

using namespace views;

GameSpaceUI::GameSpaceUI(std::string strName) : View(ViewTag::GAME_SPACE_UI, strName)
{
    ViewManager::getInstance()->registerView(this);
    // this->pGameTimer = NULL;
    this->vecTime = {};
}

GameSpaceUI::~GameSpaceUI() {}

void GameSpaceUI::initialize()
{
    // this->pGameTimer = new GameTimer(this->strName + " Game Timer");
    // this->attachChild(pGameTimer);
    // pGameTimer->setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - 20.f));
    // pGameTimer->initialize();
    // this->pGameTimer->setEnabled(true);

    createTimer();

    Player *pPlayer = (Player *)GameObjectManager::getInstance()->findObjectByName("Player");
    AnimatedTexture *pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART));
    // this->pHeart =
    this->createImage(this->strName + " Heart", pTexture, 0.05f, 75.f, SCREEN_HEIGHT - 75.f);

    this->pHealth = new Text(this->strName + " Health", std::to_string(pPlayer->getHealth()), FontManager::getInstance()->getFont(FontType::DEFAULT));
    this->pHealth->getText()->setOutlineColor(sf::Color::White);
    this->pHealth->getText()->setOutlineThickness(5.f);
    this->attachChild(this->pHealth);
    this->pHealth->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 90.f));

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET));
    this->createImage(this->strName + " Bullet", pTexture, 0.15f, 75.f, SCREEN_HEIGHT - 150.f);

    this->pBullets = new Text(this->strName + " Bullets", std::to_string(pPlayer->getBullets()), FontManager::getInstance()->getFont(FontType::DEFAULT));
    this->pBullets->getText()->setOutlineColor(sf::Color::White);
    this->pBullets->getText()->setOutlineThickness(5.f);
    this->attachChild(this->pBullets);
    this->pBullets->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 165.f));
}

void GameSpaceUI::update()
{
    Player *pPlayer = (Player *)GameObjectManager::getInstance()->findObjectByName("Player");
    this->pHealth->setText(std::to_string(pPlayer->getHealth()));
    this->pBullets->setText(std::to_string(pPlayer->getBullets()));

    // std::cout << "gamespace ui update" << std::endl;

    // this->pHeart->setPosition(sf::Vector2f(75.f, SCREEN_HEIGHT - 75.f));
    // this->pBullet->setPosition(sf::Vector2f(75.f, SCREEN_HEIGHT - 75.f));
    // this->pHealth->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 90.f));
    // this->pBullets->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 165.f));
}

void GameSpaceUI::createTimer()
{
    pTimer = new Timer(this->strName + " Timer");
    this->attachComponent(pTimer);
    pTimer->setTimeable(this);
    pTimer->reset();

    float fScale = 50.f;
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
    float fY = SCREEN_HEIGHT - 100.f;
    pColon->setPosition({fX, fY});

    fX = pColon->getGlobalBounds().left - pColon->getGlobalBounds().width;
    fY = pColon->getGlobalBounds().top;
    float fPadding = fScale - (fScale * 0.3f);

    Text *pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = fX - ((pColon->getText()->getGlobalBounds().width + fPadding) * 2.f);
    fY -= (fScale * 0.3f);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = this->vecTime[0]->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = pColon->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding) - (fScale * 0.2f);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = this->vecTime[2]->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    pText->setPosition({fX, fY});
}

Text *views::GameSpaceUI::copyText(Text *pReference, std::string strText, float fScale)
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

void GameSpaceUI::setTime(float fSeconds)
{
    int ms = (int)(fSeconds * 1000.f);

    int h = ms / (1000 * 60 * 60);
    ms -= h * (1000 * 60 * 60);

    int m = ms / (1000 * 60);
    ms -= m * (1000 * 60);

    int s = ms / 1000;
    ms -= s * 1000;

    std::stringstream CStream;
    CStream << std::setfill('0') << std::setw(2) << m << std::setw(2) << s;
    std::string strTime = CStream.str();
    // std::cout << "m: " << strTime.at() << std::endl;
    // std::cout << "s: " << s << std::endl;

    // if (strTime.length() < 5)
    //     strTime = "0" + strTime;

    // strTime.erase(2, 1);

    for (int i = 0; i < strTime.length(); i++)
    {
        this->vecTime.at(i)->setText(std::string(1, strTime.at(i)), false);
    }
}
