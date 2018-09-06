/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CDummy.cpp
 *  PURPOSE:     Dummy entity class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"

CDummy::CDummy(CGroups* pGroups, CElement* pParent, CXMLNode* pNode) : CElement(pParent, pNode)
{
    // Init
    m_iType = CElement::DUMMY;
    SetTypeName("dummy");
    m_pGroups = pGroups;

    // Add us to parent's list
    if (pGroups)
    {
        pGroups->AddToList(this);
    }
}

CDummy::~CDummy(void)
{
    // Unlink from manager
    Unlink();
}

CElement* CDummy::Clone(bool* bAddEntity, CResource* pResource)
{
    CElement* pNewElement = new CDummy(g_pGame->GetGroups(), GetParentEntity());
    pNewElement->SetName(GetName());
    pNewElement->SetTypeName(GetTypeName());
    return pNewElement;
}

void CDummy::Unlink(void)
{
    // Remove us from groupmanager's list
    if (m_pGroups)
    {
        m_pGroups->RemoveFromList(this);
    }
}

bool CDummy::ReadSpecialData(void)
{
    // Grab the position data
    GetCustomDataFloat("posX", m_vecPosition.fX, true);
    GetCustomDataFloat("posY", m_vecPosition.fY, true);
    GetCustomDataFloat("posZ", m_vecPosition.fZ, true);

    return true;
}
