//
// Created by User on 6/11/2022.
//

#include "Player.h"

Player::Player(const std::string name):
    m_name(name),
    m_level(1),
    m_coins(10),
    m_force(5){
    m_hp = std::unique_ptr<HealthPoints>(new HealthPoints());
        }

void Player::levelUp(){
    if (m_level<MAX_LVL) {
        this->m_level+=1;
    }
}

int Player::getLevel(){
    return this->m_level;
}

bool Player::isWinner(){
    if (this->m_level ==10) {
        return true;
    }
    return false;
}

int Player::getAttackStrength(){
    return(this->m_level+this->m_force);
}
void Player::buff(int points){
    if ((points<0)&&(m_force==0)) {
        return;
    }
    this->m_force += points;
}

void Player::heal(int points){
    *this->m_hp +=points;
}

void Player::damage(int points){
    *this->m_hp -= points;
}

bool Player::isKnockedOut(){
    if(*(this->m_hp.get()) == 0) return true;
    return false;
}

void Player::addCoins(int amount){
    if (amount<0) {
        amount =0;
    }
    this->m_coins+=amount;
}

bool Player::pay(int amount){
    if (amount<0) {
        amount =0;
    }
    if (this->m_coins>=amount){
        this->m_coins-=amount;
        return true;
    } else{
        return false;
    }
}

int Player::getCoins(){
    return this->m_coins;
}

std::string Player::getName(){
    return this->m_name;
}
bool Player::outOfGame(){
    bool res =  (isKnockedOut()) || (isWinner());
    return res;
}