//
// Created by User on 6/11/2022.
//

#include "Player.h"

Player::Player(const std::string name):
        m_level(1),
        m_coins(0),
        m_name(name){
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

int Player::getAttackStrength(){
    return(this->m_level+this->m_force);
}
void Player::buff(int points){
    if (points<0) {
        points =0;
    }
    this->m_force += points;
}

void Player::heal(int points){
//    if (points<0) {
//        points =0;
//    }
//    if(this->m_hp + points >= this->m_maxHP) this->m_hp = this->m_maxHP;
//    else this->m_hp += points;
    *this->m_hp +=points;
}

void Player::damage(int points){
    if (points<0) {
        points =0;
    }
    if (*this->m_hp - points <= 0) this->m_hp = 0;
    else *this->m_hp -= points;
}

bool Player::isKnockedOut(){
    if(this->m_hp == 0) return true;
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