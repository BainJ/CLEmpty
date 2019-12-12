//
//  CloudUserInfo.h

#import <Foundation/Foundation.h>
#import "CLXSMBLoginInfo.h"
@interface CLCloudUserInfo : NSObject

@property long long  ulUserID;
@property (nonatomic, copy) NSString * szToken;
@property (nonatomic, copy) NSString * szShortToken;
@property (nonatomic, copy) NSString * szHemuToken;
@property (nonatomic, copy) NSString * szEmail;
@property (nonatomic, copy) NSString * szUserName;
@property (nonatomic, copy) NSString * szDeviceID;
@property (nonatomic, copy) NSString * szProductID;
@property (nonatomic, copy) NSString * szUnifiedID;
@property (nonatomic, copy) NSString * szPassword;
@property (nonatomic, copy) NSString * szMobile;
@property (nonatomic, copy) NSString * szVIPNum;
@property (nonatomic, assign) NSInteger nSubscribe;
@property NSInteger eUserStatus;
+ (CLCloudUserInfo *)transferUserFromNewModel:(CLXSMBVirtualUser *)account;

@end
