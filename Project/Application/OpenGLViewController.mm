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
#include "FlappyBirdGameScene.h"
#include "ExamplesManager.h"


@interface OpenGLViewController (privateMethods)
-(void) createOpenGlContext;
-(void) initShaders;
@end

@implementation OpenGLViewController

- (void)viewDidLoad
{
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
        
        // initialize shaders
        [self initShaders];
        
        // run some example
        examples::ExamplesManager::Instance().RunExample(examples::Examples::kFlappyBirdExample);
        //
    }
    else
    {
        NSLog(@"Failed to create ES context");
    }
}

-(void) initShaders
{
    //init shaders
    NSString *vertexShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"unlit_color_vertex" ofType:@"vsh"] encoding:NSUTF8StringEncoding error:nil];
    const char *vertexShaderSourceCString = [vertexShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
    //
    NSString *fragmentShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"unlit_color_fragment" ofType:@"fsh"] encoding:NSUTF8StringEncoding error:nil];
    const char *fragmentShaderSourceCString = [fragmentShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
    
    // initialize unlict color shader
    ShaderManagerInstance.initUnlitColorShaders(vertexShaderSourceCString, fragmentShaderSourceCString);
    //
    vertexShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"unlit_texture_vertex" ofType:@"vsh"] encoding:NSUTF8StringEncoding error:nil];
    const char *vertexShaderUnlitTextureSourceCString = [vertexShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
    
    fragmentShaderSource = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"unlit_texture_fragment" ofType:@"fsh"] encoding:NSUTF8StringEncoding error:nil];
    const char *fragmentShaderUnlitTextureSourceCString = [fragmentShaderSource cStringUsingEncoding:NSUTF8StringEncoding];
    
    // initialize unlit texture shader
    ShaderManagerInstance.initUnlitTextureShaders(vertexShaderUnlitTextureSourceCString, fragmentShaderUnlitTextureSourceCString);
}

// main game loop - highest layer of the game architecture
-(void) update
{
    glClear(GL_COLOR_BUFFER_BIT);
    // update example
    examples::ExamplesManager::Instance().Update((float)self.timeSinceLastDraw);
    
    // Present renderbuffer
    [openGlContext presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
// application touch begin
-(void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    //
    App.OnApplicationTouchInputDown(touchLocation.x, touchLocation.y);
}

// application touch moved
-(void) touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    //
    App.OnApplicationTouchInputMove(touchLocation.x, touchLocation.y);
}

// application touch ended
-(void) touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    //
    App.OnApplicationTouchInputUp(touchLocation.x, touchLocation.y);
}

@end
