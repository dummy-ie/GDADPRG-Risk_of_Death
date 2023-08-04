#include "Timer.hpp"

using namespace components;

Timer::Timer(std::string strName) : Component(strName, ComponentType::SCRIPT)
{
    this->fTicks = 0.0f;
}

void Timer::perform()
{
    this->fTicks += this->tDeltaTime.asSeconds();

    this->fUpdateTicks += this->tDeltaTime.asSeconds();
    if (this->fUpdateTicks >= this->fUpdateInterval)
    {
        this->fUpdateTicks = 0.0f;
        this->pTimeable->setTime(this->fTicks);
        // this->pTimeable->update();
    }
}

/*void Timer::switchView() {
    if(this->pSwitchable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->pSwitchable->switchView();
    }
}*/

void Timer::start()
{
    this->fTicks = 0.0f;
    // this->fUpdateTicks = 0.0f;
}

void Timer::stop()
{
}

void Timer::setTimeable(Timeable *pTimeable)
{
    this->pTimeable = pTimeable;
}