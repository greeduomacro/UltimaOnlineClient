//
//  main.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 1/16/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include "Types.h"
#include "FileManager/FileManager.h"
#include "FileManager/FileReader.h"
#include "Asset/Skills.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //skills.idx
    //skills.mul
    
//    core::file::FileManager &fileManager = core::file::FileManager::getInstance();
//    std::vector<std::string> myVector;
//    int files = fileManager.listFiles("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles", &myVector, true);
//    std::cout << files << std::endl;
//    for (auto &i : myVector) {
//        std::cout << i << std::endl;
//    }
    
    core::asset::Skills *skills = new core::asset::Skills();
    
    for (core::asset::SkillGroup *group : skills->_skillGroups) {
        std::cout << "IDX: " << std::to_string(group->getGroupID()) << " - " << group->getName() << std::endl;
        for (core::asset::Skill *skill : skills->_skills) {
            std::cout << "---- " << skill->getName() << std::endl;
        }
        std::cout << "########################" << std::endl;
    }
    delete skills;
    
    
    
    std::cout<<"Press ENTER to exit";
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
    return 0;
}
