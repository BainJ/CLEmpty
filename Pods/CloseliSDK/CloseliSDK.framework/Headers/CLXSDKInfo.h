//
//  CLXSDKInfo.h

#import <Foundation/Foundation.h>

/**
 @brief SDK需要的用户信息、平台信息
 */
@protocol CLXSDKInfo <NSObject>

// 平台相关
@property (nonatomic, readwrite, copy) NSString *productKey;
@property (nonatomic, readwrite, copy) NSString *productSecret;

// 用户相关
@property (nonatomic, readwrite, copy) NSString *token;
@property (nonatomic, readwrite, copy) NSString *shortToken;
@property (nonatomic, readwrite, copy) NSString *thirdToken;
@property (nonatomic, readwrite, copy) NSString *unifiedID;
@property (nonatomic, readwrite, copy) NSString *account;
@property (nonatomic, readwrite, copy) NSString *password;
@property (nonatomic, readwrite, copy) NSString *userMobile;
@property (nonatomic, readwrite, copy) NSString *userEmail;
@property (nonatomic, readwrite, assign) NSInteger userId;

@property (nonatomic, readonly, assign) BOOL isLogin;

@end

@class CLCloudUserInfo;
/**
 @breif SDK用户以及平台信息管理类
 */
@interface CLXSDKInfo : NSObject <CLXSDKInfo>

+ (instancetype)sharedInstance;

- (void)setUserInfo:(CLCloudUserInfo *)userInfo;
- (void)clearUserInfo;

@end
