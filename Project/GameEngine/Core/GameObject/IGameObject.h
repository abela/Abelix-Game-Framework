//
//  IGameObject.h
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef IGameObject_h
#define IGameObject_h

namespace gameobject {
    class IGameObject
    {
    public:
        virtual ~IGameObject() {}
        virtual void SetPosition(utils::Point3D<float> position) = 0;
        virtual void SetSize(utils::Point3D<float> size) = 0;
        virtual void SetColor(utils::Point3D<float> color) = 0;
        virtual void SetRotation(float rotation) = 0;
        virtual void SetScale(float scale) = 0;
        
        virtual utils::Point3D<float> GetPosition() const = 0;
        virtual utils::Point3D<float> GetSize() const = 0;
        virtual utils::Point3D<float> GetColor() const = 0;
        virtual float GetRotation() const = 0;
        virtual float GetScale() const = 0;
        
    protected:
        // main drawing function
        virtual void Draw(float deltaTime) = 0;
        //
        utils::Point3D<float> position;
        utils::Point3D<float> size;
        utils::Point3D<float> color;
        float scale;
        float rotation;
    };
}

#endif /* IGameObject_h */
