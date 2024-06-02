#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class MyAmp : public Plugin {
  public:
    MyAmp() : Plugin(kParameterCount, 0, 0), gain(1.0) {}

    

  private:
    float gain;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MyAmp);
}

Plugin *createPlugin() { return new MyAmp(); }

END_NAMESPACE_DISTRHO