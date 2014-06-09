// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __VISIT_BATHROOM_H__
#define __VISIT_BATHROOM_H__

#include "State.h"
#include <string>

class MinersWife;

class VisitBathroom : public State<MinersWife>
{
    public:
    
        virtual ~VisitBathroom() {}

        static VisitBathroom* Instance()
        {
            static VisitBathroom instance;
            return &instance;
        }

        virtual void Enter(MinersWife* pMinersWife);
        
        virtual void Execute(MinersWife* pMinersWife);
        
        virtual void Exit(MinersWife* pMinersWife);
        
    private:
    
        VisitBathroom() {}
        
        VisitBathroom(VisitBathroom const&);
        
        void operator=(VisitBathroom const&);
        
        std::string GetNameOfEntity(int) {return "Elsa";}
        
};

#endif // __VISIT_BATHROOM_H__
