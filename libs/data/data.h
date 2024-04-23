#ifndef DATA_H
#define DATA_H

typedef struct player{
    char* first_name;
    char* last_name;
    int points;
}PLAYER;

struct player player(char* _first_name, char* _last_name, int _points);

struct player* newPlayer(char* _first_name, char* _last_name, int _points);

struct player freePlayer(struct player* _player);

typedef struct team{
    struct player* members;
    unsigned int number;
}TEAM;

struct team team(unsigned int _number, struct player* _members);

struct team* newTeam(unsigned int _number, struct player* _members);

struct team freeTeam(struct team* _team);

#endif //DATA_H