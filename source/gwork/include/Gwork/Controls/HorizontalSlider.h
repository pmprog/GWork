/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-16 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_HORIZONTALSLIDER_H
#define GWK_CONTROLS_HORIZONTALSLIDER_H

#include "Gwork/Controls/Base.h"
#include "Gwork/Controls/Button.h"
#include "Gwork/Controls/Dragger.h"
#include "Gwork/Gwork.h"
#include "Gwork/Skin.h"
#include "Gwork/Controls/Slider.h"

namespace Gwk
{
    namespace Controls
    {
        class GWK_EXPORT HorizontalSlider : public Slider
        {
            GWK_CONTROL(HorizontalSlider, Slider);

            virtual void Layout(Skin::Base* skin) override;
            virtual void Render(Skin::Base* skin) override;

            virtual float CalculateValue() override;
            virtual void  UpdateBarFromValue() override;
            virtual void  OnMouseClickLeft(int x, int y, bool bDown) override;
        };


    }
}
#endif // ifndef GWK_CONTROLS_HORIZONTALSLIDER_H