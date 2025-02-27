//
// Created by Rainy Memory on 2021/4/13.
//

#ifndef TICKETSYSTEM_AUTOMATA_ADMINISTRATOR_H
#define TICKETSYSTEM_AUTOMATA_ADMINISTRATOR_H

// Socket
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// std
#include <sstream>
#include <iomanip>      // setw setfill
#include <functional>   // std::ref
#include <chrono>       // std::chrono::seconds(0)

// BackEnd
#include "UserManager.h"
#include "TrainManager.h"
#include "OrderManager.h"

class Administrator {
    /*
     * class Administrator
     * --------------------------------------------------------
     * A class implements all functions, including two extra
     * commands: [clean], [exit].
     * This class used a Parser to parse commands, and three
     * managers to execute corresponding functions.
     * The name of parser, managers and Administrator in main.cpp
     * are credit to [Arknights], no copyright infringement intended.
     *
     */
private:
    Parser *Ptilopsis;
    UserManager *Saria;
    TrainManager *Silence;
    OrderManager *Ifrit;
    
    using path_t = const std::string;
    
    path_t UserIndexPath {"UserIndex.dat"};
    path_t UserStoragePath {"UserStorage.dat"};
    path_t TrainIndexPath {"TrainIndex.dat"};
    path_t TrainStoragePath {"TrainStorage.dat"};
    path_t TrainStationPath {"TrainStation.dat"};
    path_t OrderIndexPath {"OrderIndex.dat"};
    path_t OrderPendingPath {"OrderPending.dat"};
    
    void clean();
    
    std::string process(const std::string &cmd);

public:
    Administrator();
    
    ~Administrator();
    
    void runFrontEnd();
    
    void runBackEnd();
};

#endif //TICKETSYSTEM_AUTOMATA_ADMINISTRATOR_H
