// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __ENTER_MINE_AND_DIG_FOR_NUGGET_H__
#define __ENTER_MINE_AND_DIG_FOR_NUGGET_H__

#include "State.h"
#include <string>

class Miner;

class EnterMineAndDigForNugget : public State<Miner>
{
    public:
    
        virtual ~EnterMineAndDigForNugget() {}

        // this is a singleton
        static EnterMineAndDigForNugget* Instance()
        {
            static EnterMineAndDigForNugget instance;
            return &instance;
        }

        virtual void Enter(Miner* pMiner);
        
        virtual void Execute(Miner* pMiner);
        
        virtual void Exit(Miner* pMiner);

    private:
    
        EnterMineAndDigForNugget() {}
        
        // copy ctor
        EnterMineAndDigForNugget(EnterMineAndDigForNugget const&);

        // operator =
        void operator=(EnterMineAndDigForNugget const&);
        
        std::string GetNameOfEntity(int) {return "bob";}
};

#endif // __ENTER_MINE_AND_DIG_FOR_NUGGET_H__
