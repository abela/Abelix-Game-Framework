//
//  PipesManager.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/12/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "PipesManager.h"
#include "Utils.h"
#include <iostream>
#include <random>

#define PIPES_GENERATE_TIME_COUNTER 3.5f
#define PIPES_GENERATE_TIME         3.5f
#define PIPES_MOVE_SPEED            2
#define PIPES_MOVING_DIMENSION      8

namespace flappybird
{
    PipesManager::PipesManager() : pipesGenerateTimeCounter(PIPES_GENERATE_TIME_COUNTER),
                                    pipesGenerateTime(PIPES_GENERATE_TIME),
                                    pipesMoveSpeed(PIPES_MOVE_SPEED),
                                    movingDimension(PIPES_MOVING_DIMENSION)
    {
        std::cout<<"creating pipes manager object"<<std::endl;
    }
    
    PipesManager::~PipesManager()
    {
        std::cout<<"destroying pipes manager object"<<std::endl;
        Reset();
    }
    
    void PipesManager::Update(float deltaTime)
    {
        for(int i =0;i<m_pipes.size();i++)
        {
            m_pipes[i]->Update(deltaTime);
        }
        GeneratePipe(deltaTime);
        MovePipes(deltaTime);
    }
    
    void PipesManager::MovePipes(float deltaTime)
    {
        for(int i =0;i<m_pipes.size();i++)
        {
            m_pipes[i]->SetPosition(utils::Point3D<float>(m_pipes[i]->GetPosition().X - deltaTime * pipesMoveSpeed,
                                                          m_pipes[i]->GetPosition().Y,
                                                          m_pipes[i]->GetPosition().Z));
            if(m_pipes[i]->GetPosition().X <= -movingDimension)
            {
                m_pipes.erase(m_pipes.begin() + i);
                break;
            }
        }
    }
    
    void PipesManager::GeneratePipe(float deltaTime)
    {
        pipesGenerateTimeCounter+=deltaTime;
        if(pipesGenerateTimeCounter>=pipesGenerateTime)
        {
            //
            float startHeight = 11;
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(-movingDimension/2, movingDimension/2); // define the range
            float posDeltaY = distr(eng);
            //
            // create two vertical pipes
            // creat pipe at some point outside of the screen
            utils::Point3D<float> pipePosition(movingDimension, -startHeight + posDeltaY, -5.0f);
            // set pipe size
            utils::Point3D<float> pipeSize(1, movingDimension, 1);
            // set color
            utils::Point3D<float> pipeColor(1, 1, 1);
            // add it to the list
            std::unique_ptr<Pipe> pipe(new Pipe(pipePosition,pipeSize, pipeColor));
            // set new pipe position
            pipePosition.Set(movingDimension, startHeight + posDeltaY, -5);
            std::unique_ptr<Pipe> pipe2(new Pipe(pipePosition,pipeSize, pipeColor));
            //
            //
            //
            m_pipes.push_back(move(pipe));
            m_pipes.push_back(move(pipe2));
            // reset generate counter
            pipesGenerateTimeCounter = 0;
        }
    }
    
    void PipesManager::Reset()
    {
        m_pipes.clear();
        pipesGenerateTimeCounter = PIPES_GENERATE_TIME_COUNTER;
        pipesGenerateTime = PIPES_GENERATE_TIME;
        pipesMoveSpeed = PIPES_MOVE_SPEED;
        movingDimension = PIPES_MOVING_DIMENSION;
    }
}
