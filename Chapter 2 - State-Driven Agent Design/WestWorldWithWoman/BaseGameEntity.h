// May, 2014 PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil
// Implementation of Mat Buckland's Programming Game AI by Example
// (C) 2005, Wordware Publishing, Inc. All Rights Reserved

#ifndef __BASE_GAME_ENTITY_H__
#define __BASE_GAME_ENTITY_H__

class BaseGameEntity
{
    public:
    
        BaseGameEntity(int id) {SetID(id);}
        virtual ~BaseGameEntity() {}
        
        // all entities must implement an update function
        virtual void Update() = 0;
        
        int ID()const{return m_ID;}

    private:
    
        // every entity has a unique identifying number
        int m_ID;
        
        // this is the next valid ID. Each time a BaseGameEntity
        // is instantiated this value is updated
        static int m_iNextValidID;
        
        // this is called within the constructor to make sure the ID
        // is set correctly. It verifies that the value passed to the 
        // method is greater or equal to the next valid ID, before
        // setting the ID and incrementing the next valid ID
        void SetID(int val);
};

#endif // __BASE_GAME_ENTITY_H__
