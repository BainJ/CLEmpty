//
//  CLXAccountInfo.h

#import <Foundation/Foundation.h>
#import "CLCloudUserInfo.h"

@protocol CLXAccountInfo <NSObject>

@property (nonatomic, assign) NSInteger uid;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, assign) NSInteger status;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, copy) NSString *space;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, assign) NSInteger subscribe;
@property (nonatomic, copy) NSString *subscribeCode;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *mobile;
@property (nonatomic, copy) NSString *vipNum;
@property (nonatomic, copy) NSString *hemuToken;
@property (nonatomic, copy) NSString *shortToken;
@property (nonatomic, assign) NSInteger passId;

@end

@interface CLXAccountInfo : NSObject <CLXAccountInfo>
// 临时新老model转换
+ (CLCloudUserInfo *)transferUserFromNewModel:(CLXAccountInfo *)account;
+ (CLXAccountInfo *)transferUserFromOldModel:(CLCloudUserInfo *)account;

@end
