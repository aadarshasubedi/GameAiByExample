// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#include "BaseGameEntity.h"
#include <cassert>

int BaseGameEntity::m_iNextValidID = 0;

void BaseGameEntity::SetID(int val)
{
    assert(val >= m_iNextValidID);

    m_ID = val;
    
    m_iNextValidID = m_ID + 1;
}
