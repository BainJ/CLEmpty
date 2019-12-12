//
//  CLXGPLogProtobuf.h

#import <Foundation/Foundation.h>


// base model
@interface CLXGPLogProtobuf : NSObject

@property (nonatomic, copy) NSString *actionId;
@property (nonatomic, assign) long long clackTime;
@property (nonatomic, assign) long long endTime;
@property (nonatomic, assign) long statusCode;
@property (nonatomic, copy) NSString *phoneType;

- (NSString *)jsonValue;
@end

@interface CLGPAPIReqMessage : CLXGPLogProtobuf

@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *msg;
@property (nonatomic, assign) long sdkCode;

@end

@interface CLGPPTZMessage : CLXGPLogProtobuf
@property (nonatomic, copy) NSString *mac;
@end

@interface CLGPLibMessage : CLXGPLogProtobuf
@property (nonatomic, assign) int type;
@property (nonatomic, copy) NSString *msg;

- (instancetype)init:(int)typ message:(NSString *)msg;
@end

@interface CLGPLConnStatusMessage:CLXGPLogProtobuf

- (instancetype)initWithStatus:(int)status;

@end

@interface CLGPSessionCmdMessage : CLXGPLogProtobuf
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger cmd;
@property (nonatomic, assign) NSInteger subcmd;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, assign) NSInteger port;
@property (nonatomic, strong) NSDictionary *res;
@end

@interface CLNetworkMessage : CLXGPLogProtobuf
@property (nonatomic, copy) NSString *caas;
@property (nonatomic, copy) NSString *dns;
@property (nonatomic, copy) NSString *dnsIP;
@property (nonatomic, copy) NSString *esd;
@property (nonatomic, copy) NSString *esdVersion;
@property (nonatomic, copy) NSString *ping;
@property (nonatomic, copy) NSString *publicIP;
@property (nonatomic, copy) NSString *localIP;
@property (nonatomic, copy) NSString *update;
@property (nonatomic, copy) NSString *upns;

@end


