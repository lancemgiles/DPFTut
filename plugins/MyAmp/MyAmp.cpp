#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class MyAmp : public Plugin {
  public:
    MyAmp() : Plugin(kParameterCount, 0, 0), gain(1.0) {}

  protected:
    const char *getLabel() const override { return "MyAmp"; }
    const char *getDescription() const override {
      return "Simple amp plugin";
    }
    const char *getMaker() const override { return "dogman devices"; }
    const char *getLicense() const override { return "MIT"; }
    uint32_t getVersion() const override { return d_version(1,0,0); }
    int64_t getUniqueId() const override {
      return d_cconst('M','A','D','T'); // My Amp Dpf Tutorial
    }

  private:
    float gain;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MyAmp);
}

Plugin *createPlugin() { return new MyAmp(); }

END_NAMESPACE_DISTRHO