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

#ifndef __TrenchBroom__TitleBar__
#define __TrenchBroom__TitleBar__

#include <wx/panel.h>

class wxStaticText;

namespace TrenchBroom {
    namespace View {
        class TitleBar : public wxPanel {
        protected:
            wxStaticText* m_titleText;
        public:
            TitleBar(wxWindow* parent, const wxString& title, int hMargin, int vMargin);
        };
    }
}

#endif /* defined(__TrenchBroom__TitleBar__) */
