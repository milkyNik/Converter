//
//  TestClass.m
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import "LengthConverter.h"

@implementation LengthConverter

- (NSString*) returnStringWithType:(ConverterTypeLength) type {
    
    return @"Length";
    
}

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeLength) type_1 inType:(ConverterTypeLength) type_2 {
    
    return 5.f;
    
}

@end
