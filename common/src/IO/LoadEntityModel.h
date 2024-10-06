/*
 Copyright (C) 2024 Kristian Duske

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

#include "Result.h"
#include "assets/EntityModelDataResource.h"

#include <filesystem>
#include <functional>

namespace tb
{
class Logger;
}

namespace tb::assets
{
class EntityModel;
class Material;
} // namespace tb::assets

namespace tb::Model
{
struct MaterialConfig;
}

namespace tb::IO
{
class FileSystem;

using LoadMaterialFunc = std::function<assets::Material(const std::filesystem::path&)>;

Result<assets::EntityModel> loadEntityModelSync(
  const FileSystem& fs,
  const Model::MaterialConfig& materialConfig,
  const std::filesystem::path& path,
  const LoadMaterialFunc& loadMaterial,
  Logger& logger);

assets::EntityModel loadEntityModelAsync(
  const FileSystem& fs,
  const Model::MaterialConfig& materialConfig,
  const std::filesystem::path& path,
  const LoadMaterialFunc& loadMaterial,
  const assets::CreateEntityModelDataResource& createResource,
  Logger& logger);

} // namespace tb::IO
