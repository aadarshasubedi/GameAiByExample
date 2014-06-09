// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "State.h"
#include <cstdlib>
#include <cassert>

template <class entity_type>
class StateMachine
{
    public:
    
        StateMachine(entity_type* owner) : m_pOwner(owner),
                                           m_pCurrentState(NULL),
                                           m_pPreviousState(NULL),
                                           m_pGlobalState(NULL) {}
        virtual ~StateMachine() {}

        // use these methods to initializa the FSM
        void SetCurrentState (State<entity_type>* s) {m_pCurrentState  = s;}
        void SetGlobalState  (State<entity_type>* s) {m_pGlobalState   = s;}
        void SetPreviousState(State<entity_type>* s) {m_pPreviousState = s;}
        
        // call this to update FSM
        void Update() const
        {
            // if a global states exists, call its execute method
            if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
            
            // same for the current state
            if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
        }
        
        // change to a new state
        void ChangeState(State<entity_type>* pNewState)
        {
            assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");
            
            // keep a record of the previous state
            m_pPreviousState = m_pCurrentState;
            
            // call the exit method of the existing state
            m_pCurrentState->Exit(m_pOwner);
            
            // change state to the new state
            m_pCurrentState = pNewState;
            
            // call the entry method of the new state
            m_pCurrentState->Enter(m_pOwner);
        }
        
        // change state back to the previous state
        void RevertToPreviousState()
        {
            ChangeState(m_pPreviousState);
        }
        
        // accessors
        State<entity_type>* CurrentState()  const {return m_pCurrentState;}
        State<entity_type>* GlobalState()   const {return m_pGlobalState;}
        State<entity_type>* PreviousState() const {return m_pPreviousState;}

        // returns true if the current state's type is equal
        // to the type of the class passed as a parameter.
        bool isInState(const State<entity_type>& st) const;

    private:
    
        // a pointer to the agent that owns this instance
        entity_type* m_pOwner;
        
        State<entity_type>* m_pCurrentState;
        
        // a record of the last state the agent was include
        State<entity_type>* m_pPreviousState;
        
        // this state logic is called every time the FSM is updated
        State<entity_type>* m_pGlobalState;
};

#endif // __STATE_MACHINE_H__
