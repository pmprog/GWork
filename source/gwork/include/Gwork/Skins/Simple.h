/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-16 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_SKINS_SIMPLE_H
#define GWK_SKINS_SIMPLE_H

#include "Gwork/Skin.h"
#include "Gwork/Gwork.h"
#include "Gwork/Controls/Base.h"

namespace Gwk
{
    namespace Skin
    {
        class Simple : public Gwk::Skin::Base
        {
        public:

            Simple(Gwk::Renderer::Base* renderer)
                : Gwk::Skin::Base(renderer)
            {}

            Gwk::Color m_colBorderColor;
            Gwk::Color m_colControlOutlineLight;
            Gwk::Color m_colControlOutlineLighter;
            Gwk::Color m_colBG;
            Gwk::Color m_colBGDark;
            Gwk::Color m_colControl;
            Gwk::Color m_colControlBorderHighlight;
            Gwk::Color m_colControlDarker;
            Gwk::Color m_colControlOutlineNormal;
            Gwk::Color m_colControlBright;
            Gwk::Color m_colControlDark;
            Gwk::Color m_colHighlightBG;
            Gwk::Color m_colHighlightBorder;
            Gwk::Color m_colToolTipBackground;
            Gwk::Color m_colToolTipBorder;
            Gwk::Color m_colModal;

            Simple()
            {
                m_colBorderColor            = Gwk::Color(80, 80, 80, 255);
                m_colBG                     = Gwk::Color(248, 248, 248, 255);
                m_colBGDark                 = Gwk::Color(235, 235, 235, 255);
                m_colControl                = Gwk::Color(240, 240, 240, 255);
                m_colControlBright          = Gwk::Color(255, 255, 255, 255);
                m_colControlDark            = Gwk::Color(214, 214, 214, 255);
                m_colControlDarker          = Gwk::Color(180, 180, 180, 255);
                m_colControlOutlineNormal   = Gwk::Color(112, 112, 112, 255);
                m_colControlOutlineLight    = Gwk::Color(144, 144, 144, 255);
                m_colControlOutlineLighter  = Gwk::Color(210, 210, 210, 255);
                m_colHighlightBG            = Gwk::Color(192, 221, 252, 255);
                m_colHighlightBorder        = Gwk::Color(51, 153, 255, 255);
                m_colToolTipBackground      = Gwk::Color(255, 255, 225, 255);
                m_colToolTipBorder          = Gwk::Color(0, 0, 0, 255);
                m_colModal = Gwk::Color(25, 25, 25, 150);
                m_DefaultFont.facename  = "Microsoft Sans Serif";
                m_DefaultFont.size      = 11;
            }

            virtual void DrawGenericPanel(Controls::Base* control)
            {
                // TODO.
            }

            virtual void DrawButton(Gwk::Controls::Base* control, bool bDepressed, bool bHovered,
                                    bool bDisabled)
            {
                int w = control->Width();
                int h = control->Height();
                DrawButton(w, h, bDepressed, bHovered);
            }

            virtual void DrawWindowCloseButton(Gwk::Controls::Base* control, bool bDepressed,
                                               bool bHovered, bool bDisabled)
            {
                // TODO.
                DrawButton(control, bDepressed, bHovered, bDisabled);
            }

            virtual void DrawWindowMaximizeButton(Gwk::Controls::Base* control, bool bDepressed,
                                                  bool bHovered, bool bDisabled, bool bMaximized)
            {
                // TODO.
                DrawButton(control, bDepressed, bHovered, bDisabled);
            }

            virtual void DrawWindowMinimizeButton(Gwk::Controls::Base* control, bool bDepressed,
                                                  bool bHovered, bool bDisabled)
            {
                // TODO.
                DrawButton(control, bDepressed, bHovered, bDisabled);
            }

            virtual void DrawMenuItem(Gwk::Controls::Base* control, bool bSubmenuOpen,
                                      bool bChecked)
            {
                if (bSubmenuOpen || control->IsHovered())
                {
                    m_Render->SetDrawColor(m_colHighlightBG);
                    m_Render->DrawFilledRect(control->GetRenderBounds());
                    m_Render->SetDrawColor(m_colHighlightBorder);
                    m_Render->DrawLinedRect(control->GetRenderBounds());
                }

                if (bChecked)
                {
                    m_Render->SetDrawColor(Color(0, 0, 0, 255));
                    Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);
                    DrawCheck(r);
                }
            }

            virtual void DrawMenuStrip(Gwk::Controls::Base* control)
            {
                int w = control->Width();
                int h = control->Height();
                m_Render->SetDrawColor(Gwk::Color(246, 248, 252, 255));
                m_Render->DrawFilledRect(Gwk::Rect(0, 0, w, h));
                m_Render->SetDrawColor(Gwk::Color(218, 224, 241, 150));
                m_Render->DrawFilledRect(Gwk::Rect(0, h*0.4f, w, h*0.6f));
                m_Render->DrawFilledRect(Gwk::Rect(0, h/2, w, h/2));
            }

            virtual void DrawMenu(Gwk::Controls::Base* control, bool bPaddingDisabled)
            {
                int w = control->Width();
                int h = control->Height();
                m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(Gwk::Rect(0, 0, w, h));

                if (!bPaddingDisabled)
                {
                    m_Render->SetDrawColor(m_colControl);
                    m_Render->DrawFilledRect(Gwk::Rect(1, 0, 22, h));
                }

                m_Render->SetDrawColor(m_colControlOutlineNormal);
                m_Render->DrawLinedRect(Gwk::Rect(0, 0, w, h));
            }

            virtual void DrawShadow(Gwk::Controls::Base* control)
            {
                int w = control->Width();
                int h = control->Height();
                int x = 4;
                int y = 6;
                m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 10));
                m_Render->DrawFilledRect(Gwk::Rect(x, y, w, h));
                x += 2;
                m_Render->DrawFilledRect(Gwk::Rect(x, y, w, h));
                y += 2;
                m_Render->DrawFilledRect(Gwk::Rect(x, y, w, h));
            }

            virtual void DrawButton(int w, int h, bool bDepressed, bool bHovered,
                                    bool bSquared = false)
            {
                if (bDepressed)
                    m_Render->SetDrawColor(m_colControlDark);
                else if (bHovered)
                    m_Render->SetDrawColor(m_colControlBright);
                else
                    m_Render->SetDrawColor(m_colControl);
                m_Render->DrawFilledRect(Gwk::Rect(1, 1, w-2, h-2));

                if (bDepressed)
                    m_Render->SetDrawColor(m_colControlDark);
                else if (bHovered)
                    m_Render->SetDrawColor(m_colControl);
                else
                    m_Render->SetDrawColor(m_colControlDark);
                m_Render->DrawFilledRect(Gwk::Rect(1, h/2, w-2, h/2-2));

                if (!bDepressed)
                {
                    m_Render->SetDrawColor(m_colControlBright);
                    m_Render->DrawShavedCornerRect(Gwk::Rect(1, 1, w-2, h-2), bSquared);
                }
                else
                {
                    m_Render->SetDrawColor(m_colControlDarker);
                    m_Render->DrawShavedCornerRect(Gwk::Rect(1, 1, w-2, h-2), bSquared);
                }

                // Border
                m_Render->SetDrawColor(m_colControlOutlineNormal);
                m_Render->DrawShavedCornerRect(Gwk::Rect(0, 0, w, h), bSquared);
            }

            virtual void DrawRadioButton(Gwk::Controls::Base* control, bool bSelected,
                                         bool bDepressed)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                // Inside colour
                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(220, 242, 254, 255));
                else
                    m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h-2));

                // Border
                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(85, 130, 164, 255));
                else
                    m_Render->SetDrawColor(m_colControlOutlineLight);
                m_Render->DrawShavedCornerRect(rect);
                m_Render->SetDrawColor(Gwk::Color(0,  50,  60, 15));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, rect.h-4));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w*0.3f, rect.h-4));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, rect.h*0.3f));

                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(121, 198, 249, 255));
                else
                    m_Render->SetDrawColor(Gwk::Color(0, 50, 60, 50));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+3, 1, rect.h-5));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+3, rect.y+2, rect.w-5, 1));

                if (bSelected)
                {
                    m_Render->SetDrawColor(Gwk::Color(40, 230, 30, 255));
                    m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, rect.h-4));
                }
            }

            virtual void DrawCheckBox(Gwk::Controls::Base* control, bool bSelected,
                                      bool bDepressed)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                // Inside colour
                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(220, 242, 254, 255));
                else
                    m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(rect);

                // Border
                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(85, 130, 164, 255));
                else
                    m_Render->SetDrawColor(m_colControlOutlineLight);
                m_Render->DrawLinedRect(rect);
                m_Render->SetDrawColor(Gwk::Color(0,  50,  60, 15));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, rect.h-4));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w*0.3f, rect.h-4));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, rect.h*0.3f));

                if (control->IsHovered())
                    m_Render->SetDrawColor(Gwk::Color(121, 198, 249, 255));
                else
                    m_Render->SetDrawColor(Gwk::Color(0, 50, 60, 50));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, 1, rect.h-4));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2, rect.y+2, rect.w-4, 1));

                if (bDepressed)
                {
                    m_Render->SetDrawColor(Color(100, 100, 100, 255));
                    Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);
                    DrawCheck(r);
                }
                else if (bSelected)
                {
                    m_Render->SetDrawColor(Color(0, 0, 0, 255));
                    Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);
                    DrawCheck(r);
                }
            }

            virtual void DrawGroupBox(Gwk::Controls::Base* control, int textStart, int textHeight,
                                      int textWidth)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                rect.y += textHeight/2;
                rect.h -= textHeight/2;
                Gwk::Color m_colDarker         = Gwk::Color(0,  50,  60, 50);
                Gwk::Color m_colLighter        = Gwk::Color(255, 255, 255, 150);
                m_Render->SetDrawColor(m_colLighter);
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y+1, textStart-3, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1+textStart+textWidth, rect.y+1,
                                                    rect.w-textStart+textWidth-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, (rect.y+rect.h)-1, rect.w-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y+1, 1, rect.h));
                m_Render->DrawFilledRect(Gwk::Rect((rect.x+rect.w)-2, rect.y+1, 1, rect.h-1));
                m_Render->SetDrawColor(m_colDarker);
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y, textStart-3, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1+textStart+textWidth, rect.y,
                                                    rect.w-textStart-textWidth-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, (rect.y+rect.h)-1, rect.w-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x, rect.y+1, 1, rect.h-1));
                m_Render->DrawFilledRect(Gwk::Rect((rect.x+rect.w)-1, rect.y+1, 1, rect.h-1));
            }

            virtual void DrawTextBox(Gwk::Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                bool bHasFocus = control->HasFocus();

                // Box inside
                m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 255));
                m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h-2));
                m_Render->SetDrawColor(m_colControlOutlineLight);
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y, rect.w-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x, rect.y+1, 1, rect.h-2));
                m_Render->SetDrawColor(m_colControlOutlineLighter);
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, (rect.y+rect.h)-1, rect.w-2, 1));
                m_Render->DrawFilledRect(Gwk::Rect((rect.x+rect.w)-1, rect.y+1, 1, rect.h-2));

                if (bHasFocus)
                {
                    m_Render->SetDrawColor(Gwk::Color(50, 200, 255, 150));
                    m_Render->DrawLinedRect(rect);
                }
            }

            virtual void DrawTabButton(Gwk::Controls::Base* control, bool bActive, int dir)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                bool bHovered = control->IsHovered();

                if (bHovered)
                    m_Render->SetDrawColor(m_colControlBright);
                else
                    m_Render->SetDrawColor(m_colControl);
                m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h-1));

                if (bHovered)
                    m_Render->SetDrawColor(m_colControl);
                else
                    m_Render->SetDrawColor(m_colControlDark);
                m_Render->DrawFilledRect(Gwk::Rect(1, rect.h/2, rect.w-2, rect.h/2-1));
                m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawShavedCornerRect(Gwk::Rect(1, 1, rect.w-2, rect.h));
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawShavedCornerRect(Gwk::Rect(0, 0, rect.w, rect.h));
            }

            virtual void DrawTabControl(Gwk::Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                m_Render->SetDrawColor(m_colControl);
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawLinedRect(rect);
                //m_Render->SetDrawColor( m_colControl );
                //m_Render->DrawFilledRect( CurrentButtonRect );
            }

            virtual void DrawWindow(Gwk::Controls::Base* control, int topHeight, bool inFocus)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                // Titlebar
                if (inFocus)
                    m_Render->SetDrawColor(Gwk::Color(87, 164, 232, 230));
                else
                    m_Render->SetDrawColor(Gwk::Color(87*0.70, 164*0.70, 232*0.70, 230));
                int iBorderSize = 5;
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y+1, rect.w-2, topHeight-1));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y+topHeight-1,
                                                    iBorderSize, rect.h-2-topHeight));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+rect.w-iBorderSize, rect.y+topHeight-1,
                                                    iBorderSize, rect.h-2-topHeight));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x+1, rect.y+rect.h-iBorderSize,
                                                    rect.w-2, iBorderSize));
                // Main inner
                m_Render->SetDrawColor(Gwk::Color(m_colControlDark.r,
                                                   m_colControlDark.g,
                                                   m_colControlDark.b,
                                                   230));
                m_Render->DrawFilledRect(Gwk::Rect(rect.x + iBorderSize + 1,
                                                    rect.y + topHeight,
                                                    rect.w - iBorderSize*2 - 2,
                                                    rect.h - topHeight - iBorderSize - 1));
                // Light inner border
                m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 100));
                m_Render->DrawShavedCornerRect(Gwk::Rect(rect.x+1, rect.y+1, rect.w-2, rect.h-2));
                // Dark line between titlebar and main
                m_Render->SetDrawColor(m_colBorderColor);
                // Inside border
                m_Render->SetDrawColor(m_colControlOutlineNormal);
                m_Render->DrawLinedRect(Gwk::Rect(rect.x+iBorderSize, rect.y+topHeight-1,
                                                   rect.w-10, rect.h-topHeight-(iBorderSize-1)));
                // Dark outer border
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawShavedCornerRect(Gwk::Rect(rect.x, rect.y, rect.w, rect.h));
            }

            virtual void DrawHighlight(Gwk::Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                m_Render->SetDrawColor(Gwk::Color(255, 100, 255, 255));
                m_Render->DrawFilledRect(rect);
            }

            virtual void DrawScrollBar(Gwk::Controls::Base* control, bool isHorizontal,
                                       bool bDepressed)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                if (bDepressed)
                    m_Render->SetDrawColor(m_colControlDarker);
                else
                    m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(rect);
            }

            virtual void DrawScrollBarBar(Controls::Base* control, bool bDepressed, bool isHovered,
                                          bool isHorizontal)
            {
                //TODO: something specialized
                DrawButton(control, bDepressed, isHovered, false);
            }

            virtual void DrawTabTitleBar(Gwk::Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                m_Render->SetDrawColor(Gwk::Color(177, 193, 214, 255));
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);
                rect.h += 1;
                m_Render->DrawLinedRect(rect);
            }

            virtual void DrawProgressBar(Gwk::Controls::Base* control, bool isHorizontal,
                                         float progress)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                Gwk::Color FillColour(0, 211, 40, 255);

                if (isHorizontal)
                {
                    //Background
                    m_Render->SetDrawColor(m_colControlDark);
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h-2));
                    //Right half
                    m_Render->SetDrawColor(FillColour);
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w*progress-2, rect.h-2));
                    m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 150));
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h*0.45f));
                }
                else
                {
                    //Background
                    m_Render->SetDrawColor(m_colControlDark);
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w-2, rect.h-2));
                    //Top half
                    m_Render->SetDrawColor(FillColour);
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1+(rect.h*(1-progress)),
                                                        rect.w-2, rect.h*progress-2));
                    m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 150));
                    m_Render->DrawFilledRect(Gwk::Rect(1, 1, rect.w*0.45f, rect.h-2));
                }

                m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 150));
                m_Render->DrawShavedCornerRect(Gwk::Rect(1, 1, rect.w-2, rect.h-2));
                m_Render->SetDrawColor(Gwk::Color(255, 255, 255, 70));
                m_Render->DrawShavedCornerRect(Gwk::Rect(2, 2, rect.w-4, rect.h-4));
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawShavedCornerRect(rect);
            }

            virtual void DrawListBox(Gwk::Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawLinedRect(rect);
            }

            virtual void DrawListBoxLine(Gwk::Controls::Base* control, bool bSelected, bool bEven)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                if (bSelected)
                {
                    m_Render->SetDrawColor(m_colHighlightBorder);
                    m_Render->DrawFilledRect(rect);
                }
                else if (control->IsHovered())
                {
                    m_Render->SetDrawColor(m_colHighlightBG);
                    m_Render->DrawFilledRect(rect);
                }
            }

            virtual void DrawSlider(Gwk::Controls::Base* control, bool bIsHorizontal,
                                    int numNotches, int barSize)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                if (bIsHorizontal)
                {
                    rect.y += rect.h*0.4f;
                    rect.h -= rect.h*0.8f;
                }
                else
                {
                    rect.x += rect.w*0.4f;
                    rect.w -= rect.w*0.8f;
                }

                m_Render->SetDrawColor(m_colBGDark);
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colControlDarker);
                m_Render->DrawLinedRect(rect);
            }

            virtual void DrawComboBox(Gwk::Controls::Base* control, bool bIsDown, bool bIsMenuOpen)
            {
                DrawTextBox(control);
            }

            virtual void DrawKeyboardHighlight(Gwk::Controls::Base* control, const Gwk::Rect& r,
                                               int iOffset)
            {
                Gwk::Rect rect = r;
                rect.x += iOffset;
                rect.y += iOffset;
                rect.w -= iOffset*2;
                rect.h -= iOffset*2;

                //draw the top and bottom
                bool skip = true;

                for (int i = 0; i < rect.w/2; i++)
                {
                    m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 255));

                    if (!skip)
                    {
                        m_Render->DrawPixel(rect.x+(i*2), rect.y);
                        m_Render->DrawPixel(rect.x+(i*2), rect.y+rect.h-1);
                    }
                    else
                    {
                        skip = !skip;
                    }
                }

                skip = false;

                for (int i = 0; i < rect.h/2; i++)
                {
                    m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 255));

                    if (!skip)
                    {
                        m_Render->DrawPixel(rect.x, rect.y+i*2);
                        m_Render->DrawPixel(rect.x+rect.w-1, rect.y+i*2);
                    }
                    else
                    {
                        skip = !skip;
                    }
                }
            }

            virtual void DrawToolTip(Gwk::Controls::Base* control)
            {
                Gwk::Rect rct = control->GetRenderBounds();
                rct.x -= 3;
                rct.y -= 3;
                rct.w += 6;
                rct.h += 6;
                m_Render->SetDrawColor(m_colToolTipBackground);
                m_Render->DrawFilledRect(rct);
                m_Render->SetDrawColor(m_colToolTipBorder);
                m_Render->DrawLinedRect(rct);
            }

            virtual void DrawScrollButton(Gwk::Controls::Base* control, int iDirection,
                                          bool bDepressed, bool bHovered, bool bDisabled)
            {
                DrawButton(control, bDepressed, false, false);
                m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 240));
                Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);

                if (iDirection == Gwk::Docking::Top)
                    DrawArrowUp(r);
                else if (iDirection == Gwk::Docking::Bottom)
                    DrawArrowDown(r);
                else if (iDirection == Gwk::Docking::Left)
                    DrawArrowLeft(r);
                else
                    DrawArrowRight(r);
            }

            virtual void DrawComboDownArrow(Gwk::Controls::Base* control, bool bHovered,
                                            bool bDown, bool bOpen, bool bDisabled)
            {
                //DrawButton( control->Width(), control->Height(), bDepressed, false, true );
                m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 240));
                Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);
                DrawArrowDown(r);
            }

            virtual void DrawNumericUpDownButton(Gwk::Controls::Base* control, bool bDepressed,
                                                 bool bUp)
            {
                //DrawButton( control->Width(), control->Height(), bDepressed, false, true );
                m_Render->SetDrawColor(Gwk::Color(0, 0, 0, 240));
                Gwk::Rect r(control->Width()/2-2, control->Height()/2-2, 5, 5);

                if (bUp)
                    DrawArrowUp(r);
                else
                    DrawArrowDown(r);
            }

            virtual void DrawTreeButton(Controls::Base* control, bool bOpen)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                rect.x += 2;
                rect.y += 2;
                rect.w -= 4;
                rect.h -= 4;
                m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawLinedRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);

                if (!bOpen)   // ! because the button shows intention, not the current state
                    m_Render->DrawFilledRect(Gwk::Rect(rect.x+rect.w/2,
                                                        rect.y+2,
                                                        1,
                                                        rect.h-4));

                m_Render->DrawFilledRect(Gwk::Rect(rect.x+2,
                                                    rect.y+rect.h/2,
                                                    rect.w-4,
                                                    1));
            }

            virtual void DrawTreeControl(Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                m_Render->SetDrawColor(m_colControlBright);
                m_Render->DrawFilledRect(rect);
                m_Render->SetDrawColor(m_colBorderColor);
                m_Render->DrawLinedRect(rect);
            }

            void DrawTreeNode(Controls::Base* ctrl, bool bOpen, bool bSelected, int iLabelHeight,
                              int iLabelWidth, int iHalfWay, int iLastBranch, bool bIsRoot)
            {
                if (bSelected)
                {
                    GetRender()->SetDrawColor(Color(0, 150, 255, 100));
                    GetRender()->DrawFilledRect(Gwk::Rect(17, 0, iLabelWidth+2, iLabelHeight-1));
                    GetRender()->SetDrawColor(Color(0, 150, 255, 200));
                    GetRender()->DrawLinedRect(Gwk::Rect(17, 0, iLabelWidth+2, iLabelHeight-1));
                }

                Base::DrawTreeNode(ctrl, bOpen, bSelected, iLabelHeight, iLabelWidth, iHalfWay,
                                   iLastBranch, bIsRoot);
            }

            virtual void DrawStatusBar(Controls::Base* control)
            {
                // TODO.
            }

            void DrawColorDisplay(Controls::Base* control, Gwk::Color color)
            {
                Gwk::Rect rect = control->GetRenderBounds();

                if (color.a != 255)
                {
                    GetRender()->SetDrawColor(Gwk::Color(255, 255, 255, 255));
                    GetRender()->DrawFilledRect(rect);
                    GetRender()->SetDrawColor(Gwk::Color(128, 128, 128, 128));
                    GetRender()->DrawFilledRect(Gwk::Rect(0, 0, rect.w/2, rect.h/2));
                    GetRender()->DrawFilledRect(Gwk::Rect(rect.w/2, rect.h/2, rect.w/2, rect.h/2));
                }

                GetRender()->SetDrawColor(color);
                GetRender()->DrawFilledRect(rect);
                GetRender()->SetDrawColor(Gwk::Color(0, 0, 0, 255));
                GetRender()->DrawLinedRect(rect);
            }

            virtual void DrawModalControl(Controls::Base* control)
            {
                if (control->ShouldDrawBackground())
                {
                    Gwk::Rect rect = control->GetRenderBounds();
                    GetRender()->SetDrawColor(m_colModal);
                    GetRender()->DrawFilledRect(rect);
                }
            }

            virtual void DrawMenuDivider(Controls::Base* control)
            {
                Gwk::Rect rect = control->GetRenderBounds();
                GetRender()->SetDrawColor(m_colBGDark);
                GetRender()->DrawFilledRect(rect);
                GetRender()->SetDrawColor(m_colControlDarker);
                GetRender()->DrawLinedRect(rect);
            }

            virtual void DrawMenuRightArrow(Controls::Base* control)
            {
                DrawArrowRight(control->GetRenderBounds());
            }

            virtual void DrawSlideButton(Gwk::Controls::Base* control, bool bDepressed,
                                         bool bHorizontal)
            {
                DrawButton(control, bDepressed, control->IsHovered(), control->IsDisabled());
            }

            virtual void DrawCategoryHolder(Controls::Base* ctrl) {}
            virtual void DrawCategoryInner(Controls::Base* ctrl, bool bCollapsed) {}
        };


    }
}


#endif // ifndef GWK_SKINS_SIMPLE_H