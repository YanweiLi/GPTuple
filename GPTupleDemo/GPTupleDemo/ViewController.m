//
//  ViewController.m
//  GPTupleDemo
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import "ViewController.h"
#import <GPTuple/GPTuple.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    GPTupleBase* base = [GPTupleBase tupleWithCount:20];
    
    NSArray* a = @[@1 , @"who am I ?" , @YES];
    base = [GPTupleBase tupleWithArray:a];
    
    
    GPTuple3<NSString* , NSNumber* , NSNumber*>* tuple3 = [[GPTuple3 alloc] initWithFirst:@"who I am?" second:@1 third:@YES];
    NSLog(@"%@" , tuple3);
}

@end
