//
//  CLXNotificationProtocol.h

#ifndef CLXNotificationProtocol_h
#define CLXNotificationProtocol_h

#import "CLXHttpClientDefine.h"
/**
 @brief 通知相关API，包括注册UPNS、订阅通知、微信告警等
 */
@protocol CLXNotificationProtocol <NSObject>

/**
 设置此模块的Token.
 如果设置则使用提供token，否则使用全局默认token.
 恢复使用全局默认token，set token=nil.
 
 @param token Token---用户token or 分享token
 */
- (void)configNotificationToken:(nullable NSString *)token;

/**
 注册消息通知

 @param deviceToken UPNS token
 @param bundleId app bundle ID
 @param voipToken 当有pushkit推送时需要传此token, 此功能需要开通才支持
 @param completion Completion Handle
 */
- (void)registerNotice:(nonnull NSString *)deviceToken
              bundleId:(nonnull NSString *)bundleId
             voipToken:(nullable NSString *)voipToken
            completion:(CLXHttpTaskCompletionHandler)completion;

/**
 订阅/反订阅全部通知

 @param subscribeType 0 represent normal, 1 represent subscribeAll, 2 represent unsubscribeAll
 @param bundleId app bundle ID
 @param completion Completion Handle
 */
- (void)subscribeAll:(nonnull NSString *)subscribeType
            bundleId:(nonnull NSString *)bundleId
        deviceUnique:(nonnull NSString *)deviceUnique
          completion:(CLXHttpTaskCompletionHandler)completion;

/**
 获取通知列表

 @param osType 传入os的类型 筛选对应的订阅关系,不传默认全部,weixin传23
 @param deviceUnique 设备mac地址
 @param completion Completion Handle
 */
- (void)getPushNoticeList:(nullable NSString *)osType
             deviceUnique:(nonnull NSString *)deviceUnique
               completion:(CLXHttpTaskCompletionHandler)completion;


/**
 开关微信报警

 @param deviceUnique 设备mac地址
 @param switchType 0: 关闭开关 1:打开开关
 @param osType 需要关闭推送的接受设备os类型（1-ios,10-xinge,23-weixin）.不传全开全关
 @param completion Completion Handle
 */
- (void)setSwitchAlarmStatus:(nonnull NSString *)deviceUnique
                  switchType:(nonnull NSString *)switchType
                      osType:(nullable NSString *)osType
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 统计错过信息数
 
 @param deviceUnique 设备mac地址
 @param completion Completion Handler
 */
- (void)getMessageCount:(nonnull NSString *)deviceUnique
             completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 添加设备的邮件提醒

 @param deviceUnique 设备mac，类似xxxxS_2059a074de17
 @param sendEmails 收提醒邮件，类似hxq0506@163.com;hxq8176@arcsoft.com.cn
 @param completion Completion Handler
 */
- (void)addNotificationEmail:(nonnull NSString *)deviceUnique
                  sendEmails:(nonnull NSString *)sendEmails
                  completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 删除设备的邮件提醒

 @param deviceUnique 设备mac，类似xxxxS_2059a074de17
 @param sendEmails 收提醒邮件，类似hxq0506@163.com;hxq8176@arcsoft.com.cn
 @param completion Completion Handler
 */
- (void)removeNotificationEmail:(nonnull NSString *)deviceUnique
                     sendEmails:(nonnull NSString *)sendEmails
                     completion:(CLXHttpTaskCompletionHandler)completion;


/**
 @remark 设置报警声音
 
 @param bundleId app bundle ID
 @param deviceUnique 设备mac，类似xxxxS_2059a074de17
 @param soundName 声音文件名称
 @param completion Completion Handler
 */
- (void)setAlarmSoundWithBundleId:(nullable NSString *)bundleId
                     deviceUnique:(nullable NSString *)deviceUnique
                        soundName:(nullable NSString *)soundName
                       completion:(CLXHttpTaskCompletionHandler)completion;

/**
 @remark 获取报警声音
 
 @param bundleId app bundle ID
 @param deviceUnique 设备mac，类似xxxxS_2059a074de17
 @param completion Completion Handler
 */
- (void)getAlarmSoundWithBundleId:(nullable NSString *)bundleId
                     deviceUnique:(nullable NSString *)deviceUnique
                       completion:(CLXHttpTaskCompletionHandler)completion ;



@end

#endif /* CLXNotificationProtocol_h */
