//
//  CLXDeviceSession.h

#import <Foundation/Foundation.h>
#import "CLXSessionConsole.h"

@class CLCameraDevice;
@interface CLXDeviceSession : CLXSessionConsole

- (instancetype)initWithDevice:(CLCameraDevice *)device;

@end
