/*
 Copyright (C) 2010-2014 Kristian Duske
 
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

#ifndef TrenchBroom_GL_h
#define TrenchBroom_GL_h

#include "Functor.h"

#include <cstddef>

namespace TrenchBroom {
#define GL_FALSE 0
#define GL_TRUE 1

#define GL_NO_ERROR 0
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008

#define GL_DEPTH_BUFFER_BIT 0x00000100

#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207

#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408

#define GL_INVALID_ENUM 0x0500

#define GL_CW 0x0900
#define GL_CCW 0x0901

#define GL_CULL_FACE 0x0B44
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_FUNC 0x0B74

#define GL_TEXTURE_2D 0x0DE1
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A

#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701

#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A

#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02

#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
    
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079

#define GL_MULTISAMPLE 0x809D

#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MAX_LEVEL 0x813D

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3

#define GL_BUFFER_OBJECT_APPLE 0x85B3

#define GL_ARRAY_BUFFER 0x8892

#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_CURRENT_PROGRAM 0x8B8D

    typedef unsigned int GLenum;
    typedef unsigned int GLbitfield;
    typedef unsigned int GLuint;
    typedef int GLint;
    typedef int GLsizei;
    typedef unsigned char GLboolean;
    typedef signed char GLbyte;
    typedef short GLshort;
    typedef unsigned char GLubyte;
    typedef unsigned short GLushort;
    typedef unsigned long GLulong;
    typedef float GLfloat;
    typedef float GLclampf;
    typedef double GLdouble;
    typedef double GLclampd;
    typedef void GLvoid;
    
    typedef ptrdiff_t GLintptr;
    typedef ptrdiff_t GLsizeiptr;
    
    typedef char GLchar;
    
    extern Func0<void> glewInitialize;
    
    extern Func0<GLenum> glGetError;

    extern Func1<void, GLenum> glEnable;
    extern Func1<void, GLenum> glDisable;
    extern Func1<void, GLbitfield> glClear;
    
    extern Func1<void, GLenum> glDepthFunc;
    extern Func1<void, GLboolean> glDepthMask;
    extern Func2<void, GLclampd, GLclampd> glDepthRange;
    
    extern Func1<void, GLfloat> glLineWidth;
    extern Func2<void, GLenum, GLenum> glPolygonMode;
    extern Func1<void, GLenum> glFrontFace;
    
    extern Func0<void> glLoadIdentity;
    extern Func1<void, const GLdouble*> glLoadMatrixd;
    extern Func1<void, const GLfloat*> glLoadMatrixf;
    extern Func1<void, GLenum> glMatrixMode;

    extern Func2<void, GLenum, GLint*> glGetIntegerv;
    
    extern Func2<void, GLsizei, GLuint*> glGenTextures;
    extern Func2<void, GLsizei, const GLuint*> glDeleteTextures;
    extern Func2<void, GLenum, GLuint> glBindTexture;
    extern Func3<void, GLenum, GLenum, GLfloat> glTexParameterf;
    extern Func3<void, GLenum, GLenum, GLint> glTexParameteri;
    extern Func9<void, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*> glTexImage2D;
    extern Func1<void, GLenum> glActiveTexture;
    
    extern Func2<void, GLsizei, GLuint*> glGenBuffers;
    extern Func2<void, GLsizei, const GLuint*> glDeleteBuffers;
    extern Func2<void, GLenum, GLuint> glBindBuffer;
    extern Func4<void, GLenum, GLsizeiptr, const GLvoid*, GLenum> glBufferData;
    extern Func2<GLvoid*, GLenum, GLenum> glMapBuffer;
    extern Func1<GLboolean, GLenum> glUnmapBuffer;
    
    extern Func1<void, GLuint> glEnableVertexAttribArray;
    extern Func1<void, GLuint> glDisableVertexAttribArray;
    extern Func1<void, GLenum> glEnableClientState;
    extern Func1<void, GLenum> glDisableClientState;
    extern Func1<void, GLenum> glClientActiveTexture;
    
    extern Func6<void, GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*> glVertexAttribPointer;
    extern Func4<void, GLint, GLenum, GLsizei, const GLvoid*> glVertexPointer;
    extern Func3<void, GLenum, GLsizei, const GLvoid*> glNormalPointer;
    extern Func4<void, GLint, GLenum, GLsizei, const GLvoid*> glColorPointer;
    extern Func4<void, GLint, GLenum, GLsizei, const GLvoid*> glTexCoordPointer;
    
    extern Func3<void, GLenum, GLint, GLsizei> glDrawArrays;
    extern Func4<void, GLenum, const GLint*, const GLsizei*, GLsizei> glMultiDrawArrays;
    
    extern Func1<GLuint, GLenum> glCreateShader;
    extern Func1<void, GLuint> glDeleteShader;
    extern Func4<void, GLuint, GLsizei, const GLchar**, const GLint*> glShaderSource;
    extern Func1<void, GLuint> glCompileShader;
    extern Func3<void, GLuint, GLenum, GLint*> glGetShaderiv;
    extern Func4<void, GLuint, GLsizei, GLsizei*, GLchar*> glGetShaderInfoLog;
    extern Func2<void, GLuint, GLuint> glAttachShader;
    extern Func2<void, GLuint, GLuint> glDetachShader;
    
    extern Func0<GLuint> glCreateProgram;
    extern Func1<void, GLuint> glDeleteProgram;
    extern Func1<void, GLuint> glLinkProgram;
    extern Func3<void, GLuint, GLenum, GLint*> glGetProgramiv;
    extern Func4<void, GLuint, GLsizei, GLsizei*, GLchar*> glGetProgramInfoLog;
    extern Func1<void, GLuint> glUseProgram;
    
    extern Func2<void, GLint, GLfloat> glUniform1f;
    extern Func3<void, GLint, GLfloat, GLfloat> glUniform2f;
    extern Func4<void, GLint, GLfloat, GLfloat, GLfloat> glUniform3f;
    extern Func5<void, GLint, GLfloat, GLfloat, GLfloat, GLfloat> glUniform4f;
    extern Func2<void, GLint, GLint> glUniform1i;
    extern Func3<void, GLint, GLint, GLint> glUniform2i;
    extern Func4<void, GLint, GLint, GLint, GLint> glUniform3i;
    extern Func5<void, GLint, GLint, GLint, GLint, GLint> glUniform4i;
    extern Func2<void, GLint, GLuint> glUniform1ui;
    extern Func3<void, GLint, GLuint, GLuint> glUniform2ui;
    extern Func4<void, GLint, GLuint, GLuint, GLuint> glUniform3ui;
    extern Func5<void, GLint, GLuint, GLuint, GLuint, GLuint> glUniform4ui;
    
    extern Func3<void, GLint, GLsizei, const GLfloat*> glUniform1fv;
    extern Func3<void, GLint, GLsizei, const GLfloat*> glUniform2fv;
    extern Func3<void, GLint, GLsizei, const GLfloat*> glUniform3fv;
    extern Func3<void, GLint, GLsizei, const GLfloat*> glUniform4fv;
    extern Func3<void, GLint, GLsizei, const GLint*> glUniform1iv;
    extern Func3<void, GLint, GLsizei, const GLint*> glUniform2iv;
    extern Func3<void, GLint, GLsizei, const GLint*> glUniform3iv;
    extern Func3<void, GLint, GLsizei, const GLint*> glUniform4iv;
    extern Func3<void, GLint, GLsizei, const GLuint*> glUniform1uiv;
    extern Func3<void, GLint, GLsizei, const GLuint*> glUniform2uiv;
    extern Func3<void, GLint, GLsizei, const GLuint*> glUniform3uiv;
    extern Func3<void, GLint, GLsizei, const GLuint*> glUniform4uiv;
    
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix2fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix3fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix4fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix2x3fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix3x2fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix2x4fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix4x2fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix3x4fv;
    extern Func4<void, GLint, GLsizei, GLboolean, const GLfloat*> glUniformMatrix4x3fv;
    
    extern Func2<GLint, GLuint, const GLchar*> glGetUniformLocation;

#ifdef __APPLE__
    extern Func2<void, GLenum, GLint> glFinishObjectAPPLE;
#endif
}

#endif
