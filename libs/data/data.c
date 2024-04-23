#include "data.h"
#include <stdlib.h>

struct player player(char* _first_name, char* _last_name, int _points){
    struct player result;

    result.first_name = _first_name;
    result.last_name = _last_name;
    result.points = _points;

    return result;
}

struct player* newPlayer(char* _first_name, char* _last_name, int _points){
    struct player* result = (struct player*)malloc(sizeof(struct player));

    if(!result) return NULL;

    result->first_name = _first_name;
    result->last_name = _last_name;
    result->points = _points;

    return result;
}

struct player freePlayer(struct player* _player){
    struct player result;

    result.first_name = _player->first_name;;
    result.last_name = _player->last_name;
    result.points = _player->points;

    free(_player);

    return result;
}

struct team team(unsigned int _number, struct player* _members){
    struct team result;

    result.members = _members;
    result.number = _number;

    return result;
}

struct team* newTeam(unsigned int _number, struct player* _members){
    struct team* result = (struct team*)malloc(sizeof(struct team));

    if(!result) return NULL;

    result->members = _members;
    result->number = _number;

    return result;
}

struct team freeTeam(struct team* _team){
    struct team result;

    result.members = _team->members;
    result.number = _team->number;

    free(_team);

    return result;
}
