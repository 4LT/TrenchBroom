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

#include "Assets/Texture.h"
#include "Assets/TextureBuffer.h"
#include "Color.h"
#include "Renderer/GL.h"

#include "kdl/reflection_decl.h"

#include "vm/forward.h"

#include <atomic>
#include <filesystem>
#include <set>
#include <string>
#include <variant>
#include <vector>

namespace TrenchBroom::Assets
{

enum class TextureType
{
  Opaque,
  /**
   * Modifies texture uploading to support mask textures.
   */
  Masked
};

std::ostream& operator<<(std::ostream& lhs, const TextureType& rhs);

enum class MaterialCulling
{
  Default,
  None,
  Front,
  Back,
  Both
};

std::ostream& operator<<(std::ostream& lhs, const MaterialCulling& rhs);

struct MaterialBlendFunc
{
  enum class Enable
  {
    /**
     * Don't change GL_BLEND and don't change the blend function.
     */
    UseDefault,
    /**
     * Don't change GL_BLEND, but set the blend function.
     */
    UseFactors,
    /**
     * Set GL_BLEND to off.
     */
    DisableBlend
  };

  Enable enable;
  GLenum srcFactor;
  GLenum destFactor;

  kdl_reflect_decl(MaterialBlendFunc, enable, srcFactor, destFactor);
};

std::ostream& operator<<(std::ostream& lhs, const MaterialBlendFunc::Enable& rhs);

struct Q2Data
{
  int flags;
  int contents;
  int value;

  kdl_reflect_decl(Q2Data, flags, contents, value);
};

using GameData = std::variant<std::monostate, Q2Data>;

std::ostream& operator<<(std::ostream& lhs, const GameData& rhs);

class Material
{
private:
  using Buffer = TextureBuffer;
  using BufferList = std::vector<Buffer>;

private:
  std::string m_name;
  std::filesystem::path m_absolutePath;
  std::filesystem::path m_relativePath;

  Texture m_texture;

  std::atomic<size_t> m_usageCount = 0;

  // TODO: move these to a Q3Data variant case of m_gameData if possible
  // Quake 3 surface parameters; move these to materials when we add proper support for
  // those.
  std::set<std::string> m_surfaceParms;

  // Quake 3 surface culling; move to materials
  MaterialCulling m_culling = MaterialCulling::Default;

  // Quake 3 blend function, move to materials
  MaterialBlendFunc m_blendFunc = {
    MaterialBlendFunc::Enable::UseDefault, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};

  kdl_reflect_decl(
    Material,
    m_name,
    m_absolutePath,
    m_relativePath,
    m_usageCount,
    m_surfaceParms,
    m_culling,
    m_blendFunc);

public:
  Material(
    std::string name,
    size_t width,
    size_t height,
    const Color& averageColor,
    Buffer&& buffer,
    GLenum format,
    TextureType type,
    GameData gameData = std::monostate{});
  Material(
    std::string name,
    size_t width,
    size_t height,
    const Color& averageColor,
    BufferList buffers,
    GLenum format,
    TextureType type,
    GameData gameData = std::monostate{});
  Material(
    std::string name,
    size_t width,
    size_t height,
    GLenum format = GL_RGB,
    TextureType type = TextureType::Opaque,
    GameData gameData = std::monostate{});

  Material(std::string name, Texture texture);

  Material(const Material&) = delete;
  Material& operator=(const Material&) = delete;

  Material(Material&& other);
  Material& operator=(Material&& other);

  ~Material();

  const std::string& name() const;

  /**
   * Absolute path of the material
   */
  const std::filesystem::path& absolutePath() const;
  void setAbsolutePath(std::filesystem::path absolutePath);

  /**
   * Relative path of the material in the game filesystem
   */
  const std::filesystem::path& relativePath() const;
  void setRelativePath(std::filesystem::path relativePath);

  const Texture& texture() const;
  Texture& texture();

  const std::set<std::string>& surfaceParms() const;
  void setSurfaceParms(std::set<std::string> surfaceParms);

  MaterialCulling culling() const;
  void setCulling(MaterialCulling culling);

  void setBlendFunc(GLenum srcFactor, GLenum destFactor);
  void disableBlend();

  size_t usageCount() const;
  void incUsageCount();
  void decUsageCount();

  void activate() const;
  void deactivate() const;
};

} // namespace TrenchBroom::Assets
