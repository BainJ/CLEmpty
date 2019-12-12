//
//  SessionConnectModel.h

#import <Foundation/Foundation.h>

@interface SessionConnectModel : NSObject

@property (nonatomic,strong) NSString * mstrAccount;//必填
@property (nonatomic,strong) NSString * mstrPassword; //必填
@property (nonatomic,strong) NSString * mstrToken; //必填
@property (nonatomic,assign) BOOL needPreConnect;//是否需要预连接
@property (nonatomic,strong) NSString * mstrUnifiedID; //必填
@property (nonatomic,strong) NSString * mstrXmppServerIP;//cmd必填
@property (nonatomic,assign) int        xmppServerPort;//cmd必填
@property (nonatomic,strong) NSString * mstrRelayServerIP;//stream必填
@property (nonatomic,assign) int        relayServerPort;//stream必填
@property (nonatomic,strong) NSString * mstrRelayServerUrl;//stream必填
@property (nonatomic,strong) NSString * mstrProductKey;//stream必填
@property (nonatomic,strong) NSString * mstrCAFilePath;//stream必填
@property (nonatomic,strong) NSString * mstrConfigPath;//stream必填
@property (nonatomic,strong) NSString * mstrEmail;//stream必填
@property (nonatomic,strong) NSString * mstrPhoneNumber;//stream必填
@property (nonatomic,assign) BOOL isSharedCamera; //必填
@property (nonatomic,strong) NSString * mstrShareId; //必填
@property (nonatomic,strong) NSString * mstrStunserverIp;//stream必填
@property (nonatomic,assign) int stunserverPort;//stream必填
@property (nonatomic,strong) NSString * mstrTurnserverIp;//stream必填
@property (nonatomic,assign) int turnServerPort;//stream必填
@property (nonatomic,strong) NSString * apKey;//ap必填
@property (nonatomic,strong) NSString * apIV;//ap必填
@property (nonatomic,strong) NSString * apdeskey;//ap必填
@property (nonatomic,strong) NSString * channelNo;//子设备必传
@property (nonatomic,assign) BOOL isDownload;

@end
