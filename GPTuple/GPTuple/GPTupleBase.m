//
//  GPTupleBase.m
//  GPTuple
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import "GPTupleBase.h"
#import "GPMacrosDef.h"
#import "GPTupleSub.h"
#import <objc/runtime.h>

////////////////////////////////////////////////////////////////////////////////

#define GPT_SETTER_FUNC_DEF(index)                      \
static void  GP_CONCAT(setter , index)                  \
(GP_CONCAT(GPTuple , GP_INC(index)) *tuple, id value)   \
{                                                       \
    tuple. GP_ORDINAL_AT(index) = value;                \
}

GP_FOR_SPACE(20, GPT_SETTER_FUNC_DEF)

////////////////////////////////////////////////////////////////////////////////

#define GPT_GETTER_FUNC_DEF(index)                      \
static id GP_CONCAT(getter, index)                      \
(GP_CONCAT(GPTuple, GP_INC(index)) *tuple)              \
{                                                       \
    return [tuple GP_ORDINAL_AT(index)];                \
}

GP_FOR_SPACE(20, GPT_GETTER_FUNC_DEF)

////////////////////////////////////////////////////////////////////////////////

typedef void (*SetterType)(GPTupleBase *tuple, id value);

#define GPT_SETTER_TABLE_ITEM(index)    & GP_CONCAT(setter, index)

SetterType setterTable[] = {
    GP_FOR_COMMA(20, GPT_SETTER_TABLE_ITEM)
};

typedef id (*GetterType)(GPTupleBase *tuple);

#define GPT_GETTER_TABLE_ITEM(index)    & GP_CONCAT(getter, index)

GetterType getterTable[] = {
    GP_FOR_COMMA(20, GPT_GETTER_TABLE_ITEM)
};

////////////////////////////////////////////////////////////////////////////////

@interface GPTupleBase()
@property (nonatomic , assign) NSUInteger elementCount;
@end

@implementation GPTupleBase

+ (__kindof GPTupleBase *) tupleWithCount:(NSUInteger)count
{
#define TUPLE_CLASS(_COUNT_)    "GPTuple" GP_STRINGIFY(_COUNT_)
#define CLASS_TABLE              GP_FOR_COMMA(21, TUPLE_CLASS)
    static const char *classNames[] = {
        CLASS_TABLE // 构建20大小的数组
    };
#undef CLASS_TABLE
#undef TUPLE_CLASS
    
    NSAssert(count <= 20 && count > 0
             , @"tupleWithCount 输入参数 count 超出范围 ， 建议 count > 0 && count <= 20");
    
    GPTupleBase *tuple = nil;
    if (count <= 20 && count > 0) {
        const char *className = classNames[count];
        Class tupleClass = objc_getClass(className);
        tuple = [tupleClass new];
        tuple.elementCount = count;
    } else {
        @throw [[NSException alloc] initWithName:@"GPTupleBase 初始化错误"
                                          reason:@"tupleWithCount 输入参数 count 超出范围 ， 建议 count > 0 && count <= 20"
                                        userInfo:nil];
    }
    
    return tuple;
}

+ (instancetype) tupleWithArray:(NSArray *)array
{
    GPTupleBase *tuple = [self tupleWithCount:array.count];
    for (int i = 0; i < array.count; ++i) {
        tuple[i] = [array[i] isEqual:NSNull.null] ? nil : array[i];
    }
    
    return tuple;
}

- (NSUInteger) hash
{
    NSUInteger hashValue = 0;
    for (int i = 0; i < _elementCount; ++i) {
        hashValue &= [self[i] hash];
    }
    
    return hashValue;
}

- (NSUInteger) count
{
    return _elementCount;
}

- (id) objectAtIndexedSubscript:(NSUInteger)index
{
    NSParameterAssert(index < _elementCount);
    if (index < _elementCount) {
        return getterTable[index](self);
    } else {
        return nil;
    }
}

- (void) setObject:(id)obj atIndexedSubscript:(NSUInteger)index
{
    NSParameterAssert(index < _elementCount);
    if (index < _elementCount) {
        setterTable[index](self, obj);
    }
}

- (BOOL) isEqual:(GPTupleBase *)other
{
    if (self == other)
    {
        return YES;
    }
    
    if (![other isKindOfClass:GPTupleBase.class])
    {
        return NO;
    }
    
    if (_elementCount != other.count)
    {
        return NO;
    }
    
    for (int i = 0; i < _elementCount; ++i) {
        if (self[i] == other[i] || [self[i] isEqual:other[i]]) {
            continue;
        }
        
        return NO;
    }
    
    return YES;
}

- (__kindof GPTupleBase *) join:(GPTupleBase *)other
{
    NSUInteger selfCount = _elementCount;
    NSUInteger otherTupleCount = other.count;
    
    NSAssert(selfCount + otherTupleCount <= 20, @"two tuple items count added cannot larger than 20");
    if (selfCount + otherTupleCount > 20) {
        return nil;
    }
    
    GPTupleBase *newInstance = [GPTupleBase tupleWithCount:selfCount + otherTupleCount];
    for (int i = 0; i < selfCount; ++i) {
        newInstance[i] = self[i];
    }
    
    for (int i = 0; i < otherTupleCount; ++i) {
        newInstance[selfCount + i] = other[i];
    }
    
    return newInstance;
}

- (__kindof GPTupleBase *) take:(NSUInteger)count
{
    NSParameterAssert(count >= 1);
    if (count < 1) {
        return nil;
    }
    
    if (count >= _elementCount)
    {
        return [self copy];
    }
    
    GPTupleBase *newInstance = [GPTupleBase tupleWithCount:count];
    for (int i = 0; i < count; ++i) {
        newInstance[i] = self[i];
    }
    
    return newInstance;
}

- (__kindof GPTupleBase *) drop:(NSUInteger)count
{
    NSUInteger selfCount = _elementCount;
    NSParameterAssert(count < selfCount);
    if (count >= selfCount) {
        return nil;
    }
    
    if (count == 0) {
        return [self copy];
    }
    
    GPTupleBase *newInstance = [GPTupleBase tupleWithCount:selfCount - count];
    for (int i = 0; i + count < selfCount; ++i) {
        newInstance[i] = self[i + count];
    }
    
    return newInstance;;
}

- (NSArray *) allObjects
{
    NSMutableArray *array = [NSMutableArray array];
    for (NSObject *item in self) {
        [array addObject:item ?: NSNull.null];
    }
    return [array copy];
}

#pragma mark - NSFastEnumeration

- (NSUInteger) countByEnumeratingWithState:(nonnull NSFastEnumerationState *)state
                                  objects:(id  _Nullable __unsafe_unretained * _Nonnull)buffer
                                    count:(NSUInteger)len
{
    NSUInteger count = _elementCount;
    if (state->state == count) {
        return 0;
    }
    
    Ivar ivar = class_getInstanceVariable(self.class, "_first");
    
    state->itemsPtr = (id  _Nullable __unsafe_unretained * _Nonnull)((__bridge void *)self + ivar_getOffset(ivar));
    state->mutationsPtr = (typeof(state->mutationsPtr))&self->_hashValue;
    
    state->state = count;
    return count;
}

#pragma mark - NSCopying

- (nonnull id) copyWithZone:(nullable NSZone *)zone
{
    GPTupleBase *copied = [[self class] new];
    for (int i = 0; i < _elementCount; ++i) {
        copied[i] = self[i];
    }
    
    return copied;
}

@end
