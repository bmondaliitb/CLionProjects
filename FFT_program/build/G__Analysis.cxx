// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Analysis
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/Users/buddha/CLionProjects/FFT_program/RooMyPDF_BW.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *RooMyPDF_BW_Dictionary();
   static void RooMyPDF_BW_TClassManip(TClass*);
   static void *new_RooMyPDF_BW(void *p = nullptr);
   static void *newArray_RooMyPDF_BW(Long_t size, void *p);
   static void delete_RooMyPDF_BW(void *p);
   static void deleteArray_RooMyPDF_BW(void *p);
   static void destruct_RooMyPDF_BW(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RooMyPDF_BW*)
   {
      ::RooMyPDF_BW *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RooMyPDF_BW));
      static ::ROOT::TGenericClassInfo 
         instance("RooMyPDF_BW", "RooMyPDF_BW.h", 15,
                  typeid(::RooMyPDF_BW), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RooMyPDF_BW_Dictionary, isa_proxy, 0,
                  sizeof(::RooMyPDF_BW) );
      instance.SetNew(&new_RooMyPDF_BW);
      instance.SetNewArray(&newArray_RooMyPDF_BW);
      instance.SetDelete(&delete_RooMyPDF_BW);
      instance.SetDeleteArray(&deleteArray_RooMyPDF_BW);
      instance.SetDestructor(&destruct_RooMyPDF_BW);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RooMyPDF_BW*)
   {
      return GenerateInitInstanceLocal(static_cast<::RooMyPDF_BW*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RooMyPDF_BW*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RooMyPDF_BW_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::RooMyPDF_BW*>(nullptr))->GetClass();
      RooMyPDF_BW_TClassManip(theClass);
   return theClass;
   }

   static void RooMyPDF_BW_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_RooMyPDF_BW(void *p) {
      return  p ? new(p) ::RooMyPDF_BW : new ::RooMyPDF_BW;
   }
   static void *newArray_RooMyPDF_BW(Long_t nElements, void *p) {
      return p ? new(p) ::RooMyPDF_BW[nElements] : new ::RooMyPDF_BW[nElements];
   }
   // Wrapper around operator delete
   static void delete_RooMyPDF_BW(void *p) {
      delete (static_cast<::RooMyPDF_BW*>(p));
   }
   static void deleteArray_RooMyPDF_BW(void *p) {
      delete [] (static_cast<::RooMyPDF_BW*>(p));
   }
   static void destruct_RooMyPDF_BW(void *p) {
      typedef ::RooMyPDF_BW current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RooMyPDF_BW

namespace {
  void TriggerDictionaryInitialization_libAnalysis_Impl() {
    static const char* headers[] = {
"/Users/buddha/CLionProjects/FFT_program/RooMyPDF_BW.h",
nullptr
    };
    static const char* includePaths[] = {
"/Users/buddha/local_packages/root_install/include",
"/Users/buddha/CLionProjects/FFT_program",
"/Users/buddha/local_packages/root_install/include/",
"/Users/buddha/CLionProjects/FFT_program/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libAnalysis dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/Users/buddha/CLionProjects/FFT_program/RooMyPDF_BW.h")))  RooMyPDF_BW;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libAnalysis dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/Users/buddha/CLionProjects/FFT_program/RooMyPDF_BW.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RooMyPDF_BW", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libAnalysis",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libAnalysis_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libAnalysis_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libAnalysis() {
  TriggerDictionaryInitialization_libAnalysis_Impl();
}
