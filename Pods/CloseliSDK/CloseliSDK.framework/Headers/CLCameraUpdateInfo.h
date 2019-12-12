//
//  CLCameraUpdateInfo.h

typedef NS_ENUM(NSInteger, CLUpdateType) {
    CLUpdateTypeNone = 0,
    CLUpdateTypeNeed,
    CLUpdateTypeForce
};

typedef NS_ENUM(NSUInteger, CLServiceType) {
    CLServiceTypeFirmware = 1,
    CLServiceTypeApp,
    CLServiceTypeAndlink,
    CLServiceTypeConfig
};

/*!
 *
 * @brief 展示设备更新有关的信息.
 * 负责管理一些摄像头当前版本，防火墙当前版本，以及最新的摄像头版本，最新的防火墙版本，摄像头更新类型，更新地址URL等
 * 因此, 可以根据 CLCameraUpdateInfo 这些信息选择是否更新摄像头版本.
 *
 */
@interface CLCameraUpdateInfo : NSObject

/*! @cond PRIVATE */

///data which used for detecting error. not used.
@property (nonatomic, copy) NSString *checksum;
///camera current application version.
@property (nonatomic, copy) NSString *currentAppVersion;
///camera current firmware version.
@property (nonatomic, copy) NSString *currentFirmwareVersion;
///camera current andlink version.
@property (nonatomic, copy) NSString *currentAndlinkVersion;
///camera current config version.
@property (nonatomic, copy) NSString *currentConfigVersion;
///whether camera need to update.
@property (nonatomic, assign) CLUpdateType updateType;
///the update url.
@property (nonatomic, copy) NSString *updateURL;
///app update url or firmware update url.
@property (nonatomic, assign) CLServiceType serviceType;
///new service version
@property (nonatomic, copy) NSString *latestServiceVersion;
///current service version.
@property (nonatomic, strong) NSDictionary *currentServiceVersion;
///device desc.
@property (nonatomic, copy) NSString *deviceDesc;
///device id.
@property (nonatomic, copy) NSString *deviceId;

/*! @endcond */

@end
