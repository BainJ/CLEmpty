//
//  CLWifiBrowsManager.h

#import <Foundation/Foundation.h>
#import "CLXDeviceWifiInfo.h"

/**
 @brief WifiBrowseManagerDelegate代理方法
 */
@protocol WifiBrowseManagerDelegate <NSObject>
@optional
- (void)wifiItemAdded: (CLXDeviceWifiInfo *)wifiInfo;
- (void)wifiSetFinished: (BOOL)bSucceed;
- (void)wifiSearchTimeout;
@end

/**
 @brief wifi相关方法，manager
 */
@interface CLWifiBrowsManager : NSObject
{
    id <WifiBrowseManagerDelegate> __weak browseWifiDelegate;
}

@property (nonatomic, weak) id <WifiBrowseManagerDelegate> browseWifiDelegate;

+(CLWifiBrowsManager *)getInstance;
+(void)releaseInstance;

-(void) WiFiInfoReachWithXMPP: (CLXDeviceWifiInfo *)deviceWiFi;
-(void) WiFiChangeFinish: (BOOL) bSucceed;
-(void) WiFiChangeFinishInMain: (BOOL)bSucceed;
-(void) WiFiSearchTimeout;

@end
