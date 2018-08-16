//
//  ViewController.m
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/5/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#import "OpenGLViewController.h"
#include <stddef.h>
#import "GLView.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <sys/types.h>
#include <OpenGLES/gltypes.h>
#include "Utils.h"
#include "ShaderManager.h"
#include "Application.h"
#include "GameScene.h"


@interface OpenGLViewController (privateMethods)
-(void) createOpenGlContext;
-(void) setProjection;
@end

@implementation OpenGLViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // create opengl context
    [self createOpenGlContext];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
 {
     self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
     if (self) {
     // Custom initialization
     }
     return self;
 }

// create opengl context
-(void) createOpenGlContext
{
    openGlContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    if (openGlContext)
    {
        [EAGLContext setCurrentContext:openGlContext];
        //
        GLKView *view = (GLKView *)self.view;
        view.context = openGlContext;
        //
        GLView *glView = [[GLView alloc] initWithFrame:CGRectMake(0, 0 , 375, 675)];
        [self.view addSubview:glView];
        //
        glEnable(GL_CULL_FACE);
        //
        // create render buffer
        GLuint renderbuffer;
        glGenRenderbuffers(1, &renderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
        [openGlContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer*)glView.layer];
        
        // Create a framebuffer
        GLuint framebuffer;
        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, renderbuffer);
        
        // setup viewport
        glViewport(0,  0, 1, 1);
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //init shaders
        NSString *vertexShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"VertexShader" ofType:@"vsh"] encoding:NSUTF8StringEncoding error:nil];
        const char *vertexShaderSourceCString = [vertexShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
        
        NSString *fragmentShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"FragmentShader" ofType:@"fsh"] encoding:NSUTF8StringEncoding error:nil];
        const char *fragmentShaderSourceCString = [fragmentShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
        
        // initialize shaders
        ShaderManagerInstance.initShaders(vertexShaderSourceCString, fragmentShaderSourceCString);
        //
        // run game
        App.StartGame(flappybird::GameScene::GetNewScene());
    }
    else
    {
        NSLog(@"Failed to create ES context");
    }
}
-(void) setProjection
{
    effect = [[GLKBaseEffect alloc] init];
    float aspect = fabs(self.view.bounds.size.width / self.view.bounds.size.height);
    GLKMatrix4 projectionMatrix = GLKMatrix4MakePerspective(GLKMathDegreesToRadians(45), aspect, 0.0f, 50.0f);
    effect.transform.projectionMatrix = projectionMatrix;
    
    GLKMatrix4 modelViewMatrix = GLKMatrix4MakeTranslation(0.0f, 0.0f, -20.0f);
    modelViewMatrix = GLKMatrix4Rotate(modelViewMatrix, GLKMathDegreesToRadians(0), 1, 0, 0);
    effect.transform.modelviewMatrix = modelViewMatrix;
}

// main game loop - highest layer of the game architecture
-(void) update
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    // update application - our application main game loop
    App.Update((float)self.timeSinceLastDraw);
    
    // Present renderbuffer
    [openGlContext presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    //
    App.OnApplicationTouchInputDown(touchLocation.x, touchLocation.y);
}

@end
