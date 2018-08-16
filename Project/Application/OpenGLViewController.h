//
//  ViewController.h
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/5/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import <GLKit/GLKEffects.h>

#include <memory>

@interface OpenGLViewController : GLKViewController
{
    @private EAGLContext *openGlContext;
    @private GLKBaseEffect *effect;
}
@end

