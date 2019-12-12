//
//  MVIosImageStitch.h
//  imgTest2
//
//  Created by mario on 2018/6/19.
//  Copyright © 2018年 mario. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface MVIosImageStitch : NSObject

@property(nonatomic, copy, readonly) NSString* angleArrayString;

-(UIImage*)getStitchImageWithImages:(NSArray*)imgs;

/**
 * @brief getAngle 获取角度
 *
 * @param x 横坐标
 * @param sumAngle 总角度
 * @param startAngle 初始角度
 * @param xViewAngle 水平单图视角
 * @param yViewAngle 垂直单图视角
 * @param angleArrayString 角度数组字符串，传nil相当于传入成员变量angleArrayString
 * @param result 计算结果
 *
 * @return 0 success, -1 fail
 */
-(int)getAngle:(int)x sumAngle:(const float)sumAngle startAngle:(const float)startAngle xViewAngle:(const float)xViewAngle yViewAngle:(const float)yViewAngle angleArray:(NSString*)angleArrayString result:(float*)result;

+(NSString*)getVersion;

@end
