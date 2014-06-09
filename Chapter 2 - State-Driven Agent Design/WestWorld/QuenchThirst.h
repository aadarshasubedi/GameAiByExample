// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __QUENCH_THIRST_H__
#define __QUENCH_THIRST_H__

#include "State.h"
#include <string>

class Miner;

class QuenchThirst : public State<Miner>
{
    public:
    
        virtual ~QuenchThirst() {}

        static QuenchThirst* Instance()
        {
            static QuenchThirst instance;
            return &instance;
        }

        virtual void Enter(Miner* pMiner);
        
        virtual void Execute(Miner* pMiner);
        
        virtual void Exit(Miner* pMiner);
        
    private:
    
        QuenchThirst() {}
        
        QuenchThirst(QuenchThirst const&);
        
        void operator=(QuenchThirst const&);
        
        std::string GetNameOfEntity(int) {return "bob";}
        
};

#endif // __QUENCH_THIRST_H__
