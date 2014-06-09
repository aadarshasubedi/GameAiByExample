// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#include "Miner.h"
#include "QuenchThirst.h"
#include <iostream>

void QuenchThirst::Enter(Miner* pMiner)
{
    if (pMiner->Location() != saloon)
    {
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": Boy, ah sure is thusty! Walkin' to the saloon";
                  
        pMiner->ChangeLocation(saloon);
    }
}

void QuenchThirst::Execute(Miner* pMiner)
{
    if (pMiner->Thirsty())
    {
        pMiner->BuyAndDrinkAWhiskey();
        
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": That's mighty fine sippin liquor";
                                    
        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }
    else
    {
        std::cout << "\nERROR!\nERROR!\nERROR!";
    }
}

void QuenchThirst::Exit(Miner* pMiner)
{
    std::cout << '\n' << GetNameOfEntity(pMiner->ID())
              << ": Leavin' the saloon, feelin' good";
}
