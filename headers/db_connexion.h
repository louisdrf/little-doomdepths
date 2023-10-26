//
// Created by louis on 25/10/2023.
//

#ifndef DOOM_DB_CONNEXION_H
#define DOOM_DB_CONNEXION_H

#include <stdbool.h>
#include "../sqlite3/sqlite3.h"

sqlite3* connect_to_db();
bool prepare_and_exec_query(sqlite3 **conn, char *query);

#endif //DOOM_DB_CONNEXION_H
