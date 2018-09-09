//
//  Utils.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp


#include <stdio.h>
#include <OpenGLES/gltypes.h>
#include <memory>
#include <mutex>
#include <algorithm>

namespace utils {
    
    
    template <typename T>
    struct Point3D {
        T X;
        T Y;
        T Z;
        //
        Point3D(){};
        //
        Point3D(T X,T Y, T Z) {
            this->X = X;
            this->Y = Y;
            this->Z = Z;
        };
        void Set(T X, T Y, T Z)
        {
            this->X = X;
            this->Y = Y;
            this->Z = Z;
        }
        //
        inline Point3D& operator=(const Point3D &p) {
            X=p.X;
            Y=p.Y;
            Z=p.Z;
            return *this;
        }
        
        inline Point3D& operator+(const Point3D &p) {
            X= X + p.X;
            Y= Y + p.Y;
            Z= Z + p.Z;
            return *this;
        }
        
        inline Point3D& operator-(const Point3D &p) {
            X= X - p.X;
            Y= Y - p.Y;
            Z= Z - p.Z;
            return *this;
        }
        
        inline Point3D& operator-(const float &p) {
            X= X - X;
            Y= Y - Y;
            Z= Z - Z;
            return *this;
        }
        
        inline Point3D& operator-=(const float &p) {
            X= X - p;
            Y= Y - p;
            Z= Z - p;
            return *this;
        }
        
        inline Point3D& operator*(const float &p) {
            X= X * p;
            Y= Y * p;
            Z= Z * p;
            return *this;
        }
        
        inline bool operator==(const Point3D& lhs)
        {
            return lhs.X ==X && lhs.Y == Y;
        }
        
        inline bool operator!=(const float& lhs)
        {
            return lhs !=X && lhs != Y && lhs != Z;
        }
        
    };
    
    template <typename T>
    struct Vertex
    {
        T Position[3];
        T Color[4];
    };
    
    class Constants
    {
    public:
        static const int QUAD_POS_VERTICES_ARRAY_COUNT;
        static const int QUAD_COLOR_VERTICES_ARRAY_COUNT;
        static const GLchar* SHADER_ATTRIB_POSITION_VAR;
        static const GLchar* SHADER_ATTRIB_COLOR_VAR;
        static const GLchar* SHADER_UNIFORM_MATRIX_VAR;
        static const GLchar* SHADER_TEXTURE_COORD_VAR;
        static const GLchar* SHADER_TEXTURE_VAR;
        static const GLchar* SHADER_UNIFORM_PROJ_MATRIX_VAR;
        static const int GLOBAL_GRAVITY_CONST;
    };
    
    template <class T>
    struct SMatrix4x4
    {
        SMatrix4x4() { }
        
        inline void SetPosition( Point3D<T> pos )
        {
            m_mat[3] = pos.X;
            m_mat[7] = pos.Y;
            m_mat[11] = pos.Z;
        }
        
        inline void SetScale( T scale )
        {
            m_mat[0] = scale;
            m_mat[5] = scale;
            m_mat[10] = scale;
        }
        
        inline void MakeIdentity()
        {
            //memset( m_mat, 0, m_mat);
            
            m_mat[0] = 1;
            m_mat[5] = 1;
            m_mat[10] = 1;
            m_mat[15] = 1;
        }
        
        T m_mat[16];
    };
    
    // singleton template
    template<typename T>
    class Singleton {
    public:
        static T& Instance();
        
        Singleton(const Singleton&) = delete;
        Singleton& operator= (const Singleton) = delete;
        
    protected:
        struct initializer {};
        Singleton() {}
    };
    
    template<typename T>
    T& Singleton<T>::Instance()
    {
        static T instance{initializer{}};
        return instance;
    }
    template<typename T>
    utils::Point3D<T> lerp(T t, utils::Point3D<T> a, utils::Point3D<T> b){
        return a*(1-t) + b*t;
    }
}



#endif /* Utils_hpp */
