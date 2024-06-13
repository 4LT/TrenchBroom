/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Assets/Palette.h"
#include "IO/EntityModelParser.h"

#include <filesystem>
#include <string>

namespace TrenchBroom::Assets
{
class Palette;
} // namespace TrenchBroom::Assets

namespace TrenchBroom::IO
{
class FileSystem;
class Reader;

class Bsp29Parser : public EntityModelParser
{
private:
  std::string m_name;
  const Reader& m_reader;
  const Assets::Palette m_palette;
  const FileSystem& m_fs;

public:
  Bsp29Parser(
    std::string name,
    const Reader& reader,
    Assets::Palette palette,
    const FileSystem& fs);

  static bool canParse(const std::filesystem::path& path, Reader reader);

  Result<Assets::EntityModel> initializeModel(Logger& logger) override;
};

} // namespace TrenchBroom::IO
