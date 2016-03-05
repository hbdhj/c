//
//  HelloView.m
//  Hello
//
//  Created by denghaijun on 11-10-9.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import "HelloView.h"

@implementation HelloView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Print "hello world"
    NSString *hello = @"Hello, World";
    CGPoint point = CGPointMake(10, 20);
    UIFont *font = [UIFont systemFontOfSize:24.0];
    [[UIColor whiteColor] set];
    [hello drawAtPoint:point withFont:font];
}


@end
