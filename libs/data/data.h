#ifndef DATA_H
#define DATA_H

struct player{
    char* first_name;
    char* last_name;
    float points;
};

//struct player player(char* _first_name, char* _last_name, int _points);

//struct player* newPlayer(char* _first_name, char* _last_name, int _points);

void freePlayer(struct player* _player);

typedef struct team{
    char* name;
    struct player* members;
    unsigned int number;
}TEAM;

//struct team team(unsigned int _number, struct player* _members);

//struct team* newTeam(char* _name, unsigned int _number, struct player* _members);

void freeTeam(struct team* _team);

#endif //DATA_H