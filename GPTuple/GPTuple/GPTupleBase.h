//
//  GPTupleBase.h
//  GPTuple
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GPTupleBase : NSObject <NSCopying , NSFastEnumeration>

/**
 hash 值
 */
@property (nonatomic , assign) NSUInteger hashValue;

/**
 元素个数
 */
@property (nonatomic , assign , readonly) NSUInteger count;

/**
 初始化

 @param array 数组
 @return tuple
 */
+ (instancetype) tupleWithArray:(NSArray*) array;

/**
 工厂方法，创建count个元素大小的tuple

 @param count 元素个数
 @return tuple
 */
+ (__kindof GPTupleBase*) tupleWithCount:(NSUInteger) count;

/**
 获取index对应的元素

 @param index 下标
 @return 元素
 */
- (id)objectAtIndexedSubscript:(NSUInteger)index;

/**
 设置元素

 @param obj 对象 value值
 @param index key 值
 */
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)index;

/**
 合并两个tuple

 @param other tuple
 @return tuple
 */
- (__kindof GPTupleBase *)join:(GPTupleBase *)other;
- (__kindof GPTupleBase *)take:(NSUInteger)count;
- (__kindof GPTupleBase *)drop:(NSUInteger)count;

/**
 所有的元素

 @return 元素
 */
- (NSArray *) allObjects;
@end

