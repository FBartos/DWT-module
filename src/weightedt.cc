#include <module/Module.h>
#include <distributions/DWT1.h>
#include <distributions/DWT2.h>
#include <functions/LogWeightedtFun.h>

namespace jags { 
namespace weightedt { // module namespace

  // JAGS module class
  class WTModule : public Module {
    public:
      WTModule();
      ~WTModule();
  };

  // constructor (executed when loading the module)
  WTModule::WTModule() : Module("weightedt"){
    insert(new DWT1);
    insert(new DWT2);
    //load functions
    insert(new LogWeightedtFun);
  }
  
  // destructor (executed when unloading the module)
  WTModule::~WTModule() {
    std::vector<Function*> const &fvec = functions();
    for (unsigned int i = 0; i < fvec.size(); ++i) {
      delete fvec[i];
    }
    std::vector<Distribution*> const &dvec = distributions();
    for (unsigned int i=0;i<dvec.size();++i) {
      delete dvec[i];
    }
  }

}
}

jags::weightedt::WTModule _weightedt_module;

