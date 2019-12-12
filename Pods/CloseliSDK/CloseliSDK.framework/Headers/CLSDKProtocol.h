//
//  CLSDKProtocol.h

#ifndef CLSDKProtocol_h
#define CLSDKProtocol_h

#import "CLCommonProtocol.h"
#import "CLSDKHeader.h"
#import "CLXHttpClientProtocol.h"
#import "CLXPlusProtocol.h"

@protocol CLSDKProtocol <
CLCommonProtocol,
CLXAccountProtocol,
CLXCommonServiceProtocol,
CLXFaceRecognitionProtocol,
CLXFaceDetectionProtocol,
CLXDeviceProtocol,
CLXSMBProtocol,
CLXIndustryProtocol,
CLXNotificationProtocol,
CLXOperationHelperProtocol,
CLXPurchaseProtocol,
CLXDeviceSettingProtocol,
CLXPlusProtocol>
@end

#endif /* CLSDKProtocol_h */
