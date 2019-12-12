//
//  CLXFaceRecognitionProtocol.h

#ifndef CLXFaceRecognitionProtocol_h
#define CLXFaceRecognitionProtocol_h

#import "CLXHttpClientDefine.h"
#import <UIKit/UIKit.h>

/**
 @brief 人脸注册相关API，例如人脸列表、更新人脸、删除人脸
 */
@protocol CLXFaceRecognitionProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configFaceRecognitionToken:(nullable NSString *)token;

/**
 查询人脸列表及对应开关状态
 
 @param deviceId 设备唯一标识符，可为空
 @param personId 人脸唯一标识，可为空
 @param completion Completion Handler
 */
- (void)getFaceInfoList:(nullable NSString *)deviceId
               personId:(nullable NSString *)personId
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 更新人脸信息
 1）当deviceid不为空，如果diabledrecording或status有值，则只会修改此人脸下deviceid对应设备的录制和推送标识。
 2）当deviceid为空时，如果diabledrecording或status有值，则会修改此人脸下所有设备的录制和推送标识。
 3）facename不受deviceid影响。
 
 @param deviceId 设备ID，为nil则不区分设备
 @param personId 人脸唯一标识
 @param faceName 人脸名称
 @param disabledRecording 是否停止录制标识，0 or 1
 @param status 是否推送消息标识，0 or 1
 @param completion Completion Handler
 */
- (void)updateFaceInfo:(nullable NSString *)deviceId
              personId:(nonnull NSString *)personId
              faceName:(nullable NSString *)faceName
     disabledRecording:(nullable NSString *)disabledRecording
                status:(nullable NSString *)status
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 删除人脸信息
 
 @param personId 人脸唯一标识，传nil则删除所有
 @param completion Completion Handler
 */
- (void)unregisterFaceInfo:(nullable NSString *)personId completion:(CLXHttpTaskCompletionHandler)completion;

/**
 查询单个人脸信息及人脸在所有Camera下的开关信息
 
 @param personId 人脸唯一标识
 @param completion Completion Handler
 */
- (void)getFacePropertyListWithPersonId:(nonnull NSString *)personId completion:(CLXHttpTaskCompletionHandler)completion;

/**
 更新人脸图片
 
 @param personId 人脸唯一标识
 @param picture Picture
 @param completion Completion Handler
 */
- (void)updateFacePic:(nonnull NSString *)personId picture:(nonnull UIImage *)picture completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取用户Photo Dairy配置信息
 
 @param completion Completion Handler
 */
- (void)getAlbumSettingCompletion:(CLXHttpTaskCompletionHandler)completion;

/**
 更新用户Photo Dairy配置信息
 
 @param notifyswitch 是否通知开关，1:开， 0：关
 @param timestamp UTC时间戳
 @param completion Completion Handler
 */
- (void)updateAlbumSettingWithNotifyswitch:(nonnull NSString *)notifyswitch timestamp:(nonnull NSString *)timestamp completion:(CLXHttpTaskCompletionHandler)completion;

@end

#endif /* CLXFaceRecognitionProtocol_h */
