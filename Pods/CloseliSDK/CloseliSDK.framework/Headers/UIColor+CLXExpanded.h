
/****
 VOORBEELDEN
 
 [UIColor colorWithRGBHex:0xff00ff];
 [UIColor colorWithHexString:@"0xff00ff"]
 *******/

#import <UIKit/UIKit.h>

#define SUPPORTS_UNDOCUMENTED_API	0

@interface UIColor (CLXExpanded)
@property (nonatomic, readonly) CGColorSpaceModel colorSpaceModel;
@property (nonatomic, readonly) BOOL canProvideRGBComponents;
@property (nonatomic, readonly) CGFloat red; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat green; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat blue; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat white; // Only valid if colorSpaceModel == kCGColorSpaceModelMonochrome
@property (nonatomic, readonly) CGFloat alpha;
@property (nonatomic, readonly) UInt32 rgbHex;

- (NSString *)clx_colorSpaceString;

- (NSArray *)clx_arrayFromRGBAComponents;

- (BOOL)clx_red:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a;

- (UIColor *)clx_colorByLuminanceMapping;

- (UIColor *)clx_colorByMultiplyingByRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *)       clx_colorByAddingRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *) clx_colorByLighteningToRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *)  clx_colorByDarkeningToRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

- (UIColor *)clx_colorByMultiplyingBy:(CGFloat)f;
- (UIColor *)       clx_colorByAdding:(CGFloat)f;
- (UIColor *) clx_colorByLighteningTo:(CGFloat)f;
- (UIColor *)  clx_colorByDarkeningTo:(CGFloat)f;

- (UIColor *)clx_colorByMultiplyingByColor:(UIColor *)color;
- (UIColor *)       clx_colorByAddingColor:(UIColor *)color;
- (UIColor *) clx_colorByLighteningToColor:(UIColor *)color;
- (UIColor *)  clx_colorByDarkeningToColor:(UIColor *)color;

- (NSString *)clx_stringFromColor;
- (NSString *)clx_hexStringFromColor;

+ (UIColor *)clx_randomColor;
+ (UIColor *)clx_colorWithString:(NSString *)stringToConvert;
+ (UIColor *)clx_colorWithRGBHex:(UInt32)hex;
+ (UIColor *)clx_colorWithHexString:(NSString *)stringToConvert;
+ (UIColor *)clx_colorWithHexStr:(NSString *)hexColorStr alpha:(CGFloat)opacity;

+ (UIColor *)clx_colorWithName:(NSString *)cssColorName;

@end

#if SUPPORTS_UNDOCUMENTED_API
// UIColor_Undocumented_Expanded
// Methods which rely on undocumented methods of UIColor
@interface UIColor (UIColor_Undocumented_Expanded)
- (NSString *)clx_fetchStyleString;
- (UIColor *)clx_rgbColor; // Via Poltras
@end
#endif // SUPPORTS_UNDOCUMENTED_API
