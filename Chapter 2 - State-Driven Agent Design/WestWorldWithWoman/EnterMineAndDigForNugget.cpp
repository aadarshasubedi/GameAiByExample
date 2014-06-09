// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#include "Miner.h"
#include "EnterMineAndDigForNugget.h"
#include <iostream>

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
    // if the miner is not already located at the gold mine,
    // he must change location to the gold mine
    if (pMiner->Location() != goldmine)
    {
        std::cout << '\n' << GetNameOfEntity(pMiner->ID())
                  << ": Walkin' to the gold mine";
                  
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
    // the miner digs for gold until he is carrying in excess of 
    // MaxNuggets. If he gets thirsty during his digging he stops 
    // work and changes state to go to the saloon for a wiskey.
    pMiner->AddToGoldCarried(1);
    
    // diggin'' is hard work
    pMiner->IncreaseFatigue();
    
    std::cout << '\n' << GetNameOfEntity(pMiner->ID())
              << ": Pickin' up a nugget";
    
    // if enough gold mined, go and put it in the bank
    if (pMiner->PocketsFull())
    {
        pMiner->ChangeState(VisitBankAndDepositGold::Instance());
    }
    
    // if thirsty go and get a whiskey
    if (pMiner->Thirsty())
    {
        pMiner->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
    std::cout << '\n' << GetNameOfEntity(pMiner->ID())
              << ": Ah'm leavin' the gold mine with mah pockets full o' sweet gold";
}
