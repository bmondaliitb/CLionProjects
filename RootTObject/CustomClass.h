//
// Created by bmondal on 16/01/21.
//

#ifndef ROOTTOBJECT_CUSTOMCLASS_H
#define ROOTTOBJECT_CUSTOMCLASS_H

#include "TObject.h"

class CustomClass : public TObject{
public:
    // constructor and destructors
    CustomClass();

public:
    char* m_fileName = nullptr;
};


#endif //ROOTTOBJECT_CUSTOMCLASS_H
