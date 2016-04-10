//
//  Parser.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_PARSER_Parser_h
#define CORE_PARSER_Parser_h

#include <inttypes.h>
#include "FileReader.h"

/*
 SkillIdx,
 SkillMul,
 SoundIdx,
 SoundMul,
 LightIdx,
 LightMul,
 Fonts,
 Tiledata,
 AnimIdx,
 AnimMul,
 ArtIdx,
 ArtMul,
 TexIdx,
 TexMul,
 Hues,
 MultiIdx,
 MultiMul,
 Map0,
 Map2,
 Sta0Mul,
 Sta2Mul,
 Sta0Idx,
 Sta2Idx,
 Animdata,
 Verdata,
 GumpIdx,
 GumpMul
 */

namespace core {
    namespace parser {
        class Parser {
        public:
            Parser(core::file::FileReader &fileReader);
        protected:
            int8_t parseInt8();
            uint8_t parseUInt8();
            int16_t parseInt16();
            uint16_t parseUInt16();
            int32_t parseInt32();
            uint32_t parseUInt32();
            int64_t parseInt64();
            uint64_t parseUInt64();
            char* parseCStr(uint32_t length);
            char* parseByteArray(uint32_t numberOfBytes);
            float parseFloat();
            bool parseBool();
            core::file::FileReader& getFileReader();
        private:
            core::file::FileReader &_fileReader;
        };
    }
}

#endif /* CORE_PARSER_Parser_h */
