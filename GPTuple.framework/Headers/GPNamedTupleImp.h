//
//  GPNamedTupleImp.h
//  GPTuple
//
//  Created by Liyanwei on 2018/8/15.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import "GPMacrosDef.h"

#define GPT_Once(...)                                   X,
#define GPT_NamedPropertyType(...)                      GP_INIT(__VA_ARGS__)
#define GPT_NamedPropertyTypeWithComma(...)             GPT_NamedPropertyType(__VA_ARGS__),
#define GPT_NamedPropertyName(...)                      GP_LAST(__VA_ARGS__)
#define GPT_NamedPropertyNameWithComma(...)             GPT_NamedPropertyName(__VA_ARGS__),
#define GPT_NamedPropertyTypeAndName(...)               GPT_NamedPropertyType(__VA_ARGS__) GPT_NamedPropertyName(__VA_ARGS__)
#define GPT_NamedPropertyTypeAndNameWithComma(...)      GPT_NamedPropertyTypeAndName(__VA_ARGS__),
#define GPT_TableToList(_Table_, _Function_)            GP_INIT(_Table_(_Function_) X)
#define GPT_TableLength(_Table_)                        GP_ARG_COUNT(GPT_TableToList(_Table_, GPT_Once))
#define GPT_NamedPropertyTypeList(_Table_)              GPT_TableToList(_Table_, GPT_NamedPropertyTypeWithComma)
#define GPT_NamedPropertyNameList(_Table_)              GPT_TableToList(_Table_, GPT_NamedPropertyNameWithComma)
#define GPT_TableInvoke(_Table_, _Function_)            _Table_(_Function_)

#define GPT_TableName(_ClassName_)                      GP_CONCAT(_ClassName_, Table)
#define GPT_GenericList(...)                            GP_IF_EQ(0, GP_ARG_COUNT(__VA_ARGS__))()(<__VA_ARGS__>)
#define GPT_NamedPropertyFunctionParam(...)             id GPT_NamedPropertyName(__VA_ARGS__),
#define GPT_NamedPropertyParamsList(_Table_)            GPT_TableToList(_Table_, GPT_NamedPropertyFunctionParam)

#define GPT_NamedPropertyDefine(...) \
@property (nonatomic, strong, setter=GP_CONCAT(set_, GPT_NamedPropertyName(__VA_ARGS__)):) \
    GPT_NamedPropertyTypeAndName(__VA_ARGS__);

#define _GPTNamedTupleDef(_ClassName_, ...) \
__attribute__((objc_subclassing_restricted)) \
@interface _ClassName_ GPT_GenericList(__VA_ARGS__) : GP_CONCAT(GPTuple, GPT_TableLength(GPT_TableName(_ClassName_))) \
    <GPT_NamedPropertyTypeList(GPT_TableName(_ClassName_))>  \
GPT_TableName(_ClassName_)(GPT_NamedPropertyDefine) \
@end \
\
FOUNDATION_EXPORT _ClassName_ * GP_CONCAT(_ClassName_, Make)(GPT_NamedPropertyParamsList(GPT_TableName(_ClassName_)));

#define GPT_GetterAndSetter(_index_, _propertyName_) \
- (id)_propertyName_ { \
    return [self GP_ORDINAL_AT(_index_)]; \
} \
\
- (void)GP_CONCAT(set_, _propertyName_):(id)value { \
    [self GP_CONCAT(_set, GP_ORDINAL_CAP_AT(_index_)):value excludeNotifiyKey:@GP_STRINGIFY(_propertyName_)]; \
}

#define GPT_descriptionProperty(_, _propertyName_) \
[description appendString:@"\t" GP_STRINGIFY(_propertyName_) @" = "]; \
[description appendString:[(id)self. _propertyName_ description] ?: @"nil"]; \
[description appendString:@";\n"]; \

#define _GPTNamedTupleImp(_ClassName_) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wmismatched-return-types\"") \
_Pragma("clang diagnostic ignored \"-Wmismatched-parameter-types\"") \
@implementation _ClassName_ \
GP_FOR_EACH(GPT_GetterAndSetter, ;, GPT_NamedPropertyNameList(GPT_TableName(_ClassName_))) \
\
- (NSString *)description { \
    NSMutableString *description = [NSMutableString stringWithFormat:@"<%@: %p>(\n", self.class, self]; \
    GP_FOR_EACH(GPT_descriptionProperty, ;, GPT_NamedPropertyNameList(GPT_TableName(_ClassName_))) \
    [description appendString:@")"]; \
    return description; \
} \
@end \
_ClassName_ * GP_CONCAT(_ClassName_, Make)(GPT_NamedPropertyParamsList(GPT_TableName(_ClassName_))) { \
    return GPTupleAs(_ClassName_, GPT_NamedPropertyNameList(GPT_TableName(_ClassName_))); \
} \
_Pragma("clang diagnostic pop")
