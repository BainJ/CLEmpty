//
//  CLShareUserInfo.h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CLXSharePrivView) {//表示回放直播权限
    CLXSharePrivViewLive = 1,            //表示直播
    CLXSharePrivViewPlayBack = 2,        //表示回放
    CLXSharePrivViewLiveAndPlayBack = 3  //表示直播回放都有
};

/**
 @brief 分享设备相关数据
 */
@interface CLShareUserInfo : NSObject

@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *shareId;
@property (nonatomic, copy) NSString *userEmail;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *nikName;
@property (nonatomic, copy) NSString *telephone;
@property (nonatomic, assign) CLXSharePrivView privView;

@end
