#import <Foundation/Foundation.h>

@interface CLXSMBVirtualUser : NSObject

@property (nonatomic, assign) long long createTime;
@property (nonatomic, copy) NSString *ID;
@property (nonatomic, assign) long long modifyTime;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *remark;
@property (nonatomic, copy) NSString *storeId;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *shortToken;

@end

@interface CLXSMBUserPriv : NSObject

@property (nonatomic, copy) NSString *code;
@property (nonatomic, assign) long long createTime;
@property (nonatomic, assign) long long modifyTime;
@property (nonatomic, copy) NSString *creator;
@property (nonatomic, copy) NSString *ID;
@property (nonatomic, copy) NSString *modifier;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *remark;

@end

@interface CLXSMBStoreInfo : NSObject

@property (nonatomic, strong) NSArray<CLXSMBStoreInfo *> *child;
@property (nonatomic, copy) NSString *storeId;
@property (nonatomic, copy) NSString *storeName;
@property (nonatomic, copy) NSString *remark;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *userToken;
@property (nonatomic, copy) NSString *shortToken;
@property (nonatomic, copy) NSString *storeType;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, copy) NSString *storeOrder;
@property (nonatomic, copy) NSString *latitude;
@property (nonatomic, copy) NSString *longitude;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, assign) BOOL hasChild;
@property (nonatomic, copy) NSString *isSectionItem;
@property (nonatomic, copy) NSString *level;

@end

@interface CLXSMBStoreVirUsr : NSObject

@property (nonatomic, strong) CLXSMBStoreInfo *storeTree;
@property (nonatomic, strong) CLXSMBVirtualUser *virtualUser;

@end

@protocol CLXSMBLoginInfo <NSObject>

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *workCode;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *tel;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, assign) long long status;
@property (nonatomic, copy) NSString *remark;
@property (nonatomic, assign) long long createTime;
@property (nonatomic, assign) long long modifyTime;
@property (nonatomic, strong) NSArray *storeIdList;
@property (nonatomic, copy) NSString *roleId;
@property (nonatomic, copy) NSString *roleName;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *ownDept;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, assign) BOOL mobile;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *productKey;
@property (nonatomic, copy) NSString *secert;
@property (nonatomic, copy) NSString *qrcode;
@property (nonatomic, strong) NSArray<CLXSMBUserPriv *> *privList;
@property (nonatomic, strong) NSArray<CLXSMBStoreVirUsr *> *storeVirUsrList;

@end

@interface CLXSMBLoginInfo : NSObject <CLXSMBLoginInfo>
@end

