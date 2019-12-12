//
//  CLXHttpClientDefine.h

#ifndef CLXHttpClientDefine_h
#define CLXHttpClientDefine_h

/**
 @remark 统一API返回Handle

 @param isSucceeded API Result是否成功, Http fail以及server fail都是false，只有成功结果返回为true
 @param response 如果成功则为返回数据，失败为nil
 @param error 如果失败则为失败错误码，成功为nil
 */
typedef void (^_Nonnull CLXHttpTaskCompletionHandler)(BOOL isSucceeded, id _Nullable response, NSError *_Nullable error);


#endif /* CLXHttpClientDefine_h */
