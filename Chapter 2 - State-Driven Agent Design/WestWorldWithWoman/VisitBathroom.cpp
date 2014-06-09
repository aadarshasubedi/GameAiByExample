// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#include "MinersWife.h"
#include "VisitBathroom.h"
#include <iostream>

void VisitBathroom::Enter(MinersWife* pMinersWife)
{
    if (pMinersWife->Location() != bathroom)
    {
        std::cout << '\n' << GetNameOfEntity(pMinersWife->ID())
                  << ": Walkin' to the can. Need to powda mah pretty li'l nose";
                  
        pMinersWife->ChangeLocation(bathroom);
    }
}

void VisitBathroom::Execute(MinersWife* pMinersWife)
{
    pMinersWife->AddToWealth(pMinersWife->GoldCarried());
    
    pMinersWife->SetGoldCarried(0);
    
    std::cout << '\n' << GetNameOfEntity(pMinersWife->ID())
              << ": Depositin' gold. Total savings now: " << pMinersWife->Wealth();
              
    if (pMinersWife->Wealth() >= COMFORTABLE)
    {
        std::cout << '\n' << GetNameOfEntity(pMinersWife->ID())
                  << ": Woohoo! Rich enough for now. Back home to mah li'l lady";
        
        pMinersWife->ChangeState(GoHomeAndSleepTilRested::Instance());
    }
    else
    {
        pMinersWife->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void VisitBathroom::Exit(MinersWife* pMinersWife)
{
    std::cout << '\n' << GetNameOfEntity(pMinersWife->ID())
              << ": Leavin' the john";
}
