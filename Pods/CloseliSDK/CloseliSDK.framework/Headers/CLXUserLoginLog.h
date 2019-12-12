//
//  CLXUserLoginLog.h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CLXUserLoginLog <NSObject>

@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *imei;
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, copy) NSString *loginTime;
@property (nonatomic, copy) NSString *createTime;
@property (nonatomic, copy) NSString *telName;
@property (nonatomic, copy) NSString *tt;
@property (nonatomic, copy) NSString *type;
@end


@interface CLXUserLoginLog : NSObject<CLXUserLoginLog>
@end

@protocol CLXDeviceLoginLog <NSObject>
@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *imei;
@property (nonatomic, copy) NSString *registerTime;
@property (nonatomic, copy) NSString *registerIp;
@property (nonatomic, copy) NSString *lastIp;
@property (nonatomic, copy) NSString *lastLoginTime;
@property (nonatomic, copy) NSString *createTime;
@property (nonatomic, copy) NSString *telName;
@property (nonatomic, copy) NSString *tt;
@end


@interface CLXDeviceLoginLog : NSObject<CLXDeviceLoginLog>

@end


NS_ASSUME_NONNULL_END
