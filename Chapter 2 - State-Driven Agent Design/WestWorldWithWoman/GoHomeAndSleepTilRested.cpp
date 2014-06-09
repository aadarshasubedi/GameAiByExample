// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#include "Miner.h"
#include "GoHomeAndSleepTilRested.h"
#include <iostream>

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
    if (pMiner->Location() != shack)
    {
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": Walkin' home";
                  
        pMiner->ChangeLocation(shack);
    }
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{
    if (!pMiner->Fatigued())
    {
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": What a God-darn fantastic nap! Time to find more gold";
        
        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }
    else
    {
        pMiner->DecreaseFatigue();
    
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": ZZZZ...";
    }
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
    std::cout << '\n' << GetNameOfEntity(pMiner->ID())
              << ": Leavin' the house";
}
