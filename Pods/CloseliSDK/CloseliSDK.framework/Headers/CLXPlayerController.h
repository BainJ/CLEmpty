
#import <Foundation/Foundation.h>
#import "CLXPlayerInterface.h"
#import "CLXPlayerControllerInterface.h"
#import "CLXPlayerDataSource.h"
#import "CLXPlayerDelegate.h"
/**
 @brief CLXPlayerController
 */
@interface CLXPlayerController : NSObject <CLXPlayerInterface, CLXPlayerControllerInterface>

@property (nonatomic, weak) id <CLXPlayerDelegate> delegate;
@property (nonatomic, weak) id <CLXPlayerDataSource> dataSource;

@end

@interface CLXPlayerParam : NSObject
// 时光缩影，用来传入eventType。例如@[@"1", @"3"]
@property (nonatomic, strong) NSArray *eventTypes;

@end
