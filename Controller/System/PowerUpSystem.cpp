/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "PowerUpSystem.hpp"

using namespace systems;

/* [NOTE] : This Component is a type of [System]. It has a vector attribute that contains
            ALL [Killable] Components in the game.

            This Component listens to [CrosshairMouseInput] LEFT clicks. Once detected,
            It calls its [this->kill()] method to enable the correct [Killable] Component.

            Enabling a [Killable] Component is done by setting its [bKilled] attribute
            to TRUE (i.e [setKilled(true)]).
*/

void PowerUpSystem::perform() {
    this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;
    if (this->fTicks > this->fFrameInterval){
        
        for(ItemType EType : ItemManager::getInstance()->getActiveItems()){
            this->activatePowerUp(EType);
        }

        if(this->mapPowerUps[ItemType::PWR_HEALTH] > 0){
            Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
            
            if(pPlayer){
                //in case we picked up more than 1 health powerup
                while(this->mapPowerUps[ItemType::PWR_HEALTH] > 0){
                    this->mapPowerUps[ItemType::PWR_HEALTH] -= 1;
                    pPlayer->randomIncrementHealth();
                    std::cout<<"HEALTH IS NOW "<<pPlayer->getHealth()<<std::endl;
                }
            }
        }
        if(this->mapPowerUps[ItemType::PWR_DAMAGE] > 0){
            this->mapPowerUps[ItemType::PWR_DAMAGE] -= 1.f;
            std::cout<<"DAMAGE "<<this->mapPowerUps[ItemType::PWR_DAMAGE]<<std::endl;
        }
        else{
            this->mapPowerUps[ItemType::PWR_DAMAGE] = 0.f;
            //std::cout<<"DAMAGE "<<this->mapPowerUps[ItemType::PWR_DAMAGE]<<std::endl;
        }
        if(this->mapPowerUps[ItemType::PWR_INVINCIBILITY] > 0){
            this->mapPowerUps[ItemType::PWR_INVINCIBILITY] -= 1.f;
            std::cout<<"IN "<<this->mapPowerUps[ItemType::PWR_INVINCIBILITY]<<std::endl;
        }
        else{
            this->mapPowerUps[ItemType::PWR_INVINCIBILITY] = 0.f;
            //std::cout<<"IN "<<this->mapPowerUps[ItemType::PWR_DAMAGE]<<std::endl;
        }
        if(this->mapPowerUps[ItemType::PWR_FREEZE] > 0){
            this->mapPowerUps[ItemType::PWR_FREEZE] -= 1.f;
            std::cout<<"FRE "<<this->mapPowerUps[ItemType::PWR_FREEZE]<<std::endl;
        }
        else{
            this->mapPowerUps[ItemType::PWR_FREEZE] = 0.f;
            //std::cout<<"FRE "<<this->mapPowerUps[ItemType::PWR_DAMAGE]<<std::endl;
        }
        if (this->mapPowerUps[ItemType::PWR_REVIVE] > 0)
            this->mapPowerUps[ItemType::PWR_REVIVE] = 0.f;
        this->fTicks = 0.f;
    }
}

void PowerUpSystem::activatePowerUp(ItemType EType){
    switch(EType){
        case ItemType::PWR_HEALTH:
            this->mapPowerUps[EType] += 1.f;
            SFXManager::getInstance()->getSound(SFXType::HEALTH)->play();
            break;
        case ItemType::PWR_DAMAGE:
            this->mapPowerUps[EType] = PWR_DAMAGE_DURATION;
            SFXManager::getInstance()->getSound(SFXType::DAMAGE)->play();
            break;
        case ItemType::PWR_PIERCE:
            this->mapPowerUps[EType] = 1.f;
            SFXManager::getInstance()->getSound(SFXType::PIERCING)->play();
            break;
        case ItemType::PWR_INVINCIBILITY:
            this->mapPowerUps[EType] = PWR_INVINCIBILITY_DURATION;
            SFXManager::getInstance()->getSound(SFXType::INVINCIBILITY)->play();
            break;
        case ItemType::PWR_FREEZE:
            this->mapPowerUps[EType] = PWR_FREEZE_DURATION;
            SFXManager::getInstance()->getSound(SFXType::FREEZE)->play();
            break;
        case ItemType::PWR_REVIVE:
            this->mapPowerUps[EType] = 1.f;
        default:
            break;
    }
}

void PowerUpSystem::clearPowerUp(ItemType EType){
    this->mapPowerUps[EType] = 0.f;
}

void PowerUpSystem::clearAll(){
    this->mapPowerUps.clear();
}

bool PowerUpSystem::isActive(ItemType EType){
    return this->mapPowerUps[EType];
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */

PowerUpSystem* PowerUpSystem::P_SHARED_INSTANCE = NULL;
PowerUpSystem::PowerUpSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 1.f;
    this->fTicks = 0.f;
}
PowerUpSystem::PowerUpSystem(const PowerUpSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 1.f;
    this->fTicks = 0.f;
}

PowerUpSystem* PowerUpSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void PowerUpSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new PowerUpSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
