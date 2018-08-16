//
//  GameObject.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Updater.h"
#include "Utils.h"
#include "IGameObject.h"

namespace gameobject {
    
    class GameObject : public game::IUpdater, public IGameObject
    {
        public:
        GameObject() = default;
        
        GameObject(utils::Point3D<float>pos);
        
        GameObject(utils::Point3D<float>position,
                   utils::Point3D<float> size,
                   utils::Point3D<float> color);
            ~GameObject();
        
        void SetPosition(utils::Point3D<float> position) override;
        void SetColor(utils::Point3D<float> color) override;
        void SetRotation(float rotation) override;
        void SetScale(float scale) override;
        void SetSize(utils::Point3D<float> size) override;
        
        utils::Point3D<float> GetPosition() const override;
        float GetRotation() const override;
        float GetScale() const override;
        utils::Point3D<float> GetColor() const override;
        utils::Point3D<float> GetSize() const override;
        
        void Update(float deltaTime) override;
        
    protected:
        
        void Draw(float deltaTime) override;
        virtual void SetModelView();
        
        GLuint program;
        GLuint m_vertexBuffer;
        GLuint m_indexBuffer;
        GLuint m_vertexArray;
        //
        GLuint m_program;
        GLuint m_aPosition;
        GLuint m_aColor;
        // each object have modelview
        GLuint m_uModelview;
        
    };
    
}

#endif /* GameObject_hpp */
