/*******************************************************************************
 * Copyright (c) 2013 Alexandre Arsenault.
 *
 * This file is part of axLibrary.
 *
 * axLibrary is free or commercial software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 or any later version of the
 * License or use a commercial axLibrary License.
 *
 * axLibrary is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with axLibrary. If not, see <http://www.gnu.org/licenses/>.
 *
 * To release a closed-source product which uses axLibrary, commercial
 * licenses are available, email alx.arsenault@gmail.com for more information.
 ******************************************************************************/
#ifndef __AX_LABEL__
#define __AX_LABEL__

/// @defgroup Widgets
/// @{

/// @defgroup Label
/// @{

#include "axWindow.h"
#include "axImage.h"
#include "axWidget.h"
#include "axObjectLoader.h"

/*******************************************************************************
 * axLabel.
 ******************************************************************************/
class axLabel: public axPanel
{
public:
    /***************************************************************************
     * axLabel::Info.
     **************************************************************************/
    class Info
    {
    public:
        Info();
        
        Info(const axColor& normal_color,
             const axColor& contour_color,
             const axColor& fontColor,
             const int fontSize,
             const std::string& font_name,
             const axAlignement& alignement);
        
        /// Constructor with axObj xml file.
        /// @param path Path of the xml file.
        Info(const std::string& path);
        
        axColor normal;
        axColor contour;
        axColor font_color;
        int font_size;
        std::string font_name;
        axAlignement _alignement;
        
    };
    
    /***************************************************************************
     * axLabel::Builder.
     **************************************************************************/
    class Builder
    {
    public:
        Builder(axWindow* win);
        
        axLabel* Create(axVectorPairString attributes);
        
    private:
        axWindow* _parent;
        axLabel::Info _info;
        std::string _label;
        axSize _size;
    };
    
    /***************************************************************************
     * axLabel::axLabel.
     **************************************************************************/
    axLabel(axWindow* parent,
            const axRect& rect,
            const axLabel::Info& info,
            const std::string& label);
    
    
    void SetLabel(const std::string& label);

private:
    axLabel::Info _info;
    std::string _label;
    
    // Events.
    virtual void OnPaint();
};

/// @}
/// @}
#endif // __AX_LABEL__.