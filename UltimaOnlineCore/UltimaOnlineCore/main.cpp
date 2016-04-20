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
    
    core::file::FileManager &fileManager = core::file::FileManager::getInstance();
    std::vector<std::string> myVector;
    int files = fileManager.listFiles("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles", &myVector, true);
    std::cout << files << std::endl;
    for (auto &i : myVector) {
        std::cout << i << std::endl;
    }
    
//    std::unordered_map<int16_t,core::asset::IndexAsset*> skillsIndexTable;
//    core::file::FileReader skillsIdxFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/skills.idx");
//    core::parser::IndexParser skillsIdxParser(skillsIdxFileReader);
//    core::asset::IndexAsset *skillIdx = NULL;
//    while((skillIdx = skillsIdxParser.parse()) != NULL) {
//        skillsIndexTable[skillIdx->getLookup()] = skillIdx;
//    }
//
//    core::file::FileReader skillsFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/skills.mul");
//    core::parser::SkillParser skillsParser(skillsFileReader);
//    for (auto &i : skillsIndexTable) {
//        core::asset::SkillAsset *skill = skillsParser.parse(i.first, i.second->getSize());
//        if (skill)
//            std::cout << "ISACTION:" << skill->isAction() << " - " << skill->getSkillName() << std::endl;
//    }
    
    return 0;
}
