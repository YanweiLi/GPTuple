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
    
    NSArray* a = @[@1 , @3 , @56];
    base = [GPTupleBase tupleWithArray:a];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
