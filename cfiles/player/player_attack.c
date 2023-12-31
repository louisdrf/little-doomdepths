//
// Created by louis on 24/09/2023.
//

#include <conio.h>
#include <string.h>
#include "../../headers/player/player_attack.h"
#include "../../headers/monsters/monster.h"
#include "../../headers/utils.h"
#include "../../headers/player/player.h"
#include "../../headers/weapon/init_weapon.h"

#define DEBUG false

bool player_attack(Player *player, int idMonster) {

    int current_attack_strength;

    Monster *target = getTargetMonster(player, idMonster);
    if(target == NULL) {
    #if DEBUG
    printf("Monster targeting failed.\n");
    #endif
        return false;
    }


    if(player->current_weapon != NULL && (player->mana - player->current_weapon->mana_cost) >= 0) {

        current_attack_strength = random_int((player->current_weapon->min_strength) , (player->current_weapon->max_strength));     // si le joueur a une arme équipée et suffisamment de mana pour attaquer
        if(player->current_weapon->rarity == LEGENDARY) {
            current_attack_strength = legendary_weapon_passive(player, target, current_attack_strength);
        }
    }
    else {
        current_attack_strength = random_int((player->min_strength) , (player->max_strength));                                     // sinon le joueur attaque à mains nues
    }

    if(target->monster_type!=4) { //passif berserker du boss minotaure
        if((target->lifepoints) - current_attack_strength <= 0) {
            target->lifepoints = 0;
            target->isAlive = false;
            player->gold += target->loot_gold;
            player->nbKill++;
            player->currentXP += target->xp;
            player->totalXP += target->xp;
            if(player->currentXP >= player->nextLevelXP) {
                if(player->levelXP != NB_PLAYER_LEVELS) {
                    next_xp_level(player);
                }
            }
        }
        else target->lifepoints -= current_attack_strength;
    }
    else{
        if ((target->lifepoints) - current_attack_strength <= 0) {
            if(target->defense>0){
                target->lifepoints = 1;
                if ((target->defense) - 5 <= 0) {
                    target->defense=0;
                }
                else target->defense-=5;
                target->min_strength=target->max_strength;
            } else{
                target->lifepoints = 0;
                target->isAlive = false;
                player->gold += target->loot_gold;
            }
        } else target->lifepoints -= current_attack_strength;
    }

    player->attacks_left--;
    if(player->current_weapon != NULL) {
        if(player->mana - player->current_weapon->mana_cost >= 0) player->mana -= player->current_weapon->mana_cost;
        else player->mana = 0;
    }

    if(player->attacks_left == 0) player->turn = false;


    return true;
}