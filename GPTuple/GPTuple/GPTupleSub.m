//
//  GPTupleSub.m
//  GPTuple
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import "GPTupleSub.h"
#include <objc/runtime.h>

static NSString *propertyNameForIndex(GPTupleBase *tuple, NSUInteger index)
{
    Class tupleClass = tuple.class;
    unsigned int outCount = 0;
    objc_property_t *properties = class_copyPropertyList(tupleClass, &outCount);
    const char *propertyCName = NULL;
    if (index < outCount) {
        objc_property_t property = properties[index];
        propertyCName = property_getName(property);
    }
    free(properties);
    NSString *propertyName = [NSString stringWithCString:propertyCName encoding:NSASCIIStringEncoding];
    return propertyName;
}

#define _GPT_INIT_PARAM_IMP_FIRST(index)                GP_ORDINAL_CAP_AT(index):(id)GP_ORDINAL_AT(index)
#define _GPT_INIT_PARAM_IMP(index)                      GP_ORDINAL_AT(index):(id)GP_ORDINAL_AT(index)
#define GPT_INIT_PARAM_IMP(index)                       GP_IF_EQ(0, index)(_GPT_INIT_PARAM_IMP_FIRST(index))(_GPT_INIT_PARAM_IMP(index))

#define GPT_SYNTHESIZE(index)                                                   \
@synthesize GP_ORDINAL_AT(index) = GP_CONCAT(_, GP_ORDINAL_AT(index))

#define GPT_INIT_SET_PARAM(index)                                               \
GP_CONCAT(_, GP_ORDINAL_AT(index)) = GP_ORDINAL_AT(index);                      \
self.hashValue ^= (NSUInteger)GP_ORDINAL_AT(index)

#define GPT_SETTER(index)                                                       \
GPT_PrivateSetterDef(index)                                                     \
{                                                                               \
    NSString *propertyName = propertyNameForIndex(self, index);                 \
    if (![propertyName isEqual:@GP_STRINGIFY(GP_ORDINAL_AT(index))]) {          \
    [self willChangeValueForKey:propertyName];                                  \
    }                                                                           \
                                                                                \
    if (![@GP_STRINGIFY(GP_ORDINAL_AT(index)) isEqual:key]) {                   \
    [self willChangeValueForKey:@GP_STRINGIFY(GP_ORDINAL_AT(index))];           \
    }                                                                           \
                                                                                \
    self.hashValue ^= (NSUInteger)GP_CONCAT(_, GP_ORDINAL_AT(index));           \
    GP_CONCAT(_, GP_ORDINAL_AT(index)) = value;                                 \
    self.hashValue ^= (NSUInteger)value;                                        \
                                                                                \
    if (![@GP_STRINGIFY(GP_ORDINAL_AT(index)) isEqual:key]) {                   \
    [self didChangeValueForKey:@GP_STRINGIFY(GP_ORDINAL_AT(index))];            \
    }                                                                           \
                                                                                \
    if (![propertyName isEqual:@GP_STRINGIFY(GP_ORDINAL_AT(index))]) {          \
    [self didChangeValueForKey:propertyName];                                   \
    }                                                                           \
}                                                                               \
                                                                                \
- (void)GP_CONCAT(set, GP_ORDINAL_CAP_AT(index)):(id)value {                    \
    [self GP_CONCAT(_set, GP_ORDINAL_CAP_AT(index)):value                       \
    excludeNotifiyKey:@GP_STRINGIFY(GP_ORDINAL_AT(index))];                     \
}

#define GPT_APPEND_DESCRIPTION(index)                                           \
[description appendString:@"\t" GP_STRINGIFY(GP_ORDINAL_AT(index)) " = "];      \
[description appendString:[self. GP_ORDINAL_AT(index) description] ?: @"nil"];  \
[description appendString:@";\n"];

#define GP_TUPLE_IMP(i)                                                         \
@implementation GP_CONCAT(GPTuple, i)                                           \
GP_FOR_RECURSIVE(i, GPT_SYNTHESIZE, ;);                                         \
                                                                                \
- (instancetype)GP_CONCAT(initWith, GP_FOR_SPACE(i, GPT_INIT_PARAM_IMP)) {      \
    if (self = [super init]) {                                                  \
    GP_FOR_RECURSIVE(i, GPT_INIT_SET_PARAM, ;);                                 \
    }                                                                           \
    return self;                                                                \
}                                                                               \
                                                                                \
- (NSUInteger)count {                                                           \
return i;                                                                       \
}                                                                               \
                                                                                \
GP_FOR_RECURSIVE(GP_DEC(i), GPT_SETTER, ;)                                      \
                                                                                \
GPT_PrivateSetterDef(GP_DEC(i)) {                                               \
    NSString *propertyName = propertyNameForIndex(self, GP_DEC(i));             \
    if (![propertyName isEqual:@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i)))]) {      \
    [self willChangeValueForKey:propertyName];                                  \
}                                                                               \
                                                                                \
if (![@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i))) isEqual:key]) {                   \
[self willChangeValueForKey:@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i)))];           \
}                                                                               \
                                                                                \
if (![@"last" isEqual:key]) {                                                   \
[self willChangeValueForKey:@"last"];                                           \
}                                                                               \
self.hashValue ^= (NSUInteger)GP_CONCAT(_, GP_ORDINAL_AT(GP_DEC(i)));           \
GP_CONCAT(_, GP_ORDINAL_AT(GP_DEC(i))) = value;                                 \
self.hashValue ^= (NSUInteger)value;                                            \
if (![@"last" isEqual:key]) {                                                   \
[self didChangeValueForKey:@"last"];                                            \
}                                                                               \
                                                                                \
if (![@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i))) isEqual:key]) {                   \
[self didChangeValueForKey:@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i)))];            \
}                                                                               \
                                                                                \
if (![propertyName isEqual:@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i)))]) {          \
[self didChangeValueForKey:propertyName];                                       \
}                                                                               \
}                                                                               \
                                                                                \
- (void)GP_CONCAT(set, GP_ORDINAL_CAP_AT(GP_DEC(i))):(id)value {                \
[self GP_CONCAT(_set, GP_ORDINAL_CAP_AT(GP_DEC(i))):value                       \
excludeNotifiyKey:@GP_STRINGIFY(GP_ORDINAL_AT(GP_DEC(i)))];                     \
}                                                                               \
                                                                                \
- (id)last {                                                                    \
return self. GP_ORDINAL_AT(GP_DEC(i));                                          \
}                                                                               \
                                                                                \
- (void)setLast:(id)last {                                                      \
[self GP_CONCAT(_set, GP_ORDINAL_CAP_AT(GP_DEC(i))):last                        \
    excludeNotifiyKey:@"last"];                                                 \
}                                                                               \
                                                                                \
- (NSString *)description {                                                     \
NSMutableString *description =                                                  \
[NSMutableString stringWithFormat:@"<%@: %p>(\n", self.class, self];            \
GP_FOR_RECURSIVE(i, GPT_APPEND_DESCRIPTION, ;)                                  \
[description appendString:@"\tlast = "];                                        \
[description appendString:[self. GP_ORDINAL_AT(GP_DEC(i)) description]          \
?: @"nil"];                                                                     \
[description appendString:@";\n)"];                                             \
return description;                                                             \
}                                                                               \
                                                                                \
@end

////////////////////////////////////////////////////////////////////////////////////////////////

#define GP_TUPLE_IMP_FOREACH(index)           GP_TUPLE_IMP(GP_INC(index))
GP_FOR(20, GP_TUPLE_IMP_FOREACH, ;)
