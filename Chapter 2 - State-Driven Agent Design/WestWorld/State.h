// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __STATE_H__
#define __STATE_H__

template <class entity_type>
class State
{
    public:
    
        virtual ~State() {}

        // this will execute when the state is entered
        virtual void Enter(entity_type*) = 0;
        
        // this is called by the miner's update function each update step
        virtual void Execute(entity_type*) = 0;
        
        // this will execute when the state is exited
        virtual void Exit(entity_type*) = 0;
};

#endif // __STATE_H__
