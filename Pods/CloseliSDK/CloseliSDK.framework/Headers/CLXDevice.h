//
//  CLXDevice.h

#import <Foundation/Foundation.h>

@protocol CLXDevice <NSObject>

@property (nonatomic, copy) NSString *limit;
@property (nonatomic, copy) NSString *expireRecordingWhiteList;
@property (nonatomic, copy) NSString *technicalState;
@property (nonatomic, copy) NSString *supportValues;
@property (nonatomic, copy) NSString *channelNo;
@property (nonatomic, copy) NSString *createtime;
@property (nonatomic, copy) NSString *deviceAddSource;
@property (nonatomic, copy) NSString *serviceStatus;
@property (nonatomic, copy) NSString *serviceStatusNew;
@property (nonatomic, copy) NSString *devicetitle;
@property (nonatomic, copy) NSString *auditStatus;
@property (nonatomic, copy) NSString *shareStatus;
@property (nonatomic, copy) NSString *videoQuality;
@property (nonatomic, copy) NSString *thumbnailFileIdList;
@property (nonatomic, copy) NSString *serialNumber;
@property (nonatomic, strong) NSDictionary *settingValues;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *paymenttype;
@property (nonatomic, copy) NSString *standbyIDVRDays;
@property (nonatomic, copy) NSString *HDVideo;
@property (nonatomic, copy) NSString *creditCard;
@property (nonatomic, copy) NSString *iDVRDays;
@property (nonatomic, copy) NSString *deviceSource;
@property (nonatomic, copy) NSString *standbyServiceid;
@property (nonatomic, copy) NSString *endtime;
@property (nonatomic, copy) NSString *modelId;
@property (nonatomic, copy) NSString *rateURL;
@property (nonatomic, copy) NSString *standbyEndtime;
@property (nonatomic, copy) NSString *serviceid;
@property (nonatomic, copy) NSString *purchaseMethod;
@property (nonatomic, copy) NSString *devicePrice;
@property (nonatomic, copy) NSString *comment;
@property (nonatomic, copy) NSArray  *iplist;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *servicename;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, copy) NSString *updateCreditCardTime;
@property (nonatomic, copy) NSString *autopayment;
@property (nonatomic, copy) NSString *shareToOtherCount;
@property (nonatomic, copy) NSString *billingamount;
@property (nonatomic, copy) NSString *siteid;
@property (nonatomic, copy) NSString *orderStatus;
@property (nonatomic, copy) NSString *deviceTag;
@property (nonatomic, strong) NSDictionary *whiteListConfig;
@property (nonatomic, copy) NSString *shareMobile;
@property (nonatomic, copy) NSString *standbyRenewPrice;
@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, copy) NSString *currentprice;
@property (nonatomic, copy) NSString *purchaseStatus;
@property (nonatomic, copy) NSString *shareid;
@property (nonatomic, copy) NSString *devicename;
@property (nonatomic, copy) NSString *downloadserver;
@property (nonatomic, copy) NSString *standbyStarttime;
@property (nonatomic, copy) NSString *rateStatus;
@property (nonatomic, copy) NSString *starttime;
@property (nonatomic, copy) NSString *sysdate;
@property (nonatomic, copy) NSArray  *thumbnailUrlList;
@property (nonatomic, copy) NSString *standby;
@property (nonatomic, copy) NSString *remainingDaysToBeExpire;
@property (nonatomic, copy) NSString *expireAllowPlayback;
@property (nonatomic, copy) NSString *deviceStatus;
@property (nonatomic, copy) NSString *msgProtoType;
@property (nonatomic, assign) NSInteger privView;
@property (nonatomic, assign) NSInteger privPTZ;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *deviceid;
@property (nonatomic, copy) NSString *realmac;
@property (nonatomic, copy) NSString *onlineStatus; // available :在线，unavailable:不在线
@property (nonatomic, copy) NSString *aliveStatus;  // available :休眠，unavailable:非休眠
@property (nonatomic, strong) NSDictionary *deviceAbilities; // battery 表示电池电量，百分比，只显示数字；batteryStatus 取值0 表示取不到电池信息；battery: 1 表示低电量；2 表示正在充电；3 表示电池充满了；4 表示其它正常状态；

@end

@interface CLXDevice : NSObject<CLXDevice>

@end
