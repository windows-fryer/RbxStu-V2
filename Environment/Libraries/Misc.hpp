//
// Created by Pixeluted on 22/08/2024.
//

#pragma once
#include "Environment/EnvironmentManager.hpp"

class Misc final : public Library {
public:
    std::string GetLibraryName() override;
    luaL_Reg *GetLibraryFunctions() override;
};
