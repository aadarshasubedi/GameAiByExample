// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __VISIT_BANK_AND_DEPOSIT_GOLD_H__
#define __VISIT_BANK_AND_DEPOSIT_GOLD_H__

#include "State.h"
#include <string>

class Miner;

class VisitBankAndDepositGold : public State<Miner>
{
    public:
    
        virtual ~VisitBankAndDepositGold() {}

        static VisitBankAndDepositGold* Instance()
        {
            static VisitBankAndDepositGold instance;
            return &instance;
        }

        virtual void Enter(Miner* pMiner);
        
        virtual void Execute(Miner* pMiner);
        
        virtual void Exit(Miner* pMiner);
        
    private:
    
        VisitBankAndDepositGold() {}
        
        VisitBankAndDepositGold(VisitBankAndDepositGold const&);
        
        void operator=(VisitBankAndDepositGold const&);
        
        std::string GetNameOfEntity(int) {return "bob";}
        
};

#endif // __VISIT_BANK_AND_DEPOSIT_GOLD_H__
