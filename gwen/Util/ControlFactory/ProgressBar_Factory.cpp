
#include "GwenUtil/ControlFactory.h"
#include "Gwen/Controls.h"

namespace Gwen
{
    namespace ControlFactory
    {
        using namespace Gwen;

        namespace Properties
        {
            class CycleSpeed : public ControlFactory::Property
            {
                GWEN_CONTROL_FACTORY_PROPERTY(CycleSpeed, "");

                String GetValue(Controls::Base* ctrl)
                {
                    return Utility::Format("%f", (float)gwen_cast<Controls::ProgressBar>(
                                               ctrl)->GetCycleSpeed());
                }

                void SetValue(Controls::Base* ctrl, const String& str)
                {
                    float num;

                    if (sscanf(str.c_str(), "%f", &num) != 1)
                        return;

                    gwen_cast<Controls::ProgressBar>(ctrl)->SetCycleSpeed(num);
                }

            };


        }

        class ProgressBar_Factory : public Gwen::ControlFactory::Base
        {
        public:

            GWEN_CONTROL_FACTORY_FOR(ProgressBar, Base)
            {
                AddProperty(new Properties::CycleSpeed());
            }

            virtual Gwen::Controls::Base* CreateInstance(Gwen::Controls::Base* parent)
            {
                Gwen::Controls::ProgressBar* pControl = new Gwen::Controls::ProgressBar(parent);
                pControl->SetSize(200, 20);
                return pControl;
            }

        };


        GWEN_CONTROL_FACTORY(ProgressBar_Factory);

    }
}
